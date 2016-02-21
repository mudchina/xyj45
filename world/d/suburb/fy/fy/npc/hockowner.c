#include <ansi.h>

inherit NPC;
inherit F_PAWNOWNER;
inherit F_VENDOR;
void create()
{
	set_name("香菱", ({ "xiangling" }) );
	set("gender", "女性" );
	set("age", 29);
	set("title", "当铺老板娘");
	set("long",
		"香菱从小被卖到千金楼，生活凄苦，但因善长得男人欢心，
终被一富豪看中，娶为第十八房小老婆。\n");
	set("combat_exp", 5000);
	set("attitude", "friendly");
	set("per",30);
	set("no_arrest",1);
	set_skill("unarmed",200);
	set_skill("dodge",200);
	setup();
	carry_object(__DIR__"obj/hua_skirt")->wear();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
        add_action("do_value", "value");
        add_action("do_pawn", "pawn");
        add_action("do_sell", "sell");
        add_action("do_redeem", "redeem");
	add_action("do_vendor_list","list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if ( ob->query("gender") == "男性")
{
	switch( random(5) ) {
		case 0:
message_vision("$N嗲声嗲气地说道：哎呦呦呦呦．．．这位"+RANK_D->query_respect(ob)+
"，是啥风儿把您吹到这儿来了？\n",this_object(),ob);

			break;
		case 1:
message_vision("$N上前拉住$n的手，笑咪咪地说道：这位"+RANK_D->query_respect(ob)+
"，您好象比上次来这儿时更高大威猛，英俊潇洒了！！\n",this_object(),ob);
			break;
				}
}
	else
{
        switch( random(5) ) {
                case 0:
message_vision("$N上前轻抚$n的粉脸，说道：这位"+RANK_D->query_respect(ob)+
"，您可真标致！嫉妒死我了！\n",this_object(),ob);

                        break;
                                }


}		
}

int accept_object(object who, object ob)
{
	message_vision("$N对$n说到：谢赏！！\n",this_object(),who);
		return 1;
}
	

