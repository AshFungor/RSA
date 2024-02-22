#!/bin/sh

executable=$PWD/build/src/RSA

cp "$executable" data
executable=$PWD/data/RSA 

cd data
$executable > /dev/null < stdin-cipher.txt
$executable > /dev/null < stdin-decipher.txt

rm "$executable"
cat out.txt