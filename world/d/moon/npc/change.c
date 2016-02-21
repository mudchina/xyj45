// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//change.c
inherit NPC;
inherit F_MASTER;

void create()
{
       set_name("嫦娥", ({"chang e", "change", "chang","master"}));
       set("long",
"西王母的大弟子。早年因帮助丈夫盗取西王母之灵药而\n与其师势成水火。后得和解并邀西王母出掌月宫一门。\n");
       set("title", "月宫主人");
       set("gender", "女性");
       set("age", 20);
       set("class", "xian");
       set("attitude", "friendly");
       set("rank_info/respect", "仙姑");
       set("per", 30);
   set("int", 30);
       set("max_kee", 900);
       set("max_gin", 600);
       set("max_sen", 800);
       set("force", 800);
       set("max_force", 800);
       set("force_factor", 50);
       set("max_mana", 600);
       set("mana", 600);
       set("mana_factor", 40);
       set("combat_exp", 400000);

        set("eff_dx", 200000);
        set("nkgain", 350);

       set_skill("literate", 80);
       set_skill("unarmed", 80);
       set_skill("dodge", 180);
       set_skill("force", 80);
       set_skill("parry", 80);
       set_skill("sword", 80);
       set_skill("spells", 80);
        set_skill("moonshentong", 80);
        set_skill("baihua-zhang", 80);
        set_skill("moonforce", 80);
        set_skill("snowsword", 80);
        set_skill("moondance", 200);
        map_skill("spells", "moonshentong");
        map_skill("unarmed", "baihua-zhang");
        map_skill("force", "moonforce");
        map_skill("sword", "snowsword");
        map_skill("parry", "snowsword");
        map_skill("dodge", "moondance");

create_family("月宫", 2, "弟子");
setup();

        carry_object("/d/moon/obj/luoyi")->wear();
        carry_object("/d/moon/obj/feijian")->wield();
}

void attempt_apprentice(object ob)
{
        if ( !((string)ob->query("gender")=="女性")){
           command("shake");
           command("say 我们月宫只收女徒，这位" +
RANK_D->query_respect(ob) + "还是另请高就吧。\n");
           return;}
        if ( (int)ob->query("per") <20){
     command("shake");
   command("say 以我看这位" +
RANK_D->query_respect(ob) + "的资质并不适于跳舞，还是另请高就吧。\n");
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


