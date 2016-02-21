// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// tiejia.c
#include <armor.h>

inherit ARMOR;

void create()
{
        set_name("铁甲", ({"tie jia","tiejia","jia","armor","body",}));
        set_weight(40000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
       set("long", "一件沉甸甸的铁甲。\n");
                set("value", 5000);
                set("material", "steel");
                set("armor_prop/armor", 40);
     set("armor_prop/dodge", -10);
             }
         setup();
}
