
#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("一环禅杖" , ({ "one-ring staff", "staff" }) );
	set_weight(80000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", "一条又粗又长的精铁禅杖，上面镶著一个铜环。\n");
		set("value", 620);
		set("rigidity", 50);
		set("material", "iron");
		set("wield_msg", "$N拿出一根乌黑的$n握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}

	init_staff(33);
	setup();
}
