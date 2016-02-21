// Killer-n.c ,No greeting, 少林功夫, 北门
inherit NPC;

void create()
{
	set_name("杀手", ({"killer"}));
	set("long",
	"这是一个身材高大的江湖人，两臂粗壮，膀阔腰圆，看起来似乎不怀好意。\n"
	);

	set("gender", "男性");
	set("attitude", "aggressive");
	set("class", "bonze");

	set("age", 20+random(30));
	set("shen_type", 0);

	set("str", 25+random(10));
	set("dex", 25+random(10));
	set("int", 25+random(10));
	set("con", 25+random(10));

	set("qi", 1500);
	set("max_qi", 1500);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiaji", 50+random(100));

	set("combat_exp", 10000+random(100000));
	set("score", 1);
        set("startroom","/d/suburb/fy/city/beimen");

	set_skill("force", 20+random(80));
	set_skill("hunyuan-yiqi", 20+random(80));
	set_skill("dodge", 20+random(60));
	set_skill("shaolin-shenfa", 20+random(60));
	set_skill("unarmed", 20+random(150));
	set_skill("parry", 20+random(80));
	set_skill("finger", 20+random(100));
	set_skill("yizhi-chan", 10+random(110));
	set_skill("strike", 20+random(100));
	set_skill("banruo-zhang", 10+random(110));

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("parry", "yizhi-chan");
	map_skill("finger", "yizhi-chan");
	map_skill("strike", "banruo-zhang");

	prepare_skill("finger", "yizhi-chan");
	prepare_skill("strike", "banruo-zhang");

	set("chat_chance", 20);
	set("chat_msg", ({
		"杀手说道: 这次看那些玩家们往哪儿跑。\n",
		"杀手说道: 杀! 杀! 杀!!!。\n",
		(: random_move :)
	}) );

	setup();
}

void init()
{
::init();
remove_call_out("greeting");
call_out("greeting", 1, this_player());
}

void greeting(object ob)
{
	object me, room1;
	me = this_object();
	room1 = environment(me);

//	if(ob->query_temp("hastrystab")==6) return;
	if (room1->query("no_fight"))
		room1->set("no_fight", 0);

	if (interactive(ob))
//	&& !environment(ob)->query("no_fight"))
	{
		command("say 你这家伙不要跑，让大爷我宰了你！！！\n");
		me->set_leader(ob);
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob); 
	}       

