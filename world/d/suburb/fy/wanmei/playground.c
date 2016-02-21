// 
// 

inherit ROOM;
void create()
{
        set("short", "后山坡");
        set("long", @LONG
这里是万梅山庄的后山坡。除了漫山遍野的梅树之外就是一望无垠的
绿草坪，被各色各样的野花儿点缀着，充满无限生机。一条小河横穿而过，
河里的小鱼不时欢快地跃出水面。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"backyard",
]));
	set("outdoors","wanmei");
        set("objects", ([
                __DIR__"npc/child" :1,
		__DIR__"obj/river" : 1,
                        ]) );
        setup();
}
void init()
{		
	add_action("do_swim","swim");
	remove_call_out("do_check");
	call_out("do_check",10);
}
int do_check()
{
	object *inv;
	int i;
	object river;
	river = present("river",this_object());
	if(river)
	inv = all_inventory(river);
	for(i=0;i<sizeof(inv);i++)
	{
	if(inv[i]->query("floating"))
		{
			tell_object(this_object(),"小船漂了过来．．．\n");
			set("exits/north", __DIR__"upriver");
			call_out("close_path",10);
			break;
		}	
	destruct(inv[i]);
	}
}
void close_path()
{
        if( !query("exits/north") ) return;
        message("vision",
"小船漂走了．．．\n",
                this_object() );
                delete("exits/north");
}
int do_swim()
{
	object me;
	object room;
	me = this_player();
	message_vision("$N一个猛子扎入河中．．．\n",me);
	room = load_object(__DIR__"river");
	me->move(room);
	return 1;	
}
