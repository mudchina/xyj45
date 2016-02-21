// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "小子场");
  set ("long", @LONG

小子场是一方形青石广场，十分宽敞可行车马列队演练。周围
是楼阁殿宇，往南更是祥云瑞气腾腾，旌旗飘扬，乃是比丘国
王宫所在。

LONG);

  set("exits", ([
        "northeast"    : __DIR__"jie9",
        "south"    : __DIR__"zhaomen",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

