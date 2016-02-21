// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// created by snowcat on 12/5/1997

inherit NPC;

void create()
{
  string str;
  int i = random(4)+1;
  set_name("妖精", ({"yao jing","yao", "jing"}));
  set("gender", "男性");
  set("age", 20*i);
  set("long","一个守洞的妖精。\n");
  set("combat_exp", 20000*i);
  set("per", 15);
  set_skill("parry", 20*i);
  set_skill("unarmed", 20*i);
  set_skill("dodge", 20*i);
  set_skill("blade", 20*i);
  set_skill("fork", 20*i);
  set_skill("mace", 20*i);
  set_skill("spear", 20*i);
  set_skill("sword", 20*i);
  set_skill("whip", 20*i);
  set_skill("axe", 20*i);
  set_skill("hammer", 20*i);
  set_skill("rake", 20*i);
  set_skill("stick", 20*i);
  set_skill("staff", 20*i);
  set_skill("dagger", 20*i);
  set("max_sen",200*i);
  set("max_gee",200*i);
  set("max_gin",200*i);
  set("force",200*i);
  set("max_force",200*i);
  set("max_mana",200*i);
  set("force_factor",10*i);
  setup();
  carry_object("/d/qujing/yinwu/obj/cloth")->wear();
  str = "/d/qujing/yinwu/obj/weapon0";
  str[strlen(str)-1] = '0'+random(6);
  carry_object(str)->wield();
}

void die ()
{
  object me = this_object();
  object where = environment (me);
  object bone = present ("bone 4",where);

  if (! bone)
  {
    bone = new ("/d/obj/misc/bone");
    bone->move(where);
  }

  message_vision ("\n$N倒了下去，化为一堆兽骨。\n",me);  
  if (! present("shan yao 4",where) &&
      where->query("short")=="剥皮亭")
  {
    object ob = new ("/d/qujing/yinwu/npc/yaojing");
    ob->move(where);
    message_vision ("\n紧接着从亭柱后又闪出一位守亭的妖精！\n",me);   
  }
  destruct (me);  
}

void unconcious ()
{
  die();
}
