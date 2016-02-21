//mac's qianyuan.c
#include <room.h>

inherit ROOM;

void create()
{
  set("short","前院");
  set("long",@LONG
青石铺的地面有两个大铜香炉。炉中盛满了香灰，正面是大殿，
西边是长廊，东边是千佛洞。因庙是背山而建，向东可见笔直陡峭的
山岩，峭壁上也凿满了佛像，巍为壮观，令人叹为观止。
LONG
  );
  set("exits",([
         "north":__DIR__"dadian.c",
         "west" :__DIR__"changlang.c",
         "east" :__DIR__"changlang2.c",
         "south":__DIR__"jinggang.c"
               ]));
        set("objects", ([
                __DIR__"npc/monk" : 1,
       ]) );
  setup();
  replace_program(ROOM);
}
