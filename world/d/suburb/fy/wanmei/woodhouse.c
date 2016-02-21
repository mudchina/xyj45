inherit ROOM;
// 
// 


void create()
{
        set("short", "小木屋");
        set("long", @LONG
木屋只有半边顶，一棵老梅树盖住了那半边。墙上挂着几条浴巾，
阳光透过树枝照在浴巾上。一条竹管从房顶垂下，竹管的尽头塞着一个
木塞子，偶尔还有水珠滴下。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"frontyard",
]));
        set("objects", ([
        __DIR__"obj/towel": 1,
                        ]) );
        set("item_desc", ([
                "木塞子": "
                        你似乎可以把它拔（ｐｕｌｌ）下来！\n",

        ]) );
        setup();
}
void init()
{
        add_action("do_fillwater", "fillwater");
	add_action("do_pull","pull");
	add_action("do_climb","climb");
}
int do_pull()
{
	object me;
	if(query("resource/water"))
		return notify_fail("木塞子已经被拔下来了。\n");
	me = this_player();
	message_vision("$N＂噗＂的一声将木塞子拔了下来，冒着热气的水马上流了下来。\n",me);
	set("resource/water",1);
	set("liquid/name","热水");
	call_out("remove_water",50);
	return 1;
}

int remove_water()
{
	tell_object(this_object(),"热水滴了几滴，就流光了。\n");
	delete("resource/water");
        delete("liquid/name");
	return 1;
}
int do_fillwater(string arg)
{
        object *list, ob;
        int i, can_fillwater;
        string dir;
	if(!query("resource/water")) return 0;
        if( !arg || arg=="" ) return 0;

        if( arg=="skin" || arg=="wineskin" ) {
                list = all_inventory(this_player());
                i = sizeof(list);
                can_fillwater = 0;
                while (i--) {
                  if (((string)list[i]->query("liquid/type") == "alcohol")
 || ((string)list[i]->query("liquid/type") == "water")         ) {
                        ob = list[i];
                        can_fillwater = 1;
                        ob->set("liquid", ([
                                "type": "water",
                                "name": "热水",
                                "remaining": 15,
                                "drunk_apply": 0,
                        ]) );
                        write("你从竹管里接满了热水! \n");
                        return 1;
                   }
                }
                if (can_fillwater ==0) {
                        write("你没有装水的东西啊....\n");
                        return 1;
                }
        }
        else {
                write("你要往什么东西里灌热水？");
        }
        return 1;
}
int do_climb()
{
	object me,room;
	me = this_player();
	message_vision("$N＂嗖＂的一声，顺着老梅树窜上屋顶。\n",me);
	room = load_object(__DIR__"roof");
	me->move(room);
	return 1;	

}
