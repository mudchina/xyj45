inherit ROOM;
// 
// 


void create()
{
        set("short", "瀑后山洞");
        set("long", @LONG
飞流的水珠不时地溅入山洞，地下布满冰碴，又硌又扎。山洞内很暗，但
隐约还可看出里面空间很大，慢慢往前走去，发现前面有几个矮小的洞分别通
向更深的山腹中。但是由于洞内极冷，洞口都被寒冰盖住了。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
	"west" : __DIR__"waterfall",
	]));
        set("objects", ([
                "/obj/money/thousand-cash" :1,
                        ]) );
	set("frozen",10);
        set("item_desc", ([
                "寒冰": "
除非把寒冰化开（ｐｏｕｒ），根本没办法进入山腹中。\n",
        ]) );

        setup();
}

void init()
{
	add_action("do_pour", "pour");
}
int do_pour(string arg)
{
	object me;
	object con;
	me = this_player();
	if(!arg) return 0;
	if(!objectp(con=present(arg, me)))
	return 0;
	if(!con->query("liquid"))
	return 0;
	if(!con->query("liquid/remaining"))
	return notify_fail( con->name() + "是空的。\n");
	con->add("liquid/remaining", -1);
	message_vision("$N拿起" + con->name() + "倒了一些" +
	con->query("liquid/name")  + "在寒冰上。\n",me);
	if(con->query("liquid/name") == "热水")
	{
	tell_object(me,"寒冰化开了一点！！\n");
	add("frozen",-1);
	}
	if( query("frozen") <= 0 )
	{
	tell_object(me,"寒冰终于化开了一个小洞．．．\n");
	if(!query("exits/north"))
		set("exits/north",__DIR__"leftcave");
	call_out("close_path",10);		
	}
	return 1;
}

void close_path()
{
        if( !query("exits/north") ) return;
        message("vision",
"飘过来的水滴眨眼间冻成冰珠，渐渐地封住了洞口．．\n",
                this_object() );
                delete("exits/north");
		set("frozen",10+random(5));
}

