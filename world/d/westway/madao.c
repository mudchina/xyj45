// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// create by snowcat.c 4/8/1997
// room: /d/westway/madao.c

inherit ROOM;

void create ()
{
  set ("short", "马道");
  set ("long", @LONG

一条车马专用的长道，路上行人匆匆忙忙地赶路，西边快到酒
泉了。东南方向有一片林地，路向林地的深处伸去，那便是经
常出危险的饮马峪。

LONG);

  set("exits", ([
        "southeast" : __DIR__"yinma",
        "west"      : __DIR__"jiuquan",
      ]));
  set("outdoors", __DIR__);

  setup();
}





