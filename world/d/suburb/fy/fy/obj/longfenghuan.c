// hammer.c

#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("龙凤双环", ({ "longfeng" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "这是一套龙凤双环，上官的成名兵器\n");
                set("value", 30000);
                set("material", "iron");
                set("wield_msg", "$N双手一分，拿出一双$n握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_hammer(125);
        setup();
}
