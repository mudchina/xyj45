// Killer-s.c ,No greeting, 武当功夫, 南门
inherit NPC;

void create()
{
	set_name("杀手", ({"killer"}));
	set("long",
	"这是一个身材高大的江湖人，两臂粗壮，膀阔腰圆，看起来似乎不怀好意。\n"
	);

	set("gender", "男性");
	set("attitude", "aggressive");
	set("class", "taoist");

	set("age", 20+random(30));
	set("shen_type", 1);

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

        set("startroom","/d/suburb/fy/city/nanmen");

	set_skill("force", 20+random(80));
	set_skill("taiji-shengong",20+random(80));
	set_skill("dodge", 20+random(60));
	set_skill("tiyunzong", 20+random(60));
	set_skill("unarmed", 20+random(100));
	set_skill("taiji-quan",10+random(110));
	set_skill("parry", 20+random(80));
	set_skill("sword", 20+random(100));
	set_skill("taiji-jian", 10+random(110));

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
	map_skill("unarmed", "taiji-quan");

	set("chat_chance", 20);
	set("chat_msg", ({
		"杀手说道: 这次看那些玩家们往哪儿跑。\n",
		"杀手说道: 杀! 杀! 杀!!!。\n",
		(: random_move :)
	}) );

	setup();

	carry_object("/d/suburb/fy/city/obj/gangjian")->wield();
