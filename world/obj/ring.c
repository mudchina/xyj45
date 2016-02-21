// ring.c 订婚戒指

#include <armor.h>
#include <ansi.h>

inherit FINGER;

void create()
{
	set_name(HIC "订婚戒指" NOR, ({ "diamand ring", "diamand", "ring" }));
       	set("long", "这是风儿送给凌儿的订婚戒指，衬着她纤纤柔荑，益发光彩照人。\n");
	set("weight", 200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "枚");
		set("value", 100000);
		set("material", "钻石");
		set("armor_prop/armor", 2);
		set("armor_prop/personality", 3);
		set("female_only", 1);
	}
	setup();
}	
