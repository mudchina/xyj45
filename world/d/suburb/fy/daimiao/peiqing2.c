//mac's peiqing1.c
// 
// 

#include <room.h>
inherit ROOM;
void create()
{
  set("short","配寝殿");
  set("long",@LONG
此为泰山神的神妃的住所，神龛内有一张大型紫檀透花雕刻的龙
榻，榻上的绣龙花缎被下有东岳神的睡像，睡像为檀木雕刻，榻旁有
神妃着衣配坐。
LONG
  );
  set("exits",([
         "east":__DIR__"houqing.c",
               ]));
        set("objects", ([
        __DIR__"obj/huabei" : 1,
	__DIR__"obj/shenji" : 1,
                        ]) );
  setup();
}
void reset()
{
        object *inv;
        object con, item;
        ::reset();
        con = present("huabei", this_object());
        inv = all_inventory(con);
        if(!sizeof(inv)) {
        item = new(__DIR__"obj/xiang");
        item->move(con);
        }
}

