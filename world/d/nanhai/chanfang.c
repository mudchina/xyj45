// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: /d/nanhai/chanfang
inherit ROOM;

void create ()
{
  set ("short", "禅房");
  set ("long", @LONG

这是普陀山门人弟子们练功打坐的地方。只见几个僧人正在
一边吆喝着舞拳弄脚，另外几个在练习兵器。屋角摆着几把
铁杖铁枪。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"zoulang",
]));
set("no_clean_up", 1);
set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhangchan" : 1,
]));

  setup();
}
