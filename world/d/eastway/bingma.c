// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// create by snowcat.c 4/20/1997
// room: /d/eastway/bingma.c

inherit ROOM;

void create ()
{
  set ("short", "兵马俑阵");
  set ("long", @LONG

你来到一个巨大的兵马俑阵中，天高云阔，成千上万个栩
栩如生的兵马俑排列成几十路纵队，仿佛正在从四面八方
呼啸而来，你不禁被这个宏伟的场面惊倒。

LONG);

  set("exits", ([
        "west"       : __DIR__"shihuang",
      ]));
  set("objects", ([ /* sizeof() == 1 */
        __DIR__"obj/bingma" : 9,
      ]));
  set("outdoors", __DIR__);

  setup();
}






