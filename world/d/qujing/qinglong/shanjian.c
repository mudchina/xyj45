// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "山涧");
  set ("long", @LONG

山路绕过一个轰然作响的山涧，这里地势低平，东边岩石下涧
水急速地冲走，腾起一片白白的雾气。西北边有一个山凹，西
南有一下山的斜坡。

LONG);

  set("exits", ([
        "southwest"   : __DIR__"shanlu4",
        "northwest"   : __DIR__"dongshan",
      ]));
  set("outdoors", __DIR__);

  setup();
}

int valid_leave (object who, string dir)
{
  if (dir == "northwest")
    return notify_fail ("山涧早已将通向山凹的路淹没，很久就没人能过涧了。\n");
  return ::valid_leave(who,dir);
}

