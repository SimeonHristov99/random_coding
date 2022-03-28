#!/bin/bash

arr=$(ls -d */ | cut -d' ' -f2- | tail -1)
arr=${arr:4:-1}
arr="task"$((arr + 1))
mkdir $arr
cd $arr || exit
cp ../template.cpp ./$arr".cpp"
code ./$arr".cpp"