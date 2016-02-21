// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: /u/rainy/sea/sleep.c
inherit ROOM;

void create ()
{
  set ("short", "睡房");
  set ("long", @LONG

这里是龙宫中的睡房。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"mulang2.c",
]));
        set("sleep_room",1);
        set("if_bed",1);


  setup();
}
