// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// create by snowcat.c 4/8/1997
// room: /d/westway/fenghuo.c

inherit ROOM;

void create ()
{
  set ("short", "烽火台");
  set ("long", @LONG

高高的烽火台，从烽火台向西望去，一片茫茫大雾海一般地
迷茫，什么也看不清。向东望去，远远地烽火台一个连一个
坐在群山峰上一直通向天边极远处。

LONG);

  set("exits", ([
        "northdown"  : __DIR__"jiayu",
      ]));
  set("outdoors", __DIR__);

  setup();
}


