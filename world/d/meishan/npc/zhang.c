// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 

inherit NPC;
void create()
{

  set_name("张伯时", ({ "zhang boshi", "zhang", "taiwei" }) );
  set("gender", "男性" );
  set("long", "张伯时是梅山七兄弟中的老五。\n");
  set("title", "梅山太尉");
  set("age", 35);
  set("attitude", "peaceful");
  set("str", 25);
  set("int", 25);
  set("combat_exp",560000);
  set("force",800);
  set("max_force",800);
  set("force_factor", 20);
  set("max_kee", 900);
  set("max_sen", 600);
  set("max_mana", 400);
  set("mana", 400);
  set("mana_factor", 20);
  set_skill("unarmed",109);
  set_skill("dodge",109);
  set_skill("parry", 109);
  set_skill("blade",109);
  set_skill("force",109);
  setup();
  carry_object("/d/obj/armor/yinjia")->wear();
  carry_object("/d/obj/weapon/blade/blade")->wield();
}

