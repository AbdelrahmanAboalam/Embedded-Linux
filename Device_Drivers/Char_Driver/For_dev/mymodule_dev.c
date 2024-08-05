#include<linux/module.h>
#include<linux/init.h>
#include<linux/cdev.h>
#include<linux/fs.h>
#include<linux/proc_fs.h>
#include<linux/uaccess.h>
#include<linux/device.h>


//---------------------------------------------Prototypes--------------------------------------------------------//
int driver_open(struct inode *device_file,struct file *instacne);
int driver_close(struct inode *device_file,struct file *instacne);
ssize_t driver_read (struct file *file, char __user *user_buffer, size_t size, loff_t *loff);
ssize_t driver_write (struct file *file, const char __user *user_buffer, size_t size, loff_t *loff);

//---------------------------------------------defines-----------------------------------------------------------//
#define Name "iti_driver"
#define DRIVER_NAME "iti_driver"

//---------------------------------------------buffer&ID--------------------------------------------------------//
//   buffer[1024]----------> it is STORAGE DEVICE 1024 charcter                                                 //
//   ID -------------------> To save major (12 bits) and minor (20 bits)                                        //   
//--------------------------------------------------------------------------------------------------------------//

char buffer[1024];
dev_t ID;

//---------------------------------------------Structs----------------------------------------------------------//
//   class---------------------> it is to make struct called iti_class to pass it to class_creat                //   
//   module--------------------> this if the function class_create want owner as parameter                      //
//   file_operations-----------> it is to functions tht handeled the opreations to it                           //   
//   cdev----------------------> it is to make struct to call it when we want to handel file in dev             //   
//--------------------------------------------------------------------------------------------------------------//
struct module *root;
struct class *iti_class;
struct file_operations fops =
{
    .open= driver_open,
    .write= driver_write,
    .read= driver_read,
    .release= driver_close,
    .owner=THIS_MODULE
};
struct cdev cdev_object;


//---------------------------------------------Open_file--------------------------------------------------------//
//   inode---------------------> it is to give the inode of this file to check it's same file                   //   
//   file----------------------> this to compare the inode with the inode of file                               //
//   private_data--------------> it is used to point the inode number with the inode number of device           //   
//--------------------------------------------------------------------------------------------------------------//
int driver_open(struct inode *device_file,struct file *instacne)
{
    printk("Opend file\n");
    dev_t			i_rdev;
    instacne->private_data=&i_rdev;
    return 0;
}
//---------------------------------------------Close_file-------------------------------------------------------//
//   inode---------------------> it is to give the inode of this file to check it's same file                   //   
//   file----------------------> this to compare the inode with the inode of file                               //
//--------------------------------------------------------------------------------------------------------------//
int driver_close(struct inode *device_file,struct file *instacne)
{
    printk("closed file\n");
    return 0;
}
//---------------------------------------------Read_file--------------------------------------------------------//
//   file----------------------> Pointer to the file object                                                     //
//   user_buffer--------------> Buffer to copy data to, in user space                                           //  
//   size--------------> Size of the user buffer                                                                //   
//   loff--------------> Pointer to the offset within the file                                                  //   
//--------------------------------------------------------------------------------------------------------------//

//---------------------------------------------Descreption-------------------------------------------------------//
//  This function is called when the user attempts to read data from the device file.                            //
//  It should copy data from the device to the user buffer and update the file offset.                           //
//  Returns the number of bytes read on success, or a negative error code on failure.                            //
//---------------------------------------------------------------------------------------------------------------//
ssize_t driver_read (struct file *file, char __user *user_buffer, size_t size, loff_t *loff)
{
    printk("Read file\n");

    return 0;
}

//---------------------------------------------Write_file-------------------------------------------------------//
//   file----------------------> Pointer to the file object                                                     //
//   user_buffer--------------> Buffer to copy data to, in user space                                           //  
//   size--------------> Size of the user buffer                                                                //   
//   loff--------------> Pointer to the offset within the file                                                  //   
//--------------------------------------------------------------------------------------------------------------//


//---------------------------------------------Descreption-------------------------------------------------------//
//  This function is called when the user attempts to write data to the device file.                             //
//  It should copy data from the user buffer to the device and update the file offset.                           //
//  Returns the number of bytes written on success, or a negative error code on failure.                         //
//---------------------------------------------------------------------------------------------------------------//

ssize_t driver_write (struct file *file, const char __user *user_buffer, size_t size, loff_t *loff)
{
    printk("Write file\n");
    return 0;
}



//---------------------------------------------Init_Function-------------------------------------------------------//

static int __init  myinit (void)
{
//Number of devicese is 1 minor number start from 0 and ID is major number and it will be give random number not slected before
    if(alloc_chrdev_region(&ID, 0, 1 , Name) < 0)
    {
        printk("device can't allocated\n");
        return -1;
    }

    printk("Major is : %d  -  Mainor is : %d\n",MAJOR(ID),MINOR(ID));
//---------------------------------------------Here_To_Creat_Class-------------------------------------------------//
//  If gives you error here delete root and pass only the Name of class                                            //
//  you will find it in /sys/dev                                                                                   //
//-----------------------------------------------------------------------------------------------------------------//
    iti_class= class_create(root,"ITI_DEV_2");
    if(iti_class==NULL)
    {
        printk("Class can't allocated\n");
        return -1;
    }

    printk("Class allocated\n");
//---------------------------------------------Here_To_Creat_Device-------------------------------------------------//
// You will find it in the driver dirctory as Link from /dev                                                        //
//------------------------------------------------------------------------------------------------------------------//

    device_create(iti_class,NULL,ID,NULL,"ITI_DEV_SUB");

//---------------------------------------------Here_To_Handel_file--------------------------------------------------//
// you can check it by "cat /dev/name of device"                                                                    //
//------------------------------------------------------------------------------------------------------------------//
    if(cdev_add(&cdev_object,ID,1)==-1)
    {
        printk("cdev_add Failed");
    }

    cdev_init(&cdev_object,&fops);
    
    return 0;
}

//-----------------------------------------------------------------------------------------------------------------//


//---------------------------------------------Exit_Function-------------------------------------------------------//

static void __exit  myexit (void)
{
    device_destroy(iti_class,ID);
    class_destroy(iti_class);
    unregister_chrdev_region(ID,1);


    printk("Exit \n");
}



module_init(myinit);
module_exit(myexit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Aboalam");
MODULE_DESCRIPTION("Try driver for dev");