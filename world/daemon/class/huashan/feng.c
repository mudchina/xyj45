// feng.c 风清扬

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("风清扬", ({ "feng qingyang", "feng", "qingyang" }));
//	set("nickname", "大师兄");
	set("long", 
"他就是华山剑宗的长老风清扬。他身材瘦长，眉宇间一直笼罩着一股淡淡的忧伤\n"
"神色，显然对当年的剑宗气宗之争一直难以忘怀。\n");
	set("gender", "男性");
	set("age", 68);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("per", 30);
	
	set("kee", 4800);
	set("max_kee", 4800);
	set("gin", 3600);
	set("max_gin", 3600);
	set("force", 4400);
	set("max_force", 4400);
	set("force_factor", 200);

	set("combat_exp", 1750000);
	set("score", 200000);

	set_skill("cuff", 200);
	set_skill("force", 180);
	set_skill("blade", 200);
	set_skill("dodge", 180);
	set_skill("parry", 200);
	set_skill("sword", 220);
	set_skill("strike", 200);
	set_skill("zixia-shengong", 150);
	set_skill("poyu-quan", 170);
	set_skill("fanliangyi-dao", 180);
	set_skill("huashan-jianfa", 200);
	set_skill("hunyuan-zhang", 170);
	set_skill("dugu-jiujian", 200);
	set_skill("huashan-shenfa",160);
	set_skill("literate", 120);

	map_skill("cuff", "poyu-quan");
	map_skill("force", "zixia-shengong");
	map_skill("dodge", "huashan-shenfa");
	map_skill("parry", "dugu-jiujian");
	map_skill("sword", "dugu-jiujian");
	map_skill("blade", "fanliangyi-dao");
	map_skill("strike", "hunyuan-zhang");

	create_family("华山派", 12, "弟子");

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.poqi" :),
//		(: perform_action, "sword.pozhang" :),
//		(: perform_action, "sword.pojian" :),
		(: exert_function, "recover" :),
	}) );

	setup();
	carry_object("/obj/cloth")->wear();
	carry_object("/obj/changjian")->wield();
}

void attempt_apprentice(object ob)
{
	int student_num;
	string temp;
	string line;

	temp = read_file("/daemon/class/huashan/FENG", 1, 1);
	student_num = atoi(temp);

	line = "风清扬说道：“我现在共有" + temp + "个徒弟。”\n";
	write(line);

	if ( student_num == 3)
	{
		command("say 你来晚了，我已经收了三个徒弟了。");
		return;
	}

	if ((string)ob->query("family/family_name") != "" &&
	    (string)ob->query("family/family_name") != "华山派")
	{
		command("say " + RANK_D->query_respect(ob) + "既然已有名师指点，何必又来拜老朽呢？");
		return;
	}

	if (((int)ob->query_skill("sword",1) < 150) || ((int)ob->query_skill("huashan-jianfa",1) < 150))
	{
		command("say 我看" + RANK_D->query_respect(ob) + "的华山剑法还没学到家吧。");
		return;
	}
	if (((int)ob->query_skill("force",1) < 150) || ((int)ob->query_skill("zixia-shengong",1) < 130))
	{
		command("say 我看" + RANK_D->query_respect(ob) + "的紫霞神功还没学到家吧。");
		return;
	}
	if (((int)ob->query_skill("dodge",1) < 150) || ((int)ob->query_skill("huashan-shenfa",1) < 150))
	{
		command("say 我看" + RANK_D->query_respect(ob) + "的华山身法还没学到家吧。");
		return;
	}
	if ( (int)ob->query_skill("literate",1) < 160)
	{
		command("say 我看" + RANK_D->query_respect(ob) + "的读书识字还没学到家吧。");
		return;
	}

	if ((int)ob->query("shen") < 100000)
	{
		command("say 我华山派乃是堂堂名门正派，对弟子要求极严。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
		return;
	}

	if ((int)ob->query_int() < 41) {
		command("say 依我看" + RANK_D->query_respect(ob) + "的资质似乎不适合学我独孤九剑？");
		return;
	}

	command("say 好吧，我就收下你了。");
	command("recruit " + ob->query("id"));
	if((string)ob->query("class") != "swordsman")
		ob->set("class", "swordsman");

	student_num++;
//	temp = itoa(student_num);
	if(student_num == 1)
		temp = "1";
	else if(student_num == 2)
		temp = "2";
	else if(student_num == 3)
		temp = "3";
	write_file("/daemon/class/huashan/FENG", temp, 1);
}
