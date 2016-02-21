// master.c

inherit NPC;
inherit F_MASTER;
inherit F_QUEST;

#include <ansi.h>
void create()
{
        set_name("叶孤城", ({ "master ye", "master", "master gucheng" }) );
        set("nickname", HIW "白云城主"NOR);
        set("gender", "男性" );
        set("age", 34);
        set("str", 30);
        set("cor", 30);
        set("cps", 30);
        set("int", 30);
	set("per", 30);
        set("agi",25);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.tianwaifeixian" :),
                (: perform_action, "dodge.tianwaifeixian" :),
        }) );
	set("attitude","friendly");
        set("max_force", 15000);
        set("force", 15000);
        set("force_factor", 30);
	set("max_kee",99999999);
        set("max_gin",999999);
        set("max_sen",999999);
	set("eff_kee",999999);
	set("kee",999999);
        set("chat_chance", 1);
        set("chat_msg", ({
                "叶孤城从点点血斑的白袍撕下一条布条。\n叶孤城用从点点血斑的白袍撕下的布条替自己裹伤。\n",
        }) );

        set("long",
"
白云城主以前充满了尊荣和光采．而现在．．．
他知道那被唐门暗器所伤的伤口已完全溃烂．．．
\n"
	);
        create_family("白云城", 2, "城主");

        set("combat_exp", 100000000);
        set("score", 200000);

        set_skill("move", 100);
        set_skill("parry", 120);
        set_skill("dodge", 80);
        set_skill("force", 40);
        set_skill("literate", 60);
	set_skill("sword", 100);
	set_skill("unarmed",40);
	set_skill("changquan",100);
	set_skill("feixian-steps",100);
	set_skill("feixian-sword",150);
	set_skill("jingyiforce",60);
        map_skill("dodge", "feixian-steps");
	map_skill("sword", "feixian-sword");
	map_skill("force", "jingyiforce");
	map_skill("parry", "feixian-sword");
	map_skill("unarmed", "changquan");


        setup();
        carry_object(__DIR__"obj/whitecloth")->wear();
        carry_object(__DIR__"obj/bsword")->wield();
	carry_object(__DIR__"obj/bcloth")->wear();

}

void attempt_apprentice(object me)
{
        command("recruit " + me->query("id") );
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "swordsman");
}
void init()
{
        add_action("give_quest", "quest");
}
 
int accept_object(object who, object ob)
{
if(ob->query("name") == "七彩丝缎带" && ob->query("realsilk"))
{
	command("say 我身受重伤，还是你画妆成我去吧！\n");
	command("say 但你武功低微．．．．\n");
	command("say 兴国禅寺的主持是我的好友，也许他可帮上你．\n");
	who->set_temp("marks/ye",1);
	return 1;
}
return 0;
}

void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 32000 ) {
                student->set("title","白云城弟子");
                return ;
        } else if ( exp <= 128000 ) {
                student->set("title","白云城领班");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","白云城小管家");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","白云城管家");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","白云城大管家");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","白云城总管");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","白云城大总管");
                return ;
        } else
                student->set("title","白云城副城主");
                return ;

}

