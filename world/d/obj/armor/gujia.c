// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// lightarmor.c
#include <armor.h>

inherit ARMOR;

void create()
{
        set_name("兽骨甲", ({"shougu jia","shougujia","jia","armor"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
       set("long", "一件兽骨甲。\n");
                set("value", 2500);
                set("material", "bone");
                set("armor_prop/armor", 35);
             }
         setup();
}
