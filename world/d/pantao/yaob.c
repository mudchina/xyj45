// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// created by snowcat.c 5/23/1997
// room: /d/pantao/yaob.c

inherit ROOM;

#define FILE __DIR__"npc/taibai"

void create ()
{
  set ("short", "瑶池");
  set ("long", @LONG

                       ◇瑶池◇

琼香缭绕，瑞霭缤纷，瑶台铺彩结，宝阁散氤氲。凤翥鸾腾形
缥缈，金花玉萼影浮沉。五彩描金桌，千花碧玉盆。桌上有龙
肝凤髓，熊掌猩唇。珍馐百味般般美，异果嘉肴色色新。

LONG);

  set("exits", ([
        "south" : __DIR__"palace1",
        "west"  : __DIR__"yaoa",
        "east"  : __DIR__"yaoc",
      ]));

  set ("no_fight", 1);
  set ("no_magic", 1);
  setup();
}

void init()
{
   if(sizeof(filter_array(children(FILE),(:clonep:)))<1)
       new(FILE)->move(this_object());
}

