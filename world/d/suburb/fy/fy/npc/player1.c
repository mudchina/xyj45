// 
// 

inherit NPC;
int custom();
void create()
{
        set_name("蓝小云", ({ "wang" }) );
        set("gender", "女性" );
        set("age", 39);
	set("combat_exp", 1517131);
	set("nickname","九阴邪女");
	set("title","九阴派第八十二代弟子");
        set("chat_chance", 2);
        set("chat_msg", ({
		(: custom :)	
        }) );

        set("attitude", "friendly");
	set("max_force",1226);
	set("force",1226);
	set("force_factor",162/10);
	set("atman",731);
	set("mana",592);	
	set_skill("unarmed",150);
	set_skill("nine-moon-claw",118);
	map_skill("unarmed","nine-moon-claw");
	set_skill("dodge",199);
	set_skill("five-steps",99);
	map_skill("dodge","five-steps");
        setup();
        carry_object("/obj/cloth")->wear();

}

int custom()
{
command("hi");
return 1;
}
