# Hello

Q1-The thee Linux Distributions: 1-ubuntu
				2-kali
				3-readhat
Q2- man command is a help command used for get short reference manuals for individual commands, Apifunctions, concepts (only used with External commands only)

Q3- rm command is used for remove Files and Directories and it used for remove a directory with files in using recursive tag ( rm -r mydir)  this will remove mydir and its files

   rmdir command only used to remove Empty Directories but it can remove non Empty Directory using reursive tag (rmdir -r mydir)

Q4-     to go to home                 -----> cd
	to make Directory dir1,docs   -----> mkdir dir1 docs
	to go in dir1                 -----> cd dir1
	to make Directory dir11,dir12 -----> mkdir dir11 dir12
	to go in dir11                -----> cd dir11
	to creat file in dir11        -----> touch file
	to go for docs from dir11     -----> cd ../docs
	to creat mycv in docs         -----> touch mycv
	to go in Documents in home    -----> cd ../Documents
	to creat Oldfiles             -----> touch Oldfiles
	a- if I remove dir11 with rmdir I get (Failed to remove : Directory is not Empty) so
	   that I should Recursive Tag ----> rmdir -r dir11
	b- it gives me "Failed to remove OldFiles : Not a Directory"
	c- For Absloute ----> /home/user/docs/mycv
	   For Relative ----> docs/mycv

Q5- cp /etc/passwd ~/mypasswd

Q6- to rename file ------> mv mv mypasswd oldpasswd

Q7-  1-cd ~
     2- cd
     3- cd /home/youssef
     4- cd ../../home/youssef
     
Q8-  ls /usr/bin/w*

Q9- type command is used for showing us the type of any command (Internal - External - Hashed) and information about the commands according to shell like ---> type ls

Q10- to find 2 types of command start with c
       ------> find /usr/bin -maxdepth 1 -type f -name 'c*' | head -n 2 
       
Q11- man -k readfile

Q12- apropos command is similer command to man command it is also considered as one of the help  
     commands but not commonly used.
