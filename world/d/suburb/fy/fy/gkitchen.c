inherit ROOM;
void create()
{
        set("short", "镖局厨房");
        set("long", @LONG
金狮镖局对伙计们十分款待，不但每月有薪金，而且还包吃住。这里就是伙计们
一日三餐的地方。厨房的墙上挂满了锅碗瓢盆，还有一些风干的卤味儿。房中放着一
张长台，长台的周围摆着几条长凳。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"goldlion",
]));
        set("objects", ([
        __DIR__"npc/goldcook" : 1,
                        ]) );

        setup();
        replace_program(ROOM);
}
