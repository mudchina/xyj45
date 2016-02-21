inherit ROOM;
void create()
{
        set("short", "南风大街");
        set("long", @LONG
这里的街道宽敞而干净，汉白玉砌的路面被雨水冲得光明如镜，街道两侧的
瓦房高大而宏伟，分明是巨富宅院。双人合抱的杨树十步一株，整齐的排在两边。
西边的千金楼白天门可箩雀，但是到了晚上却是热闹非凡。千金楼为了方便客人，
又在南风大街的对面开了一座千银当铺。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"swind5",
  "north" : __DIR__"swind3",
  "east" : __DIR__"qianyin",
  "west" : "/d/suburb/fy/qianjin/qianjin",
]));
        set("outdoors", "fengyun");
        setup();
        replace_program(ROOM);
}
