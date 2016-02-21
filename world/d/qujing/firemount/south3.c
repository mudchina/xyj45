// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// rewritten by snowcat on 4/11/1997
// Room: south3

inherit ROOM;

void create ()
{
  set ("short", "山脚");
  set ("long", @LONG

这里是山脚，道路十分泥泞，杂草丛生。南面是翠云山，往北翻过一
座小山丘便是火焰山。

LONG);

  set("exits", ([
        "northeast" : __DIR__"xiaomiao",
        "south"     : __DIR__"cuiyun5",
        "northup"   : __DIR__"south2",
      ]));
  set("outdoors", "firemount");

  setup();
}
