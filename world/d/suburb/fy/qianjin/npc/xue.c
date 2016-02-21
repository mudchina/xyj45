// thousand_hand.c

#include <ansi.h>

inherit NPC;
string	summon_more( object who);
void create()
{
	set_name( "湖上雪", ({ "xue", "girl" }) );
	set("long", "这是千金楼湖上八娇之一．
湖上雪，风急堕还多。
轻片有时敲竹户，素华无韵入澄波，望外玉相磨。
湖水远，天地色相和。
仰面莫思梁苑赋，朝来且听玉人歌，不醉拟如何？
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
        set("chat_chance", 1);
        set("chat_msg", ({
"湖上雪眼中含类，低声悲泣：
什么时候才能见到我的唯一的亲哥哥＂花满城＂\n",
        }) );

	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		(: summon_more(this_object()) :),
	}) );
	set_skill("unarmed", 1+random(200));
	setup();
        carry_object(__DIR__"obj/xue")->wear();
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
        if( (string) me->name() == "花满城" && !this_object()->query("given"))
	{
        message_vision("$N向$n道了个万福：\n",this_object(),me);
        command("smile");
	command("say 哥！终于见到你了！这个给你！听说里面有个大秘密．\n");
	pai = new(__DIR__"obj/xuepai");
	if(pai)
	pai->move(me);
        message_vision("$N拿出雪玉璧给$n。\n",this_object(),me);
	this_object()->set("given",1);
	return 1;	
	}

	if( !obj->value() &&  !obj->query("value")) return 0;
        command("smile");
	message_vision("$N向$n道了个万福：\n",this_object(),me);
        command("say 多谢这位" + RANK_D->query_respect(me) +
"，头一次见到象您这么大方的！");
        return 1;
}

