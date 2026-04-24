# The Friday Programming Language & Compiler
---

##### Introduction
The friday programming language is a compiled, staticly-typed, imperative, modular, C-like language that supports object-oriented, functional and modern system's programming languages features and patterns with zero-runtime-overhead abstractions. The language itself is built on top of the LLVM framework, which bridges Friday to any other programming language that is LLVM-compatible. The language itself uses manual memory model with copy semantics by default like C, but still it has some features to address common C mistakes like double free or memory leaks.

## Language Reference
---
#### Index
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

- Memory model
  - Memory management
  - The defer keyword

- Compile-time utilities
  - Static reflection

- Friday Standard Library (FSL)

### Basic Knowledge
---

#### An "Hello, World!" program

```C
fn main() -> void {
  print "Hello, World!";
}
```