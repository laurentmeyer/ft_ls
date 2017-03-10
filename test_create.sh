#!/bin/bash

mkdir test
cd test
touch aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
touch rootfile
echo "file1 content" > rootfile
mkdir dir1
ln -s rootfile1 dir1/symlink1
mkdir dir01
echo "file1 content" > dir1/file1
touch dir1/file1
echo "file1 content" > dir1/file1
mkdir dir2
touch dir2/file1
echo "file1 content" > dir2/file1
mkdir dir11
touch dir11/file1
echo "file1 content" > dir11/file1
cd ..
