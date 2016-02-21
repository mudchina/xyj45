// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// created by snowcat.c 5/27/1997
// room: /d/pantao/pan1b.c

inherit ROOM;

void create ()
{
  set ("short", "九千年蟠桃园");
  set ("long", @LONG

蟠桃园内花红叶绿，夭夭灼灼花盈树，颗颗枝枝果压枝。只见
是：时开时结千年熟，无夏无冬万载迟，先熟的，酡颜醉脸，
还生的，带蒂青皮。好个凝脂肌带绿，映日显丹姿。

这里的蟠桃紫纹缃核，九千年一熟。

LONG);

  set("exits", ([
        "west"       : __DIR__"pan1a",
        "east"       : __DIR__"pan1c",
        "north"      : __DIR__"yaoa",  
        "south"      : __DIR__"pan2b",  
      ]));

  set("outdoors",1);
  setup();
}

