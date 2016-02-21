// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// honghaier.c 红孩儿
// By Dream Dec. 20, 1996

inherit NPC;
inherit F_MASTER;

void create()
{
   set_name("红孩儿", ({ "honghaier" }));
   set("title", "南海观音之徒");   
   set("long", @LONG
他本是牛魔王之子，生性好斗；后被南海观音收服，脾气却不见有什么好转。
他使得一手的好枪法，火云枪更是鲜有敌手，寻常人是不敢碰他的。
LONG);
   set("gender", "男性");
   set("age", 15);
   set("attitude", "heroism");
   set("max_kee", 750);
   set("max_gin", 600);
   set("max_sen", 750);
   set("force", 450);
   set("max_force", 300);
   set("force_factor", 20);
   set("max_mana", 350);
   set("mana", 500);
   set("mana_factor", 50);
   set("combat_exp", 240000);
   set_skill("literate", 80);
   set_skill("spells", 100);
   set_skill("buddhism", 100);
   set_skill("unarmed", 60);
   set_skill("jienan-zhi", 60);
   set_skill("dodge", 80);
   set_skill("lotusmove", 80);
   set_skill("parry", 80);
   set_skill("force", 80);
   set_skill("lotusforce", 70);
   set_skill("staff", 50);
   set_skill("lunhui-zhang", 40);
   set_skill("spear", 120);
   set_skill("huoyun-qiang", 150);
   map_skill("spells", "buddhism");
   map_skill("unarmed", "jienan-zhi");
   map_skill("dodge", "lotusmove");
   map_skill("force", "lotusforce");
   map_skill("parry", "huoyun-qiang");
   map_skill("staff", "lunhui-zhang");
   map_skill("spear", "huoyun-qiang");
   set("chat_chance_combat", 40);
   set("chat_msg_combat", ({
     (: cast_spell, "bighammer" :),
     (: cast_spell, "jingang" :),
   }) );

   create_family("南海普陀山", 2, "弟子");

   setup();
   carry_object("/obj/money/gold");
   carry_object("/obj/money/gold");
   carry_object("/obj/cloth")->wear();
   carry_object("/d/nanhai/obj/jingu2");
   carry_object("/d/nanhai/obj/huojianqiang")->wield();
}

void attempt_apprentice(object ob)
{
   if (((int)ob->query_skill("buddhism", 1) < 50 )) {
     command("say " + RANK_D->query_respect(ob) + "的佛法修行还不精，还需多加努力才是！");
     return;
   }
   command("smile");
   command("say 很好，我就收下你，希望你多加努力，早成正果。\n");

   command("recruit " + ob->query("id") );
   return;
}

