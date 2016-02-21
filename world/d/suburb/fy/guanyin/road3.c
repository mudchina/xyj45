// 
// 

inherit ROOM;
void create()
{
        set("short", "小路");
        set("long", @LONG
石峰中竟有一条小路，蜿蜒曲折，如羊肠盘旋，就算再多走几次
也无法辨出方向的......普天之下无论谁到了这里，也休想轻易出去。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"road2",
  "west" : __DIR__"road4",
  "northwest" : __DIR__"deep",
]));

        set("outdoors", "fengyun");
        setup();
        replace_program(ROOM);
}
