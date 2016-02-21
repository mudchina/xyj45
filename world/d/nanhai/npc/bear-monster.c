// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// bear-monster.c 黑熊怪□
// By Dream Dec. 20, 1996

inherit NPC;
inherit F_MASTER;

void create()
{
   set_name("黑熊怪", ({ "bear monster", "bear", "monster" }));
   set("title", "南海观音之徒");   
   set("long", @LONG
黑熊怪本是山间野兽，不知从哪里学到一身好本领。
后遇见南海观音，被南海观音收为徒弟。
LONG);
   set("gender", "男性");
   set("age", 30);
   set("attitude", "heroism");
   set("per", 9);
   set("rank_info/self", "黑熊");
   set("rank_info/rude", "熊怪");
   set("max_kee", 850);
   set("max_gin", 800);
   set("max_sen", 850);
   set("force", 400);
   set("max_force", 500);
   set("force_factor", 50);
   set("max_mana", 250);
   set("mana", 300);
   set("mana_factor", 20);
   set("combat_exp", 30000);
   set_skill("literate", 50);
   set_skill("spells", 60);
   set_skill("buddhism", 60);
   set_skill("unarmed", 100);
   set_skill("jienan-zhi", 95);
   set_skill("dodge", 80);
   set_skill("lotusmove", 80);
   set_skill("parry", 85);
   set_skill("force", 90);
   set_skill("lotusforce", 90);
   set_skill("staff", 60);
   set_skill("lunhui-zhang", 50);
   set_skill("spear", 60);
   set_skill("huoyun-qiang", 50);

   map_skill("spells", "buddhism");
   map_skill("unarmed", "jienan-zhi");
   map_skill("dodge", "lotusmove");
   map_skill("force", "lotusforce");
   map_skill("parry", "lunhui-zhang");
   map_skill("staff", "lunhui-zhang");
   map_skill("spear", "huoyun-qiang");

   set("chat_chance_combat", 80);
   set("chat_msg_combat", ({
     (: cast_spell, "bighammer" :),
     (: cast_spell, "jingang" :),
   }) );
        create_family("南海普陀山", 2, "弟子");

   setup();
   carry_object("/obj/cloth")->wear();
carry_object("/d/nanhai/obj/jingu3");
//   carry_object("/d/nanhai/obj/jingu3");
}

void attempt_apprentice(object ob)
{
   if ( (string)ob->query("family/family_name")=="南海普陀山") {
     command("smile");
     command("say 很好，我就收下你，希望你多加努力，早成正果。\n");

     command("recruit " + ob->query("id") );
     return;
   }

   command("shake");
   command("say " + "菩萨不让我随便收外人为徒。\n");
   return;
}

