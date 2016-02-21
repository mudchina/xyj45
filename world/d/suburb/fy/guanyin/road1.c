// 
// 

inherit ROOM;
void create()
{
        set("short", "石峰群");
        set("long", @LONG
这里是一片岩石，大大小小，各色各样，千奇百怪的岩石。大的如
石峰排云，高入云霄，直插入穹苍中；小的也高有数十丈，如太古洪荒
时的恶龙怪兽，静静地蹲据在那里。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"entrance",
  "east" : __DIR__"road2",
]));

        set("outdoors", "fengyun");
        setup();
        replace_program(ROOM);
}
