// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <armor.h>

inherit ARMOR;

void create()
{
        set_name("彩贝甲", ({"color shell","jia","armor","shell"}));
        set_weight(8000);
   set_max_encumbrance(3);
        if( clonep() ) {
     object a;
     seteuid(getuid());
     if(a=new("/d/sea/obj/pearl"))
        a->move(this_object());
                set_default_object(__FILE__);
       } else {
                set("unit", "件");
            set("long", "一件七彩贝甲。\n");
                set("value", 0);
     set("no_sell",1);
                set("material", "wood");
                set("armor_prop/armor", 25);
     set("armor_prop/dodge",10);
             }
       setup();
}

