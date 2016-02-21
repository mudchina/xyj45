// wander.c

inherit NPC;

void create()
{
        set_name("流氓", ({ "wander" }) );
        set("gender", "男性" );
        set("age", 22);
        set("long", "这个流氓衣襟半敞，歪戴着一顶毡帽，跽着一双破布鞋，正在向你\n"
        "上下打量，贼眉鼠眼，不怀好意。\n");

        set("combat_exp", 5000);
        set("attitude", "heroism");
        set_skill("unarmed", 60);
        set_skill("parry", 60);
	set_skill("dodge", 60);
        set("chat_chance", 15);
        set("chat_msg", ({
                (:random_move :)
        }) );
	setup();
	add_money("silver", 1);
        carry_object("/obj/cloth")->wear();
        
}
