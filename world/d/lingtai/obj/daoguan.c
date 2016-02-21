// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <armor.h>

inherit HEAD;

void create()
{
        set_name("红木道冠", ({ "bonnet", "hat" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "顶");
     set("long", "一顶硬红木的道冠。\n");
                set("material", "steel");
                set("value", 100);
                set("armor_prop/armor", 1);
     set("armor_prop/intelligence", 1);
     set("armor_prop/personality", 1);
        }
        setup();
}

