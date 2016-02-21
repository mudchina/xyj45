inherit ROOM;
// 
// 


void create()
{
        set("short", "中间小洞");
        set("long", @LONG
洞口很小，须低头侧身方可进入。刚一进入就听到了里面隐约的滴水声，抬头
望去，水是从洞壁渗出来的。再侧耳聆听，洞壁之后竟然有依稀的“隆隆”声，仿
佛是一股暗流在冲击着洞壁。洞壁上还是寒冰密布！
LONG
        );
	set("frozen",10);
        set("item_desc", ([
                "寒冰": "
除非把寒冰化开（ｐｏｕｒ），根本没办法进入山腹中。\n",
        ]) );
        set("objects", ([
                __DIR__"obj/blackthorn" :1,
                __DIR__"obj/silk_cloth" :1,
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
	if(!query("exits/south"))
		set("exits/south",__DIR__"rightcave");
	call_out("close_path",10);		
	}
	return 1;
}

void close_path()
{
        if( !query("exits/south") ) return;
        message("vision",
"飘过来的水滴眨眼间冻成冰珠，渐渐地封住了洞口．．\n",
                this_object() );
                delete("exits/south");
		set("frozen",10+random(5));
}

