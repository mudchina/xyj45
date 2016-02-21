// hammer.c

#include <weapon.h>

inherit DAGGER;

void create()
{
        set_name("红绸舞器", ({ "wuqi" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把红绸舞器\n");
                set("value", 3);
                set("material", "stone");
                set("wield_msg", "$N拿出一把$n，握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_dagger(5);
        setup();
}
