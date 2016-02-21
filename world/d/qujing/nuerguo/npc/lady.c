// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// created 4/4/1997 by snowcat

inherit NPC;

void create()
{
  set_name("梅鸳鸯", ({"mei yuanyan", "mei"}));
  set("title", "护宫女使");
  set("gender", "女性");
  set("age", 42);
  set("long", "一位看护西梁宫殿的女使臣。\n");
  set("combat_exp", 30000);
  set_skill("snowsword", 40);
  set_skill("sword", 40);
  set_skill("unarmed", 40);
  set_skill("dodge", 40);
  set_skill("parry", 40);
  set_skill("dragonstep", 30);
  map_skill("dodge", "dragonstep");
  map_skill("sword", "snowsword");
  map_skill("parry", "snowsword");
  set("force", 400);
  set("max_force", 200);
  set("force_factor", 4);

  setup();
  carry_object("/d/qujing/nuerguo/obj/skirt")->wear();
  carry_object("/d/obj/weapon/sword/xijian")->wield();
}

void init()
{
  ::init();
}

