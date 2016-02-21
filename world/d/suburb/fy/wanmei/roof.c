inherit ROOM;
// 
// 


void create()
{
        set("short", "小木屋顶");
        set("long", @LONG
一个扁平的乌木箱几乎占据了整个屋顶。乌木箱制作精细，滴水
不漏，箱中灌满泉水。每当夏日骄阳直射，箱中泉水就被晒热，再由
竹管流下，供人沐浴。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "down" : __DIR__"woodhouse",
]));
        set("outdoors", "wanmei");
        set("objects", ([
        __DIR__"npc/dodo": 1,
                        ]) );
        setup();
        replace_program(ROOM);
}
