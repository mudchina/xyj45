// 
// 

#include <room.h>
inherit ROOM;
void create()
{
  set("short","洞天福地");
  set("long",@LONG
峰回路转，有一石坊立于道上，上书四个金字：洞天福地。向北
一座寺庙隐约可见，山风吹来，清新凉爽，令人精神一震。向西山道
遮没在绿树之中，仅可见一线天光。
LONG
  );
  set("exits",([
         "westdown":__DIR__"qiyan.c",
         "northup" :__DIR__"chansi.c"
               ]));
        set("objects", ([
                __DIR__"npc/laoshi" : 1,
       ]) );
        set("outdoors", "qianfo");
  setup();
  replace_program(ROOM);
}
