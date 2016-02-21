// Room: /d/village/eexit.c

inherit ROOM;

void create()
{
	set("short", "西村口");
	set("long", @LONG
这里是华山脚下，虽然远离县城，却没有什麽山贼草寇在附近出没。
东面是一个小村庄，看来村子里人家不多，村民们过着日出而作，日落而
息的宁静生活。穿过这个小村子，就是上华山的山路了。北边有间破房子。

LONG
	);

	set("exits", ([ /* sizeof() == 2 */
	"east" :__DIR__"nwroad1",
	"north" : __DIR__"shack",
]));
	
        set("objects", ([ __DIR__"npc/kid": 2 ]) );
        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}

