//mac's houqing.c
// 
// 

inherit ROOM;
#include <ansi.h>
void create()
{
  set("short","后寝宫");
  set("long",@LONG
神龛内奉东岳大帝和帝后塑像，高一丈，两伺女分立左右，神龛
外两侧配有太监塑像，平台上有日形和月形碑各一块，以示日月同辉
之意。很多虔诚的信徒都在这儿膜拜（ｍｏｂａｉ）。
LONG
  );
  set("exits",([
         "north":__DIR__"tongting.c",
         "south":__DIR__"tiankuang.c",
         "east" :__DIR__"peiqing1.c",
         "west" :__DIR__"peiqing2.c",
               ]));
        set("item_desc", ([
                "东岳大帝": "
东岳大帝高六尺，型貌活灵活现，宛如真人一般。\n",
        ]) );
  setup();
}

void init()
{
add_action("do_mobai", "mobai");
}

int do_mobai()
{
       object who;
       who = this_player();
        if((int) who->query("sen") <=50)
        return notify_fail("你的神不够。\n");
       message_vision("$N虔诚地跪在东岳大帝塑像前磕了个头。\n" ,who);
       who->receive_damage("sen",50);
       if( (int)who->query("bellicosity") > 0)
           who->add("bellicosity", - (random((int)who->query("kar")) + 7 ) );
       message_vision("$N身上的杀孽之气似乎轻了。 \n" , who);
	add("number",1);
	if((int) query("number") ==	random(40) + 20 )
	{
	message_vision( HIR "\n\n$N觉得眼前一花，东岳大帝似乎动了一下！！！！\n\n" NOR,who);
	if ( !objectp(who = present("master dadi", this_object())) )
		{
		who = new(__DIR__"npc/dadi");
		who->move(this_object());
		}
	}	
	return 1;
}

void reset()
{
object obj;
:: reset();
delete("number");
if(objectp(obj = present("master dadi", this_object())) )
destruct(obj);
}
