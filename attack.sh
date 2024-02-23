#!/bin/sh

cd build/attacks && $PWD/attack

echo "initial text:"
cat plaintext.txt
echo 

echo "resulting text:"
cat result.txt
echo