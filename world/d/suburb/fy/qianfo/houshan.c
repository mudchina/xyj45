//mac's houshan.c
#include <room.h>

inherit ROOM;

void create()
{
  set("short","後山平地");
  set("long",@LONG
这里是一块开阔平地，在从山合抱之中，四面松涛环绕，是寺
中众僧健身习武的地方。地上放了许多练功用的器械。
LONG
  );
  set("exits",([
         "southwest": __DIR__"chanfang.c",
         "southeast": __DIR__"chanfang2.c",
               ]));
          set("objects", ([
                __DIR__"obj/bigstone" : 1,
       ]) );
  set("outdoors","qianfo"); 
  setup();
  replace_program(ROOM);
}
