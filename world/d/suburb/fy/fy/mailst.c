
inherit ROOM;

void create()
{
	set("short", "风云绎站");
	set("long", @LONG
每天快马三匹，早午晚各传递书信三次。风云城的官府衙役和普通百姓都可以在
这儿免费和外地书信来往。不管你的书信要寄到那里，只要放到这里，三天之内绝
对可以送到。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"wcloud2",
	]));
	set("objects", ([
		__DIR__"npc/officer": 1
	]) );

	setup();
}

int valid_leave(object me, string dir)
{
	object mbox;

	if( mbox = me->query_temp("mbox_ob") ) {
		tell_object(me, "你将信箱交回驿站。\n");
		destruct(mbox);
	}
	return 1;
}
