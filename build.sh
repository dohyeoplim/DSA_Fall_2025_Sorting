#!/bin/bash
set -e

CC=clang
CFLAGS="-Wall -Wextra -g"

$CC $CFLAGS src/util.c src/sort.c src/main.c -o sort
echo "Done. Run ./sort"
