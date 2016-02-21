// teacher.c

inherit NPC;

void create()
{
        int i,amun;
        string *order = ({"张", "王", "李", "赵", "孙", "徐", "郑", "周", "吴",
"蒋", "沈", "杨", "苗", "尹", "金", "魏", "陶", "俞", "柳", "朱"});
	string *orderr = ({"阿发", "拆捌", "裁答", "发胳", "妈唔",
"欧派", "机咖", "腊玛"});
        set_name( order[random(20)] + orderr[random(8)], ({ "shuseng", "seng" }) );
	set("title", "落第书生");
	set("gender", "男性" );
	set("age", random(20)+20);
	set("int", 26);
	set("long",
		"他以教书为业.\n");
        set("chat_chance", 15);
        set("chat_msg", ({
                (: random_move :)
        }) );

	set("attitude", "peaceful");
	set_skill("literate", 40);
	set("combat_exp", random(50));
	set_skill("dodge", random(5));
	setup();
}
