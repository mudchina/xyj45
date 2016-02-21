// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "独木桥");
  set ("long", @LONG

……独木桥摇摇摆摆，木头上长满了滑青苔……

LONG);

  set("exits", ([
        "south"   : __DIR__"lingyun2",
        "northwest"   : __DIR__"lingyun1",
      ]));
  set("outdoors", __DIR__);

  setup();
}

void init ()
{
  call_out ("shaking",random(3)+1);
}

void shaking ()
{
  tell_room (this_object(),"独木桥歪歪斜斜地晃荡了一下。\n");
}
