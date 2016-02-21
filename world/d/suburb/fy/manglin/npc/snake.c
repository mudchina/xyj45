
inherit NPC;

void create()
{
        set_name("×Ï°ß¾Şòş", ({ "snake" }) );
        set("race", "Ò°ÊŞ");
        set("age", 15);
        set("long", "Ò»ÌõË®Í°´ÖÏ¸µÄ¾Şòş¡£\n");

        set("limbs", ({ "Í·²¿", "ÉíÌå", "Î²°Í", "Æß´ç" }) );
        set("verbs", ({ "bite" }) );
        set("attitude", "aggressive");
        set_skill("dodge", 150);
        set("combat_exp", 999999);
	set("bellicosity", 30000 );
	set_temp("apply/attack",200);
	set_temp("apply/damage",100);
        setup();
}
