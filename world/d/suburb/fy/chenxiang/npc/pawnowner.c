#include <ansi.h>

inherit NPC;
inherit F_PAWNOWNER;
inherit F_VENDOR;
void create()
{
	set_name("胡老头", ({ "oldhu" }) );
	set("gender", "男性" );
	set("age", 69);
	set("combat_exp", 50);
	set("attitude", "friendly");
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
        add_action("do_value", "value");
        add_action("do_pawn", "pawn");
        add_action("do_sell", "sell");
        add_action("do_redeem", "redeem");
	add_action("do_vendor_list","list");

}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(5) ) {
		case 0:
message_vision("$N说道：这位"+RANK_D->query_respect(ob)+
"，要去闯莽林吗？\n",this_object(),ob);
			break;
		case 1:
message_vision("$N说道："
+ "侬还是将身上所有值钱的东西典在这吧，万一您在莽林里成仙，带着这么多东西多浪费！\n",this_object(),ob);
			break;
		case 2:
message_vision("$N抬头环扫了一眼四周积满灰尘的东西，低声叹道：唉，又一个去送死的。\n"
,this_object(),ob);
			break;
				}
}
