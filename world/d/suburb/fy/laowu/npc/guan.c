
inherit NPC;

void create()
{
        set_name("老屋人", ({ "laowuren"}) );
        set("gender", "男性" );
        set("age", 32+ random(10));
        set("long", "这是一位久居拉哈苏的本地人。\n");
        set("combat_exp", 5000);
        set("attitude", "aggrensive");
        set_skill("unarmed", 30 + random(100));
        set("chat_chance", 10);
        set("chat_msg", ({
                "老屋人用力搓了搓被冻麻的双手\n",
        }) );
	setup();
	add_money("silver", 5);
        carry_object(__DIR__"obj/bigcloth")->wear();
}

