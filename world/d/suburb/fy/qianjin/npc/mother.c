// mother.c

inherit NPC;

void create()
{
	set_name("俏鸨母", ({ "mother" }) );
	set("gender", "女性" );
	set("age", 39);
	set("str", 10);
	set("per", 6);
	set("long", @LONG
    鸨母是个浓妆艳抹的中年女子，身材微胖，全身上下珠光宝气。
LONG
);
	set("combat_exp", 10);
	set("attitude", "friendly");
       set("chat_chance", 5);
        set("chat_msg", ({
"鸨母拉了拉你的衣角，悄悄说道：拿来，我给你找个最好的．\n",
                (: random_move :)
        }) );

	set_skill("unarmed", 100);
	set_skill("parry", 50);

	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
		"鸨母说道：你当这里是什么地方，敢来这里骚扰？\n",
	}) );
	setup();
	
	carry_object(__DIR__"obj/color_cloth")->wear();
	carry_object("/obj/toy/poison_dust.c");
}

