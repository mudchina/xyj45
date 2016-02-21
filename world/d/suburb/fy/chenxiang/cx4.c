// 
// 

inherit ROOM;
void create()
{
        set("short", "沉香镇石桥");
        set("long", @LONG
这里充分地显示着江南小镇那种独特仅有的风格，园拱形的小桥横跨
一条弯弯的小河流。桥下的流水被浮萍染成爱人的翠绿。偶尔一两只轻舟
划过，带动着河边的莲藕。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"cx3",
  "south" : __DIR__"cxcenter",
]));
        set("outdoors", "chenxiang");
        setup();
        replace_program(ROOM);
}
