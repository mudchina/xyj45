
inherit NPC;

void create()
{
	set_name("活佛", ({ "huofe", "huo","fe" }) );
	set("gender", "男性" );
	set("age", 109);
	set("int", 30);
	set("long",
		"塞外活佛，到中原来旅游．\n"
		);
        set("combat_exp", 1000000);
        set("score", 90000);
        set_skill("unarmed", 150);
	set_skill("move", 100);
        set_skill("staff", 150);
        set_skill("force", 150);
        set_skill("parry", 150);
        set_skill("literate", 150);
	set_skill("iron-cloth", 150);
	set_skill("magic", 150);

	set_skill("bloodystrike", 150);
	set_skill("cloudstaff", 150);
	set_skill("bolomiduo", 150);
	set_skill("buddhism", 150);
	set_skill("essencemagic", 150);
        set_skill("jin-gang", 150);


	map_skill("unarmed", "bloodystrike");
        map_skill("force", "bolomiduo");
        map_skill("literate", "buddhism");
        map_skill("iron-cloth", "jin-gang");
        map_skill("magic", "essencemagic");

	setup();
}
