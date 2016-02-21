// 
// 

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_QUEST;

void create()
{
        set_name("兴国大师", ({ "master xing", "master", "xing" }) );

        set("gender", "男性");
        set("age", 74);
        set("attitude", "peaceful");
        set("class", "bonze");
        set("apprentice_available", 3);
	set("student_title","大师");
        set("str", 27);
        set("int", 30);
        set("spi", 30);
        set("con", 30);
        set("spi", 30);
        set("con", 30);
        set("cps", 30);
        set("cor", 20);
        set("agi",25);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "staff.longxianyuye" :),
        }) );
        set("atman", 300);
        set("max_atman", 300);
        set("force", 1500);
        set("max_force", 1500);
        set("force_factor", 5);
        set("mana", 300);
        set("max_mana", 300);
        set("combat_exp", 1000000);
        set("score", 9000);
        set_skill("staff", 100);
	set_skill("changquan",100);
        set_skill("unarmed", 120);
        set_skill("force", 100);
        set_skill("dodge", 120);
        set_skill("literate", 80);
        set_skill("chanting", 100);
        set_skill("parry", 120);
        set_skill("magic", 100);
        set_skill("cloudstaff", 100);
        set_skill("lotusforce", 100);
        set_skill("buddhism", 100);
        set_skill("essencemagic", 100);
        set_skill("notracesnow",120);
        map_skill("staff", "cloudstaff");
        map_skill("parry", "cloudstaff");
        map_skill("force", "lotusforce");
        map_skill("magic", "essencemagic");
        map_skill("dodge","notracesnow");
	map_skill("unarmed", "changquan");
        create_family("兴国禅寺", 3, "住持");
        setup();
        carry_object(__DIR__"obj/buddha_staff")->wield();
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
        if( (string)ob->query("gender") != "男性" )
                command("say 阿弥陀佛，女施主不要跟老纳开玩笑。");
        else if(ob->query_temp("marks/ye")){
		ob->set("class","bonze");
		command("say 看在白云城主的份上，我就收你为徒吧！\n");
                command("say 阿弥陀佛，善哉！善哉！");
                command("recruit " + ob->query("id") );
        }
	else if(ob->query_temp("marks/lady")){
                ob->set("class","bonze");
                command("say 看在你不惧生死，见义勇为的份上，我就收你为徒吧！\n");
                command("say 阿弥陀佛，善哉！善哉！");
                command("recruit " + ob->query("id") );
        }
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
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 32000 ) {
                student->set("title","兴国禅寺大师");
                return ;
        } else if ( exp <= 128000 ) {
                student->set("title","兴国禅寺罗汉");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","兴国禅寺金刚");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","兴国禅寺高僧");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","兴国禅寺圣僧");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","兴国禅寺神僧");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","兴国禅寺活佛");
                return ;
        } else
                student->set("title","兴国禅寺副主持");
                return ;

}

