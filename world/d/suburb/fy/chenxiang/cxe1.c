// 
// 

inherit ROOM;
void create()
{
        set("short", "沉香镇东街");
        set("long", @LONG
这里的街道显得比较荒芜。一条小溪顺着街北静静地流淌，每当太阳
落山，一阵阵的浓雾便从东面的莽林渗来，渐渐地将整个沉香镇吞没在烟
雾迷漫之中。直到第二天太阳高照，浓雾才渐渐散去。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"cxe2",
  "west" : __DIR__"cxcenter",
]));
        set("outdoors", "chenxiang");
        setup();
        replace_program(ROOM);
}
