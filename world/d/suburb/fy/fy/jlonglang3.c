
inherit ROOM;
#include <room.h>
void create()
{
        set("short", "走廊");
        set("long", @LONG
一人多高，只容两人并行的檀香木走廊，廊中的两侧陈列着一些奇花异草。滚滚
热气从走廊的一头冒出，将檀木地板打得又湿又滑，你几乎要扶着栏杆才不会滑倒。
LONG
        );
        set("exits", ([
                "east" : __DIR__"jlonglang2",
		"west" : __DIR__"jlongpool",
        ]));
        set("objects", ([
                __DIR__"npc/smilegirl": 1,
        ]) );
	set("no_fight",1);
	set("no_magic",1);
        setup();
        create_door("west", "檀木门", "east", DOOR_CLOSED);

}
int valid_leave(object me, string dir)
{
        object *inv;
        object ob;
        int i;
	int withtowel=0;
        if( dir == "west" && ob=present("chuchu", this_object()))
        {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
			if ((string)(inv[i]->query("id")) != "white towel")
                        return notify_fail(ob->name()+"向你笑道：身上穿戴那么多，怎么能洗澡？\n");
			if( (string)(inv[i]->query("id")) == "white towel" &&
			    !(int)(inv[i]->query("equipped")))
			return notify_fail(ob->name()+"向你笑道：还是围上毛巾再进去吧，不要吓到别人．\n");
			if( (string)(inv[i]->query("id")) == "white towel" )
				withtowel = 1;
                }
	if( !withtowel)
	return notify_fail(ob->name()+"向你笑道：没有白毛巾怎么洗？\n");
        }
	if( dir == "east" && ob=present("chuchu", this_object()))
	{
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
		if( (string)(inv[i]->query("id")) == "white towel")
			{
		tell_object(me,ob->name()+"笑咪咪的将你身上湿的"+
		inv[i]->name()+"拿了回去．\n\n\n");	
		destruct(inv[i]);
			}
                }


	}
        return 1;
}

