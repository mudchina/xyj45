// Room: /d/wiz/entrance.c

inherit ROOM;
#include <room.h>
#include <ansi.h>
void create()
{
	set("short", "巫师会客室");
	set("long", @LONG
这里是巫师和玩家聊天的地方，如果你有什麽意见要让巫师们知道，在这里
留言是最快的途径，不过如果是对於游戏中的问题，请您先确定我们提供的说明
文件里没有说明，再提出疑问，巫师的主要职责并不是教玩家如何玩。
    
为了杜绝机器人，您可以在这里检举(accuse)某个玩家，该名玩家会被抓去
做一些小小的测验，目前这项功能尚未做任何限制，请勿利用来骚扰别人。
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "southeast" : (: look_door,     "southeast" :),
]));
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : "/d/suburb/fy/snow/inn",
//  "north" : "/d/suburb/fy/wizard/bigroom.c",
  "west" : __DIR__"hall1",
]));
	set("no_fight", 1);
	set("no_clean_up", 0);
	set("NONPC",1);
	set("no_magic", 1);
//	create_door("southeast", "木门", "northwest", DOOR_CLOSED);
	setup();
}

void init()
{
	add_action("do_accuse", "accuse");
}

int do_accuse(string arg)
{
	object me, room;
	if( !arg ) return notify_fail("检举谁？\n");
	me = find_player(arg);
	if( !me) return notify_fail("检举谁？\n");
	tell_object(me,HIR"你被"+this_player()->name()+"检举为机器人．\n"NOR);
	tell_object(this_player(), "你检举"+me->name()+"为机器人．\n");
	message_vision(HIY"忽然一阵闪光罩住了$N。\n"NOR,me);
        me->set_temp("last_location", base_name(environment(me)));
	room = load_object("/d/suburb/fy/wiz/courthouse");
	me->move(room);
	return 1;
}	
