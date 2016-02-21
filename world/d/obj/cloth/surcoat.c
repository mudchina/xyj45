// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <armor.h>

inherit SURCOAT;

void create()
{
        set_name("披风", ({ "surcoat" }) );
        set_weight(1600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
     set("value", 100);
                set("armor_prop/armor", 2);
        }
        setup();
}

