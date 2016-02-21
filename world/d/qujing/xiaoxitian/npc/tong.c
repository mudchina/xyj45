// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// created by snowcat on 12/16/1997

inherit NPC;

string *names = ({
  "黑鼠怪",
  "黄犰怪",
  "灰狨怪",
  "白猁怪",
  "赤狻怪",
  "土猬怪",
  "石猊怪",
  "木猱怪",
  "水獾怪",
});

void create()
{
  set_name("小童", ({"xiao tong", "tong"}));
  set("gender", "男性");
  set("age", 13);
  set("combat_exp", 150000+random(30000));
  set("per", 10);
  set_skill("parry", 80);
  set_skill("unarmed", 80);
  set_skill("dodge", 80);
  set_skill("blade", 80);
  set_skill("fork", 80);
  set_skill("rake", 80);
  set_skill("hammer", 80);
  set_skill("sword", 80);
  set_skill("stick", 80);
  set_skill("staff", 80);
  set("max_sen",1100);
  set("max_gee",1100);
  set("max_gin",1100);
  set("force",1100);
  set("max_force",1100);
  set("max_mana",1100);
  set("force_factor",10);
  setup();
  carry_object("/d/obj/cloth/sengyi")->wear();
  carry_object("/d/qujing/xiaoxitian/obj/shield");
}

void kill_ob (object ob)
{
  object me = this_object();

  if (me->query("id")!="yao guai")
  {
    set("combat_exp", 1500000+random(70000));
    message_vision ("$N顿时变了颜色，现了妖精的本相！\n",me);
    me->set_name(names[random(sizeof(names))], ({"yao guai", "yao", "guai", "xiao tong", "tong"}));
    command("wear dun");
  }
  ::kill_ob(ob);
}
