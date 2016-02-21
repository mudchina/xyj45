// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// created by snowcat on 4/12/1997

inherit NPC;

void create()
{
  set_name("小妖", ({"xiao yao","yao"}));
  set("gender", "男性");
  set("age", 10);
  set("long","一个贼眉鼠眼的小妖精。\n");
  set("combat_exp", 10000);
  set("per", 15);
  set_skill("dodge", 40);
  set_skill("parry", 40);
  set_skill("unarmed", 40);
  set("max_sen",200);
  set("max_gee",200);
  set("max_gin",200);
  set("force",300);
  set("max_force",300);
  set("max_mana",300);
  set("force_factor",5);
  set_skill("spells",10);
  set_skill("stick",10);
  set("chat_chance",2);
  set("chat_msg",({
        "小妖皱一皱小贼眉。\n",
        "小妖拼命地眨眨一对闪闪发光的小鼠眼。\n",
        "小妖一跳，叭叽一声摔在地上。\n",
        "小妖走到你面前，哇呀咿啊叫了几声。\n",
        "小妖嗖地一声，甩手倒挂在洞岩上。\n",
        "小妖一不小心，呀呀呀从洞岩上失手掉下来。\n",
    }));
  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();

}
