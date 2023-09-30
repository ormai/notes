#!/usr/bin/env bash

program=$1 # First argument
tests=$(ls -1 ./tests | /usr/bin/grep .in | /usr/bin/cut -d '.' -f 1)
failed=false

[[ $tests == '' ]] && echo "The test cases directory is empty." && exit 0
[[ $program == '' ]] && echo "You have to specify the name of a Python script. Es: ./tests N1.py" && exit 0

for i in $tests
do
  # Execute the $program and store the stdout in the output.txt file
  /usr/bin/python3 $program < ./tests/${i}.in > /tmp/python-test-output.txt 2> /dev/null

  # Compare the output of the program with the output expected.
  if [[ $(git diff --no-index /tmp/python-test-output.txt ./tests/${i}.out) ]]; then
    failed=true
    echo "Program failed with input ${i}.in"
  fi
done

[[ $failed == false ]] && echo "All tests passed successfully."
