
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
                "south" : __DIR__"hfenglang1",
		"east" : __DIR__"hfenglang3",
        ]));
        setup();
        replace_program(ROOM);

}
