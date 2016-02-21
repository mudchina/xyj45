// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// shoupi.c

#include <armor.h>

inherit ARMOR;

void create()
{
        set_name("铠甲", ({"armor"}));
   set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "iron");
                set("unit", "副");
     set("armor_prop/armor", 5);
        }
        setup();
}
