// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: /u/mimi/zhuziguo/zixiagong.c    snowcat moved to /d/qujing/wuji
inherit ROOM;

void create()
{
  set ("short", "紫霞宫");
  set ("long", @LONG

国王的后宫。
LONG);

  set("exits", ([ /* sizeof() == 1 */
    "south" : __DIR__"palace",
  ]));
  setup();
}
