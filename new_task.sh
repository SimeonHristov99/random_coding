#!/bin/bash

CPP_EXT='.cpp'
PY_EXT='.py'

# get the last folder name
arr=$(ls -d */ | cut -d' ' -f2- | tail -1)

# get the last task number from the folder name
arr=${arr:4:-1}

# create the new folder name with an incremented task
arr="task"$((arr + 1))

if [[ $1 != "cpp" && $1 != "py" ]]; then
    echo "Usage: new_task.sh [py | cpp]"
    exit
fi

# create the new folder
mkdir $arr

# go into it
cd $arr || exit

# according to command line argument make a `.cpp` or a `.py` file
# and open the file in VS code

if [[ $1 == "cpp" ]]; then

    # add the extension
    arr=$arr"$CPP_EXT"

    # copy the corresponding temaplate file
    cp ../template.cpp ./$arr

elif [[ $1 == "py" ]]; then
    arr=$arr"$PY_EXT"
    cp ../template.py ./$arr
else
    echo "Usage: new_task.sh [py | cpp]"
    exit
fi

code ./$arr
