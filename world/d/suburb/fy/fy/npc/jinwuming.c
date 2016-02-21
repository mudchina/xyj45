// 
// 

inherit NPC;
inherit F_MASTER;
inherit F_QUEST;

#include <ansi.h>
void create()
{
        set_name("荆无命", ({ "master jin", "master", "master jinwu" }) );
        set("nickname", RED"左手剑"NOR);
        set("gender", "男性" );
        set("age", 44);
        set("str", 30);
        set("cor", 30);
        set("cps", 30);
        set("int", 30);
	set("per", 3);
	set("attitude","friendly");
        set("max_force", 15000);
        set("force", 15000);
        set("force_factor", 3);


        set("long",
"
这人的身子站得更直，更挺，就像是一杆枪。他整个人似已麻木，既不知痛痒，
也不知哀乐。
\n"
	);
        create_family("金钱帮", 2, "护法");

        set("combat_exp", 1000000);
        set("score", 200000);
        set("agi",25);
        set("int",30);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.duxin" :),
		(: perform_action, "sword.sharenruma" :),
		(: exert_function, "calm" :),
		(: perform_action, "dodge.canglongyixian" :),
        }) );

        set_skill("move", 50);
        set_skill("parry", 60);
        set_skill("dodge", 60);
        set_skill("force", 60);
        set_skill("literate", 30);
	set_skill("jingxing",60);
	set_skill("sword", 90);
	set_skill("jinhong-steps",60);
	set_skill("lefthand-sword",60);
	set_skill("sharen-sword",150);
        map_skill("dodge", "jinhong-steps");
	map_skill("sword", "sharen-sword");
	map_skill("force", "jingxing");


        setup();
        carry_object(__DIR__"obj/whitecloth")->wear();
        carry_object("/obj/longsword")->wield();
}

void attempt_apprentice(object me)
{
        command("recruit " + me->query("id") );
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "assassin");
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
                student->set("title","金钱帮帮众");
                return ;
        } else if ( exp <= 64000 ) {
                student->set("title","金钱帮副堂主");
                return ;
        } else if ( exp <= 128000 ) {
                student->set("title","金钱帮堂主");
                return ;
        } else if ( exp <= 256000 ) {
                student->set("title","金钱帮副坛主");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","金钱帮坛主");
                return ;
        } else if ( exp <= 1024000 ) {
                student->set("title","金钱帮副舵主");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","金钱帮舵主");
                return ;
        } else if ( exp <= 2304000 ) {
                student->set("title","金钱帮护法");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","金钱帮大护法");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","金钱帮长老");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","金钱帮大长老");
                return ;
        } else
                student->set("title","金钱帮副帮主");
                return ;

}

