// 
// 

inherit NPC;
int custom();
void create()
{
        set_name("管零", ({ "yano" }) );
        set("gender", "男性" );
        set("age", 35);
	set("combat_exp", 1607996);
	set("nickname",".");
	set("title","风云一刀第三代弟子");
        set("chat_chance", 2);
        set("chat_msg", ({
		(: custom :)	
        }) );

        set("attitude", "friendly");
	set("max_force",1460);
	set("force",2389);
	set("force_factor",180/10);
	set("atman",1300);
	set("mana",2800);	
	set_skill("unarmed",150);
	set_skill("meihua-shou",100);
	map_skill("unarmed","meihua-shou");
	set_skill("dodge",200);
	set_skill("five-steps",100);
	map_skill("dodge","five-steps");
        setup();
        carry_object("/obj/cloth")->wear();

}

int custom()
{
command("oath tin");
return 1;
}
