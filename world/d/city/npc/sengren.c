// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;

void create()
{
   set_name("游方僧人", ({"seng ren","seng"}));
   set("long", "一位游方和尚，骨瘦如柴，身上的袈裟打满了补丁。\n");

   set("gender", "男性");
   set("attitude", "friendly");
   set("class", "bonze");

   set("age", 30+random(20));
   set("shen_type", 1);
   set("str", 20);
   set("int", 30);
   set("con", 25);
   set("dex", 23);
   set("max_kee", 380);
   set("max_gin", 300);
   set("combat_exp", 10000+random(30000));

   set("chat_chance", 40);
        set("chat_msg", ({
     (: random_move :)
   }));


   set_skill("force", 30+random(40));
   set_skill("unarmed", 30+random(40));
   set_skill("dodge", 30+random(40));
   set_skill("parry", 30+random(40));

   setup();
   carry_object("/d/obj/cloth/sengyi")->wear();

   setup();
}

