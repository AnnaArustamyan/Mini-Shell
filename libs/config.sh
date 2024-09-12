#!/bin/bash

cd libs
path="`pwd`/$1"
mkdir -p $path/libs
cd readline-8.2 && ./configure --prefix=$path
make
make install