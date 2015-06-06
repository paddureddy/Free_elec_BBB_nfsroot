#include <linux/init.h>
#include <linux/module.h>
#include <linux/i2c.h>



/* l3g4200d gyroscope registers */
#define WHO_AM_I    0x0F

#define CTRL_REG1       0x20    /* power control reg */
#define CTRL_REG2       0x21    /* power control reg */
#define CTRL_REG3       0x22    /* power control reg */
#define CTRL_REG4       0x23    /* interrupt control reg */
#define CTRL_REG5       0x24    /* interrupt control reg */
#define AXISDATA_REG    0x28




static u8 l3g4200d_read_reg(struct i2c_client *client, u8 addr){
          s32 err = i2c_smbus_write_byte(client,addr);
          s32 val = i2c_smbus_read_byte(client);
     
          return (u8) val;

}
static int l3g4200d_remove(struct i2c_client *client){
 
           return 0;
}



static int l3g4200d_probe(struct i2c_client *client, const struct i2c_device_id *id){

           printk(KERN_INFO "Probing for L3G4200D Gyroscope\n");
           u8 whoami = l3g4200d_read_reg(client, WHO_AM_I);
           printk(KERN_INFO "WHO_AM_I:%0x",whoami);
           return 0;


}


static const struct i2c_device_id l3g4200d_id[] = {

                   {"l3g4200d", 0},
                   {}
};


static struct i2c_driver l3g4200d_driver ={

        .driver = {
              .name = "l3g4200d",

         },
       
        .id_table = l3g4200d_id,
        .probe    = l3g4200d_probe,
        .remove   = l3g4200d_remove,

};


static int __init l3g4200d_init(void){

         pr_info("l3g4200d Gyroscope Driver init\n");
         return i2c_add_driver(&l3g4200d_driver);
}

static void __exit l3g4200d_exit(void){

         pr_info("l3g4200d Gyroscope Driver exit\n");
         return i2c_del_driver(&l3g4200d_driver);
}


module_init(l3g4200d_init);
module_exit(l3g4200d_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("PADMKAAR REDDY THATIKONDA");
MODULE_VERSION("1.0");


