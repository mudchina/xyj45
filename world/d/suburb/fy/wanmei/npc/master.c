// servant.c

inherit NPC;
inherit F_MASTER;
inherit F_QUEST;

void create()
{
        set_name("西门吹雪", ({ "master ximen", "ximen", "master" }) );
        set("title", "万梅庄主");
        set("gender", "男性");
        set("age", 34);
        set("long",
"西门吹雪乃是当代绝顶高手之一．剑法已经到达了＂无剑＂的境界．．\n"
               ); 

        set("attitude", "peaceful");
        set("combat_exp", 10000000);
        set("score", 200000);
        set("agi",25);
        set("int",30);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.hunranyijian" :),
                (: perform_action, "dodge.feitiantui" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
		"西门吹雪冷笑道：如此废物，还来杀我？\n"
        }) );
        set("chat_chance", 1);
        set("chat_msg", ({
                "西门吹雪怒骂道：陆小凤，你就是逃到幽灵山庄，我也要杀了你！！\n",
        }) );
        set("str", 30);
        set("int", 30);
        set("cor", 300);
        set("cps", 30);
        set("con", 30);

        set("force", 4000);
        set("max_force", 2200);
        set("force_factor", 30);

        set("inquiry", ([
                "拜师": 
"我向来有个规矩，凡是想拜我为师的，得接我三招不死，你想试试(accept 
test)？\n",
		"apprentice" :
"我向来有个规矩，凡是想拜我为师的，得接我三招不死，你想试试(accept
test)？\n"

        ]) );

        create_family("万梅山庄", 1, "庄主");

        set_skill("force", 100);
        set_skill("unarmed", 100);
        set_skill("sword", 150);
        set_skill("parry", 100);
        set_skill("dodge", 80);
        set_skill("throwing", 50);
	set_skill("move", 150);

        set_skill("doomforce", 100);
        set_skill("doomstrike", 100);
        set_skill("doomsteps", 90);
	set_skill("doomsword",120);

        map_skill("force", "doomforce");
        map_skill("unarmed", "doomstrike");
        map_skill("sword", "doomsword");
        map_skill("dodge", "doomsteps");


        setup();

        carry_object(__DIR__"obj/xuejian")->wield();
	carry_object(__DIR__"obj/cloth")->wear();
}

void init()
{
        ::init();
        add_action("do_accept", "accept");
        add_action("give_quest", "quest");

}
int do_accept(string arg)
{
        mapping guild;

        if( arg== "test" ) {
                say("\n西门吹雪点了点头，说道：很好，这是第一招....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(), 
query_temp("weapon"));
                if( (int)this_player()->query("kee") < 0 
                || !present(this_player(), environment())) {
                        
say("西门吹雪叹了口气，说道：连第一招都撑不过，真是自不量力....\n");
                        return 1;
		}
                say("\n西门吹雪说道：这是第二招....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(), 
query_temp("weapon"));
                if( (int)this_player()->query("kee") < 0 
                || !present(this_player(), environment())) {
                        
say("西门吹雪「哼」地一声，说道：便是有这许多不怕死的家伙....\n");
                        return 1;
                }
                say("\n西门吹雪说道：第三招来了....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(), 
query_temp("weapon"));
                if( (int)this_player()->query("kee") < 0 
                || !present(this_player(), environment())) {
                        
say("西门吹雪叹道：可惜，难道我一身武功竟无传人....\n");
                        return 1;
                }
                
say("\n西门吹雪哈哈大笑，说道：今日终於觅得一个可造之才！\n\n");
                command("recruit " + this_player()->query("id") );
                return 1;
        }
        return 0;
}

void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 32000 ) {
                student->set("title","万梅山庄弟子");
                return ;
        } else if ( exp <= 128000 ) {
                student->set("title","万梅山庄领班");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","万梅山庄小管家");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","万梅山庄管家");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","万梅山庄大管家");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","万梅山庄总管");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","万梅山庄大总管");
                return ;
        } else
                student->set("title","万梅山庄副庄主");
                return ;

}

void killed_enemy(object who)
{
        command("say 狂妄之徒，死不足惜！\n");
}

