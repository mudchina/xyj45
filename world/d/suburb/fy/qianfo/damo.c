// 
// 

#include <room.h>
inherit ROOM;
void create()
{
  set("short","达摩堂");
  set("long",@LONG
菩提达摩为中国禅宗的始祖，于嵩山少林寺创壁观婆罗门，六祖
慧能为禅道之祖，百丈禅师建丛林成其形。这里供奉的正是这三位开
山尊宿。
LONG
  );
  set("exits",([
         "west":__DIR__"tianwang.c"
               ]));
        set("objects", ([
                __DIR__"obj/damo" : 1,
       ]) );
  setup();
  replace_program(ROOM);
}
