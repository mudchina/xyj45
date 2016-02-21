// hammer.c

#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("翠玉琵琶", ({ "pipa" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一个翠玉所制的琵琶\n");
                set("value", 3);
                set("material", "stone");
                set("wield_msg", "$N拿出一把$n，握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_hammer(15);
        setup();
}
