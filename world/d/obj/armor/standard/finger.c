// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// shoupi.c

#include <armor.h>

inherit FINGER;

void create()
{
        set_name("指套", ({"finger"}));
   set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "iron");
                set("unit", "套");
     set("armor_prop/armor", 1);
        }
        setup();
}

