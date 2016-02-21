// 
// 

inherit NPC;
void create()
{
        set_name("锡护卫", ({ "xi wei", "xi"}) );
        set("gender", "男性" );
        set("age", 32);
        set("long", "这是西方神教五大护卫之一。\n");
        set("combat_exp", 80000);
        set("attitude", "friendly");
        set_skill("unarmed", 100);
	set_skill("demon-strike",50);
	set_skill("demon-steps",70);
	set_skill("dodge", 80);
        set_skill("force",80);
       	map_skill("unarmed", "demon-strike");
	map_skill("dodge","demon-steps");
	set("force",100);
	set("force_factor",20);
	set("max_force",100);
	create_family("西方神教", 7, "教众");
        set("chat_chance", 1);
        set("chat_msg", ({
                "锡护卫向你喝道：别乱走动！\n",
                "锡护卫向你喝道：你乱走什么！\n",
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
                if( me->query("family/master_name") != "羽天白") {
        command("say 非教主亲授弟子不可入内。");
        write("这个方向的路被挡住了 。\n");
        return 1;
                }
                else
                        return 0;
        }
        return 0;
}
