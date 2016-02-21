// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// shoe.c
#include <armor.h>
inherit BOOTS;

void create()
{
        set_name("踏云靴", ({ "cloudy shoes", "shoes" }) );
        set_weight(1700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
                set("value", 10000);
                set("material", "cloth");
                set("armor_prop/armor", 2);
                set("armor_prop/dodge", 8);
        }
        setup();
}

