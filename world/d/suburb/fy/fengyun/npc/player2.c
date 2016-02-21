// 
// 

inherit NPC;
int custom();
void create()
{
        set_name("花仙", ({ "jiao" }) );
        set("gender", "女性" );
        set("age", 30);
	set("combat_exp", 1064180);
	set("nickname","妖女");
	set("title","风云一刀第三代弟子");
        set("chat_chance", 2);
        set("chat_msg", ({
		(: custom :)	
        }) );

        set("attitude", "friendly");
	set("max_force",1270);
	set("force",1226);
	set("force_factor",159/10);
	set("atman",731);
	set("mana",592);	
	set_skill("unarmed",150);
	set_skill("bloodystrike",130);
	map_skill("unarmed","bloodystrike");
	set_skill("dodge",199);
	set_skill("five-steps",99);
	map_skill("dodge","five-steps");
        setup();
        carry_object("/obj/cloth")->wear();

}

int custom()
{
command("smile");
return 1;
}
