// 
// 

inherit ROOM;
void create()
{
        set("short", "石峰边缘");
        set("long", @LONG
这里不但像是已到了沙漠的尽头，简直像是到了天地的尽头。再往
前走，便要跌入百韧不复的深渊中。前面俱是石峰，无边无际，再也难
往前走。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : "/u/quicksand/desert2",
  "north" : __DIR__"road1",
]));

        set("outdoors", "fengyun");
        setup();
        replace_program(ROOM);
}
