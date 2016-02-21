// 
// 

inherit NPC;
int custom();
void create()
{
        set_name("诸葛十一", ({ "elv" }) );
        set("gender", "男性" );
        set("age", 42);
	set("combat_exp", 4720306);
	set("nickname","抽刀断水");
	set("title","振远镖局第二代大弟子");
        set("chat_chance", 2);
        set("chat_msg", ({
		(: custom :)	
        }) );

        set("attitude", "friendly");
	set("max_force",1460);
	set("force",2389);
	set("force_factor",231/10);
	set("atman",1300);
	set("mana",2800);	
	set_skill("unarmed",150);
	set_skill("celestrike",100);
	map_skill("unarmed","celestrike");
	set_skill("dodge",200);
	set_skill("five-steps",100);
	map_skill("dodge","five-steps");
        setup();
        carry_object("/obj/cloth")->wear();

}

int custom()
{
command("club");
return 1;
}
