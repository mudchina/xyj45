// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;

void create()
{
        set_name("范芦平", ({"fan luping", "fan"}));
        set("age", 32);
        set("gender", "男性");
        set("long",
"一个精精瘦瘦的小个子，在练一套拳．\n");
   set("title", "武馆教头");
        set("attitude", "peaceful");

        set("combat_exp", 20000);
        set("shen_type", 1);
   set("max_force", 200);
   set("force", 200);
   set("force_factor", 5);
        set_skill("unarmed", 30);
        set_skill("dodge", 30);
   set_skill("force", 30);
        set_skill("parry", 30);
   setup();
        carry_object("/d/obj/cloth/linen")->wear();
}

int recognize_apprentice(object ob)
{
   return 1;
}

