// 
// 

#include <room.h>
inherit ROOM;
void create()
{
  set("short","大雄宝殿");
  set("long",@LONG
此殿为正殿，四周偃牙高啄，六龙翔舞，中尊为释迦，端座在长
方形须弥座上。左右有迦叶，阿难两尊者和两菩萨伺立。迦叶居左，
擎拳含笑，阿难居右，合掌而立。两极端前角，各有甲胄护法天王，
两像遥立对峙，各持长剑，嗔目怒视。
LONG
  );
  set("exits",([
         "south":__DIR__"qianyuan.c",
//         "north":__DIR__"tianwang.c"
               ]));
        set("objects", ([
                __DIR__"obj/copperman" : 1,
		__DIR__"obj/heart":1,
                __DIR__"obj/liver":1,
                __DIR__"obj/stomach":1,
                __DIR__"obj/lung":1,
                __DIR__"obj/kidney":1,
       ]) );
        set("item_desc", ([
                "mark": "你似乎可以将内力从掌印输入（ｔｏｕｃｈ）铜人体内。\n",
                "掌印" : "你似乎可以将内力从掌印输入（ｔｏｕｃｈ）铜人体内。\n",

        ]) );
  setup();
}
