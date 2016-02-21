// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// created by snowcat on 12/9/1997

inherit NPC;

string *names = ({
  "虎怪",
  "狼怪",
  "彪怪",
  "豹怪",
  "羊怪",
  "鹿怪",
  "马怪",
});

void create()
{
  int i = random(9)+1;
  string str;
  set_name(names[random(sizeof(names))], ({"yao guai", "yao", "guai"}));
  set("gender", "男性");
  set("age", 30*i);
  set("attitude", "aggressive");
  set("combat_exp", 20000*i);
  set("per", 10);
  set_skill("parry", 10*i);
  set_skill("unarmed", 10*i);
  set_skill("dodge", 10*i);
  set_skill("blade", 10*i);
  set_skill("fork", 10*i);
  set_skill("mace", 10*i);
  set_skill("spear", 10*i);
  set_skill("sword", 10*i);
  set_skill("whip", 10*i);
  set_skill("axe", 10*i);
  set_skill("hammer", 10*i);
  set_skill("rake", 10*i);
  set_skill("stick", 10*i);
  set_skill("staff", 10*i);
  set_skill("dagger", 10*i);
  set("max_sen",100*i);
  set("max_gee",100*i);
  set("max_gin",100*i);
  set("force",100*i);
  set("max_force",100*i);
  set("max_mana",100*i);
  set("force_factor",10*i);
  setup();
  carry_object("/d/qujing/baotou/obj/cloth1")->wear();
  str = "/d/qujing/baotou/obj/weapon0";
  str[strlen(str)-1] = '0'+random(4);
  carry_object(str)->wield(); 
}

