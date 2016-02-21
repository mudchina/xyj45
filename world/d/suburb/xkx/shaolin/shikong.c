// Room: /d/shaolin/shikong.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "时空");
	set("long", @LONG
时空梦境。
LONG
	);

	set("exits", ([
		"east" : __DIR__"shulin1",
	]));

	set("outdoors", "shaolin");
	set("objects",([
		CLASS_D("shaolin") + "/shikong" : 1,
	]));
	setup();
}


void init()
{
	add_action("do_pick", "pick");
	add_action("do_dream", "dream");
}

int do_pick(string arg)
{
	object me;

	me = this_player();
	if ( !arg || ( arg != "flower" ) ) return notify_fail("你要摘什麽？\n");

	else if ( random((int)me->query("kar")) < 7 )
		message_vision("$N将花摘了下来，但一不小心被刺了一下。\n", me);

	else
		message_vision("$N摘下一朵美丽的血红色鲜花。\n", me);

	return 1;
}

int do_dream(string arg)
{
	object me;

	if ( !arg )
	{
		return notify_fail("你做了一个美梦，觉得有点飘飘然了。\n");
	}

	me = this_player();
	if ( arg == "exp" )
	{
		mapping mine;
		
		mine = me->query_entire_dbase();
		write("你在梦中和时空大战三百回合，领悟不少。\n");
		mine["combat_exp"] += 100;

		return 1;
	}

	if (
		arg == "literate" ||
		arg == "force" ||
		arg == "unarmed" ||
		arg == "dodge" ||
		arg == "parry" ||
		arg == "stealing" ||
		arg == "shaolin-banruo" ||
		arg == "shaolin-cibei" ||
		arg == "shaolin-damo" ||
		arg == "shaolin-fengyun" ||
		arg == "shaolin-fumo" ||
		arg == "shaolin-jingang" ||
		arg == "shaolin-longzhua" ||
		arg == "shaolin-luohan" ||
		arg == "shaolin-nianhua" ||
		arg == "shaolin-pudu" ||
		arg == "shaolin-qianye" ||
		arg == "shaolin-qigong" ||
		arg == "shaolin-sanhua" ||
		arg == "shaolin-shenfa" ||
		arg == "shaolin-weituo" ||
		arg == "shaolin-wuchang" ||
		arg == "shaolin-xiuluo" ||
		arg == "shaolin-yingzhua" ||
		arg == "shaolin-yizhi" ||
		arg == "shaolin-zuigun" ||
		arg == "sword"
		)
	{
		write("你梦见时空给你讲解" + to_chinese(arg) + "的诀窍，获益非浅。\n");
		me->improve_skill(arg, random(10*me->query("int")));

		return 1;
	}
	
	return notify_fail("你做了一个美梦，梦中见到了" + arg + "。\n");
}

