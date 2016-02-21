// waiter.c

inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
	set_name("采菱女", ({ "cailing" }) );
	set("gender", "女性" );
	set("age", 11);
	set("long",
		"这位高卷着裤脚，笑咪咪地看着你．\n");
	set("combat_exp", 500);
	set("attitude", "friendly");
	set("per",30);
	set("vendor_goods", ([
                __DIR__"obj/ou":12,


	]) );
	set_skill("unarmed",50);
	set_skill("dodge",50);
	setup();
	carry_object("obj/cloth")->wear();
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
message_vision("$N笑道：这的姑娘都爱吃嫩藕，买一块？\n",this_object(),ob);
			break;
	}
}
int accept_object(object me, object obj)
{
        command("smile");
        command("say 多谢这位" + RANK_D->query_respect(me) +
"，您一定会在这儿玩的开心的！");
        return 1;
}

