// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/cangjing.c

inherit ROOM;

void create ()
{
  set ("short", "藏经楼");
  set ("long", @LONG

藏经楼里古色古香，门边有一落地铜炉，正在冒着袅袅香烟，
门后墙头挂着一些铜铃，靠壁放有一排奇怪的檀香书柜。东南
方面有长道通向后殿。

LONG);

  set("exits", ([
        "southeast"    : __DIR__"houdian",
      ]));

  set("objects", ([
         "/d/obj/book/daode"    : 1,
      ]));
  setup();
}

void init ()
{
  add_action ("do_spell","spell");
}

int do_spell (string arg)
{
  object who = this_player();

  if (! arg)
    return 0;

  if (arg != "shugui")
    return 0;

  tell_object (who,"你悄声地对书柜念了几声咒语，一阵风将你带了过去。\n");
  who->move(__DIR__"miyuan");
  return 1;
}
