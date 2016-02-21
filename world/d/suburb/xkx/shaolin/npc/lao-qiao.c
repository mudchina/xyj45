// lao-qiao.c ÇÇÈý»±

inherit NPC;

void create()
{
	set_name("ÇÇÈý»±", ({ "lao qiao", "qiao" }));
	set("gender", "ÄÐÐÔ");
	set("age", 55 );

	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set("kee", 400);
	set("max_kee", 400);
	set("eff_kee", 400);
	set("gin", 300);
	set("max_gin", 300);

	setup();

}
	
