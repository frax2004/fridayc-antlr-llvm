# The Friday Programming Language & Compiler
---

##### Introduction
The friday programming language is a compiled, staticly-typed, imperative, modular, C-like language that supports object-oriented, functional and modern system's programming languages features and patterns with zero-runtime-overhead abstractions. The language itself is built on top of the LLVM framework, which bridges Friday to any other programming language that is LLVM-compatible. The language itself uses manual memory model with copy semantics by default like C, but still it has some features to address common C mistakes like double free or memory leaks.

## Language Reference
---
#### Index
- Core language features
  - Basic knowledge
    - An "Hello, World!" program
    - Comments
    - Identifiers
    - Literals
    - Array literals
  
  - Source code management
    - Namespaces
    - The using statement

  - Types and Variables
    - Variables
    - Primitive types
    - Explicit casts
    - Function types
    - Arrays
    - Pointers
    - Structs

  - Statements
    - If statements
    - Loops
    - Functions
    - Overloading
    - Operator overloading
    - Native functions

  - Memory model
    - Memory management
    - The defer statement

  - Compile-time utilities
    - Static reflection

- Friday Standard Library (FSL)

### Basic Knowledge
---

#### An "Hello, World!" program
Like in any other compiled language, a Friday program (.fx, .fr) starts with the main function
```C
// test.fx
fn main() -> void {
  print "Hello, World!";
}
```
A Friday program can be JIT executed using the LLVM-JIT framework or directly built and compiled into binary.
To build this program, execute the following command on the shell:
```bash
fridayc build test.fx
```
Or, to run the JIT version of this program, execute the following command on the shell:
```bash
fridayc run test.fx
```

#### Comments
The Friday language allows two types of comments (same as C): single line and multiline comments.

```C
// This is single line comment
/* This
is a 
multiline
comment */
/* This is also a multiline comment */
```

#### Identifiers
Identifiers in the Friday language share the same rule as C identifiers, that is:
- They must start with a non digit alphabetical character or with '_'
- The charset allowed for the identifiers is the English alphabet (any case) with the '_' symbol and the 0-9 digits.
Also, the language is case sensitive, which means that the identifier (or the keyword) 'X' is different from 'x'.
```C
number    // valid identifier
__numb3r_ // valid identifier
9umber    // invalid identifier
```

#### Literals
There are 7 kinds of literals:
- Integer literals
- Floating-point literals
- Character literals
  - Must be enclosed by '' and must contain exactly one character
- Boolean literals
- Pointer literal
- Array literals

```C
-67 // This is an integer literal
6.7 // This is a Floating-point literal
true // This is a boolean literal
null // This is the pointer literal
'a' // This is a valid character literal
'ac' // This is an invalid character literal
'' // This is also an invalid character literal
"A very long literal" // This is a valid string literal
"" // This is also a valid string literal
[1, 2, 3, 4] // This is a valid int array
[3.4, 1] // This is an invalid array
```


### Source Code Management
---

#### Namespaces
Each source file is a `Translation Unit` or a namespace, except for the **only one** file that contains the **main** function (in which case the namespace must be none).
Every other file that is built with the source file that contains the main function, must declare its namespace. A namespace can be shared between different files but a file can declare only a namespace of membership.

There are some rules to follow:
- namespace identifiers follow the same rules as regular identifiers, except that the '.' character could be included after the first character.
- the **namespace declaration** (if present) must be the first statement in the file
- if a source file (that does not contain the main function) does not declare a namespace of membership, then its names will be visible under the global namespace
- the file that contains the main function must not declare any namespace of membership because the main function is the entry point and must be declared in the global namespace.
- namespaces (unlike other languages) have nothing in common with filenames or directories

```C++
// in file test.fx
namespace test;
/* ... */

// in file main.fx
// do not declare any namespace here
/* ... */
fn main() -> void {}
/* ... */
```

#### The using statement
To be able to access the names declared in a different namespace, there are either two ways:
- use the fully-qualified-name
- "use" the namespace

```C++
// in file testing.fx
namespace outer.inner;

fn getData() -> int {
  return 3;
}

// in file main.fx
fn main() -> void {
  let data: int = outer.inner.getData();
  /* do something with data */
}

// or
using outer.inner;
fn main() -> void {
  let data: int = getData();
  /* do something with data */
}
```

