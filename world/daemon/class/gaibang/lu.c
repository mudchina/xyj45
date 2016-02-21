// sample master.c code
// xiake island master.c

inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
	set_name("鲁有脚", ({"lu youjiao", "lu", "youjiao"}));
	set("title", "丐帮九袋长老");
	set("nickname", "掌棒龙头");
	set("gender", "男性");
	set("age", 45);
	set("long", 
		"鲁有脚虽然武功算不得顶尖高手，可是在江湖上却颇有声望。\n"
		"因为他在丐帮中有仁有义，行事光明磊落，深得洪七公的器重。\n");
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 12);
	set("con", 25);
	set("dex", 20);

	set("kee", 900);
	set("max_kee", 900);
	set("gin", 100);
	set("max_gin", 100);
	set("force", 1200);
	set("max_force", 1200);
	set("jiali", 100);
	
	set("combat_exp", 100000);
	set("score", 20000);
	
	set_skill("force", 90); // 基本内功
	set_skill("huntian-qigong", 90); // 混天气功
	set_skill("unarmed", 95); // 基本拳脚
	set_skill("xianglong-zhang", 90); // 降龙十八掌
	set_skill("dodge", 90); // 基本躲闪
	set_skill("xiaoyaoyou", 90); // 逍遥游
	set_skill("parry", 90); // 基本招架
	set_skill("staff", 85); // 基本棍杖
	set_skill("begging", 60);
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	
	create_family("丐帮", 18, "九袋长老");
	setup();
}

void attempt_apprentice(object ob)
{
	if ( (int)ob->query("int") >= 25 ) {
		command("say 我们丐帮的武艺一向以刚猛为主，" + 
		RANK_D->query_respect(ob) + "聪慧过人，似乎不宜学丐帮的功夫？");
		return;
	}
	command("say 好吧，希望" + RANK_D->query_respect(ob) +
	"能好好学习本门武功，将来在江湖中闯出一番作为。");
	command("recruit " + ob->query("id"));
}
