// 
// 

inherit ROOM;
void create()
{
        set("short", "山谷口");
        set("long", @LONG
气温越来越暧，简直近于酷热，这整个山谷，竟似已变得一股洪炉，
要炼出人们的灵魂。但在前面，山谷中豁然开朗，群峰合抱间，竟是一
片花海。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"flower",
  "north" : __DIR__"flower2",
]));

        set("outdoors", "fengyun");
        setup();
        replace_program(ROOM);
}
