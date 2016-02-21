inherit ROOM;
void create()
{
        set("short", "湖上雪");
        set("long", @LONG
湖上雪，风急堕还多。
轻片有时敲竹户，素华无韵入澄波，望外玉相磨。
湖水远，天地色相和。
仰面莫思梁苑赋，朝来且听玉人歌，不醉拟如何？
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"liu",
  "southwest" : __DIR__"nu",
]));
        set("objects", ([
        __DIR__"npc/xue" : 1,
                        ]) );

        setup();
        replace_program(ROOM);
}
