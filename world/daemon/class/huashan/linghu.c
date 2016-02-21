// linghu.c 令狐冲

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("令狐冲", ({ "ling huchong", "ling", "huchong" }));
	set("nickname", "大师兄");
	set("long", 
"令弧冲身材较瘦，长的浓眉阔眼，气宇暄昂，他在\n"
"同门中排行老大，是华山派年轻一代中的顶尖好手。\n"
"目前掌门人岳不群不在，就由他执掌日常事物。\n");
	set("gender", "男性");
	set("age", 28);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("per", 30);
	
	set("kee", 2800);
	set("max_kee", 2800);
	set("gin", 1600);
	set("max_gin", 1600);
	set("force", 2400);
	set("max_force", 2400);
	set("force_factor", 60);

	set("combat_exp", 800000);
	set("score", 100000);

	set_skill("blade", 140);
	set_skill("cuff", 160);
	set_skill("strike",125);
	set_skill("force", 150);
	set_skill("dodge", 180);
	set_skill("parry", 140);
	set_skill("sword", 190);
	set_skill("dugu-jiujian", 120);
	set_skill("zixia-shengong", 130);
	set_skill("poyu-quan", 140);
	set_skill("fanliangyi-dao", 120);
	set_skill("hunyuan-zhang", 120);
	set_skill("huashan-jianfa", 190);
	set_skill("huashan-shenfa",160);
	set_skill("literate", 80);
//	set_skill("chongling-jianfa", 60);

	map_skill("force", "zixia-shengong");
	map_skill("cuff", "poyu-quan");
	map_skill("blade", "fanliangyi-dao");
	map_skill("strike", "hunyuan-zhang");
	map_skill("dodge", "huashan-shenfa");
	map_skill("parry", "huashan-jianfa");
	map_skill("sword", "dugu-jiujian");

//	prepare_skill("poyu-quan", "hunyuan-zhang");
//	prepare_skill("strike", "hunyuan-zhang");
//	prepare_skill("cuff", "poyu-quan");

	create_family("华山派", 14, "弟子");

	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
                (: perform_action, "sword.poqi" :),
                (: exert_function, "recover" :),
	}) );

	set("inquiry", ([
		"风清扬" : "唉，已经很久没有见到他老人家了。你问这干嘛？\n",
		"任盈盈" : "你真有她的消息吗？说罢，你见他神情激动,好象眼睛红红的！\n",
	]));
	setup();

	carry_object("/obj/cloth")->wear();
	carry_object("/obj/changjian")->wield();
	carry_object("/d/heimuya/npc/obj/card2")->wear();
}


void init()

{
	object ob;
	ob = this_player();	
	::init();
	if( interactive(ob) && !is_fighting() )
	       {
			remove_call_out("greeting");
			call_out("greeting", 1, ob);
		}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	say("何日才能见到盈盈啊!" + RANK_D->query_respect(ob)
	  +"，你可有她的消息?\n");
}

int accept_object(object who, object ob)
{
	object obn;

	if( !who || environment(who) != environment() )
		return 0;
	if( !objectp(ob) )
		return 0;
	if( !present(ob, who) )
		return notify_fail("你没有这件东西。\n");

	if( (string)ob->query("name") != "信")
		return notify_fail("令狐冲不需要这件东西。\n");
    say( "令狐冲双手捧着任盈盈的信，泪如雨下, 这块白虎堂令牌你拿去还给盈盈,告诉她我就去找她!" );
	obn = new("/d/heimuya/npc/obj/card2");
	obn->set_amount(1);
	obn->move(who);
	destruct(ob);
    set_temp("card2",0);
    return 1;
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("shen") < 0) {
		command("say 我华山派乃是堂堂名门正派，对弟子要求极严。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
		return;
	}

	if ((int)ob->query_int() < 25) {
		command("say 依我看" + RANK_D->query_respect(ob) + "的资质似乎不适合学我华山派武功？");
		return;
	}

	command("say 好吧，我就收下你了。");
	command("recruit " + ob->query("id"));
	if((string)ob->query("class") != "swordsman")
		ob->set("class", "swordsman");

	return;
}
