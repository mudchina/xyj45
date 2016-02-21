// master.c

inherit NPC;
inherit F_MASTER;
inherit F_QUEST;

#include <ansi.h>
void create()
{
        set_name("李寻欢", ({ "master li", "master", "master li xunhuan" }) );
        set("nickname", RED"小李飞刀"NOR);
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

        set("rank_info/respect", "李探花");

        set("long",
"李寻欢别号李探花，又有江湖绰号小李飞刀。
一手飞刀绝技，在百晓生的兵器谱上排行第三。
不发则已，但例无虚发。\n"                
	);
        create_family("风云一刀", 2, "人杰");
	set("student_title","人杰");
        set("combat_exp", 10000000);
        set("score", 200000);

        set("chat_chance", 10);
        set("chat_msg", ({
                "李寻欢不停的在咳，嘴角流下一丝鲜血。\n",
                "李寻欢的脸色越发苍白了。\n",
"李寻欢叹口气，呆呆地望着手里的木像。\n",
        }) );

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "xiaoli-feidao" :)
        }) );

        set_skill("move", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("throwing", 300);
	set_skill("feidao", 220);
        set_skill("force", 40);
        set_skill("literate", 200);

       map_skill("throwing", "feidao");


        setup();
        carry_object(__DIR__"obj/whitecloth")->wear();
        carry_object(__DIR__"obj/xlfd_knife")->wield();
}

void attempt_apprentice(object ob)
{
	if(time()-(int) ob->query("last_time_app_master_li") < 600)
	{
	         message_vision("$N笑道：你怎么这么快又回来了．．．\n",
        this_object());
        return;
        }
	if((int) ob->query("force_factor") < 100)
	{
	 message_vision("$N笑道：你对武功的了解还不够．．．\n",
        this_object());
	return;

	}
	if( random(100) || random((int)ob->query("kar")) <  25 ||
	   query("already"))
	{
	message_vision("$N咳了两声，说道：不要开玩笑，我可不想误人子弟。\n",
	this_object());
	ob->set("last_time_app_master_li",time());
                return;
        }
        command("sigh");
        command("say 很好，" + RANK_D->query_respect(ob) + 
"他日切不可为非作歹。\n");
        command("recruit " + ob->query("id") );
	ob->delete("betrayer");
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "traveller");
	set("already",1);
}
void reset()
{
	set("already",0);
} 
void init()
{
        add_action("give_quest", "quest");
}

