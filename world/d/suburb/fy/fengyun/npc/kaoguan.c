// teacher.c

inherit NPC;

void create()
{
	set_name("王仁德", ({ "kaoguan", "kao" }) );
	set("title", "御封考官");
	set("gender", "男性" );
	set("age", 47);
	set("int", 26);
	set("long",
		"王仁德是个博学多闻的御封考官，他年轻时曾经中过举人，但是\n"
		"因为生性喜爱年青人不愿做官，王仁德以监考为业，如果你愿学\n"
		"王仁德总是会教的．\n");
	set("attitude", "peaceful");
	set_skill("literate", 40);
	setup();
}

int recognize_apprentice(object ob)
{
	return 1;
}
