#include <weapon.h>
inherit WHIP;
void create()
{
        set_name( "订作的", ({ "order" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("no_drop",1);
                set("no_get",1);
                set("owner","fengyun");
                set("rigidity",300);
                set("material", "skin");
	        set("wield_msg", "$N从腰间摸出一条$n握在手中。\n");
        	set("unwield_msg", "$N将手中的$n束在腰间。\n");
        }
        init_whip(30);
        setup();
}
