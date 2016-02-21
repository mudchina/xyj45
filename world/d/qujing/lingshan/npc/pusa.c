// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// snowcat 12 14 1997

inherit NPC;

void create()
{
  set_name("菩萨", ({ "pu sa", "pu", "sa" }));
  set("title", "灵山");
  set("gender", "男性");
  set("age", 1000);
  set("attitude", "peaceful");
  set("str",40);
  set("per",40);
  set("max_kee", 3000);
  set("max_gin", 3000);
  set("max_sen", 3000);
  set("force", 3000);
  set("max_force", 3000);
  set("force_factor", 120);
  set("max_mana", 3000);
  set("mana", 3000);
  set("mana_factor", 120);
  set("combat_exp", 1600000);
  set_skill("spells", 140);
  set_skill("buddhism", 140);
  set_skill("unarmed", 140);
  set_skill("jienan-zhi", 140);
  set_skill("dodge", 140);
  set_skill("lotusmove", 140);
  set_skill("parry", 140);
  set_skill("force", 140);
  set_skill("lotusforce", 140);
  set_skill("staff", 140);
  set_skill("lunhui-zhang", 140);
  map_skill("spells", "buddhism");
  map_skill("unarmed", "jienan-zhi");
  map_skill("dodge", "lotusmove");
  map_skill("force", "lotusforce");
  map_skill("parry", "lunhui-zhang");
  map_skill("staff", "lunhui-zhang");
  set("chat_chance_combat", 80);
  set("chat_msg_combat", ({
   (: cast_spell, "bighammer" :),
  }) );

  setup();
  carry_object("/d/obj/cloth/jia_sha")->wear();
}

