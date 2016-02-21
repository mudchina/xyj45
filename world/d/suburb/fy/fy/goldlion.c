inherit ROOM;
void create()
{
        set("short", "金狮镖局大院");
        set("long", @LONG
镖局大院里黑石铺地，大院右边零乱的放着一些大小不依的石锁，想必是镖局
中的趟子手用来练臂力的。左侧则是碗口粗细一人多高的梅花桩。听说总镖头查猛
原本是少林俗家弟子，后得高人指点，在轻功和掌法上都有颇深的造诣。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"nwind4",
  "east"  : __DIR__"ghall", 
  "north" : __DIR__"gcang",
  "south" : __DIR__"gkitchen",
]));
        set("objects", ([
        __DIR__"npc/biaoshi" : 1,
        __DIR__"npc/biaoshi1": 1,
                        ]) );

        set("outdoors", "fengyun");
        setup();
        replace_program(ROOM);
}
