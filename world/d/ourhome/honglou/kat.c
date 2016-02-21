// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: /u/hkgroup/kat
inherit ROOM;

void create ()
{
  set ("short", "荡悠悠三更梦");
  set ("long", @LONG

　　　　枯藤，老树，昏鸦……

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"pavilion",
]));
  set("outdoors", "/u/hkgroup");

  setup();
}
