#include <weapon.h>
inherit STAFF;
void create()
{
	set_name("订作的" , ({ "order" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", "一条又粗又长的精铁禅杖，上面镶著一个环。\n");
                set("no_drop",1);
                set("no_get",1);
                set("owner","fengyun");
                set("rigidity",300);
		set("material", "iron");
		set("wield_msg", "$N拿出一根乌黑的$n握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}
	init_staff(30);
	setup();
}
