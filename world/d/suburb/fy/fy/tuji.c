inherit ROOM;
void create()
{
        set("short", "屠记肉铺");
        set("long", @LONG
脏稀稀的木板上放着几块颜色灰暗，不堪入目的生肉。一堆绿头苍蝇忙忙碌碌的
飞起飞落。几个生了锈的铁勾上挂着半风干了的羊头，猪头，和牛头。柜台的左角儿
放着几个木匣，匣中放着些煮熟了的杂碎和排骨。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"wcloud5",
]));
        set("objects", ([
        __DIR__"npc/butcher" : 1,
                        ]) );

        setup();
        replace_program(ROOM);
}
