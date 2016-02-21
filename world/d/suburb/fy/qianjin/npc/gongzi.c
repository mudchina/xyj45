// beggar.c

inherit NPC;

void create()
{
        set_name("雅公子", ({ "gongzi" }) );
        set("gender", "男性" );
        set("age", 20);
        set("long", "一个手摇摺扇，自命风流的家伙\n");
        set("combat_exp", 10000);
        set("str", 27);
        set("force", 200);
	set("attitude", "friendly");
        set("max_force", 200);
        set("force_factor", 2);

        set("chat_chance", 5);
        set("chat_msg", ({
"雅公子望着竹桥下的花海吟道：芳心一点娇无力，倩影三更月有痕．\n",
"雅公子摇头自叹道：湖上女，我猜不出．．．\n",
        }) );
        set("inquiry", ([
                "湖上八娇" : "哦，她们都住在荷花荡上\n",
		"湖上女" : "唉！她让我悟出那两句诗之时去找她．\n",
		"nu" : "唉！她让我悟出那两句诗之时去找她．\n",
        ]) );
	set_skill("dodge",50);
	set_skill("parry",50);
	set_skill("dagger",50);
        setup();
        carry_object(__DIR__"obj/fycloth")->wear();
	carry_object(__DIR__"obj/zheshan")->wield();
}

int accept_object(object me, object obj)
{
        command("smile");
        command("say 多谢这位" + RANK_D->query_respect(me) + 
"，您一定会在这儿玩的开心的！");
        return 1;
}
