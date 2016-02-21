// chaoyang.c

inherit ROOM;

void create()
{
        set("short", "朝阳峰");
	set("long", @LONG
这里就是华山的东峰—朝阳峰，於此俯瞰，黄河隐显东迤如带，南望
小孤峰背倚山河。东壁悬崖上，更有一个巨型掌印，相传为「河神巨灵」
劈山时所留下的。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
		  "westdown" : __DIR__"zhenyue",
	]));


        set("no_clean_up", 1);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}
 
