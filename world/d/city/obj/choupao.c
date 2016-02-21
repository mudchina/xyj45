// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// linen.c

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("绸袍", ({"choupao"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "件");
                set("value", 1000);
                set("armor_prop/armor", 5);
        }
        setup();
}

