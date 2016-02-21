// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: /d/nanhai/shanglu
inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

蜿蜒曲折的山路，北上就是普陀山的山门。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"shanglu2",
  "northup" : __DIR__"gate",
]));
  set("outdoors", "/d/nanhai");

  setup();
}
