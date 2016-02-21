// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "宝阁");
  set ("long", @LONG

阁内有香案无数，每个香案上有金银香炉数只，仙香袅袅，缭
缭绕绕，阁北有一玉座落地金莲灯。西边有一殿门通向大雄宝
殿，楼上为宝阁藏经处。

LONG);

  set("exits", ([
        "up"   : __DIR__"baoge2",
        "west"   : __DIR__"daxiong",
      ]));
  set("objects", ([
        __DIR__"npc/randeng" : 1,
        __DIR__"npc/xiantong" : 2,
     ]));

  setup();
}

