#!/bin/bash

gcc -I./  ./euclid_division.c -c -o ./bin/euclid.o
gcc -I./  ./diophantine.c      -c -o ./bin/diophantine.o


# ** compile simple test programs
gcc -I./ ./euclid_simple.c ./bin/euclid.o -o ./bin/euclid_simple
gcc -I./ ./diophantine_simple.c ./bin/euclid.o ./bin/diophantine.o -o ./bin/diophantine_simple
