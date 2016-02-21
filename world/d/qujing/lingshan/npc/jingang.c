// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// snowcat 12 14 1997

inherit NPC;

void create()
{
  set_name("金刚", ({ "jin gang", "jin", "gang" }));
  set("title", "灵山");
  set("gender", "男性");
  set("age", 500);
  set("attitude", "peaceful");
  set("str",40);
  set("per",40);
  set("max_kee", 2000);
  set("max_gin", 2000);
  set("max_sen", 2000);
  set("force", 2000);
  set("max_force", 2000);
  set("force_factor", 100);
  set("max_mana", 2000);
  set("mana", 2000);
  set("mana_factor", 100);
  set("combat_exp", 1400000);
  set_skill("spells", 100);
  set_skill("buddhism", 100);
  set_skill("unarmed", 100);
  set_skill("jienan-zhi", 100);
  set_skill("dodge", 100);
  set_skill("lotusmove", 100);
  set_skill("parry", 100);
  set_skill("force", 100);
  set_skill("lotusforce", 100);
  set_skill("staff", 100);
  set_skill("lunhui-zhang", 100);
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

