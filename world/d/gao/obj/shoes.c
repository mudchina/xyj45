// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <armor.h>

inherit BOOTS;

void create()
{
        set_name("圆口布鞋", ({"shoes"}));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
     set("value", 100);
                set("material", "cloth");
                set("armor_prop/armor", 3);
        }
        setup();
}

