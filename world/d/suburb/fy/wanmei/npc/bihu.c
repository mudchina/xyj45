inherit NPC;
void create()
{
    set_name("壁虎", ({ "bihu" }) );
        set("race", "野兽");
        set("age", 1);
        set("gender", "雌性");
    	set("combat_exp", 1000);
        set("attitude","peaceful");
        set("limbs", ({ "头部", "身体","尾巴" }) );
    	set("verbs", ({ "bite","claw" }) );
        set_temp("apply/dodge", 100);
	set("chat_chance", 7);
        set("chat_msg", ({
	(: random_move :)
        }) );
        setup();
}
