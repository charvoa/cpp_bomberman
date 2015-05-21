#!/bin/bash

export LD_LIBRARY_PATH=`pwd`/LibBomberman_linux_x64/libs/:`pwd`/Sound/lib/
file=$(pwd)"/bomberman"

make re; ./bomberman;
