#!/bin/bash

export LD_LIBRARY_PATH=`pwd`/LibBomberman_linux_x64/libs/:`pwd`/Sound/lib/
file=$(pwd)"/bomberman"

if [ -f "$file" ]
then
    echo "Running Bomberman by La Pintade";
    make ; ./bomberman;
else
    make re ; ./bomberman;
fi
