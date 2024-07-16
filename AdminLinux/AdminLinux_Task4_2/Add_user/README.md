# Task 4 section 2

1- To creat a secondry group

``` bash
sudo groupadd -g 30000 pgroup
```

2- To lock any user change expired date

``` bash
sudo usermod --expiredate 1 abdo
```

3- To delete user
```bash
sudo userdel abdo
```

4- To delete group
```bash
sudo groupdel pgroup
```

5- 

**useradd**

Is low level command using it just create the user but does not create its home directory or any of the files that needed for the configuration 

**adduser**

s high level command it creates the home directory automatically without any additional options also copy the meta data from /etc/skel

