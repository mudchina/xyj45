//mac's chuxun.c
#include <room.h>
inherit ROOM;
void create()
{
  set("short","出巡阁");
  set("long",@LONG
此阁按东岳大帝出巡的场面列置：前有卫士，十八学士，东岳大
帝乘坐四轮六马大辇，两边各为八人大轿，穿红衣者为炳灵公，穿蓝
衣者为延嬉工，除前簇后拥的文武百官外，中间还有乐队，仪仗。最
前面是夜叉鸣锣，骐鳞开道。
LONG
  );
  set("exits",([
         "east":__DIR__"renan.c",
               ]));
        set("objects", ([
                __DIR__"npc/di" : 1,
       ]) );
  setup();
  replace_program(ROOM);
}
