/*  
 *  simple-kmod.c - The simplest kernel module.
 */
#include <linux/module.h>   /* Needed by all modules */
#include <linux/kernel.h>   /* Needed for KERN_INFO */

MODULE_LICENSE("MIT");
MODULE_VERSION(KMODVER);

static char *mystring = "Version 1";

module_param(mystring, charp, 0000);
MODULE_PARM_DESC(mystring, "A character string");


int init_module(void)
{
    printk(KERN_INFO "Hello world from simple_kmod.\n");
    printk(KERN_INFO "mystring is a string: %s\n", mystring);

    /* 
     * A non 0 return means init_module failed; module can't be loaded. 
     */
    return 0;
}

void cleanup_module(void)
{
    printk(KERN_INFO "Goodbye world from simple_kmod.\n");
    printk(KERN_INFO "mystring is a string: %s\n", mystring);
}
