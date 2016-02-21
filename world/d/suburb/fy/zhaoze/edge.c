// 
// 


inherit ROOM;
void create()
{
        set("short", "沼泽边缘");
        set("long", @LONG
这里乌云密布，天色极暗。再往前走就是武林中有名的死域
－－火沼泽。那里不但荆棘密布，猛兽出没，还有能至人于死地
在一瞬间随时喷射的毒火泉。
LONG
        );
        set("exits", ([ 
  "north" : "/d/suburb/fy/manglin/edge4",
 
]));

        set("item_desc", ([
                "bush": "这里荆棘(bush)密布，但你似乎可以砍开(chop)它们。\n",
                "荆棘": "这里荆棘(bush)密布，但你似乎可以砍开(chop)它们。\n"

        ]) );

        set("outdoors", "zhaoze");
        setup();
}
void init()
{
        add_action("do_cut", "chop");
	load_object(__DIR__"center");
}
int do_cut(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("你要砍开什么？\n");
                return 1;
        }
        if( arg == "bush" || arg == "荆棘" )
	{
	me = this_player();
	obj = me->query_temp("weapon");
	if( !obj ) 
	{
	write("你空着手，怎么砍？\n");
	return 1;
	}
	if( obj->query("jungle"))
	{
	if( !query("exits/south") ) {
        set("exits/south", __DIR__"zhaoze1");
	message_vision(sprintf("$N用手中的%s砍出一条向南的路．\n",obj->name()),
		me);
	}
	else
	message_vision(sprintf("$N用手中的%s砍向路边的荆棘．\n",obj->name()),
                me);
	}
	else
 	message_vision(sprintf("$N用手中的%s向丛生的荆棘一顿乱砍．\n",obj->name()),
		me);
	}
	else
	 write("你要砍开什么？\n");
                return 1;
}

void reset()
{
	::reset();
	delete("exits/south");
}
