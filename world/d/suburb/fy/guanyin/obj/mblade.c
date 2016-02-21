
#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("天缺古月寒 ", ({ "destblade" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把刃上有一个缺口的利器！");
                set("value", 500000);
		set("rigidity", 2000);
                set("material", "steel");
        }
        init_blade(30);
        setup();
}

