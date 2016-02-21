// mu-ren.c 木人

inherit NPC;
inherit F_CLEAN_UP;

void consider();

void create()
{
	seteuid(getuid());
	set_name("木人", ({ "mu ren", "mu", "wood man", "wood" }) );
	set("gender", "男性" );
	set("age", 30);
	set("long", "一个练功用的比武木人，制作精巧，如同真人一般。\n");
	set("attitude", "heroism");

	set("str", 25);
	set("cor", 25);
	set("cps", 25);
	set("int", 25);

	set("max_kee", 300);
	set("eff_kee", 300);
	set("kee", 300);
	set("max_gin", 100);
	set("gin", 100);
	set("force", 300);
	set("max_force", 300);
	set("jiali", 10);
	set("shen_type", 0);

	set("combat_exp", 50000);

//	set_heart_beat(0);

	set_skill("force", 30); 
	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);

	setup();
        
}

int accept_fight(object ob)
{
	object me;
	mapping hp_status, skill_status, map_status;
	string *sname, *mname;
	int i, me_neili;

	me = this_object();

	if (is_fighting()) return 0;

	hp_status = ob->query_entire_dbase();

		me->set("str", hp_status["str"]);
		me->set("int", hp_status["int"]);
		me->set("con", hp_status["con"]);
		me->set("dex", hp_status["dex"]);

		me->set("max_kee",    hp_status["max_kee"]);
		me->set("eff_kee",    hp_status["eff_kee"]);
		me->set("kee",        hp_status["kee"]);
		me->set("max_gin",  hp_status["max_gin"]);
		me->set("eff_gin",  hp_status["eff_gin"]);
		me->set("gin",      hp_status["gin"]);
		me->set("max_force", hp_status["max_force"]);
//		me->set("force",     hp_status["force"]);
		me->set("jiali",     hp_status["jiali"]);
		me->set("combat_exp",hp_status["combat_exp"]);

	skill_status = ob->query_skills();
	sname  = sort_array( keys(skill_status), (: strcmp :) );

	for(i=0; i<sizeof(skill_status); i++) {
		me->set_skill(sname[i], skill_status[sname[i]]);
	}
	
	command("enable unarmed none");	
	command("enable dodge none");	
	command("enable parry none");	

	map_status = ob->query_skill_map();
	mname  = sort_array( keys(map_status), (: strcmp :) );

	for(i=0; i<sizeof(map_status); i++) {
//		me->map_skill(mname[i], map_status[mname[i]]);
		command("enable " + mname[i] + " " + map_status[mname[i]]);
	}
	
	me->set("force",     hp_status["force"]);

	return 1;
}

int accept_kill(object me)
{
	return 0;
}
