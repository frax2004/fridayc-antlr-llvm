<div align="center">

  <!-- Logo (Sostituisci il percorso se necessario) -->
  <img src="logo/friday.png" alt="Friday Logo" width="180">

  <h1>The Friday Programming Language</h1>

  <!-- Badge in una sola riga -->
  <img src="https://img.shields.io/badge/License-GPL--3.0-blue.svg" alt="License">
  <img src="https://img.shields.io/badge/LLVM-16+-60c53e.svg?logo=llvm" alt="LLVM">
  <img src="https://img.shields.io/badge/ANTLR-4-red.svg" alt="ANTLR">
  <img src="https://img.shields.io/badge/C++-23+-00599C.svg?logo=c%2B%2B" alt="C++">
  <img src="https://img.shields.io/badge/Java-17+-ED8B00.svg?logo=openjdk" alt="Java">
  <img src="https://img.shields.io/badge/Build-passing-brightgreen.svg" alt="Build Status">

  <p>
    <i>A compiled, staticly-typed, imperative, modular, C-like language that supports object-oriented and functional patterns built on top of LLVM and Antlr4</i>
  </p>

</div>

---

##### Introduction
The friday programming language is a compiled, staticly-typed, imperative, modular, C-like language that supports object-oriented, functional and modern system's programming languages features and patterns with zero-runtime-overhead abstractions. The language itself is built on top of the LLVM framework, which bridges Friday to any other programming language that is LLVM-compatible. The language itself uses manual memory model with copy semantics by default like C, but still it has some features to address common C mistakes like double free or memory leaks.

