// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <weapon.h>

inherit MACE;

void create()
{
        set_name("竹节鞭", ({"bamboo mace", "mace"}));
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 500);
                set("material", "wood");
        }

        init_mace(15);
        setup();
}

