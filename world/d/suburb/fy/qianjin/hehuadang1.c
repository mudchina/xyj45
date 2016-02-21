inherit ROOM;
void create()
{
        set("short", "荷花荡");
        set("long", @LONG
花园对面，正对一个大湖，俗名荷花荡。每至春时，红绿间发，宛似西湖胜景。
沿湖遍插芙蓉，湖中种五色莲花。盛开之日，满湖锦云烂熳，香气袭人，小舟荡桨
采菱，歌声泠泠。遇斜风微起，依船竟渡，纵横如飞。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"hehuadang2",
  "south" : __DIR__"hehuadang",
]));
        set("objects", ([
        __DIR__"npc/dayan" : 2,
                        ]) );

	set("outdoors","fengyun");
        setup();
        replace_program(ROOM);
}
