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
  - Source code management
    - Namespaces

  - Types and Variables
    - Variables
    - Primitive types
    - Function types
    - Arrays
    - Pointers
    - Structs

  - Statements
    - If statements
    - Loops
    - Functions
    - Native functions
    - Generics

  - Memory model
    - Memory management
    - The defer keyword

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
There are 6 kinds of literals:
- Integer literals
- Floating-point literals
- Character literals
  - Must be enclosed by '' and must contain exactly one character
- Boolean literals
- Pointer literal

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
```