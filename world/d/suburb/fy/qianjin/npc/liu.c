// thousand_hand.c

#include <ansi.h>

inherit NPC;
string	summon_more( object who);
void create()
{
	set_name( "湖上柳", ({ "liu", "girl" }) );
	set("long", "这是千金楼湖上八娇之一．
湖上柳，烟里不胜催。
宿雾洗开明媚眼，东风摇弄好腰肢，烟雨更相宜。
环曲岸，阴覆画桥低。
线拂行人春晚后，絮飞晴雪暖风时，幽意更依依。
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
"湖上柳挥动舞器，轻歌漫舞：
风萧萧兮易水寒
壮士一去兮不复还\n",
        }) );

	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		(: summon_more(this_object()) :),
	}) );
	set_skill("dagger", 1+random(200));
	setup();
        carry_object(__DIR__"obj/liu")->wear();
	carry_object(__DIR__"obj/wuqi")->wield();
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
        if( (int) obj->value() >= (30+ random(100)) * 10000)
	{
        message_vision("$N向$n道了个万福：\n",this_object(),me);
        command("smile");
	command("say 哇．．我最喜欢的耶！太谢谢你了！这个给你！\n");
	pai = new(__DIR__"obj/liupai");
	if(pai)
	pai->move(me);
        message_vision("$N拿出柳玉璧给$n。\n",this_object(),me);
	return 1;	
	}

	if( !obj->value() &&  !obj->query("value")) return 0;
        command("smile");
	message_vision("$N向$n道了个万福：\n",this_object(),me);
        command("say 多谢这位" + RANK_D->query_respect(me) +
"，头一次见到象您这么大方的！");
        return 1;
}

