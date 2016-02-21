// 
// 

inherit NPC;
int custom();
void create()
{
        set_name("蝠王", ({ "bat" }) );
        set("gender", "女性" );
        set("age", 33);
	set("combat_exp", 4665677);
	set("title","风云一刀第三代弟子");
	set("nickname","杀官造反");
        set("chat_chance", 2);
        set("chat_msg", ({
		(: custom :)	
        }) );

        set("attitude", "friendly");
	set("max_force",1460);
	set("force",2389);
	set("force_factor",100/10);
	set("atman",1300);
	set("mana",2800);	
	set_skill("unarmed",150);
	set_skill("celestrike",129);
	map_skill("unarmed","celestrike");
	set_skill("dodge",200);
	set_skill("five-steps",101);
	map_skill("dodge","five-steps");
        setup();
        carry_object("/obj/cloth")->wear();

}

int custom()
{
command("sigh");
return 1;
}
