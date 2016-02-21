// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// shoupi.c

#include <armor.h>

inherit SHIELD;

void create()
{
        set_name("盾牌", ({"shield"}));
   set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "wood");
                set("unit", "面");
     set("armor_prop/armor", 5);
        }
        setup();
}

