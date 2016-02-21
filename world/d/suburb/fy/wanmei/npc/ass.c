inherit NPC;
void create()
{
        set_name("冷血刺客", ({ "hitman", "man" }) );
        set("gender", "男性");
        set("age", 34+random(20));
        set("long",
"这是一个面目不清的刺客．．．\n"
               ); 

        set("attitude", "peaceful");
        set("combat_exp", 1000000);
        set("chat_chance", 10);
        set("chat_msg", ({
                "刺客骂道：这么厉害！ 这回可要提头见教主了！\n",
		(: random_move :)
        }) );
        set_skill("sword", 150);
        set_skill("dodge", 80);
	set_skill("move", 150);
        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
               (: random_move :) 
        }) );

        set("arrive_msg", "＂嗖＂的一声蹿了过来");
        set("leave_msg", "＂嗖＂的一声，消失了");
        setup();
	carry_object(__DIR__"obj/kcloth")->wear();
	carry_object(__DIR__"obj/ksword")->wield();
}

void init()
{
        remove_call_out("hunting");
        call_out("hunting",1);
}
void hunting()

{
 object tar;
if(objectp(tar=present("master ximen",environment())))
{
	command("say 你老婆被陆小凤抢了，现在他又叫我来杀了你，他就可以和你老婆
无忧无虑了！哈哈哈！\n");
	kill_ob(tar);
}

}
