
inherit ROOM;
void close_path();
void create()
{
        set("short", "风云雅阁");
        set("long", @LONG
这里专门招待江湖上万儿极响亮的人物。能有幸坐在这儿的，不是一掷千金的豪客，
就是跺跺脚江湖四颤的一方霸主。整间房子的中央只有一张上等翠玉打磨成的八仙桌，
桌上放着四只御赐金杯。三面的墙上挂满了字画，剩下的一面是一道一垂及地的红布
挂帘。
LONG
        );
        set("exits", ([
                "down" : __DIR__"fyge",
		"east" : __DIR__"fysf",
        ]));
        set("objects", ([
                __DIR__"npc/servent": 1,
		"/obj/npc/champion":1,
        ]) );
        set("item_desc", ([
                "curtain": "这个红布挂帘似乎可以掀开(open)。\n",
		"挂帘" : "这个红布挂帘似乎可以掀开(open)。\n",
		"红布挂帘" : "这个红布挂帘似乎可以掀开(open)。\n"
        ]) );

        setup();
}

void init()
{
        add_action("do_open", "open");
}
void close_path()
{
        if( !query("exits/north") ) return;
        message("vision",
"红布挂帘又落了下来，盖住了暗门。\n",
                this_object() );
                delete("exits/north");
}


int do_open(string arg)
{
	object me;
	me = this_player();
        if( !arg || arg=="" ) return 0;

        if( arg=="curtain" || arg =="红布挂帘" || arg=="挂帘") {
                write("你掀开红布挂帘，");
	if( (int) me->query("force_factor") >= 100 )
		{
		write("推开了后面向北的一扇暗门。\n");
	        if( !query("exits/west") ) {
     		set("exits/north", __DIR__"fysecret");
        	call_out("close_path", 5);
						}
		return 1;	
		}
		else
		write("试着推了推后面的暗门，但没有推开。\n");
		return 1;
	}
		write("你要掀开什么？\n");
}

int valid_leave(object me, string dir)
{
        object ob;
        int i;
        if( dir == "north" && ob=present("royal servant", this_object()))
	{
	message_vision("$N对$n喝道：想进去？宰了我再说！！\n", ob,me);
	ob->kill_ob(me);
	return notify_fail("快逃！\n");
	}
	else
		return 1;
}