### Types and Variables
---

#### Variables
A variable in Friday is a stack value that has the lifetime of the scope in which it is declared.

A variable can be **mutable** if declared with the keyword `let` or **immutable** if declared with the keyword `const`

A variable declaration could explicitly specify a type (which helps detect potential errors) or let the compiler infer the type.

All variable must be initialized when declared (due to the **Resource Acquisition Is Initialization** or **RAII** principle).

```C
const pi: float = 3.14159; // constant declared explicitly as float
let n = 0; // the compiler infers automatically the type int because the expression assigned evaluates to an int
const word = "An inferred string variable"; // the compiler infers the type *byte (pointer to byte)
```

#### Primitive types
Primitive types in friday are much simpler than other languages:
Here is a table of the available fundamental types and their matching version in C

|Friday Type|Description|C type|
|-|-|-|
|`int`|${64}$-bit $^*$ width signed integer| `int64_t` or `long long int` |
|`float`|${64}$-bit $^*$ width floating point| `double` |
|`byte`|${8}$-bit $^*$ width signed integer| `int8_t` or `char` |
|`bool`|${1}$-bit $^*$ boolean integer| `_Bool` or `bool` |
|`void`|${0}$-bit $^*$ empty type| `void` |

$(^*)$ : Bit width are guaranted to be the specified ones (platform independent)

#### Explicit Casts
Implicit casts are not supported in Friday since they are almost always the cause of unwanted errors or non-intentional numeric overflows.

Th only implicit cast that is permitted is from `null` to `any pointer type`.

Type coercions are permitted anyway through explicit cast.
```C
const N1: int = 3.4; // invalid assignment: cannot implicit cast a floating point literal to an integer
const N2: int = 3.4 as int; // ok;
```

#### Function types
Functions have a type which can be used for functional patterns with function pointers, that is, a reference to a function.

```C
fn add(x: int, y: int) -> int {
  return x + y;
}

let y: fn(int, int) -> int = add; // or let the compiler infer the type
```

#### Arrays
Arrays in Friday are compile-time-length known pointers of a particular non-void type.

Arrays are in fact a pair of pointer to the data and its length that must be compile-time known.

To show what really arrays are, here's what an int array looks like from a C program perspective:

```C
let struct {
  int64_t const *ptr;
  const int64_t len;
} numbers = { 
  .ptr = {1, 2, 3, 4}, 
  .len = 4 
};
```

That in Friday corresponds to:
```C
let numbers: []int = [1, 3, 4, 5]; // array of integers of length 4
```

Arrays elements are accessed with the usual `operator[]` with indexes ranging in $0$ , $ ...$ , $ $\<array\>.len$-1$.

Unlike C, arrays cannot decay to pointers and their fields cannot be reassigned, however the .ptr field can be used to initialize an entity of type `*type` where **type** is the element type of the array.

#### Pointers
Pointers in Friday store either a reference to an object or null.
Null objects cannot be dereferenced (if that happens, that results in an undefined behavior)

Non-void type pointers can be dereferenced, indexed witht the usual array syntax and pointer arithmethic is supported.

```C
let object: int = 7;
let pointerToObject: *int = &object; // the '&' operator is used to take the address of the referenced object
let result = *pointerToObject; // result = 7, the operator '*' is used to dereference the pointer to the referenced object.
const nullPointer = null; // the type of nullPointer is *void
*nullPointer; // undefined behaviour
```

#### Structs
Structs in Friday are aggregate types of at least $1$-bit width (bit width of a struct containing only one boolean field)

```C++
struct Vec2 {
  x: float;
  y: float;
}

// Structs are allocated by default in the stack with the `operator new`
// The following statement is an aggregate initialization, not a constructor call.
let y = new Vec2{
  y: 56;
  x: 43; // Order independent field initialization
};
```
Here the `operator new` is **only a syntax indicator** and **does not mean** nothing else (like a memory **heap allocation** in other languages).
Since struct variables are stack allocated, they share the same rules as primitive variables.
Also, since variables must be initialized during initialization (due to the **Resource Acquisition Is Initialization** or **RAII** principle), all fields must be initialized. (see more on memory management)