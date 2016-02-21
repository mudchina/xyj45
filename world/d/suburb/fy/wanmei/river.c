// 
// 

inherit ROOM;
void create()
{
        set("short", "小河流");
        set("long", @LONG
这里是小河流的中央，河流虽浅但水流湍急。水面波涛起伏与日光辉映，
发出鱼鳞般的光芒。几条小鱼偶尔跃出又复落水中，圈圈水波打破了宁静和
谐的溪面。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"playground",
]));
	set("outdoors","wanmei");
        set("objects", ([
                __DIR__"npc/snake" :3,
                        ]) );
        setup();
}
void init()
{
	if(interactive(this_player()))
	call_out("do_flush",5,this_player());
	
}

void do_flush(object me)
{
	object room;

        if(!me || environment(me) != this_object())
                return;
	tell_object(me,"一阵暗流涌来，你被冲往河下游．．\n");
	room= load_object(__DIR__"lowriver");
	me->move(room);
}	
