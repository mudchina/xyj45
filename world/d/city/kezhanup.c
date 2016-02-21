// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit ROOM;

void create ()
{
  set ("short", "南城客栈二楼");
  set ("long", @LONG

这里摆设讲究，用的餐具都是从景德镇运来。摆的桌椅都是红木的，
在光照之下反射出淡淡的的光泽。推窗望去，长安城中心尽收眼底。
一群酒客推杯换盏，正喝的热闹。
LONG);

  set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/haoke1" : 1,
  __DIR__"npc/haoke2" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"kezhan",
]));

  setup();
}
