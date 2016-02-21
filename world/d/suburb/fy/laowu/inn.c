
inherit ROOM;

void create()
{
        set("short", "小客栈");
        set("long", @LONG
简陋的客厅当中供着一个手捧金元宝的财神爷，后面的一扇门上，挂着已洗的发白
的蓝布棉门帘，上面还贴着张斗大的红“喜”字，无论谁走进这里，都可以看得出这地
方的主人，一定是整天在做着发财梦的穷小子。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"street2",
  "east" : __DIR__"pofang",
]));
        set("objects", ([
        __DIR__"npc/waiter" : 1,
                        ]) );
       setup();
        replace_program(ROOM);

}

