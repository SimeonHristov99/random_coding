#!/bin/bash

function is_empty {
    local dir="$1"
    shopt -s nullglob
    local files=("$dir"/* "$dir"/.*)
    [[ ${#files[@]} -eq 2 ]]
}

# get the current date in the format in the repository
current_date=$(date +"%y_%m_%d")

# create a new folder with a name equal to the current date
if [[ -e "$current_date" && "$(ls -A "$current_date")" ]]; then
    echo "Folder $current_date already exists and is not empty! Will not proceed."
    exit
fi

echo "Creating folder: $current_date"
mkdir "$current_date"

for _ in {1..7}; do
    ./new_task_cpp.sh
done
