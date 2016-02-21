// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// created by snowcat.c 5/23/1997
// room: /d/pantao/yaoc.c

inherit ROOM;

void create ()
{
  set ("short", "瑶池东廊");
  set ("long", @LONG

瑶池东廊一列玉桌整齐排开，摆满各类仙酒。廊里酒香扑鼻；
有几个造酒的仙官，盘糟的力士，领几个运水的道人，烧火的
童子，在此酿造玉液琼浆，香醪佳酿。

LONG);

  set("exits", ([
        "west"  : __DIR__"yaob",
        "south" : __DIR__"pan1e",
      ]));

  setup();
}

