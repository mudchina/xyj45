inherit ROOM;
#include <room.h>
void create()
{
        set("short", "镖局账房");
        set("long", @LONG
这里是金狮镖局出入镖银的账房，整间屋子是由坚硬的花岗石砌成的。连唯一的一
个小窗上都镶满拇指粗细的钢条。屋角有小床。这里由总镖头最亲信的人日夜把守。不
但如此，房中还有黄铜警铃，铃声一响，镖局伙计们就会蜂拥而至。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"ghall",
]));
        set("objects", ([
        __DIR__"npc/xiansheng" : 1,
                        ]) );
        set("item_desc", ([
                "bed": "这个小床似乎可以推开(push)。\n",
                "床": "这个小床似乎可以推开(push)。\n",
                "小床": "这个小床似乎可以推开(push)。\n",
                "bell" : "你可以试着摇摇(ring)。\n",
                "铃" : "你可以试着摇摇(ring)。\n",
                "警铃" : "你可以试着摇摇(ring)。\n",
		"黄铜警铃" : "你可以试着摇摇(ring)。\n",
        ]) );
        setup();
        create_door("south", "铁门", "north", DOOR_CLOSED);

}
void init()
{
	add_action("do_ring", "ring"); 
	add_action("do_push", "push");
}

int do_ring(string arg)
{
int i;
object ob;
if ( !arg && arg != "bell" && arg != "黄铜警铃" && arg != "警铃" && arg != "铃")
                return 0;
message_vision("$N试着摇了摇黄铜警铃．．．\n", this_player());
if( !(int) query("notyet"))
for(i;i<=random(3)+1;i++)
{
ob = new(__DIR__"npc/resting_biao");
if(ob) ob->move(this_object());
message_vision("$N冲了进来．．．\n", ob);
ob->kill_ob(this_player());
set("notyet",1);
}
return 1;
}

int do_push(string arg)
{
object ob;
object sect;
if ( !arg && arg != "bed" && arg != "小床" && arg != "床")
                return 0;
	if( ob = present("xiansheng", this_object()))
	{
	message_vision("$N用很一种奇怪的眼神瞄$n\n", ob, this_player());
	return 1;
	}
        if( !query("exits/down") ) {
        message_vision("$N把小床推开发现了一条密道．\n", this_player());	
        set("exits/down", __DIR__"secret_room");
	sect = find_object(__DIR__"secret_room");
	if( !sect)
	sect = load_object(__DIR__"secret_room");
	sect->set("exits/up", __FILE__);
	}
	else
	{
        message_vision("$N把小床推过来掩盖住密道．\n", this_player());
	delete("exits/down");
        sect = find_object(__DIR__"secret_room");
        if( !sect)
	sect = load_object(__DIR__"secret_room");
	sect->delete("exits/up");
	}
	return 1;
}
