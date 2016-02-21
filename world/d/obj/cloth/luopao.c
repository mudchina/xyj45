// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// pao.c
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("皂罗袍", ({"purple cloth", "cloth"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("value", 4000);
                set("material", "cloth");
                set("armor_prop/armor", 15);
                set("armor_prop/dodge", 5);
                set("armor_prop/spells", 10);
             }
   setup();
}

