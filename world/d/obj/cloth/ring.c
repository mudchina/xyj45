// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <armor.h>

inherit FINGER;

void create()
{
        set_name("戒指", ({ "ring" }) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("material", "gold");
     set("value", 100);
                set("armor_prop/armor", 2);
        }
        setup();
}

