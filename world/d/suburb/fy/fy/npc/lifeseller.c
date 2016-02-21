
inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
	set_name("薛陀子", ({ "xue" }) );
	set("gender", "男性" );
	set("age", 69);
	set("long",
		"这位陀子正用白多黑少的双眼盯着你\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("per",30);
	set("vendor_goods", ([
                __DIR__"obj/baozi1":30,
                __DIR__"obj/baozi2":30,
                __DIR__"obj/baozi3":30,
		__DIR__"obj/baozi4":30,
                __DIR__"obj/baozi5":30,

	]) );
	set_skill("unarmed",200);
	set_skill("dodge",200);
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
message_vision("$N用白多黑少的眼睛盯了$n一眼．\n",this_object(),ob);
			break;
		case 1:
message_vision("$N捶了捶自己的陀背说道：这位"+RANK_D->query_respect(ob)+
"要买什么？\n",this_object(),ob);
			break;
		case 2:
message_vision("$N哼道：买包子还是买．．．？\n",this_object());
	}
}
int accept_object(object who, object ob)
{
        int val;
	object paper;

        val = ob->value();
        if( !val )
                return 0;
        else if( val >= 2000) {
	paper = new(__DIR__"obj/baozhizhi");
	if( paper) {
	paper->set("targetprice", val);
	paper->move(who);
		    }
        }
        say( "薛陀子说道：多谢这位" + RANK_D->query_respect(who)
                + "可怜我这没用的穷老人．\n");

        return 1;
}

