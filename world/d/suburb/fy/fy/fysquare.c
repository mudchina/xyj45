inherit ROOM;
void create()
{
        set("short", "风云广场");
        set("long", @LONG
风云城的风街和云路在这里呈十字交叉，宽阔的街道在这里形成一个巨大的广场。
广场的中央是方园约十丈的水池，池中有尾尾金鱼在悠闲的漫游。金色的鱼鳞与碧绿的
浮萍相互辉映，赏心悦目。池水的中央是一条石柱，石柱上刻着一条九头龙。龙首向四
面伸展，宏伟壮观。每当雨天，潺潺雨珠涓涓涌出龙首，如情人之泪，落断情肠。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"nwind1",
  "south" : __DIR__"swind1",
  "east" : __DIR__"ecloud1",
  "west" : __DIR__"wcloud1",
]));
	set("NONPC",1);
		set("no_fight",1);
			set("no_magic",1);
        set("outdoors", "fengyun");
        set("resource/water",1);
	set("liquid/name","碧绿的水");
	set("liquid/type", "alcohol");
	set("liquid/drunk_apply",3);
        set("objects", ([
                __DIR__"npc/half_god" : 1,
//		"/obj/example/turkey" : 10,
       ]) );

        setup();
        // To "load" the board, don't ever "clone" a bulletin board.
        call_other( "/obj/board/fysquare_b", "???" );

}

void init()
{
        add_action("do_fillwater", "fillwater");
	add_action("do_drink", "drink");
	add_action("do_study", "study");
}
int do_drink()
{
	write("这不可喝东西！\n");
	return 1;
}
int do_study()
{
        write("这不可学东西！\n");
        return 1;
}

	
int do_fillwater(string arg)
{
        object *list, ob;
        int i, can_fillwater;
        string dir;

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
                                "name": "清水",
                                "remaining": 15,
                                "drunk_apply": 6,
                        ]) );
                        write("你从水池里装满了清水！ \n");
                        return 1;
                   }
                }
                if (can_fillwater ==0) {
                        write("你没有装水的东西啊....\n");
                        return 1;
                }
        }
        else {
                write("你要往什么东西里灌水？\n");
        }
        return 1;
}

