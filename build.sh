#!/bin/bash

FILES_TO_COMPILE="bethyw.cpp input.cpp parse.cpp"

if [ $# -eq 0 ]; then
  set -x
  cd "${0%/*}"
  mkdir -p bin
  rm ./bin/bethyw 2> /dev/null
  g++ --std=c++17 -Wall ${FILES_TO_COMPILE} main.cpp -o ./bin/bethyw
elif [[ $1 == test* ]]; then
  # Do we need to compile Catch2?
  if [ ! -f ./bin/catch.o ]; then
    set -x
    cd "${0%/*}"
    g++ --std=c++11 -c ./libs/catch2/catch_main.cpp -o ./bin/catch.o
  else
    set -x
  fi
  
  cd "${0%/*}"
  mkdir -p bin
  rm ../bin/bethyw-test 2> /dev/null
  g++ --std=c++11 -Wall ./tests/$1.cpp ${FILES_TO_COMPILE} ./bin/catch.o -o ./bin/bethyw-test
else
  echo "Unknown argument" "$1"
fi