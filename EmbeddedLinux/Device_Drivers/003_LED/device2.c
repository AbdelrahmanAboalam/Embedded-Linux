#include <linux/module.h>
#include <linux/init.h>
#include <linux/platform_device.h>

static struct platform_device platDevice2 = {

    .name = "LED2",
    .id = 1, // minor number

};

static int __init device2_init(void)
{
    

    // Register the platform device
    
    if (platform_device_register(&platDevice2))
    {
        printk(KERN_ERR "Failed to register platform device LED2\n");
        return -1;
    }

    printk(KERN_INFO "LED2 device has been inserted\n");
    return 0;
}

static void __exit device2_exit(void)
{
    // Unregister the platform device
    platform_device_unregister(&platDevice2);
    printk(KERN_INFO "LED2 device has been removed\n");
}

module_init(device2_init);
module_exit(device2_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Qemu");
MODULE_DESCRIPTION("Hello from iti");