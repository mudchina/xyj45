// 
// 

inherit NPC;
void create()
{
        set_name("丧尽天良的畜生", ({ "pig" }) );
        set("gender", "男性");
        set("age", 24);
	set("str",30);
        set("long",
                "这个人正在光天化日下强奸民女！！！\n");
        set("combat_exp", 6000);
        set("score", 400);
        set("chat_chance", 50);
        set("chat_msg", ({
                "丧尽天良的畜生狞笑着剥下了千金小姐的鞋子．．\n",
		"丧尽天良的畜生狞笑着剥下了千金小姐的袜子．．\n",
		"丧尽天良的畜生狞笑着剥下了千金小姐的．．．．\n",
        }) );
        set_skill("unarmed", 100);
        set_skill("parry", 20);
        set_skill("dodge", 40);
        setup();
}
void init()
{
add_action("do_look","look");
}

int do_look(string arg)
{

if (arg == "pig" )
{
write("这个人正在光天化日下强奸民女！！！\n");
write("他看起来约二十多岁。\n");
write("武功看起来好象深不可测，出手似乎极重。\n");
return 1;
}
return 0;
}

void die()
{
	object me;
	me=this_object()->query_temp("last_damage_from");
	if(objectp(me))
        me->set_temp("marks/lady",1);
::die();
}
