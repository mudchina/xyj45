// 
// 

inherit NPC;
int give_him();
void create()
{
	set_name("穿开裆裤的小孩儿", ({ "boy","little boy" }) );
	set("gender", "男性" );
	set("age", 5);
	set("combat_exp", 5);
	set("attitude", "friendly");
	set("per",2);
	set("arrive_msg", "歪歪扭妞地爬了过来");
	set("leave_msg", "歪歪扭妞地爬开了");
        set("chat_chance", 15);
        set("chat_msg", ({
		                (: random_move :)
        }) );
        set("inquiry", ([
                "开裆裤" : (: give_him :),
		"kaidang" : (: give_him :),
        ]));
	setup();
}
int give_him()
{
	object me , obj;
	me = this_player();
	if( !query("given")) {
	obj = new(__DIR__"obj/kaidang");
	message_vision("$N将开裆裤脱下来，给了$n。\n",this_object(), me);
	obj->move(me);
	set("given",1);
	return 1;
	}
	return 0;
}

void reset()
{
delete("given");
}

