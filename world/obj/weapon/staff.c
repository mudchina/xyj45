// staff.c : Gun zi

#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("木棍", ({ "staff" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是一把看起相当普通的木棍");
                set("value", 300);
                set("material", "wood");
        }
        init_staff(10);

// These properties are optional, if you don't set them, it will use the
// default values.

        set("wield_msg", "$N把$n紧紧地握在手中。\n");
        set("unwield_msg", "$N松开了手中的$n。\n");

// The setup() is required.

        setup();
}
