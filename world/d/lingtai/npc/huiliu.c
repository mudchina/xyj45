// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// worker.c

inherit NPC;
void create()
{
        set_name("慧琉", ({"hui liu"}));
        set("gender", "男性" );
        set("age", 33);
        set("long", "一个相貌堂堂的道士．");
   set("title", "道长");
   set("class", "taoist");
        set("combat_exp", 45000);
        set("attitude", "peaceful");
        create_family("方寸山三星洞", 4, "弟子");
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("force", 30);   
        set_skill("wuxiangforce", 30);
        map_skill("force", "wuxiangforce");

        set("per", 30);
        set("max_kee", 500);
        set("max_sen", 300);
        set("force", 450);
        set("max_force", 300);
        set("force_factor", 5);
        setup();
        carry_object("/d/lingtai/obj/cloth")->wear();
}

