// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//change.c
inherit NPC;
inherit F_MASTER;

void create()
{
       set_name("玉兔", ({"yu tu", "rabbit", "jade rabbit" }));
       set("long",
"玉兔仙原本只是嫦娥的宠物，因吃了嫦娥掉在地上的灵药而成人形。玉兔
因灵药之事被王母罚去捣药，久而久之竟颇通药道。\n");
       set("gender", "女性");
       set("age", 20);
       set("class", "xian");
       set("attitude", "friendly");
       set("rank_info/respect", "仙姑");
       set("per", 30);
   set("int", 30);
       set("max_kee", 500);
       set("max_gin", 500);
       set("max_sen", 800);
       set("force", 800);
       set("max_force", 800);
       set("force_factor", 50);
       set("max_mana", 600);
       set("mana", 600);
       set("mana_factor", 40);
       set("combat_exp", 200000);

        set("eff_dx", 200000);
        set("nkgain", 100);

       set_skill("literate", 50);
       set_skill("unarmed",50);
       set_skill("dodge", 100);
       set_skill("force", 80);
       set_skill("parry", 80);
       set_skill("sword", 80);
       set_skill("spells", 50);
        set_skill("moonshentong", 50);
        set_skill("baihua-zhang", 50);
        set_skill("moonforce", 80);
        set_skill("moondance", 100);
        map_skill("spells", "moonshentong");
        map_skill("unarmed", "baihua-zhang");
        map_skill("force", "moonforce");
        map_skill("dodge", "moondance");

create_family("月宫", 2, "弟子");
setup();

        carry_object("/d/moon/obj/luoyi")->wear();
        carry_object("/d/moon/obj/daoyaochu")->wield();
}

void attempt_apprentice(object ob)
{
        if ( !((string)ob->query("gender")=="女性")){
           command("shake");
           command("say 我们月宫只收女徒，这位" +
RANK_D->query_respect(ob) + "还是另请高就吧。\n");
           return;
        }

        command("pat "+ob->query("id"));
        command("say 好，希望" + RANK_D->query_respect(ob) +
"多加努力，把我们月宫发扬光大。\n");
        command("recruit " + ob->query("id") );
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "xian");
}


