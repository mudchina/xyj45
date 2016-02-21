// 
// 

inherit NPC;
inherit F_MASTER;
inherit F_QUEST;

#include <ansi.h>
void create()
{
        set_name("上官金虹", ({ "master shangguan", "master", "master shang" }) );
        set("nickname", RED"龙凤双环"NOR);
        set("gender", "男性" );
        set("age", 44);
        set("str", 30);
        set("cor", 30);
        set("cps", 30);
        set("int", 30);
	set("per", 30);
	set("attitude","friendly");
        set("max_force", 15000);
        set("force", 15000);
        set("force_factor", 3);


        set("long",
"
一个人正站在桌子前翻阅着，不时用朱笔在卷宗上勾划，批改，嘴里偶而会露出一丝
得意的笑容。他是站着的。他认为一个人只要坐下来，就会令自己的精神松弛，一个
人的精神若松弛，就容易造成错误。
\n"
	);
        create_family("金钱帮", 1, "帮主");

        set("combat_exp", 10000000);
        set("score", 200000);
        set("agi",25);
        set("int",30);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "calm" :),
                (: perform_action, "dodge.canglongyixian" :),
        }) );
        set_skill("move", 70);
        set_skill("parry", 80);
        set_skill("dodge", 80);
        set_skill("force", 80);
        set_skill("literate", 60);
	set_skill("jingxing",120);
	set_skill("hammer", 150);
	set_skill("jinhong-steps",120);
	set_skill("longfenghuan",150);
        map_skill("dodge", "jinhong-steps");
	map_skill("hammer", "longfenghuan");
	map_skill("parry", "longfenghuan");
	map_skill("force", "jingxing");


        setup();
        carry_object(__DIR__"obj/whitecloth")->wear();
        carry_object(__DIR__"obj/longfenghuan")->wield();
}

void attempt_apprentice(object me)
{
	       if( (int)me->query("str") + (int)me->query("max_force") / 10 < 60 )
		{	message_vision("$N对$n说道：你双臂无力，如何学我的龙凤双环？\n", this_object(),me);
			return;
		}	
	
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

