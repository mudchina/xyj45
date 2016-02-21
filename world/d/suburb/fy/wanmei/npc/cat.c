inherit NPC;
void create()
{
    set_name("小猫咪", ({ "catty" }) );
        set("race", "野兽");
        set("age", 1);
        set("gender", "雌性");
        set("long", "一只小小的，猫头猫脑的小花猫\n");
    	set("combat_exp", 1000);
        set("attitude","peaceful");
        set("limbs", ({ "头部", "身体","尾巴" }) );
    	set("verbs", ({ "bite","claw" }) );
        set_temp("apply/dodge", 100);
	set("chat_chance", 7);
        set("chat_msg", ({
	(: random_move :)
        }) );
        set("arrive_msg", "跳了过来");
        set("leave_msg", "＂喵～＂的一声，跳开了");
        setup();
}
