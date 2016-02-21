// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//change.c
inherit NPC;
inherit F_MASTER;

void create()
{
       set_name("痴梦仙姑",({"chi meng","dream", "fairy"}));
       set("long",
"此乃迷津痴梦仙姑也；不受金银之谢，但遇有缘者渡之！\n");
       set("title", "迷津渡者");
       set("gender", "女性");
       set("age", 18);
       set("class", "xian");
       set("attitude", "friendly");
       set("rank_info/respect", "仙姑");
       set("per", 30);
   set("int", 30);
       set("max_kee", 1000);
       set("max_gin", 1000);
       set("max_sen", 1000);
       set("force", 800);
       set("max_force", 600);
       set("force_factor", 50);
       set("max_mana", 500);
       set("mana", 500);
       set("mana_factor", 40);
       set("combat_exp", 300000);
       set_skill("literate", 50);
       set_skill("unarmed", 80);
       set_skill("dodge", 100);
       set_skill("force", 70);
       set_skill("parry", 70);
       set_skill("sword", 100);
       set_skill("spells", 100);
        set_skill("moonshentong",130);
        set_skill("baihua-zhang", 70);
        set_skill("moonforce", 60);
        set_skill("snowsword", 100);
        set_skill("moondance", 100);
        map_skill("spells", "moonshentong");
        map_skill("unarmed", "baihua-zhang");
        map_skill("force", "moonforce");
        map_skill("sword", "snowsword");
        map_skill("parry", "snowsword");
        map_skill("dodge", "moondance");

create_family("月宫", 2, "弟子");
setup();

        carry_object("/d/moon/obj/luoyi")->wear();
   carry_object("/d/moon/obj/snowsword")->wield();
}

void attempt_apprentice(object ob)
{
        if ( !((string)ob->query("gender")=="女性")){
           command("shake");
           command("say 我们月宫只收女徒，这位" +
RANK_D->query_respect(ob) + "还是另请高就吧。\n");
           return;
        }
   if (random(this_player()->query("kar")) < 15 || this_player()->query("mark/moon_chimeng")){
     this_player()->set("mark/moon_chimeng", 1);
     command("shake");
     command("say 你我无缘，还是另请高就吧。\n");
     return;
   }
        else{
   command("pat "+ob->query("id"));
        command("say 好，希望" + RANK_D->query_respect(ob) +
"多加努力，把我们月宫发扬光大。\n");
        command("recruit " + ob->query("id") );
        return;}
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "xian");
}


