// tao_2.c

inherit NPC;

void create()
{
        set_name("僵尸护法", ({ "tfighter" }) );
        set("nickname", "僵尸护法");
        set("gender", "男性");
        set("age", 32);
        set("long",
                
"僵尸护法是茅山派的护法，着一身黑色的道袍\n"
);
        set("combat_exp", 2000);
        set("score", 200);

        set("class", "taoist");

        set("str", 20);
        set("int", 30);
        set("cor", 20);
        set("cps", 30);
        set("spi", 30);
        set("pursuer", 1);

        set("force", 150);
        set("max_force", 150);
        set("force_factor", 5);

        set("atman", 150);
        set("max_atman", 150);

        set("mana", 300);
        set("max_mana", 300);
        set("mana_factor", 5);

        set("inquiry", ([
                "谷衣心法": 
"谷衣心法是我茅山派为对抗邪魔外道所创的内功心法。\n",
                "茅山派": 
"我茅山派自张天师开山立派至今，世世代代皆以降妖伏魔为己任。\n"
        ]) );
        set("chat_chance", 25);
        set("chat_msg", ({
                "僵尸护法说道：我们茅山派实力最强！谁敢欺负我们？\n",
                "僵尸护法对你说道：小心我把你变成僵尸! \n",
                "僵尸护法对你念了一会咒，你不禁毛骨悚然起来...\n",
                (:random_move :)        
        }) ); 

        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: command("你敢惹我，追到天涯海角我都要杀了你！") :),
                (: cast_spell, "drainerbolt" :),
                (: cast_spell, "netherbolt" :),
                (: cast_spell, "feeblebolt" :),
                (: cast_spell, "invocation" :),
                (: command("cast animate on corpse") :),
                (:command("cast animate on corpse") :),         
        }) );

        create_family("茅山派", 6, "弟子");

        set_skill("literate", 10);
        set_skill("magic", 30);
        set_skill("force", 30);
        set_skill("spells", 30);
        set_skill("scratching", 30);
        set_skill("unarmed", 30);
        set_skill("sword", 30);
        set_skill("parry", 30);
        set_skill("dodge", 30);
        set_skill("gouyee", 30);

        set_skill("taoism", 30);
        set_skill("necromancy", 30);    

        map_skill("spells", "necromancy");

        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);

        setup();

        carry_object("/obj/example/sword")->wield();
//        carry_object(__DIR__"obj/taoism_book");
//        carry_object(__DIR__"obj/s_spells_book");
        add_money("gold", 3);

}

int accept_fight(object me)
{
        if( (string)me->query("family/family_name")=="茅山派" ) {
                command("nod");
                command("say 进招吧。");
                return 1;
        }
        command("say 茅山派不和别派的人过招。");
        return 0;
}
 
