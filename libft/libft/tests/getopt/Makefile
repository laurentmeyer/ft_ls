TESTROOT = ~/ft_ls/libft/libft/tests
TESTDIR = $(TESTROOT)/test
RESFILE = result.txt

all : remove_demo create_demo
	@echo "\n=========== TEST SIMPLE =========\n" > $(RESFILE)
	-@ls -R $(TESTDIR) > diff1.txt
	-@ls -R $(TESTDIR)/dir1 > diff2.txt
	-@diff diff1.txt diff2.txt >> $(RESFILE)
	@rm diff1.txt
	@rm diff2.txt
	@cat $(RESFILE)

remove_demo :
	-@rm $(RESFILE)
	@cd $(TESTROOT)
	@chmod 0777 $(TESTDIR)/dirnorights
	@rm -rf $(TESTDIR)

create_demo :
	@mkdir $(TESTDIR)
	@touch $(TESTDIR)/aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	@touch $(TESTDIR)/rootfile
	@mkfifo $(TESTDIR)/fifo1
	@echo "file1 content" > $(TESTDIR)/rootfile
	@mkdir $(TESTDIR)/dir1
	@ln -s $(TESTDIR)/rootfile1 $(TESTDIR)/dir1/symlink1
	@mkdir $(TESTDIR)/dir1/subdir1
	@touch $(TESTDIR)/dir1/subdir1/file1
	@echo "file1 content" > $(TESTDIR)/dir1/subdir1/file1
	@mkdir $(TESTDIR)/dir01
	@echo "file1 content" > $(TESTDIR)/dir1/file1
	@touch $(TESTDIR)/dir1/file1
	@echo "file1 content" > $(TESTDIR)/dir1/file1
	@mkdir $(TESTDIR)/dir2
	@touch $(TESTDIR)/dir2/file1
	@echo "file1 content" > $(TESTDIR)/dir2/file1
	@mkdir $(TESTDIR)/dir11
	@touch $(TESTDIR)/dir11/file1
	@echo "file1 content" > $(TESTDIR)/dir11/file1
	@mkdir $(TESTDIR)/dirnorights
	@touch  $(TESTDIR)/dirnorights/file1
	@echo "file1 content" >  $(TESTDIR)/dirnorights/file1
	@mkdir $(TESTDIR)/dirwithrights
	@echo "file1 content" >  $(TESTDIR)/dirwithrights/file1
	@chmod 0000 $(TESTDIR)/dirnorights
