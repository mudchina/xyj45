// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <armor.h>

inherit BOOTS;

void create()
{
        set_name( "僧鞋", ({ "seng xie", "xie" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
                set("long", "一双圆口青布僧鞋。");
                set("value", 100);
                set("material", "boots");
                set("armor_prop/dodge", 3);
        }
        setup();
}

