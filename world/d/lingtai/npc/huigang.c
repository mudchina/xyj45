// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// worker.c

inherit NPC;

void create()
{
        set_name("慧纲", ({"hui gang"}));
        set("gender", "男性" );
        set("age", 33);
        set("long", "一个相貌堂堂的道士．");
        set("combat_exp", 40000);
   set("title", "道长");
   set("class", "taoist");
        set("attitude", "peaceful");
        create_family("方寸山三星洞", 4, "弟子");
        set_skill("unarmed", 30);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_skill("literate", 40);
        set_skill("dodge", 30);  
        set_skill("force", 40);   
        set_skill("wuxiangforce", 40);
        map_skill("force", "wuxiangforce");
   set_skill("dao", 20);
   set_skill("spells", 20);
   map_skill("spells", "dao");
        set("per", 30);
        set("max_kee", 300);
        set("max_gin", 200);
        set("max_sen", 300);
        set("force", 450);
        set("max_force", 300);
        set("force_factor", 5);
   set("max_mana", 200);
   set("mana", 200);
   set("mana_factor", 20);
        setup();
        carry_object("/d/lingtai/obj/cloth")->wear();
}

