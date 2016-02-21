inherit NPC;
#include <ansi.h>
inherit F_MASTER;
inherit F_QUEST;

void create()
{
	set_name(HIY "东岳大帝" NOR, ({ "master dadi", "master", "dadi" }) );

	set("gender", "男性");
	set("age", 99);
	set("long",
"东岳大帝高六尺，型貌活灵活现，宛如真人一般。\n");
	set("attitude", "peaceful");
	set("str", 2600);
	set("cor", 30);
	set("int", 24);
	set("cps", 30);
	set("force", 40000);
	set("max_force", 80000);
	set("force_factor", 1000);
	set("combat_exp", 10000000);
	set("score", 200000);
	set_skill("unarmed", 120);
	set_skill("force", 100);
	set_skill("iron-cloth", 100);
	set_skill("yiqiforce", 60);
	set_skill("literate",100);
	set_skill("incarnation",320);
	set_skill("dodge",100);
	set_temp("apply/attack",300);
	set_temp("apply/damage",30000);
	map_skill("iron-cloth", "yiqiforce");
        map_skill("force", "yiqiforce");
        map_skill("unarmed", "yiqiforce");
	set("no_shown",1);
	create_family("东岳派", 1, "祖师");
	setup();
}
int accept_fight(object me)
{
        return 0;
}
void attempt_apprentice(object me)
{
        command("recruit " + me->query("id") );
                return;
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "xianren");
}
void init()
{
add_action("do_look","look");
}

int do_look(string arg)
{

if (arg == "master dadi" || arg == "dadi" || arg =="master")
{
write("东岳大帝高六尺，型貌活灵活现，宛如真人一般。\n");
return 1;
}
return 0;
}


void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 320000 ) {
                student->set("title","地仙");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","人仙");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","天仙");
                return ;
        } else
                student->set("title","大罗金仙");
                return ;

}

