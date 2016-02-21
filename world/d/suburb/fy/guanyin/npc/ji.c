inherit NPC;

void create()
{
        set_name("姬冰雁", ({ "bingyan" }) );
        set("gender", "男性" );
        set("age", 42);
	set("str",40);
        set("long",
                "楚留香的死党，很有风度的姬冰雁\n");
	set("combat_exp", 7000000);
        set("chat_chance", 2);
        set("chat_msg", ({
                "姬冰雁道：他真的是这么说的！！\n",
		"姬冰雁道：你死，他也死！\n",
        }) );

        set("attitude", "friendly");
        setup();
        carry_object(__DIR__"obj/bcloth2")->wear();

}
