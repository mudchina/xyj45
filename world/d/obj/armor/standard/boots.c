// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// shoupi.c

#include <armor.h>

inherit BOOTS;

void create()
{
        set_name("靴子", ({"boots"}));
   set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "leather");
                set("unit", "双");
     set("armor_prop/armor", 1);
        }
        setup();
}

