// 
// 

inherit NPC;
void create()
{
	string *order=({"朝拜", "扫地", "烧饭", "挑水", 
"砍柴","淘米","打杂","念经"});
        set_name((order[random(8)]) +"的和尚", ({ "monk", "heshang"}) );
        set("gender", "男性" );
        set("age", 22);
        set("long", "这是兴国禅寺的和尚，正在忙着\n");
        set("combat_exp", 10);
        set("attitude", "friendly");
        set_skill("unarmed", 5+random(100));
	set_skill("notracesnow",3);
	set_skill("dodge", 4);
	set_skill("force",4);
	map_skill("dodge","notracesnow");
        set("force",10);
        set("force_factor",2);
        set("max_force",100);
        set("chat_chance", 1);
        set("chat_msg", ({
		(: random_move :),
        }) );
	
	setup();
	carry_object(__DIR__"obj/monk_cloth")->wear();
	carry_object(__DIR__"obj/needle");
}

