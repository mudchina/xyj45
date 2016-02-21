// thousand_hand.c

#include <ansi.h>

inherit NPC;
string	summon_more( object who);
void create()
{
	int i,amun;
	string *order = ({"张", "王", "李", "赵", "孙", "徐", "郑", "周", "吴", "蒋", "沈", "杨", "苗", "尹", "金", "魏", "陶", "俞", "柳", "朱"});
	set_name( (order[random(20)]) + "护法", ({ "hu fa", "hu", "fa" }) );
	set("long", "这是一位神水宫的护法，专门担任维持治安。\n");
	set("attitude", "friendly");
	set("title", "千手观音");
	set("max_gin", 500);
	set("max_kee", 500);
	set("max_sen", 500);
	set("age", 33);
        set("gender", "女性" );


	set("str", 35);
	set("cor", 30);
	set("cps", 25);

	set("combat_exp", 50000);
        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :)
        }) );
	set("chat_chance_combat", 4);
	set("chat_msg_combat", ({
		(: summon_more(this_object()) :),
	}) );
        create_family("九阴派", 12, "弟子");
	set_skill("throwing",100+random(90));
	set_skill("parry", 1+random(170));
	set_skill("dodge", 1+random(150));
	set_skill("unarmed", 1+random(100));
	set_skill("nine-moon-claw", 1+random(80));
	map_skill("unarmed", "nine-moon-claw");
	setup();
        carry_object("/obj/cloth")->wear();
        add_money("silver", 50);
	amun = random(5)+1;
        for(i=1; i<= amun; i++){
                carry_object(__DIR__"obj/pearl")->wield();
        }

}

string summon_more(object who)
{
	int i;
	object *enemy;
	object another;
	if((string) environment(who)->query("outdoors") == "girlvillage")
	{
	seteuid(getuid());
	another = new(__DIR__"thousand_hand");
	another->move(environment(who));
	message_vision(another->name()+ "走了过来。\n"
		, this_object() );
	enemy = who->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			another->kill_ob(enemy[i]);
			if( userp(enemy[i]) ) enemy[i]->fight_ob(another);
			else enemy[i]->kill_ob(another);
		}
	}
	set_leader(who);
	return "1";
	}
	else
	return "0";


}

void init()
{       object ob;
        if( interactive( ob = this_player())
&& (string) environment(ob)->query("outdoors") == "girlvillage"
)
	{
	if( (string)ob->query("gender") == "男性")
	{
	command("say 大胆！竟敢踏入神水宫！\n");
	kill_ob(ob);
	}
	}
}

