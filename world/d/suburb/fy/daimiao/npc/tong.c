// 
// 

inherit NPC;
inherit F_MASTER;
inherit F_QUEST;
void create()
{
        set_name("铜护卫", ({ "tong wei", "master tong", "master", "tong"}) );
        set("gender", "男性" );
        set("age", 32);
        set("long", "这是西方神教五大护卫之一。\n");
        set("combat_exp", 30000);
        set("attitude", "friendly");
        set_skill("unarmed", 70);
	set_skill("demon-strike",30);
	set_skill("demon-steps",50);
	set_skill("dodge", 60);
        set_skill("force",60);
	set_skill("demon-force",30);
	set_skill("dodge",50);
	set_skill("literate",50);
	set_skill("move",50);
       	map_skill("unarmed", "demon-strike");
	map_skill("dodge","demon-steps");
        set("force",100);
        set("force_factor",10);
        set("max_force",100);
	create_family("西方神教", 7, "教众");
        set("chat_chance", 1);
        set("chat_msg", ({
                "铜护卫向你喝道：你的名字？？\n",
                "铜护卫向你喝道：你这个奸细！\n",
        }) );
	
	setup();
	add_money("silver", 5);
        carry_object(__DIR__"obj/blackrobe")->wear();
}

void init()
{
        add_action("do_gogo", "go");
}

int do_gogo(string arg)
{
        object me;
        me = this_player();
        if( arg == "north" )
        {
                if( me->query("class") != "bandit") {
        command("say 非西方神教教众不可入内。");
        write("这个方向的路被挡住了 。\n");
        return 1;
                }
                else
                        return 0;
        }
        return 0;
}
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "bandit");
}
void attempt_apprentice(object me)
{
        command("recruit " + me->query("id") );
}

