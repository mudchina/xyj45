// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <weapon.h>

inherit THROWING;

void create()
{
        set_name("珍珠", ({"pearl"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",    "一颗浑圆的珍珠。\n");
                set("unit", "颗");
                set("base_unit", "颗");
                set("base_weight", 1);
                set("value", 1000);
     set("weapon_prop/personality",1);
     set("wield_msg","$N轻轻将珍珠捏在指缝中。\n");
        }
        set_amount(1);
        init_throwing(20);
        setup();
}

