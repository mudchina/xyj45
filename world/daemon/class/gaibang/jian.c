// sample master.c code
// xiake island master.c

inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
	set_name("简长老", ({"jian zhanglao", "jian", "zhanglao"}));
	set("title", "丐帮九袋长老");
	set("nickname", "执法长老");
	set("gender", "男性");
	set("age", 50);
	set("long", 
		"简长老是丐邦的执法长老，代帮主执掌法刀以及青竹令等。\n"
		"他向来嫉恶如仇，弟子中有谁犯过，出手决不容情。\n");

	set("attitude", "peaceful");
	
	set("str", 24);
	set("int", 20);
	set("con", 24);
	set("dex", 20);

	set("kee", 900);
	set("max_kee", 900);
	set("gin", 100);
	set("max_gin", 100);
	set("force", 1500);
	set("max_force", 1500);
	set("jiali", 100);
	
	set("combat_exp", 100000);
	set("score", 20000);
	
	set_skill("force", 95); // 基本内功
	set_skill("huntian-qigong", 90); // 混天气功
	set_skill("unarmed", 90); // 基本拳脚
	set_skill("xianglong-zhang", 85); // 降龙十八掌
	set_skill("dodge", 90); // 基本躲闪
	set_skill("xiaoyaoyou", 95); // 逍遥游
	set_skill("parry", 85); // 基本招架
	set_skill("staff", 90); // 基本棍杖
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	
	create_family("丐帮", 18, "九袋长老");
	setup();
}

void init()
{
        object ob;
	mapping myfam;
        
        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
		myfam = (mapping)ob->query("family");
		if ((!myfam || myfam["family_name"] != "丐帮") &&
			(!wizardp(ob))) {
			remove_call_out("saying");
			call_out("saying",2,ob);
		}
        }
}

void saying(object ob)
{
        if (!ob || environment(ob) != environment())
                return;

	message_vision("\n简长老看了$N一眼，冷冷地说到：“洪帮主他老人家说我不该"
	    "随意责打丐帮弟子，\n你又不属我丐帮，我打你总可以吧？”\n"
	    "说完右腿一抬，$N顺势应了一招青城派的「屁股向后，平沙落雁式」"
	    "－－叭叽\n\n", ob);
	remove_call_out("kicking");
	call_out("kicking",1,ob);
	
}

void kicking(object ob)
{
        if (!ob || environment(ob) != environment())
                return;

	ob->move("/d/suburb/xkx/city/pomiao");
	 message("vision","只听“嘭”地一声，紧接着" +  ob->query("name") +
		"从小门里飞了出来，屁股上有一个清楚的鞋印。\n", environment(ob), ob);
}

void attempt_apprentice(object ob)
{
	command("say 老夫不收徒弟，" + RANK_D->query_respect(ob) + "还是请回吧。");
}
