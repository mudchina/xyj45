// 
// 

inherit ROOM;
void create()
{
        set("short", "右偏院");
        set("long", @LONG
这是一个可爱的小草坪，草坪上有一圆石桌，桌边有石凳。桌面是精致
大理石，石上刻着一个棋盘。盘上还放着一局未完的残棋。桌上还有两杯残
酒，尚有余温。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"yard",
]));
        set("outdoors", "wanmei");
        set("objects", ([
		__DIR__"obj/book1" : 1,
                        ]) );

        setup();
}
void init()
{
	add_action("do_look","look");
	add_action("do_study","study");
}

int do_look(string arg)
{
	if(!arg || (arg != "残棋" && arg != "canqi"))
	return 0;
	this_player()->add_temp("looked_canqi",1);
	if((int) this_player()->query_temp("looked_canqi") <= 15)
	{
	write("一局未完的残棋，棋势奥妙无穷．．．\n");
	return 1;
	}
	else
	{
	write("你似乎看出了一些奥妙．．学习一下吧．．\n");
	return 1;
	}
}
 
int do_study(string arg)
{
	if(!arg || (arg != "残棋" && arg != "canqi"))
	return 0;
	if(this_player()->query_temp("looked_canqi") <= 15)
	{
	write("一局未完的残棋，棋势奥妙无穷．．．\n");
	return 1;
	}
	else
	return 0;
	
}
