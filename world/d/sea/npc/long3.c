// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// long3.c
// created 6-6-97 pickle

#include <skill.h>

inherit NPC;
//inherit F_MASTER;

void create()
{
  set_name("睚眦",({"ya zi","zi","ya","long","yazi","dragon"}));
  set("long","龙生九子不成龙，各有所好：睚眦乃第三子，平生好杀。\n");
  set("gender", "男性");
  set("age", 39);
  set("title", "龙王九子之");
  set("class","dragon");
  set("attitude", "heroic");
  set("max_kee", 1200);
  set("max_sen", 1000);
  set("force", 800);
  set("max_force", 800);
  set("max_mana", 800);
  set("mana", 800);
  set("force_factor",50);
  set("mana_factor",30);
  set("str",30);
  set("con",30);
  set("per",10+random(10));
  set("bellicosity",500);
  set("cor",30);

  set("combat_exp", 900000+random(100000));
  set_skill("unarmed", 130);
  set_skill("dodge", 140);
  set_skill("force", 100);
  set_skill("parry", 140);
  set_skill("fork", 130);
  set_skill("spells", 100);
  set_skill("seashentong", 100);
  set_skill("dragonfight", 140);
  set_skill("dragonforce", 140);
  set_skill("fengbo-cha", 150);
  set_skill("dragonstep", 150);
  map_skill("spells", "seashentong");
  map_skill("unarmed", "dragonfight");
  map_skill("force", "dragonforce");
  map_skill("fork","fengbo-cha");
  map_skill("parry", "fengbo-cha");
  map_skill("dodge", "dragonstep");

        set("nkgain", 400);

  set("chat_chance_combat", 20);
  set("chat_msg_combat", ({
    (: cast_spell, "hufa" :),
    (: exert_function, "shield" :),
    "睚眦阴笑道：杀！杀！杀！\n,"
  }) );

  setup();  

  carry_object("/d/obj/armor/yinjia")->wear();
  carry_object("/d/sea/obj/dragonfork")->wield();
  carry_object("/d/sea/obj/longzhu3");
}

int accept_fight(object me)
{
  command("hate");
  command("grin");
  command("say 好久没杀人了！"+RANK_D->query_rude(me)+"你拿命来！");
  command("kill "+ me->query("id"));
  return 1;
}








