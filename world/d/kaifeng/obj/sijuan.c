// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <armor.h>

inherit WRISTS;

void create()
{
        set_name("透明丝绢", ({ "si juan", "si", "juan" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("material", "silk");
     set("value", 1000);
                set("armor_prop/dodge", 1);
        }
        setup();
}

