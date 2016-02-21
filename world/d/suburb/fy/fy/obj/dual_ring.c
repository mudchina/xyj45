// hammer.c

#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("子母双环", ({ "dual_ring" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "这是一套沈重的子母双环，打造的相当坚实。\n");
                set("value", 300);
                set("material", "iron");
                set("wield_msg", "$N拿出一双$n，试了试重量，然後握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_hammer(25);
        setup();
}
