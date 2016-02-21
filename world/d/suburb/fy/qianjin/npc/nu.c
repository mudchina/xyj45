// thousand_hand.c

#include <ansi.h>

inherit NPC;
string	summon_more( object who);
void create()
{
	set_name( "湖上女", ({ "nu", "girl" }) );
	set("long", "这是千金楼湖上八娇之一．
湖上女，精选正轻盈。
犹恨乍离金殿侣，相将尽是采莲人，清唱谩频频。
轩内好，嬉戏下龙津。
玉管朱弦闻尽夜，踏青斗草争青春，玉辇从群真。
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
	set_skill("unarmed", 1+random(200));
	setup();
        carry_object(__DIR__"obj/nu")->wear();
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
        if( (string)(NATURE_D->outdoor_room_description()) == "    " +
"夜幕低垂，满天繁星。
" && !this_object()->query("given"))
	{
        message_vision("$N向$n道了个万福：\n",this_object(),me);
        command("smile");
	command("say 你还满聪明的！这个给你！\n");
	pai = new(__DIR__"obj/nupai");
	if(pai)
	pai->move(me);
        message_vision("$N拿出女玉璧给$n。\n",this_object(),me);
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

