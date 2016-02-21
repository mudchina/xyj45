// 
// 

inherit NPC;
inherit F_VENDOR;
void create()
{
	set_name("卖面的老人", ({ "oldman" }) );
	set("gender", "男性" );
	set("age", 65);
	set("long",
		"
卖面的老人年纪已经很大了，耳目已经有点不灵了，说话也不太清楚，就
象是大多数这类面馆老板一样经过了艰难困苦的一生，既没有产业，也没
有亲人。到老来还是同样的艰难困苦。
\n");
	set("combat_exp", 5);
	set("attitude", "friendly");
	set("per",1);
	set("vendor_goods", ([
		__DIR__"obj/hezi" : 100,
		__DIR__"obj/caomian" : 100,
		"/obj/example/wineskin" : 50,
	]) );
        set("inquiry", ([
                "杀人案" : "那家伙有把刀，会喷火的刀，就是他杀的．\n",
		"murder" : "那家伙有把刀，会喷火的刀，就是他杀的．\n",
        ]));

	setup();
	carry_object("/obj/cloth")->wear();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(10) ) {
		case 0:
command("say 我快不行了，拿几两银子行行好吧．\n");	
			break;
	}
}

int accept_object(object me, object obj)
{
	object ob;
	if( obj->value() > 500 && (int) query("given") < 10)
	{
        command("say 多谢这位" + RANK_D->query_respect(me) +
"，这小店就送于你吧．");
	ob = new(__DIR__"obj/qiju");
	ob->move(me);
	add("given",1);
	}
	else
	command("say 多谢这位" + RANK_D->query_respect(me) + "\n");	
        return 1;
}

void reset()
{
delete("given");
}
