//mac's yaocan
#include <room.h>
inherit ROOM;
void create()
{
  set("short","遥参亭");
  set("long",@LONG
   从此向北便可遥望泰山，因此此亭又称遥参亭。这里有两块碑：《宋
天贶殿碑铭》 和《宋封祀坛颂碑》，前碑记叙天贶殿的修建事情，后碑叙述的
是宋真宗登泰山祭拜答谢降“天书”的情况。
LONG
  );
  set("exits",([
         "north":__DIR__"daimiao.c",
         "southwest":"/d/suburb/fy/chenxiang/road",
               ]));
        set("objects", ([
                __DIR__"npc/jin" : 1,
		__DIR__"npc/tiao" : 2,
       ]) );
        set("item_desc", ([
                "《宋天贶殿碑铭》": "
			阿铁到此一游．．哈哈哈．．\n",
                "《宋封祀坛颂碑》": "
			阿铁到此一游．．哈哈哈．．\n"

        ]) );
  setup();
  replace_program(ROOM);
}
