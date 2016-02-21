inherit ROOM;
void create()
{
        set("short", "湖上酒");
        set("long", @LONG
湖上酒，终日助清欢。
檀板轻声银甲缓，醅浮香米玉蛆寒，醉眼暗相看。
春殿晚，仙艳奉杯盘。
湖上风光真可爱，醉乡天地就中宽，帝王正清安。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"hua",
  "northeast" : __DIR__"shui",
]));
        set("objects", ([
        __DIR__"npc/jiu" : 1,
                        ]) );

        setup();
        replace_program(ROOM);
}
