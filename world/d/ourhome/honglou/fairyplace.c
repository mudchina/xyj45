// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: /u/hkgroup/fairyplace
inherit ROOM;

void create ()
{
  set ("short", "太虚幻境");
  set ("long", @LONG

　　　　问谁幻入华胥境　千古风流造业人

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"main",
]));
  set("objects", ([
           __DIR__"npc/fairygirl": 1,
]));

  setup();
}
