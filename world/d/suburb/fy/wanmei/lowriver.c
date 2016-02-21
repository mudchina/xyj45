// 
// 

inherit ROOM;
void create()
{
        set("short", "小河流下游");
        set("long", @LONG
这里的河床极窄，水流湍急。无风但河浪汹涌，走在河边，稍有不慎就会
被河浪卷走。只有武功极高之人才敢涉足。
......水流越来越急，几乎已经立不住足了......
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"playground",
]));
	set("outdoors","wanmei");
        set("objects", ([
                __DIR__"npc/cor" :2,
                        ]) );
        setup();
}
void init()
{
	if(interactive(this_player()))
	call_out("do_flush",10,this_player());
}

void do_flush(object me)
{
        object room;
	if(!me || environment(me) != this_object())
		return;
	tell_object(me,"一阵暗流涌来，你被冲往河下游．．\n");
	room= load_object("/d/suburb/fy/qianjin/hehuadang");
	me->move(room);
}	
