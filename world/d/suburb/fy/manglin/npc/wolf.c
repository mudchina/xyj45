
inherit NPC;

void create()
{
	set_name("灰毛恶狼", ({ "wolf", "big wolf" }) );
	set("race", "野兽");
	set("gender", "雄性");
	set("age", 20);
	set("long", "这是一只凶猛无比的灰色恶狼\n");
	
	set("str", 48);
	set("cor", 52);
	set("cps", 22);

	set("max_kee", 600);
	set("max_gin", 600);
	set("max_sen", 900);
	set("attitude", "aggressive");
	set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("chat_chance_combat", 1);
        set("chat_msg_combat", ({
                "恶狼向天狂嚎几声．\n",
                "恶狼眼里的绿光使你不寒而颤．\n"
        }) );
		set("combat_exp", 20000);
		set("bellicosity", 3000 );
	
	set_temp("apply/attack", 120);
	set_temp("apply/armor", 120);

	setup();
}
