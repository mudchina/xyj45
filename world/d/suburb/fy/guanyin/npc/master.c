inherit NPC;
inherit F_MASTER;
inherit F_QUEST;

int kill_him();
void create()
{
	set_name("石观音", ({ "master guanyin", "master","guanyin" }) );
	set("gender", "女性" );
	set("age", 25);
	set("int", 30);
	set("str",60);
	set("per", 30);
	set("agi",100);
        set("apprentice_available", 50);
        create_family("天枫派", 2, "掌门");
	set("long",
"石观音的美丽，竟已是今人不能想象的，因为她的美丽已全部占据了
人们的想象力。有很多人都常用“星眸”来形容女子的美丽，但星光又怎
及她这双眼睛的明亮与温柔。有很多人都常用“春山”来形容美女的眉，
但纵是雾里朦胧的春山也不及她秀眉的婉约。
"
		);
        set("force_factor", 400);
        set("chat_chance", 2);
        set("chat_msg", ({
                "石观音道：“你......你不觉我老？”\n",
                "石观音笑了笑，又道：“你可知道这里是什么地方？”\n",
		"石观音眼光突然朦胧，柔声道：“你既知道，为何还不过来？”\n",
        }) );

        set("max_gin", 3000);
        set("max_kee", 3000);
        set("max_sen", 3000);
        set("eff_gin", 3000);
        set("eff_kee", 3000);
        set("eff_sen", 3000);
        set("gin", 3000);
        set("kee", 3000);
        set("sen", 3000);
        set("max_atman", 300);
        set("atman", 300);
        set("max_force", 3000);
        set("force", 3000);
        set("max_mana", 300);
        set("mana", 300);
        set("agi",25);
        set("int",30);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.yaozhan" :),
        }) );
        set("combat_exp", 99999999);
        set("inquiry", ([
                "无花" : (: kill_him :),
                "李姑娘" : (: kill_him :),
                "李琦" : (: kill_him :),
                "天枫十四郎" : (: kill_him :),
                "南宫灵" : (: kill_him :),

        ]));
        set_skill("unarmed", 100);
        set_skill("blade", 150);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("literate", 100);
	set_skill("dodge", 100);

	set_skill("kongshoudao", 100);
	set_skill("wind-blade", 130);
	set_skill("ghosty-force", 150);
	set_skill("ghosty-steps", 100);

	map_skill("unarmed", "kongshoudao");
        map_skill("blade", "wind-blade");
        map_skill("force", "ghosty-force");
        map_skill("parry", "wind-blade");
        map_skill("dodge", "ghosty-steps");

	setup();
	carry_object(__DIR__"obj/whitecloth")->wear();
        carry_object(__DIR__"obj/mblade");
}
void reset()
{
        delete_temp("learned");
        set("apprentice_available", 20);
}
void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say 慢著，一个一个来。");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say 本掌门今天已经收了二十个弟子，不想再收徒了。");
        }
}
void do_recruit(object ob)
{
                command("smile");
                command("say 你日后可要多多努力！");
                command("smile");
                command("recruit " + ob->query("id") );
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "bandit");
        add("apprentice_availavble", -1);
}

void init()
{
        add_action("give_quest", "quest");
}
void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 32000 ) {
                student->set("title","天枫派弟子");
                return ;
        } else if ( exp <= 128000 ) {
                student->set("title","天枫派小魔");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","天枫派少魔");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","天枫派大魔");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","天枫派奇魔");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","天枫派长老");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","天枫派元老");
                return ;
        } else
                student->set("title","天枫派副掌门");
                return ;
}

int kill_him()
{
        object me;
        me = this_player();
        command("say 看来你已经知道我的来历了！！ \n");
        this_object()->kill_ob(me);
        me->kill_ob(this_object());
        return 1;
}

