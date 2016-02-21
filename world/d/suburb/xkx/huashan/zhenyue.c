// zhenyue.c

inherit ROOM;

void create()
{
        set("short", "镇岳宫");
	set("long", @LONG
这里地势略为平坦，上、下山的游客多在此稍作休息再继续前行。附
近有几间简陋的旅社，欲登东峰观日出者，大都于头晚歇息于此。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "northup" : __DIR__"canglong",
  "eastup" : __DIR__"chaoyang",
  "southup" : __DIR__"yunu",
]));
        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}
 
