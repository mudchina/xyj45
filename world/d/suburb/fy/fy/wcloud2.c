inherit ROOM;
void create()
{
        set("short", "西云大路");
        set("long", @LONG
也许是快到风云广场的原故，这里的气氛渐渐明朗起来。脚下已不是坎坷不平
的黄土路，大块的黑石砌成的大路可容八马并行，路上的行人脚步轻快，神情开朗，
大路的南侧是风云城中的知府衙门，大路的北首是风云绎站。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"mailst",
  "south" : __DIR__"govern",
  "west"  : __DIR__"wcloud3",
  "east"  : __DIR__"wcloud1",
]));

        set("outdoors", "fengyun");
        setup();
        replace_program(ROOM);
}
