
inherit NPC;

void create()
{
        set_name("镖师", ({ "biaoshi", "bian"}) );
        set("gender", "男性" );
        set("age", 32);
        set("long", "这是一位高达六尺的镖师。\n");
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set_skill("hammer", 90);
	set_skill("dodge", 100);
        set("iron-cloth", 200);
        set("chat_chance", 10);
        set("chat_msg", ({
                "镖师又将手中的石锁一口气连举了七八十下。\n",
                "镖师望了望自己粗壮的胳膊，又捏了两下，脸上露出得意之色。\n",
        }) );
	
	setup();
	add_money("silver", 50);
        carry_object(__DIR__"obj/jinzhuang")->wear();
	carry_object(__DIR__"obj/stonehammer")->wield();
}

