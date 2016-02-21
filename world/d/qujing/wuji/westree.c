// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: /u/mimi/zhuziguo/westree.c  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create()
{
  set ("short", "东大街");
  set ("long", @LONG

east street

LONG);

  set("exits", ([ /* sizeof() == 1 */
    "east" : __DIR__"eastgate",
  ]));
  set("outdoors", __DIR__"");
  setup();
}
