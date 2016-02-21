// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: /d/nanhai/shanglu2
inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

蜿蜒曲折的山路，西边通往海边。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"tingjing",
  "eastup" : __DIR__"shanglu",
]));
  set("outdoors", "/d/nanhai");

  setup();
}
