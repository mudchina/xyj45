// 
// 

inherit ROOM;
void create()
{
        set("short", "中药店");
        set("long", @LONG
一股浓烈的中草药的味道扑鼻而来。墙角一座小炉，炉上一个发黑的瓷锅
正在卟卟地冒着热气，显然在煎着药材。另一面立着一个黑色的木柜，上面插
满了四寸见方的木匣。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"cx3",
]));
        set("objects", ([
        __DIR__"npc/medman": 1,
                        ]) );
        setup();
}
void init()
{
	add_action("do_soup","煮汤");
	add_action("do_soup","cook");
}

int do_soup()
{
object ob1,ob2,ob3,ob4,ob5,ob6;
object me;
me = this_player();
ob1 = present("pilosulae",me);
ob2 = present("dioscoreae",me);
ob3 = present("codonopsis",me);
ob4 = present("astragalt",me);
ob5 = present("lycii",me);
ob6 = present("freshfish",me);
if( ob1 && ob2 && ob3 && ob4 && ob5 && ob6 )
{
message_vision("$N将一条鱼和一些中药放入瓷锅中，炖了起来．\n",me);
destruct(ob1);
destruct(ob2);
destruct(ob3);
destruct(ob4);
destruct(ob5);
destruct(ob6);
call_out("give_soup",random(5)+1,me);
return 1;
}
return 0;
}

int give_soup(object me)
{
object soup;
if(me) 
if( environment(me) == this_object())
{
soup = new(__DIR__"obj/med");
if(soup->move(me))
message_vision("$N将炖好的当归补血鱼汤放在怀里．\n",me);
}
return 1;
}
