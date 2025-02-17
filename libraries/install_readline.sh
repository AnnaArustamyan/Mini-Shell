#!/bin/bash

cd libraries
path="`pwd`/$1"
cd readline && ./configure --prefix=$path
make
make install
