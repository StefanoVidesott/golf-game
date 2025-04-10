#!/bin/bash

# This script creates a file named "context" in the current directory.
# The file contains all the names and content of all the files inside include and his subdirectories.
# The script is intended to be run from the root of the repository.

# Check if the "context" file already exists
if [ -f "context.txt" ]; then
    echo "The file 'context.txt' already exists. Please remove it before running this script."
    exit 1
fi

# Create the "context.txt" file
touch context.txt
echo "Creating context.txt file..."
# Find all files in the "include" directory and its subdirectories
find include -type f | while read -r file; do
    # Get the file name without the path
    filename=$(basename "$file")
    # Get the content of the file
    content=$(cat "$file")
    # Write the filename and content to the "context.txt" file
    echo "File: $filename" >> context.txt
    echo "$content" >> context.txt
    echo "" >> context.txt
done

tree -I "build" >> context.txt

echo "Context.txt file created successfully."
