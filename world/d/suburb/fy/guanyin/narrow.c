// 
// 

inherit ROOM;
void create()
{
        set("short", "石峰狭道");
        set("long", @LONG
风，卷起黄沙，迷漫在狭谷间，更平添了一种凄秘诡谲之意，两山
夹立，天仅一线。人行在狭谷间，但见黄沙，却连天也瞧不见了。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"sand",
  "south" : __DIR__"deep2",
  "east" : __DIR__"deep",
]));

        setup();
        replace_program(ROOM);
}
