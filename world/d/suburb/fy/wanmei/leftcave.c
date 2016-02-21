inherit ROOM;
// 
// 


void create()
{
        set("short", "左边小洞");
        set("long", @LONG
钻进洞中抬头望去，黑暗中依稀看到山洞顶部凹凸不平，上面有许多草藤交
织成的巢穴，也不知是如何固定在上面的，刚好有一只小鸟从穴中飞出，沿洞壁
盘旋一周，鸣叫着又钻了回去。到处都是寒冰！
LONG
        );
	set("frozen",10);
        set("item_desc", ([
                "寒冰": "
除非把寒冰化开（ｐｏｕｒ），根本没办法进入山腹中。\n",
        ]) );
        set("objects", ([
                __DIR__"obj/icy_boot" :1,
                __DIR__"obj/icy_cloth" :1,
                __DIR__"obj/icy_girth" :1,
                __DIR__"obj/icy_ribbon" :1,

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
	if(!query("exits/west"))
		set("exits/west",__DIR__"centercave");
	call_out("close_path",10);		
	}
	return 1;
}

void close_path()
{
        if( !query("exits/west") ) return;
        message("vision",
"飘过来的水滴眨眼间冻成冰珠，渐渐地封住了洞口．．\n",
                this_object() );
                delete("exits/west");
		set("frozen",10+random(5));
}

