// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: /d/nanhai/restroom
inherit ROOM;

void create ()
{
  set ("short", "休息室");
  set ("long", @LONG

这里是普陀山的休息室，屋子里空荡荡的什么也没有，不知普陀
山门人弟子们是怎么样睡觉的。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"xiaoyuan",
]));
  set("no_fight", 1);
  set("light_up", 1);
  set("no_magic", 1);
  set("sleep_room", 1);

  setup();
}
