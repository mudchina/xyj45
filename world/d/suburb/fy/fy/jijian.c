inherit ROOM;
#include <ansi.h>
int check_legal_name(string arg);
void create()
{
        set("short", "祭剑亭");
        set("long", @LONG
风云老少大多认为祭剑是取得比武胜利的必要条件之一。
每逢年一度的风云城大赛，凡是参赛的人都会到这儿来祭一次
兵刃，以求好运。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"ecloud2",
]));
        set("objects", ([
        "/d/suburb/fy/fengyun/npc/wangfuren" : 1,
			]) );
        setup();
        replace_program(ROOM);

}
