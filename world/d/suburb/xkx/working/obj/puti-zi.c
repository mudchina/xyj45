// puti-zi.c 菩提子

#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("菩提子", ({"puti zi", "zi"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗晶莹如玉的菩提子，采自灵山佛祖座前，珍稀无比，
乃万年菩提树之实，功能化百劫，渡千灾，与天地同寿。\n");
		set("value", 1000000);
	}
	setup();
}

int do_eat(string arg)
{
	int force_limit, neili_limit, force_skill, add_skill, improve;

	force_limit = (int)this_player()->query_skill("force")*10;
	neili_limit = (int)this_player()->query("max_force");
	force_skill = (int)this_player()->query_skill("force", 1);
	
	if (!id(arg))
	return notify_fail("你要吃什么？\n");
//39
	if ( neili_limit <= force_limit  )
	{
		improve = force_limit - neili_limit;

		if ( improve < 100 )
		{ 
			add_skill = force_skill + (100 - improve)/5 + 1;
			this_player()->set_skill("force", add_skill );
		}
	}
	
	this_player()->add("max_force", 100);
	this_player()->add("force", 100);

	message_vision(HIY "$N吃下一颗菩提子，顿然间只觉一股浩荡无比的真气直冲顶门...\n" NOR, this_player());
	this_player()->unconcious();
	destruct(this_object());
	return 1;
}

