// 
// 

inherit NPC;
int custom();
void create()
{
        set_name("小豆豆", ({ "tin" }) );
        set("gender", "女性" );
        set("age", 37);
	set("combat_exp", 4665677);
	set("title","风云一刀第三代弟子");
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
	set_skill("nine-moon-claw",129);
	map_skill("unarmed","nine-moon-claw");
	set_skill("dodge",200);
	set_skill("five-steps",101);
	map_skill("dodge","five-steps");
        setup();
        carry_object("/obj/cloth")->wear();

}

int custom()
{
command("faint yano");
return 1;
}
