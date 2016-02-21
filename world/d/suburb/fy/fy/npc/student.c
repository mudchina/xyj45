
inherit NPC;

void create()
{
        set_name("考生", ({ "student", "sheng"}) );
        set("gender", "男性" );
        set("age", 12);
        set("long", "这是一位正在考试的考生。\n");
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set_skill("hammer", 90);
	set_skill("dodge", 100);
        set("iron-cloth", 200);
        set("chat_chance", 1);
        set("chat_msg", ({
                "考生抬起头，四下望了一眼．．．\n",
        }) );
	
	setup();
	add_money("silver", 1);
        carry_object(__DIR__"obj/fycloth")->wear();
}

