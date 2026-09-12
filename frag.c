#include <stdio.h>
#include <stdlib.h>


void foo() {
  bar();
}

void bar() {
  foo();
}
