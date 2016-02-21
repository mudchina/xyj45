// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// gangcha.c

#include <weapon.h>

inherit FORK;

void create()
{
        set_name("木叉", ({ "fork", "cha"}) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 100);
                set("material", "iron");
        }
        init_fork(5);
        setup();
}

