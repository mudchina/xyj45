// 
// 

#include <weapon.h>
inherit STAFF;
void create()
{
	set_name("古松琴", ({ "qin" }) );
	set_weight(40000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("value", 500);
		set("material", "wood");
		set("long", "一个古色古香的古松琴\n");
		set("weapon_prop/karma",3);
	}
	init_staff(5);
	setup();
}
void init()
{
add_action("do_play","play");
}
int do_play()
{
	object me;
	me = this_player();
message_vision("$N一划古松琴，弹出一首如流水般的曲子．\n",me);
me->set_temp("played_qin",1);
	return 1;
}
