// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "乾坤场");
  set ("long", @LONG

场子上设有一旗杆，几面幡旗随风飘荡。往东面看去有殿宇琼
楼幢幢，那里是王宫之所在。西面是热闹的街道，不时传来一
些嘈杂的人声。

LONG);

  set("exits", ([
        "east"    : __DIR__"gongmen",
        "west"    : __DIR__"jiedao2",
        "south"    : __DIR__"zhongshi",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

