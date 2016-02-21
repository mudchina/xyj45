// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// shoupi.c

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("狼皮裙", ({"wolf skirt", "skirt"}));
   set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "件");
                set("value", 100);
     set("armor_prop/armor", 5);

        }
        setup();
}

