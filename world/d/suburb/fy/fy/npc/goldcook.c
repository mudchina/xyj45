// fatman.c

inherit NPC;

void create()
{
        set_name("大厨", ({ "cook" }) );
        set("gender", "男性" );
        set("age", 42);
        set("long", "这是一个手艺精湛的大厨.\n");

        set("combat_exp", 1000);
        set("attitude", "heroism");
        set_skill("unarmed", 130);
        set_skill("parry", 30);
	set_skill("dodge", 30);
	setup();
	add_money("gold", 1);
        carry_object(__DIR__"obj/jinzhuang")->wear();
	carry_object(__DIR__"obj/luwei");
        
}
