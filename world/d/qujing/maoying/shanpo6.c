// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "山坡");
  set ("long", @LONG

山坡上长着古树青藤，路上枯枝落叶遍地，坡边高高低低长着
灌木蒿草，夹杂着一些大大小小的岩石。坡下幽幽深深，不时
可见沟渠洞穴。

LONG);

  set("exits", ([
        "westdown"   : __DIR__"shanpo5",
        "southeast"   : __DIR__"shanpo8",
      ]));
  set("outdoors", __DIR__);

  setup();
}



