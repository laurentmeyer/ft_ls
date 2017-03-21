#!/bin/bash

TESTROOT=~/ft_ls/libft/libft/tests
TESTDIR=$TESTROOT/test


cd $TESTROOT
chmod 0777 $TESTDIR/dirnorights
rm -rf $TESTDIR

mkdir $TESTDIR
cd $TESTDIR
touch aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
touch rootfile
mkfifo fifo1
echo "file1 content" > rootfile
mkdir dir1
ln -s rootfile1 dir1/symlink1
mkdir dir1/subdir1
touch dir1/subdir1/file1
echo "file1 content" > dir1/subdir1/file1
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
mkdir dirnorights
touch  dirnorights/file1
echo "file1 content" >  dirnorights/file1
chmod 0000 dirnorights
cd ..
