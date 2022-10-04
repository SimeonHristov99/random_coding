#!/bin/bash

if [[ -e template.cpp ]]; then
    # when calling from main directory
    # put new task in most recently created folder
    last_created_folder=$(ls | sort -V | grep "$(date +"%y")" | tail -n -1)
    cd "$last_created_folder" || exit
elif [[ ! -e ../template.cpp ]]; then
    echo "ERROR: The script should be called in the main folder or a first-level subfolder."
    exit
fi

# get the lexicographically largest filename
filename=$(ls | sort -V | tail -n 1)

if [[ -z $filename ]]; then
    filename="task0."
fi;

# get the last task number from the folder name
if [[ ! "${filename::4}" == "task" ]]; then
    echo "ERROR: Unknown task prefix: ${filename::4}"
    exit
fi

# extract the number of the last created task
last_task_number=${filename%%.*}
last_task_number=${last_task_number#task}

if [ $# -eq 0 ]; then
    # create the new folder name with an incremented task
    filename=${filename::4}$((last_task_number + 1))".cpp"
else
    # otherwise use suffix entered by user
    filename=${filename::4}"$1"".cpp"
fi

cp ../template.cpp ./"$filename"
cd ..
