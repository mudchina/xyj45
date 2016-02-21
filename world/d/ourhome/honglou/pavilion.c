// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: /u/hkgroup/pavilion
inherit ROOM;

void create ()
{
  set ("short", "沁芳亭");
  set ("long", @LONG

　　绕堤柳借三篙翠，隔岸花分一脉香。

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"wux",
  "south" : __DIR__"path1",
  "north" : __DIR__"yard1",
  "down" : __DIR__"kat",
]));
  set("outdoors", "/u/hkgroup");

  setup();
}
