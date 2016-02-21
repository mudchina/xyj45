inherit ROOM;
void create()
{
        set("short", "南城门楼");
        set("long", @LONG
门楼呈方形，往下望是川流不息的人群，阳光下，流动的人群象微风中的彩带,
北方是风云城的中心，就是在这里也可以依稀的看到风云广场中心的纹龙柱。城中
的房屋连绵不断，索碎的小路象细小的银蛇，蜿蜒盘旋在灰色的房屋之间.
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "down" : "/d/suburb/fy/fy/sgate",
  "east" : __DIR__"swall1",
  "west" : __DIR__"swall10",
]));
        set("outdoors", "fengyun");
        setup();
        replace_program(ROOM);
}
