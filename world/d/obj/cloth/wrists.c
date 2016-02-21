// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <armor.h>

inherit WRISTS;

void create()
{
        set_name("护腕", ({ "wrists" }) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("material", "copper");
     set("value", 100);
                set("armor_prop/armor", 2);
        }
        setup();
}

