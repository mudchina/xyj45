
inherit ROOM;

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
                "west" : __DIR__"hfeng",
		"north" : __DIR__"hfenglang2",
        ]));
        setup();
}
int valid_leave(object me, string dir)
{
           if( random((int)me->query("kar")) < 1 )
              {
               message_vision("$N脚下一个不稳，四脚朝天地摔在地上。\n\n",me);
               this_player()->unconcious();
               return 0;
              }
	if(  dir == "north" && me->query("gender") != "女性")
	return notify_fail("这是女人浴室，你冲进去作什么？\n");
	return 1;
}

