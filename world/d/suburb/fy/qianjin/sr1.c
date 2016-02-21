inherit ROOM;
void create()
{
        set("short", "底舱");
        set("long", @LONG
底舱阴暗潮湿，腐朽扑鼻。和上舱的富丽豪华极不吻合。一盏阴暗的吊烛随着船
身的摇摆而发出吱吱声。四壁阴冷而滑腻，似乎还有水珠的渗出。舱底冰冷，似乎可
以感到湖水的流动。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"secret_room",
  "west" : __DIR__"sr3",
]));

        setup();
        replace_program(ROOM);
}
