// worker.c

inherit NPC;

void create()
{
        set_name("看门卫兵", ({ "gateman" }) );
        set("gender", "男性" );
        set("age", 52);
        set("long", "这个卫兵大约五十出头，一部花白的络腮胡子，苍老的脸盘上有好几道\n"
        "刀疤，一看就是从死人堆里爬出来的老兵油子，通红的酒糟鼻子，死样\n"
        "活气的眼神，都表明他现在最关心的不是别的，只是腰间的那个银酒壶!!\n");

        set("combat_exp", 20000);
        set("attitude", "heroism");
        set_skill("unarmed", 80);
        set_skill("parry", 80);
	set_skill("dodge", 80);
	set_skill("sword",80);
        set("chat_chance", 15);
        set("chat_msg", ({
                (:random_move :)
        }) );
	setup();
	add_money("silver", 2);
        carry_object("/obj/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
        
}
