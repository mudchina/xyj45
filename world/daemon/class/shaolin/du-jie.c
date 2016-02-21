// dujie.c

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("渡劫", ({ "du jie", "jie" }) );
	set("title", "少林长老");
	set("gender", "男性");
	set("age", 90);
	set("long",
		"这是一个面颊深陷，瘦骨零丁的老僧，他脸色惨白，象一张纸一样。\n");

	set("attitude", "peaceful");
	set("combat_exp", 1000000);
	set("score", 200000);

	set("str", 30);
	set("int", 30);
	set("cor", 30);
	set("cps", 30);
	set("con", 30);

	set("kee", 4000);
	set("max_kee", 2000);
	set("force", 4000);
	set("max_force", 2000);
	set("jiali", 90);

	create_family("少林派", 1, "弟子");
	assign_apprentice("弟子", 0);

	set_skill("force", 150);
	set_skill("whip", 180);
	set_skill("parry", 180);
	set_skill("dodge", 180);

	set_skill("hunyuan-yiqi", 150);
	set_skill("riyue-bian", 180);
	set_skill("shaolin-shenfa", 180);

	map_skill("force", "hunyuan-yiqi");
	map_skill("whip",  "riyue-bian");
	map_skill("parry", "riyue-bian");
	map_skill("dodge", "shaolin-shenfa");

	set("inquiry", ([
		"金刚罩"     : (: ask_me :),
	]));

	set("count", 1);

	setup();

	carry_object("/d/suburb/xkx/shaolin/obj/changbian")->wield();
}

void init()
{
	object me, ob;
	mapping fam;

	me = this_player();
	ob = this_object();

	::init();
	if( interactive(me) ) 
	{
		if ( mapp(fam = me->query("family")) && fam["family_name"] == "少林派" 
		&& fam["generation"] == 36 ) return;

		if ( mapp(fam = me->query("family")) && fam["family_name"] == "少林派" 
		&& fam["generation"] > 36 		
		&& me->query("kee") < 50 ) 
		{
			me->move("/d/suburb/xkx/shaolin/qyping");
			me->unconcious();
			return;
		}

		COMBAT_D->do_attack(ob, me, query_temp("weapon") );
		
		me->set_temp("fighter", 1);

		ob->fight_ob(me);
		me->fight_ob(ob);

		call_out("halt", 10);

		return;
	}

	return;
}

void halt()
{
	command("halt");
}

string ask_me()
{
	mapping fam; 
	object ob;
	
	if ( !this_player()->query_temp("fighter") 
	||    this_player()->query("combat_exp") < 5000 )
	{
		command("say 大胆鼠辈，乳臭未干，竟敢偷入金刚伏魔圈，且让老衲来超度与你！");
		this_object()->kill_ob(this_player());
		this_player()->kill_ob(this_object());
	}

	if ( present("jingang zhao", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"宝罩只有一件，而且就在你身上，真是贪得无餍！";

	if ( present("jingang zhao", environment()) )
		return RANK_D->query_respect(this_player()) + 
		"宝罩只有一件，而且就在这里任你取走，真是贪得无餍！";

	if ( present("fumo dao", this_player()) || present("fumo dao", environment()) )
		return RANK_D->query_respect(this_player()) + 
		"取了伏魔刀，就不能再拿金刚罩，莫要贪得无餍！";

	if (query("count") < 1)
		return "抱歉，你来晚了，金刚罩已经给人取走了。";

	ob = new("/d/suburb/xkx/shaolin/obj/jingang-zhao");
	ob->move(this_player());

	add("count", -1);

	message_vision("\n渡劫一声不吭地瞧了$N半饷，扭过身，从树洞里取出金刚罩递给$N。\n\n", this_player());

	return "你能挨我们三个老不死的三招日月神鞭不死，确实是命大，这件金刚罩就是你的了！";
}
