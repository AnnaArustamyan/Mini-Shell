#!/bin/bash

cd libraries
path="`pwd`/$1"
mkdir -p $path/libraries
cd readline && ./configure --prefix=$path
make
make install
