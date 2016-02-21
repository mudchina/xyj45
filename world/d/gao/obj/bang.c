// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// bang.c
#include <weapon.h>

inherit STICK;

void create()
{
        set_name("木棒", ({"mu bang"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
     set("value", 100);
     set("material", "wood");
        }
   init_stick(15);
   setup();
}
