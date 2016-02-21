// 
// 

inherit NPC;
void create()
{
        set_name("风清", ({ "fengqing" }) );
        set("gender", "男性" );
        set("class", "bonze");
	set("title","兴国禅寺风字辈大师");
        set("age", random(40)+20);
        set("cor", 24);
        set("cps", 29);
        set("int", 25);
        set("long", "他是兴国禅寺中颇有威望的风字辈大师\n");
        set("combat_exp", 6);
        set("attitude", "friendly");
        set("max_force", 500);
        set("force", 500);
        set("force_factor", 5);
        set("chat_chance", 1);
        set("chat_msg", ({
                "风清看了看自己的断腿，苦笑了一下。\n",
        }) );
        set("inquiry", ([
                "断腿" : "我的腿是在火沼中被一把喷火的刀砍断的。\n",
                "leg" : "我的腿是在火沼中被一把喷火的刀砍断的。\n",
	]));
        setup();
        carry_object(__DIR__"obj/monk_cloth")->wear();
        carry_object(__DIR__"obj/shoe2")->wear();
}
int accept_fight(object me)
{
        command("say 阿弥陀佛！贫僧武功低微，施主不要开这种玩笑。\n");
        return 0;
}
