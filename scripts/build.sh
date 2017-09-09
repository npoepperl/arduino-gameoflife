#!/bin/bash

libDirectory="lib/"
gameOfLifeSrcPath=$libDirectory"gameoflife/src/"
gameOfLifeBuildPath=$gameOfLifeSrcPath"build/"

workingDir=$(pwd)

rebuild="no"
test="no"
buildSuccessful="no"

while [ "$1" != '' ]
  do
    [ $1 == "-r" ] && rebuild="yes" && echo "A rebuild will be performed!" && shift
    [ $1 == "-t" ] && test="yes" && echo "All tests will be executed after successful build!" && shift
done


if [ $rebuild == "yes" ]; then
    if [ -d $gameOfLifeBuildPath ]; then
        rm -r -f $gameOfLifeBuildPath
    else
        echo "The build-directory doesn't exist."
    fi
fi

if [ -d $libDirectory ]; then
    if [ ! -d $gameOfLifeBuildPath ]; then
        mkdir $gameOfLifeBuildPath
    fi

    cd $gameOfLifeBuildPath

    cmake .. 1> cmake.log 2> /dev/null

    if [ $? -eq 0 ]; then
        echo "Cmake successfully created buildfiles."
    else
        echo "Error creating buildfiles."
        exit 1
    fi

    make 1> build.log 2> /dev/null

    if [ $? -eq 0 ]; then
        echo "Build was successful."
    else
        echo "Error building library."
        exit 1
    fi

    if [ $test == "yes" ]; then
        echo "Tests will be executed."
        ./test/testGameOfLife/gtestRunner
    fi
fi

cd $workingDir