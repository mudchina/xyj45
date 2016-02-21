
inherit ROOM;
#include <room.h>
void create()
{
        set("short", "长廊");
        set("long", @LONG
这里是给到这儿的小姐们更衣入浴的，地上是五光十色的彩带和香味扑鼻的花瓣,
昂贵的衣裳满地都是，透过蒙蒙水雾，你可以看到白腻的身躯，修长的大腿，坚挺的
胸膛，和乌黑的长发。。。。。。
LONG
        );
        set("exits", ([
                "west" : __DIR__"hfenglang2",
		"east" : __DIR__"hfengpool",
        ]));
        set("objects", ([
                __DIR__"npc/smileboy": 1,
        ]) );
	set("no_fight",1);
	set("no_magic",1);
        setup();
        create_door("east", "檀木门", "west", DOOR_CLOSED);

}
int valid_leave(object me, string dir)
{
        object *inv;
        object ob;
        int i;
	int withtowel=0;
        if( dir == "east" && ob=present("jintong", this_object()))
        {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
			if((string)(inv[i]->query("id")) != "white towel")
                        return notify_fail(ob->name()+"向你笑道：身上穿戴那么多，怎么能洗澡？\n");
			if( (string)(inv[i]->query("id")) == "white towel" &&
			    !(int) inv[i]->query("equipped"))
			return notify_fail(ob->name()+"向你笑道：还是围上毛巾再进去吧，不要吓到别人．\n");
			if( (string)(inv[i]->query("id")) == "white towel" )
				withtowel = 1;
                }
	if( !withtowel)
	return notify_fail(ob->name()+"向你笑道：没有白毛巾怎么洗？\n");
        }
	if( dir == "west" && ob=present("jintong", this_object()))
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

