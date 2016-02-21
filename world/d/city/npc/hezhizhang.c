// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;

void create()
{
        set_name("贺知章", ({"he zhizhang", "he"}));
        set("age", 52);
        set("gender", "男性");
   set("int", 35);
        set("long",
"贺知章是国子监大学士，统管全国文人考试及升级。\n");
   set("title", "国子监大学士");
        set("attitude", "friendly");
   set("class", "scholar");
        set("combat_exp", 40000);
        set("shen_type", 1);
   set("max_force", 400);
   set("force", 400);
   set("force_factor", 5);
        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
   set_skill("literate", 150);
   setup();
        carry_object(__DIR__"obj/choupao")->wear();
}


