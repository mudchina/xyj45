// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: /u/hkgroup/main
inherit ROOM;

void create ()
{
  set ("short", "大观楼");
  set ("long", @LONG

　　崇阁巍峨，层楼高起，面面琳宫合抱，迢迢复道纡行。
青松拂檐，玉兰绕砌；金辉兽面，彩焕螭头。

LONG);

  set("exits", ([ /* sizeof() == 5 */
  "up" : __DIR__"fairyplace",
  "west" : __DIR__"mainwest",
  "north" : __DIR__"bridge",
  "south" : __DIR__"yard2",
  "east" : __DIR__"maineast",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/leng" : 1,
]));
  set("light_up", 1);
  set("no_fight", 1);
  set("no_magic", 1);

  setup();
  "obj/board/honglou_b"->foo();
}
