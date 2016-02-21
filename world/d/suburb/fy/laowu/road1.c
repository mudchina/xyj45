inherit ROOM;
void create()
{
        set("short", "南北大道");
        set("long", @LONG
这是风云城的一条主要大道。它上穿白山黑水，直达松花江。下接风云京都，
再通江南海口。这条干线上商旅不绝。一条车痕向南方和北方伸展。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"road5",
  "south" : __DIR__"road0",
  "east" : "/d/suburb/fy/qianfo/road1",
 "westup" : "/u/taoguan/sroad",
]));
        set("outdoors", "laowu");
        setup();
        replace_program(ROOM);
}
