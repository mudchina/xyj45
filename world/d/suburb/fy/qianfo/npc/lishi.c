inherit NPC;
void create()
{
        set_name("力士", ({ "lishi","力士" }) );
        set("gender", "男性" );
        set("class", "bonze");
        set("str", 26);
        set("long", "面貌雄伟，作忿怒相，上半身赤裸，两脚张开，呈紧张状．\n");
        set("combat_exp", 6000);
        set("attitude", "friendly");
        set("max_force", 500);
        set("force", 500);
	set("max_sen",1);
	set("sen",1);
        set("force_factor", 5);
	set("no_shown",1);
        set_skill("force", 60);
        set_skill("unarmed", 500);
        set_skill("dodge", 60);
        setup();
        carry_object(__DIR__"obj/hat");
        carry_object(__DIR__"obj/staff");
}

int accept_fight(object me)
{
        return 0;
}
void init()
{
add_action("do_look","look");
}

int do_look(string arg)
{

if (arg == "lishi" || arg == "力士")
{
write("面貌雄伟，作忿怒相，上半身赤裸，两脚张开，呈紧张状．\n");
return 1;
}
return 0;
}

