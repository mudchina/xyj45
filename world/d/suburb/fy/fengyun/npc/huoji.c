// kuliman.c

inherit NPC;

void create()
{
        set_name("伙计", ({ "huoji" }) );
        set("gender", "男性" );
        set("age", 22);
        set("long", "这个伙计正在手忙脚乱的往镖车上装载货物. \n");

        set("combat_exp", 1000);
        set("attitude", "heroism");
        set_skill("unarmed", 10);
        set_skill("parry", 10);
	set_skill("dodge", 10);
        set("chat_chance", 25);
	setup();
	add_money("silver", 1);
        carry_object(__DIR__"obj/jinzhuang")->wear();
        
}
