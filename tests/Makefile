LSDIR = ~/ft_ls
TESTROOT = $(LSDIR)/tests
BINARY = $(LSDIR)/ft_ls
TESTDIR = $(TESTROOT)/testdir
STDOUT = $(TESTROOT)/stdout.txt
STDERR = $(TESTROOT)/stderr.txt

all : setup
	#echo "\n=========== TEST SIMPLE =========\n" > $(STDOUT)
	#echo "\n=========== TEST SIMPLE =========\n" > $(STDERR)
	#-ls -R $(TESTDIR) > diff1.txt
	#-$(BINARY) -R $(TESTDIR) > diff2.txt
	#-diff diff1.txt diff2.txt >> $(STDOUT)
	#rm diff1.txt
	#rm diff2.txt
	#cat $(STDOUT)

make_diff :

clean :
	-rm $(STDOUT) $(STDERR)
	chmod 0777 $(TESTDIR)/dirnorights
	rm -rf $(TESTDIR)

re : clean all

setup :
	mkdir $(TESTDIR)
	gcc -o create-a-socket create-a-socket.c
	./create-a-socket $(TESTDIR)/mysock
	touch $(TESTDIR)/aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	touch $(TESTDIR)/rootfile
	mkfifo $(TESTDIR)/fifo1
	echo "file1 content" > $(TESTDIR)/rootfile
	mkdir $(TESTDIR)/dir1
	ln -s $(TESTDIR)/dir1 $(TESTDIR)/dir1symlink
	ln -s $(TESTDIR)/rootfile1 $(TESTDIR)/dir1/symlink1
	mkdir $(TESTDIR)/dir1/subdir1
	touch $(TESTDIR)/dir1/subdir1/file1
	echo "file1 content" > $(TESTDIR)/dir1/subdir1/file1
	mkdir $(TESTDIR)/dir01
	echo "file1 content" > $(TESTDIR)/dir1/file1
	touch $(TESTDIR)/dir1/file1
	touch $(TESTDIR)/dir1/file2
	touch $(TESTDIR)/dir1/file3
	touch $(TESTDIR)/dir1/file4
	touch $(TESTDIR)/dir1/file5
	touch $(TESTDIR)/dir1/file6
	touch $(TESTDIR)/dir1/file7
	echo "file1 content" > $(TESTDIR)/dir1/file1
	mkdir $(TESTDIR)/dir2
	touch $(TESTDIR)/dir2/file1
	echo "file1 content" > $(TESTDIR)/dir2/file1
	mkdir $(TESTDIR)/dir11
	touch $(TESTDIR)/dir11/file1
	echo "file1 content" > $(TESTDIR)/dir11/file1
	mkdir $(TESTDIR)/dirnorights
	touch  $(TESTDIR)/dirnorights/file1
	echo "file1 content" >  $(TESTDIR)/dirnorights/file1
	mkdir $(TESTDIR)/dirwithrights
	echo "file1 content" >  $(TESTDIR)/dirwithrights/file1
	chmod 0000 $(TESTDIR)/dirnorights
