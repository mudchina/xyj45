// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// worker.c

inherit NPC;

void create()
{
        set_name("道士", ({"taoist", "dao"}));
        set("gender", "男性" );
        set("age", 23);
        set("long", "一个道士，看起来无精打采的样子。\n");
        set("combat_exp", 12000);
        set("attitude", "peaceful");
        set_skill("dodge", 20);
   set("class", "taoist");
        set_skill("parry", 30);
        set_skill("unarmed", 30);  
        set("per", 30);
        set("max_kee", 300);
        set("max_sen", 300);
        set("force", 150);
        set("max_force", 100);
        set("force_factor", 3);
   set("max_mana", 50);
   set("mana", 50);
   set("mana_factor", 1);
        setup();
   carry_object("/d/lingtai/obj/cloth")->wear();
}

