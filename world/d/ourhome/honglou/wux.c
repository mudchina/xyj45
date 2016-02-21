// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: /u/hkgroup/wux
inherit ROOM;

void create ()
{
  set ("short", "星亭");
  set ("long", @LONG

　　　　天上星星亮晶晶。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"pavilion",
]));
  set("outdoors", "/u/hkgroup");

  setup();
}
