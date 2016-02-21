// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;

void create()
{
   set_name("僧人", ({"seng ren","seng"}));

   set("gender", "男性");
   set("attitude", "friendly");
   set("class", "bonze");

   set("age", 20+random(30));
   set("shen_type", 1);
   set("str", 20);
   set("int", 30);
   set("con", 25);
   set("dex", 23);
   set("max_kee", 550);
   set("max_gin", 500);
   set("combat_exp", 40000+random(20000));

   set_skill("force", 60+random(20));
   set_skill("unarmed", 60+random(20));
   set_skill("dodge", 60+random(20));
   set_skill("parry", 60+random(20));

   setup();
   carry_object("/d/obj/cloth/sengyi")->wear();
   carry_object("/d/obj/cloth/sengxie")->wear();

}