## Language Reference
---
#### Index
- [Core language features](#core-language-features)
  - [Basic knowledge](#basic-knowledge)
    - [An "Hello, World!" program](#an-hello-world-program)
    - [Comments](#comments)
    - [Identifiers](#identifiers)
    - [Literals](#literals)
  
  - [Source code management](#source-code-management)
    - [Namespaces](#namespaces)
    - [The using statement](#the-using-statement)

  - [Types and Variables](#types-and-variables)
    - [Variables](#variables)
    - [Primitive types](#primitive-types)
    - [Operators](#operators)
    - [Explicit casts](#explicit-casts)
    - [Function types](#function-types)
    - [Arrays](#arrays)
    - [Pointers](#pointers)
    - [Structs](#structs)

  - [Statements](#statements)
    - [If statements](#if-statements)
    - [Loops](#loops)
    - [Functions](#functions)
    - [Member functions](#member-functions)
    - [Native functions](#native-functions)
    - [Overloading](#overloading)
    - [Operator overloading](#operator-overloading)

  - [Memory model](#memory-model)
    - [Memory management](#memory-management)
    - [The defer statement](#the-defer-statement)

  - [Compile-time utilities](#compile-time-utilities)
    - [Static reflection](#static-reflection)

- [Friday Standard Library (FSL)](#the-friday-standard-library-fsl)

## Core Language Features
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
- String literals
  - Must be enclosed by "" and can contain 0+ characters
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
const word = "An inferred string variable"; // the compiler infers the type []byte (array of 27 bytes)
```

#### Primitive types
Primitive types in friday are much simpler than other languages:
Here is a table of the available fundamental types and their matching version in C

|Friday Type|Description|C type|
|-|-|-|
|`int`|64-bit* width signed integer| `int64_t` or `long long int` |
|`float`|64-bit* width floating point| `double` |
|`byte`|8-bit* width signed integer| `int8_t` or `char` |
|`bool`|1-bit* boolean integer| `_Bool` or `bool` |
|`void`|0-bit* empty type| `void` |
|`*any`|64-bit* pointer| `void` |
|`[]any`|64-bit* pointer + 64-bit* length| `void` |

(*) : Bit width are guaranted to be the specified ones (platform independent)

#### Operators
Here's a table of each Friday type and the operators supported by each type
|Operator|Description|Supported by default by|
|-|-|-|
|`+`| unary plus | `int`, `float`|
|`-`| unary minus | `int`, `float`|
|`+`| binary plus | `int`, `float`|
|`-`| binary minus | `int`, `float`|
|`*`| multiply | `int`, `float`|
|`/`| divide | `int`, `float`|
|`%`| division rest | `int` |
|`<<`| bitwise shift left | `int` |
|`<`| less than | `int`, `float`, `byte`, `*any`, `[]any` |
|`<=`| less than or equal to | `int`, `float`, `byte`, `*any`, `[]any` |
|`==`| equal to | `int`, `float`, `byte`, `*any`, `[]any` |
|`!=`| not equal to | `int`, `float`, `byte`, `*any`, `[]any` |
|`>`| greater than | `int`, `float`, `byte`, `*any`, `[]any` |
|`>=`| greater than or equal to | `int`, `float`, `byte`, `*any`, `[]any` |
|`>>`| bitwise shift right | `int` |
|`and`| logical and | `bool` |
|`or`| logical or | `bool` |
|`not`| logical not | `bool` |
|`&`| bitwise and | `bool`, `int` |
|`\|`| bitwise or | `bool`, `int` |
|`~`| bitwise not | `bool`, `int` |
|`.`| member access | `any-struct`, `[]any` |
|`*`| dereference | `*non-void` |
|`&`| reference | `any-type` |
|`as`| explicit cast | `non-void` |
|`sizeof`| byte size operator | `any-object`, `any-type` |
|`alignof`| byte alignment operator | `any-object`, `any-type` |
|`[]`| array element access | `[]non-void`, `*non-void` |

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
struct {
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

Arrays elements are accessed with the usual `operator[]` with indexes ranging in 0 ,  ... ,  \<array\>.len-1.

Unlike C, arrays cannot decay to pointers and their fields cannot be reassigned, however the .ptr field can be used to initialize an entity of type `*type` where **type** is the element type of the array.

#### Pointers
Pointers in Friday store either a reference to an object or null.
Null objects cannot be dereferenced (if that happens, that results in an undefined behavior)

Non-void type pointers can be dereferenced, indexed with the usual array syntax (`operator[]`) and pointer arithmethic is supported.

```C
let object: int = 7;
let pointerToObject: *int = &object; // the '&' operator is used to take the address of the referenced object
let result = *pointerToObject; // result = 7, the operator '*' is used to dereference the pointer to the referenced object.
const nullPointer = null; // the type of nullPointer is *void
*nullPointer; // undefined behaviour
```

#### Structs
Structs in Friday are aggregate types of at least 1-bit width (bit width of a struct containing only one boolean field)

Note that a struct cannot have a field that has the same type as the declaring struct (**recursive struct problem**)

```C++
struct Vec2 {
  x: float; // ok
  y: float; // ok
  z: Vec2; // Error, recursive struct field
  w: *Vec2; // ok
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

### Statements
---

#### If Statements
If statements in Friday are similar to C if statements for the most syntax but behave in the same way:

```C
if condition {
  /* ... */
} elif condition {
  /* ... */
} else {
  /* ... */
}
```

#### Loops

There are two kinds of loops in Friday:
- `while` loop
- `for` loop

###### While loop
While loops in Friday behave the exact same way as in C.
Here's an example of the **while loop**

```C
while condition {
  /* ... */  
}
```

###### For loop
Range based for loops are not yet supported in Friday, so for now only the classic C-style for loop is allowed.

Here's an example of the **for loop**
```C
for(let i = 0; i < 10; ++i) {
  /* ... */  
}
```

#### Functions
Any non-native function in Friday can be defined in two ways:

```C
// standard way: name, parameter list, return type, function body
fn add(x: int, y: int) -> int {
  return x + y;
}
// shorthand
fn subtract(x: int, y: int) -> int => x - y;
// same as 
fn subtract(x: int, y: int) -> int {
  return x - y;
}

fn main() -> void { // the return type of the main function must be void
  const f = add;
  print f(2, 3); // function call using function pointer to function add
}
```

When a function has only one instruction and that instruction is a return statement, the function body can be shortened with an an `inline-body` as showed in the example above.

#### Member Functions
Structs in the Friday programming language can have associated functions called **member functions** like many other language's class methods, except that member functions have the **explicit this parameter**
as the first parameter and that they are defined inside structs.

###### The explicit 'this' parameter
The explicit **this** parameter is the access point to the fields and member functions of the instance that called that member function. Thus the explicit this parameter must be the first parameter of the member function and its type must be a one-dimentional pointer to the declaring struct type.

```C
struct Rectangle {
  x: float;
  y: float;

  fn area(this: *Rectangle) -> float => this.x * this.y;

  fn foo() -> void {
    // error: a member function must have the explicit this parameter as the first parameter
  }
}
```
Note that, since struct instances use the dot notation to access fields and pointer to struct should access the referenced instance first, auto dereference is applied to the pointer object if it is a one dimentional pointer (otherwise the dereference syntax is needed).

#### Native Functions
Functions can also be declared as **native**, which means that its implementation is defined in another object file during the compilation process (even in another language like C/C++ or Rust). This brings an interface between Friday and other compiled languages.

```C
native fn add(x: int, y: int) -> int; // leave a ; to complete the native function declaration
```

Note that native functions **cannot be member functions** and that not giving the implementation of any native function results in a link error (possibly **undefined reference to object X**).


#### Overloading
Functions in Friday can also be overloaded, which means that two functions with different parameters can have the same name, and that the compile will figure out what is the correct overload of the function (if there is any matching) based on the types of the arguments that are passed in the function call.

A function with its overload must differ in the parameter list in either one of the following features:
- different **order** of the parameters
- different **types** of the parameters
- different **number** of parameters

A function and its overloads can have a different return types, but the return type alone is not sufficient to differ the overloaded functions.

```C
fn add(x: int, y: int) -> int => x + y; // ok
fn add(x: float, y: float) -> float => x + y; // ok
fn add(x: float, y: float) -> int => x + y; // error: cannot overload two functions with the return type alone

fn main() -> void {
  let y1 = add(3, 3); // ok, calls add(int, int)
  let y2 = add(2.3, 2.1); // ok calls add(float, float)
  let y3 = add(3.1, 3); // error: no matching function for call to add(float, int)
  let y4 = add(y2 as int, 3); // ok, calls add(int, int)
}
```

#### Operator overloading
Operators in the Friday programming language are also member functions defined whithin their type definition, so they can be overloaded:

```C
struct Vec2 {
  x: float;
  y: float;

  fn operator+(this: *Vec2, other: Vec2) -> Vec2 => new Vec2{
    x: this.x + other.x,
    y: this.y + other.y
  };

  fn describe(this: *Vec2) -> void {
    print this.x;
    print this.y;
  } 
}

fn main() -> void {
  let u = new Vec2{
    x: 1,
    y: 2
  };
  
  let v = new Vec2{
    x: 5,
    y: 8
  };

  (u + v).describe();
}
```

All operators can be overloaded except:
- `.` (field access operator)
- `as` (explicit cast operator)
- `sizeof` (byte size operator)
- `alignof` (byte align operator)

### Memory Model
---

#### Memory Management
Memory management in the Friday programming language is manual like C, but it offers some tools to handle it better.
The Friday language follows the copy semantics, which means that every object is by default copied.

Note that copy of a pointer is not the copy of the referenced object, but a copy of the address of the referenced object.
Memory can be **stack** allocated or **heap** allocated. 

###### Heap Memory Allocations
Memory is allocated and freed with 2 native functions coming from C: **malloc** and **free**
from the `cstd` library.

```fridaylang
using cstd;

fn main() -> void {
  let x: *int = malloc(sizeof int);
  /* ... */
  free(x);
}
```

### The Defer Statement
The defer statement is a modern compiler feature that lets execute code automatically on scope exit.
In the Friday language, here's an example of usage:

```C
fn main() -> void {
  let x: *int = malloc(sizeof int);
  print "Very difficult job started";
  defer free(x); // deferred statement execution
  defer {
    print "Freed x";
  } // deferred scope excecution
  print "Very difficult job done";
}
```

**Output :**
```cmd
Very difficult job started
Very difficult job done
Freed x;
```

Note that if there is more than one defer statement they will be stacked and executed from the first to the last at the end of the enclosing scope.

### Compile-Time Utilities
---

#### Static Reflection
```bash
⚠️ This section is incomplete ⚠️ 
```

## The Friday Standard Library (FSL)
---

```bash
⚠️ This section is incomplete ⚠️ 
```

