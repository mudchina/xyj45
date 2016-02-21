// farmer.c

inherit NPC;

void create()
{
	set_name("农夫", ({ "farmer" }) );
	set("gender", "男性" );
	set("age", 33);
	set("long", "一位以耕种水稻为生的农夫，拖着沉重的步伐，带着满身的汗水从田中回来。\n");
	set("combat_exp", 20);
	set("attitude", "friendly");
        set("chat_chance", 10);
        set("chat_msg", ({
			(: random_move :)
        }) );
	setup();
	carry_object("/obj/cloth")->wear();
}
