
#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
	set_name( HIR "红缨" NOR + "长枪" NOR, ({ "changqiang" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把看起相当普通的长枪，份量大约有十来斤左右。\n");
		set("value", 4000);
		set("material", "steel");
		set("wield_msg", "$N「唰」地一声把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入地下。\n");
	}
	init_dagger(25);
	setup();
}
