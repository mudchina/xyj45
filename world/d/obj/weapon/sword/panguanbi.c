// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// blade.c

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("判官笔", ({"panguanbi", "sword"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
                set("value", 300);
        }
        init_sword(20);
        setup();
}
