// 
// 

inherit NPC;
inherit F_MASTER;
inherit F_QUEST;

#include <ansi.h>
int kill_him();
void create()
{
        set_name("羽天白", ({ "master yu", "master"}) );
        set("nickname", HIR "万胜刀魔" NOR);
        set("gender", "男性" );
        set("age", 64);
	set("per", 3);
        set("agi",25);
        set("int",30);
	set("attitude","friendly");
        set("max_force", 1500);
        set("force", 1500);
        set("force_factor", 30);
        set("long",
"
羽天白是西方神教中的教主，羽天白的来历谁也不清楚，
也没人敢问。凡是问过或知道羽天白来历的人都不明不白的
消失了。
\n"
	);
        create_family("西方神教", 1, "教主");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "blade.tiandirenmo" :),
                (: perform_action, "dodge.lianhuanbabu" :),
                (: perform_action, "blade.tiandirenmo" :),
                (: exert_function, "mihun" :)
        }) );
        set("combat_exp", 1000000);
        set("score", 200000);

        set_skill("move", 100);
        set_skill("parry",100);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("literate", 80);
	set_skill("unarmed",60);
	set_skill("demon-steps",100);
	set_skill("demon-strike",100);
	set_skill("demon-force",100);
	set_skill("blade",150);
	set_skill("demon-blade",150);
        map_skill("dodge", "demon-steps");
	map_skill("force", "demon-force");
	map_skill("unarmed", "demon-strike");
	map_skill("blade","demon-blade");
	map_skill("parry","demon-blade");
        set("inquiry", ([
                "白天羽" : (: kill_him :),
                "万马堂" : (: kill_him :),
        ]));
        setup();
        carry_object(__DIR__"obj/wufu")->wear();
	carry_object(__DIR__"obj/lou")->wield();

}

void attempt_apprentice(object me)
{
	if(me->query_temp("for_bandit"))
	{
	command("say 好！好！老夫今天可找到块有用之材。\n");
        command("recruit " + me->query("id") );
		return;
	}
	else
	{
	command("sigh");
        command("say 最近本教层出意外，先是罗刹牌被盗，再者副教主被刺。\n");
	command("say 你若有能力察清此事，老夫便收你为徒。\n");

	}
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "bandit");
}
void init()
{
        add_action("give_quest", "quest");
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
int accept_object(object me, object obj)
{
	if(obj->query("for_bandit"))
	{
	me->set_temp("for_bandit",1);
        command("say 好，真是好！真是块可雕之材！\n");
	return 1;
	}
	return 0;
}
void re_rank(object student)
{
	int exp;
	exp = (int) student->query("combat_exp");
	if( exp <= 32000 ) {
		student->set("title","西方神教教徒");
		return ;	
	} else if ( exp <= 64000 ) {
		student->set("title","西方神教副堂主");
		return ;
        } else if ( exp <= 128000 ) {
                student->set("title","西方神教堂主");
                return ;
        } else if ( exp <= 256000 ) {
                student->set("title","西方神教副坛主");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","西方神教坛主");
                return ;
        } else if ( exp <= 1024000 ) {
                student->set("title","西方神教副舵主");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","西方神教舵主");
                return ;
        } else if ( exp <= 2304000 ) {
                student->set("title","西方神教护法");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","西方神教大护法");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","西方神教长老");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","西方神教大长老");
                return ;
        } else 
                student->set("title","西方神教副教主");
                return ;

}

