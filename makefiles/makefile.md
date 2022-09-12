## Compiling Process

source.c -> [preprocessor] -> [compiler] -> [assembler] -> [linker] -> executable

[preprocessor] => -E
[compiler] => -S => assemnly code (.s)
[assembler] => -C => object code (.o)

## Makefile Receipt

target: prerequisites
    ->(tab) action(s)
