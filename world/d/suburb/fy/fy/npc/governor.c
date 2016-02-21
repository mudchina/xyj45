// 
// 

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_QUEST;

void create()
{
        set_name("殷正廉", ({ "master yin", "master","yin" }) );
        set("long",
                "风云城中最高的官，有至高无上的权力\n");
	set("nickname", RED"一品钦差"NOR);
        set("attitude", "heroism");
	set("student_title","官员");
	create_family("朝廷",6,"官员");
	set("vendetta_mark", "authority");
        set("str", 27);
        set("cor", 26);
        set("cps", 25);
	set("agi",25);
	set("int",30);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.yuhuan" :),
        }) );
        set("combat_exp", 90000000);
	set_temp("apply/damage",500);
        set_skill("unarmed", 200);
	set_skill("sword",100);
	set_skill("force",80);
        set_skill("parry", 120);
        set_skill("dodge", 110);
	set_skill("changquan",200);
	set_skill("feixian-steps",60);
	set_skill("feixian-sword",80);
	set_skill("jingyiforce",50);
        set_skill("move", 100);
	set_skill("literate",90);
	set_skill("leadership",150);
	set_skill("strategy",150);
	map_skill("unarmed","changquan");
	map_skill("dodge","feixian-steps");
	map_skill("force","jingyiforce");
	map_skill("sword","feixian-sword");
        setup();

        carry_object(__DIR__"obj/guanfu")->wear();
}

void attempt_apprentice(object me)
{
	if( !me->query("class"))
	{
	command("smile");
	command("say 很好！朝廷正在用人之时，努力吧！\n");
        command("recruit " + me->query("id") );
	}
	else
	command("say 朝廷不需要你这种不三不四，来历不明之人！\n");
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "official");
		ob->set("vendetta_mark", "authority");

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
                student->set("title","朝廷七品芝麻官");
                return ;
        } else if ( exp <= 64000 ) {
                student->set("title","朝廷六品官");
                return ;
        } else if ( exp <= 128000 ) {
                student->set("title","朝廷五品官");
                return ;
        } else if ( exp <= 256000 ) {
                student->set("title","朝廷四品官");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","朝廷三品官");
                return ;
        } else if ( exp <= 1024000 ) {
                student->set("title","朝廷二品官");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","朝廷一品官");
                return ;
        } else if ( exp <= 2304000 ) {
                student->set("title","朝廷钦差大臣");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","朝廷兵马统领");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","朝廷兵马总统领");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","镇远将军");
                return ;
        } else
                student->set("title","定国大将军");
                return ;

}

