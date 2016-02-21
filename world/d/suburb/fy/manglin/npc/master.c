// 
// 

inherit NPC;
inherit F_MASTER;
inherit F_QUEST;

#include <ansi.h>
void create()
{
        set_name("裴冥通天", ({ "master peiming", "master", "peiming" }) );
        set("nickname", HIG"五毒童子"NOR);
        set("gender", "男性" );
        set("age", 44);
        set("str", 30);
        set("cor", 30);
        set("cps", 30);
        set("int", 30);
	set("per", 30);
	set("attitude","aggresive");
        set("max_force", 15000);
        set("force", 15000);
        set("force_factor", 3);
        set("long",
"
裴冥通天学艺于自然，以最毒之物为师，一身毒气杀人于无形．
更精于通天降．．
\n"
	);
        create_family("通天门", 1, "门主");

        set("combat_exp", 10000000);
        set("score", 200000);
        set("chat_chance", 10);
        set("chat_msg", ({
                                (: random_move :)
        }) );

        set_skill("move", 70);
        set_skill("parry", 80);
        set_skill("dodge", 80);
        set_skill("force", 80);
        set_skill("literate", 60);
	set_skill("cursism",100);
	set_skill("celecurse",70);
	map_skill("force", "celecurse");
	map_skill("cursism","celecurse");


        setup();
        carry_object(__DIR__"obj/ducloth")->wear();
}

void attempt_apprentice(object me)
{
	if( !me->query("class")){
	command("smile");
        command("recruit " + me->query("id") );
	}
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "diabloist");
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
                student->set("title","通天门众");
                return ;
        } else if ( exp <= 64000 ) {
                student->set("title","通天门副堂主");
                return ;
        } else if ( exp <= 128000 ) {
                student->set("title","通天门堂主");
                return ;
        } else if ( exp <= 256000 ) {
                student->set("title","通天门副坛主");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","通天门坛主");
                return ;
        } else if ( exp <= 1024000 ) {
                student->set("title","通天门副舵主");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","通天门舵主");
                return ;
        } else if ( exp <= 2304000 ) {
                student->set("title","通天门护法");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","通天门大护法");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","通天门长老");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","通天门大长老");
                return ;
        } else
                student->set("title","通天门副门主");
                return ;

}

