inherit ROOM;
void create()
{
        set("short", "南风大街");
        set("long", @LONG
这里的街道宽敞而干净，汉白玉砌的路面被雨水冲得光明如镜，街道两侧的
瓦房高大而宏伟，分明是巨富宅院。双人合抱的杨树十步一株，整齐的排在两边。
只听到树上的小鸟时而不时的啾鸣几声，这里到处都散发着安祥宁静的气氛。
街道西边是普生堂，东边则是南宫钱庄。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"sgate",
  "north" : __DIR__"swind4",
  "east" : __DIR__"nanbank",
  "west" : __DIR__"pusheng",
]));
        set("outdoors", "fengyun");
        setup();
        replace_program(ROOM);
}
