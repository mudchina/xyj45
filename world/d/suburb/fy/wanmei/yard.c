// 
// 

inherit ROOM;
void create()
{
        set("short", "山庄正院");
        set("long", @LONG
正院的前方是庄主会客的雪梅阁，另一方则是枯梅堂的后门。
山风穿堂而过，枯梅堂的白烟笼罩于雪梅阁。阁前白玉石阶布满
了各色的花瓣。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"meidang",
  "southwest" : __DIR__"right",
  "northwest" : __DIR__"left",
  "east" : __DIR__"center",
  "north" : __DIR__"cleft",
  "south" : __DIR__"cright",
]));
        set("outdoors", "wanmei");

        setup();
        replace_program(ROOM);
}
