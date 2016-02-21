
inherit NPC;

void create()
{
	set_name("白颈灰熊", ({ "bear", "big bear" }) );
	set("race", "野兽");
	set("gender", "雄性");
	set("age", 20);
	set("long", "这是一只凶猛无比的灰色熊\n");
	
	set("str", 48);
	set("cor", 52);
	set("cps", 22);

	set("max_kee", 600);
	set("max_gin", 600);
	set("max_sen", 900);
	set("attitude", "aggressive");
	set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

		set("combat_exp", 20000);
		set("bellicosity", 3000 );
	
	set_temp("apply/attack", 100);
	set_temp("apply/armor", 220);
	set_temp("apply/damage", 100);
	setup();
}
