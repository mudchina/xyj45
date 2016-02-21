
inherit NPC;

void create()
{
        set_name("风骚雅人", ({ "yaren", "ren"}) );
        set("gender", "男性" );
        set("age", 22);
        set("long", "这是一位小有才华的雅人，正在追求灵感。\n");
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set_skill("hammer", 90);
	set_skill("dodge", 100);
        set("iron-cloth", 200);
        set("chat_chance", 1);
        set("chat_msg", ({
                "风骚雅人张了张口，又合上了。\n",
                "风骚雅人踱来踱去，似乎正在打腹稿。\n",
        }) );
	
	setup();
	add_money("silver", 5);
        carry_object(__DIR__"obj/fycloth")->wear();
}

