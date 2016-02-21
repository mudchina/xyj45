#include <weapon.h>
inherit STAFF;
void create()
{
        set_name("金刚杵", ({ "staff","金刚杵" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("value", 3000);
                set("material", "gold");
        }
        init_staff(10);

        set("wield_msg", "$N把$n紧紧地握在手中。\n");
        set("unwield_msg", "$N松开了手中的$n。\n");
        setup();
}
