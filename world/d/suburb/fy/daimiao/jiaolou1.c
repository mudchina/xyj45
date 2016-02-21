//mac's jiaolou1.c
// 
// 

#include <room.h>
inherit ROOM;
void create()
{
  set("short","À¤½ÇÂ¥");
  set("long",@LONG
ÕâÊÇá·ÃíÎ§Ç½ËÄÓçµÄ½ÇÂ¥£¬·Ö±ğÒÔËÄØÔÎªÃû£¬ÒÔÇó±ÜĞ×Ç÷¼ª£¬Â¥ÖĞ
ÓĞÒ»Ãæ´ó±®£¬±®ÉÏÊéÒ»´ó×Ö£º
[33m
				À¤
[37m
LONG
  );
  set("exits",([
         "north":__DIR__"jiaolou3.c",
         "east" :__DIR__"zhengyan.c",
               ]));
   
        set("objects", ([
                __DIR__"npc/gang1" : 1,
       ]) );
  setup();
  replace_program(ROOM);
}
