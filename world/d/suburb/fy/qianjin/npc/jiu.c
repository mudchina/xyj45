// thousand_hand.c

#include <ansi.h>

inherit NPC;
string	summon_more( object who);
void create()
{
	set_name( "湖上酒", ({ "jiu", "girl" }) );
	set("long", "这是千金楼湖上八娇之一．
湖上酒，终日助清欢。
檀板轻声银甲缓，醅浮香米玉蛆寒，醉眼暗相看。
春殿晚，仙艳奉杯盘。
湖上风光真可爱，醉乡天地就中宽，帝王正清安。
\n");
	set("attitude", "friendly");
	set("title", HIM "湖上八娇" NOR);
	set("max_gin", 500);
	set("max_kee", 500);
	set("max_sen", 500);
	set("age", 17);
        set("gender", "女性" );


	set("str", 35);
	set("cor", 30);
	set("cps", 25);
	set("per", 40);
	set("combat_exp", 50000);

	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		(: summon_more(this_object()) :),
	}) );
	set_skill("unarmed", 1+random(100));
	setup();
        carry_object(__DIR__"obj/jiu")->wear();
        add_money("gold", 5);

}

string summon_more(object who)
{
	int i;
	object *enemy;
	object another;
	seteuid(getuid());
	another = new(__DIR__"jianu");
	another->move(environment(who));
	message_vision(another->name()+ "走了过来。\n"
		, this_object() );
	enemy = who->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			another->kill_ob(enemy[i]);
			enemy[i]->kill_ob(another);
			another->set_leader(enemy[i]);
		}
	}
	return "1";
}
int accept_object(object me, object obj)
{
	object pai;
    if ((string)obj->query("liquid/type")=="alcohol")
        if ((int)obj->query("liquid/remaining") != 0)
	{
	command("say 哇．．太谢谢你了！这个给你！\n");
	pai = new(__DIR__"obj/jiupai");
	if(pai)
	pai->move(me);
        message_vision("$N拿出酒玉璧给$n。\n",this_object(),me);
	return 1;	
	}

	if( !obj->value() &&  !obj->query("value")) return 0;
        command("smile");
	message_vision("$N向$n道了个万福：\n",this_object(),me);
        command("say 多谢这位" + RANK_D->query_respect(me) +
"，头一次见到象您这么大方的！");
        return 1;
}

