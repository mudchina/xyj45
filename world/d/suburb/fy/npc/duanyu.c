// duanyu.c 段誉

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("段誉", ({"duan yu", "duan", "yu"}));
	set("nickname", GRN"大理王子"NOR);
	set("gender", "男性");
	set("age", 20);
	set("long", 
		"他是一个身穿青衫的年轻男子。脸孔略尖，自有一股书生的呆气。\n");
	set("attitude", "peaceful");
	
	set("str", 12);
	set("int", 30);
	set("con", 30);
	set("per", 30);

	set("chat_chance", 1);
	set("chat_msg", ({
		"段誉叹了口气道：“唉……何时能再见到语嫣啊……”\n",
		(: random_move :),
	}));

	set("inquiry", ([
		"大理" : "大理是个好地方，山清水秀，风景宜人。\n",
		"王语嫣" : "唉，她心里只有她表哥，从来就没把我放在眼里。\n",
		"拜师" : "嗯....，我的师傅是老子、孔子和庄子，他们的学问我还没学全呢。\n",
	]));

	set("gin", 2000);
	set("max_gin", 2000);
	set("atman", 2000);
	set("max_atman", 2000);
	set("kee", 2000);
	set("max_kee", 2000);
	set("force", 4000);
	set("max_force", 4000);
	set("force_factor",200);
	
	set("combat_exp", 500000);
	set("score", 20000);
	 
	set_skill("force", 100);		// 基本内功
	set_skill("beiming-shengong", 100);	// 北冥神功
	set_skill("finger", 120);		// 基本指法
	set_skill("sword", 120);		// 基本剑法
	set_skill("liumai-shenjian", 120);	// 六脉神剑
	set_skill("dodge", 150);		// 基本躲闪
	set_skill("lingboweibu", 150);		// 凌波微步
	set_skill("parry", 80);			// 基本招架
	
	map_skill("sword", "liumai-shenjian");
	map_skill("force", "beiming-shengong");
	map_skill("dodge", "lingboweibu");
	map_skill("parry", "liumai-shenjian");
	map_skill("finger", "liumai-shenjian");
//	prepare_skill("finger","liumai-shenjian");
	
	setup();
	
	carry_object("/d/suburb/fy/city/obj/gangjian");
	carry_object("/obj/cloth")->wear();
}
