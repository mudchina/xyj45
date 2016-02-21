// 
// 

#include <room.h>
inherit ROOM;
void create()
{
  set("short","斋堂");
  set("long",@LONG
斋堂为寺内僧众吃饭的地方，安宾头庐尊者像，传说晋僧道安常
注经论，夜里梦见梵僧宾头庐劝他设  斋堂，于是大悟之下设斋堂以
供之。
LONG
  );
  set("exits",([
//            "north":__DIR__"changlang3.c",
            "east" :__DIR__"guanyin.c",
               ]));
          set("objects", ([
                __DIR__"npc/monk" : 1,
       ]) );
  setup();
  replace_program(ROOM);
}
