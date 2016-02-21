// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "待客馆");
  set ("long", @LONG

这里是接待远方来客和贵宾的地方。雪白的墙上贴着剪纸花，
北边的墙头放着一神龛。南边挂有几个细麻帐，分别罩着几张
考究的大客床。

LONG);

  set("exits", ([
        "west"   : __DIR__"xiaojie9",
      ]));
  set("objects", ([
        __DIR__"npc/chaiguan"  : 1,
      ]));
  set("valid_startroom",1);
  set("sleep_room",1);
  set("if_bed",1);
  setup();
}



