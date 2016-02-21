// 
// 

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_QUEST;

void create()
{
        set_name("定邦大师", ({ "master ding", "master", "ding" }) );

        set("gender", "男性");
        set("age", 74);
        set("attitude", "peaceful");
        set("class", "bonze");
        set("apprentice_available", 3);
	set("student_title","俗家弟子");
        set("str", 27);
        set("int", 30);
        set("spi", 30);
        set("con", 30);
        set("spi", 30);
        set("con", 30);
        set("cps", 30);
        set("cor", 20);
        set("atman", 300);
        set("max_atman", 300);
        set("force", 1500);
        set("max_force", 1500);
        set("force_factor", 5);
        set("mana", 300);
        set("max_mana", 300);
        set("combat_exp", 1000000);
        set("score", 9000);
        set_skill("unarmed", 200);
	set_skill("changquan",120);
        set_skill("force", 100);
        set_skill("dodge", 30);
        set_skill("literate", 60);
        set_skill("chanting", 100);
        set_skill("parry", 50);
        set_skill("lotusforce", 100);
        set_skill("buddhism", 100);
        set_skill("notracesnow",40);
        map_skill("force", "lotusforce");
        map_skill("dodge","notracesnow");
	map_skill("unarmed","changquan");
        create_family("兴国禅寺", 4, "大师");
        setup();
        carry_object(__DIR__"obj/staff")->wield();
	carry_object("/obj/cloth")->wear();
}

void init()
{
        add_action("give_quest", "quest");
}

void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say 慢著，一个一个来。");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say 老纳今天已经收够了弟子，不想再收徒了。");
        }
}

void do_recruit(object ob)
{
                ob->set("class","bonze");
                command("say 阿弥陀佛，善哉！善哉！");
                command("recruit " + ob->query("id") );
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                add("apprentice_availavble", -1);
                return 1;
        }
}

int accept_fight(object me)
{
        if( (string)me->query("class")=="bonze" )
                command("say 阿弥陀佛！出家人戒逞强恶斗！老衲不敢违反清规。");
        else
                command("say 施主既然身负绝艺，老衲佩服便是，也不必较量了。");

        return 0;
}
void re_rank(object student)
{
                student->set("title","兴国禅寺俗家弟子");
                return ;

}

