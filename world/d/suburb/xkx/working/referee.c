// referee.c

inherit NPC;

void create()
{
	set_name("公平子", ({ "gongping zi", "zi", "referee" }) );
	set("gender", "男性");
	set("age", 35);
	set("long",
		"这是一位仙风道骨的中年道人，早年云游四方，性好任侠，公正无私。\n");
	set("combat_exp",60000);
        set("shen_type", 1);
	set("attitude", "friendly");

	set("apply/attack", 50);
	set("apply/defense", 50);

	set("max_kee", 800);
	set("max_gin", 800);
	set("max_force", 800);

	set_skill("force", 80);
	set_skill("unarmed", 80);
	set_skill("parry",80);
	set_skill("dodge", 80);

	setup();
        carry_object("/d/obj/clone/misc/cloth")->wear();
}

void init()
{
        ::init();	
        add_action("do_bihua", "bihua");
}

int do_bihua(string arg)
{     
	object ob1, ob2;
	ob1 = this_player();

	if( !arg || arg=="" ) return 0;

	if ( this_object()->query_temp("busy") ) 
		return notify_fail("每次只能有两人参加比武。\n");

        if (!ob2 = present(arg,environment(ob1)) ) 
		return notify_fail("你想跟谁比划？\n");

	remove_call_out("check");
	call_out("check",0, ob1, ob2);

	remove_call_out("fighting");
	call_out("fighting",2, ob1, ob2);
}

void fighting(object ob1, object ob2)
{
	ob1->fight_ob(ob2);
	ob2->fight_ob(ob1);
}

void check(object ob1, object ob2)
{
	this_object()->set_temp("busy",1);
	command("chat 现在由" + ob1->query("name") 
		+ "与" + ob2->query("name") + "开始比武较艺！\n");
	call_out("observe",1,ob1,ob2);
}

int observe(object ob1,object ob2)
{
	object ob;

	if(ob1->is_fighting()) 
	{
		call_out("observe",1,ob1,ob2);
		return 1;
	}

	if (ob1->query("kee")*100/ob1->query("max_kee") > 50 ) 
	{
		command("chat " + ob1->query("name") 
			+ "比武战胜" + ob2->query("name") + "！\n");
		ob = new("/d/obj/clone/money/silver");
		ob->move(ob1);
	}
	else
	{
		command("chat " + ob2->query("name") 
			+ "比武战胜" + ob1->query("name") + "！\n");
		ob = new("/d/obj/clone/money/silver");
		ob->move(ob2);
	}
	
	this_object()->delete_temp("busy");
	return 1;

}
