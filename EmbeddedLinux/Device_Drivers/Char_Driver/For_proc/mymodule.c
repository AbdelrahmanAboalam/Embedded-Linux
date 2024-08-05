#include<linux/module.h>
#include<linux/init.h>
#include<linux/cdev.h>
#include<linux/fs.h>
#include<linux/proc_fs.h>


ssize_t my_write(struct file *file, const char __user *buff, size_t size, loff_t *loff);
ssize_t	my_read (struct file *file, char __user *buff, size_t size, loff_t *loff);


struct proc_dir_entry *proc_dir;
const struct proc_ops proc_file_opreathions = 
{
 
    .proc_write=my_write,

    .proc_read=my_read
};


ssize_t my_write(struct file *file, const char __user *buff, size_t size, loff_t *loff)
{
    char buffer[10];
    if (size>10)
    {

        printk("Not ok");   
    }
    else
    {
        printk("Write Ok");
        (void)copy_from_user(buffer,buff,size);
        printk("The first byte : %d",buffer[0]);
    }
    return 1;
}

	ssize_t	my_read (struct file *file, char __user *buff, size_t size, loff_t *loff)
    {
        printk("Hello from read");
        return 0;
    }


int my_kernel_init(void)
{

    proc_dir=proc_create("google",0666,NULL,&proc_file_opreathions);
    printk("Hello From Kernel\n");
    return 0;
}


void my_kernel_exit(void)
{   
    proc_remove(proc_dir);

    printk("Exit From Kernel\n");

}


module_init(my_kernel_init);
module_exit(my_kernel_exit);

MODULE_LICENSE("GPL");