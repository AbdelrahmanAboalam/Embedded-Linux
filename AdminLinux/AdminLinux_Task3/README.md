# For Task3

## Section 1

- After run script it added a Global variable that I can use it every time

  ![Screenshot from 2024-07-07 23-31-17](https://github.com/Aboalam15/Embedded-Linux/assets/159071759/d0fc02e0-f5a8-4edc-a881-f75165f7dac5)
## Section 2

## Q1

-To list user and redirect to another file 
```bash
ls /usr/bin > /tmp/commands.list
```
```bash
less /tmp/commands.list
```
![Screenshot from 2024-07-09 19-01-59](https://github.com/Aboalam15/Embedded-Linux/assets/159071759/e40e822b-0808-4f1b-bff9-09f258409300)
![Screenshot from 2024-07-09 19-01-53](https://github.com/Aboalam15/Embedded-Linux/assets/159071759/ab0de83f-d14e-4f57-8e93-bc6c621655ee)

# Q2

- To display My name and date in my terminal go to
```bash
nano /home/usr/.bashrc
```
and then add this commands
```bash
echo yourname
```
```bash
echo /$(date +"%m/%d/%Y") 
```
![Screenshot from 2024-07-07 23-31-17](https://github.com/Aboalam15/Embedded-Linux/assets/159071759/741c1dfa-00f7-46ec-8910-10a0e3b9444d)



# Q3

- To count the number of users using this command
```bash
ls /usr/bin |wc -w
```
![Screenshot from 2024-07-09 18-49-17](https://github.com/Aboalam15/Embedded-Linux/assets/159071759/cba231e7-24d3-4a46-a504-37d6a8b2b308)

# Q4 

- If I run
```bash
cat file1 | cat file2
```
This will display the content of file2 only

- If I run
```bash
ls | rm
```
This will list the files in current file and give it to rm command to remove it

- If I run
```bash
ls /etc/passwd | wc -l
```
It will give me list of users informations

# Q5

- To find file name called .profile
```bash
find / -name .profile
```
- You can also use local but want to add pakage
```bash
sudo apt install mlocate
```
Then you can use 
```bash
local .profile
```

# Q6

- -i and --inode print the index number of ech file
![Screenshot from 2024-07-09 19-39-49](https://github.com/Aboalam15/Embedded-Linux/assets/159071759/cd744088-b8ed-4b98-91b2-60cc6e926036)

# Q7 

- To make symbolic link you can use
```bash
ln -s /Desktop /home/aboalam/Desktop/workspace/SoftLink
```
 ![image](https://github.com/Aboalam15/Embedded-Linux/assets/159071759/d56e1849-c03b-463f-a1db-8d486d66614b)

# Q8 
- Hard links only can link to files only
- we use the same pravious command without -s

# Q9

- ![image](https://github.com/Aboalam15/Embedded-Linux/assets/159071759/6909e597-2d67-4c09-b7e3-a33022c9dd5d)


