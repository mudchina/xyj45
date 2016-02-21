// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//created 5-20-97 pickle
 
inherit NPC;
inherit F_MASTER;
 
void create()
{
  set_name("魏徵", ({"wei zheng", "wei", "zheng", "weizheng", "shifu", "master"}));
  set ("long", @LONG
魏徵先仕齐府为太子李建成屡设妙计。但李建成不听其
劝告，终为太宗所杀。太宗爱魏徵之才，将其收罗，并
封为郑国公。
LONG);
 
  set("title", "郑国公");
  set("gender", "男性");
  set("age", 55);
  set("str", 15);
  set("per", 25);
  set("int", 40);
  set("combat_exp", 40000);
  set_skill("literate", 200);
  set_skill("spells", 150);
  set_skill("baguazhou", 100);
  set_skill("force", 30);
  set_skill("lengquan-force", 30);
  set_skill("dodge", 30);
  set_skill("yanxing-steps", 30);
  set_skill("parry", 30);
  set_skill("unarmed", 30);
  set_skill("changquan", 30);
  set_skill("sword", 40);
  map_skill("spells", "baguazhou");
  map_skill("force", "lengquan-force");
  map_skill("unarmed", "changquan");
  map_skill("dodge", "yanxing-steps");
  set("max_sen", 1000);
  set("max_kee", 300);
  set("force", 200);
  set("max_force", 200);
  set("force_factor", 10);
  set("mana", 700);
  set("max_mana", 700);
  set("mana_factor", 70);
 
  create_family("将军府", 2, "文人");
  setup();
 
  carry_object("/d/obj/weapon/spear/gangqiang");
  carry_object("/d/obj/weapon/mace/malemace")->wield();
  carry_object("/d/obj/armor/tiejia")->wear();
}
 
int accept_fight(object me)
{
  command("say 老夫手重，若是伤人反而不美了。\n");
  return 0;
}
