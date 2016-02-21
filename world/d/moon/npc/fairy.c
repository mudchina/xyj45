// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//change.c
inherit NPC;
inherit F_MASTER;

void create()
{
       set_name("蝶衣",({"butterfly","die yi", "fairy"}));
       set("long",
"其仙袂乍飘兮，闻麝兰之馥郁；荷花欲动兮，听环佩之铿锵。靥笑春
桃兮，云髻堆翠；唇绽樱颗兮，榴齿含香。纤腰之楚兮，若风回雪舞
\n");
       set("title", "月宫舞仙");
       set("gender", "女性");
       set("age", 18);
       set("class", "xian");
       set("attitude", "friendly");
       set("rank_info/respect", "仙姑");
       set("per", 30);
   set("int", 30);
       set("max_kee", 800);
       set("max_gin", 600);
       set("max_sen", 600);
       set("force", 600);
       set("max_force", 600);
       set("force_factor", 40);
       set("max_mana", 500);
       set("mana", 500);
       set("mana_factor", 40);
       set("combat_exp", 100000);
       set_skill("literate", 50);
       set_skill("unarmed", 50);
       set_skill("dodge", 100);
       set_skill("force", 50);
       set_skill("parry", 50);
       set_skill("sword", 50);
       set_skill("spells", 50);
        set_skill("moonshentong", 40);
        set_skill("baihua-zhang", 40);
        set_skill("moonforce", 40);
        set_skill("snowsword", 40);
        set_skill("moondance", 80);
        map_skill("spells", "moonshentong");
        map_skill("unarmed", "baihua-zhang");
        map_skill("force", "moonforce");
        map_skill("sword", "snowsword");
        map_skill("parry", "snowsword");
        map_skill("dodge", "moondance");

create_family("月宫", 2, "弟子");
setup();

        carry_object("/d/obj/cloth/luoyi")->wear();
   carry_object("/d/obj/weapon/sword/snow_sword")->wield();
}


