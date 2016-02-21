// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: /changan/eastseashore.c

#include <ansi.h>
inherit ROOM;

void check_trigger();
void on_board();
void arrive();
void close_passage();
int do_zuo(string arg);
int do_dive();
void reset();


void create ()
{
  set ("short", "东海之滨");
  set ("long", @LONG

面前便是东海，茫茫大海望不到边际。海面上波涛汹涌，几丈
高的浪头此起彼伏，象是要吞灭一切敢于到海上的东西。也许
这里便是路的尽头，面前的大海对一个凡人来说是不可逾越的。
离岸不远处漂着一只木筏(mufa)。
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "mufa" : "一只木筏，以几根大圆木捆成。你不禁想坐(zuo)上去试一试。
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"seashore2",
]));
  set("outdoors", 1);

  setup();
}

void init()
{
    add_action("do_zuo", "zuo");
    add_action("do_zuo", "sit");
    add_action("do_dive", "dive");
}

void check_trigger()
{
    object room;

    if(!query("exits/enter") ) {
        if( !(room = find_object(__DIR__"mufa")) )
            room = load_object(__DIR__"mufa");
        if( room = find_object(__DIR__"mufa") ) {
            if((int)room->query("zuo_trigger")==0 ) {
                room->set("zuo_trigger", 1);
                set("exits/enter", __DIR__"mufa");
                room->set("exits/out", __FILE__);
                message("vision", "一只木筏从海上漂了过来。\n", this_object() );
                message("vision", "木筏一震，显然是搁浅了。\n", room);
                remove_call_out("on_board");
                call_out("on_board", 15);
            }
            else
                message("vision", "木筏正漂向岸边，看样子还得耐心地等等。\n",this_object() );
        }
        else
            message("vision", "ERROR: mufa not found\n", this_object() );
    }
    else 
        message("vision", "木筏已经靠岸了，随时都可上去。\n",
            this_object() );
}


void on_board()
{
    object room;

    if( !query("exits/enter") ) return;

    message("vision", "一个浪头打来，木筏向海上漂去。\n",
        this_object() );

    if( room = find_object(__DIR__"mufa") )
    {
        room->delete("exits/out");
        message("vision", "周围是白茫茫的一片汪洋，已经看不到任何陆地的迹象了...\n", room );
    }
    delete("exits/enter");

    remove_call_out("arrive");
    call_out("arrive", 20);
}

void arrive()
{
    object room;
    if( room = find_object(__DIR__"mufa") )
    {
        room->set("exits/out", __DIR__"aolaiws");
        message("vision", "木筏一震，搁浅了。显然是到陆地了，赶紧上去吧。\n",room );
    }
    remove_call_out("close_passage");
    call_out("close_passage", 20);
}

void close_passage()
{
    object room;
    if( room = find_object(__DIR__"mufa") ) {
        room->delete("exits/out");
        message("vision","一个浪头打来，木筏向海上漂去。\n", room);
room->set("zuo_trigger", 0);
    }
}

int do_zuo(string arg)
{
    string dir;

    if( (arg=="mufa") || (arg=="木筏")){ 
        message_vision("$N试着想坐上木筏。\n", this_player());
        check_trigger();
        return 1;
    }
    else return notify_fail("你要坐上什么？\n");
}

int do_dive()
{       object me, zhou;
        me=this_player();



       if(( !(zhou=present("bishui zhou", me))
     ||(string)zhou->query("unit")!="张")
     && (string)me->query("family/family_name")!="龙宫"
     && (string)me->query("family/family_name")!="东海龙宫")

     return notify_fail("你一个猛子扎到水里．．．\n"+
       "\n但没多会儿就被憋得半死，只好赶紧爬上岸来。\n");


                message_vision(HIY "$N一个猛子扎到水中，然后不见了．\n" NOR, me);
                me->move("/d/sea/under1");
     message_vision("$N潜了过来。\n",me);
                return 1;
}

void reset()
{
    object room;

    ::reset();
    if( room = find_object(__DIR__"mufa") )
        room->delete("zuo_trigger"); 
}
