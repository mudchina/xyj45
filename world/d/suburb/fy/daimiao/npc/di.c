// 
// 

inherit NPC;
inherit F_MASTER;
inherit F_QUEST;

#include <ansi.h>
void create()
{
        set_name("地利老人", ({ "master di", "master"}) );
        set("nickname", HIW "地舵舵主"NOR);
        set("gender", "男性" );
        set("age", 63);
	set("per", 3);
        set("agi",25);
        set("int",30);
	set("attitude","friendly");
        set("max_force", 15000);
        set("force", 15000);
        set("force_factor", 30);
        set("long",
"
地利老人在西方神教中的地位是仅次于天时老人的，
地利老人统领着西方神教中的地舵。
\n"
	);
        create_family("西方神教", 3, "舵主");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.dimo" :),
                (: perform_action, "dodge.lianhuanbabu" :),
                (: perform_action, "unarmed.dimo" :),
                (: exert_function, "mihun" :)
        }) );
        set("combat_exp", 1000000);
        set("score", 200000);

        set_skill("move", 70);
        set_skill("parry",70);
        set_skill("dodge", 70);
        set_skill("force", 70);
        set_skill("literate", 70);
	set_skill("unarmed",70);
	set_skill("demon-steps",70);
	set_skill("demon-strike",70);
	set_skill("demon-force",70);
	set_skill("perception",70);
        map_skill("dodge", "demon-steps");
	map_skill("force", "demon-force");
	map_skill("unarmed", "demon-strike");
        setup();
        carry_object(__DIR__"obj/duoyi2")->wear();

}

void attempt_apprentice(object me)
{
	if(me->query("family/family_name") == "西方神教")
	{
		command("say 你已是西方神教弟子，跟谁学都一样。\n");
		return;
	}
	command("smile");
	command("say 多加努力，你是一块不世之材！\n");
        command("recruit " + me->query("id") );
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

