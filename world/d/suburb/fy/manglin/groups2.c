inherit ROOM;
// 
// 


void create()
{
        set("short", "莽林之中");
        set("long", @LONG
四周古树参天，荆棘密布。浓密宽厚的树叶遮蔽了日月星辰，使人分不出
昼夜。四下如死一般的寂静，只有风吹过树梢的沙沙之声。偶尔一两声虎啸狼
嚎随着腥风飘至耳际。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"dummy2",
  "west" : __DIR__"dummy2",
  "north" : __DIR__"center2",

]));
        set("objects", ([
                __DIR__"npc/tiger" : 1,
                __DIR__"npc/wolf" : 2,
                __DIR__"npc/snake" : 1,
                __DIR__"npc/bear" : 1,
       ]) );

        setup();
replace_program(ROOM);
}
