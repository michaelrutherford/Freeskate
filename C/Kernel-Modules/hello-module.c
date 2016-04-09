#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Michael Rutherford");
MODULE_DESCRIPTION("A simple kernel module");

static char* hello_message = "Hello, Kernel";

module_param(hello_message, charp, 0000);
MODULE_PARM_DESC(hello_message, "The string that holds the message.");

static int __init hello_init(void)
{
	printk(KERN_INFO "%s\n", hello_message);
	return 0;
}

static void __exit hello_exit(void)
{
	printk(KERN_INFO "Goodbye, Kernel!\n");
}

module_init(hello_init);
module_exit(hello_exit);
