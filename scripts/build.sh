#!/bin/bash

libDirectory="lib/"
gameOfLifeSrcPath=$libDirectory"gameoflife/src/"
gameOfLifeBuildPath=$gameOfLifeSrcPath"build/"

workingDir=$(pwd)

if [ $1 == "-r" ]; then
    if [ -d $gameOfLifeBuildPath ]; then
        echo $gameOfLifeBuildPath
        rm -r -f $gameOfLifeBuildPath
    else
        echo "build existiert nicht"
    fi
else
    echo "komisch"
fi

if [ -d $libDirectory ]; then
    if [ ! -d $gameOfLifeBuildPath ]; then
        mkdir $gameOfLifeBuildPath
    fi

    cd $gameOfLifeBuildPath

    cmake ..
    make
else
    echo "lib directory does not exist ["$libDirectory"]."
fi

cd $workingDir