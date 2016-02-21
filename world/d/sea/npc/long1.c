// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <skill.h>

inherit NPC;

void create()
{
  set_name("蒲牢",({"pu lao","pu","lao","long","pulao","dragon"}));
  set("long","龙生九子不成龙，各有所好：蒲牢乃第一子，平生好鸣。\n");
  set("gender", "男性");
  set("age", 41);
  set("title", "龙王九子之");
  set("class","dragon");
  set("attitude", "peaceful");
  set("max_kee", 1200);
  set("max_sen", 1000);
  set("force", 1000);
  set("max_force", 1000);
  set("force_factor", 60);
  set("max_mana", 800);
  set("mana", 1000);
  set("mana_factor", 30);

  set("str",30);
  set("con",30);
  set("per",10+random(10));
  set("bellicosity",500);
  set("cor",30);

  set("combat_exp", 900000+random(100000));
  set_skill("unarmed", 140);
  set_skill("dodge", 150);
  set_skill("force", 130);
  set_skill("parry", 150);
  set_skill("spear", 150);
  set_skill("spells", 150);
  set_skill("seashentong", 100);
  set_skill("dragonfight", 130);
  set_skill("dragonforce", 130);
  set_skill("bawang-qiang", 150);
  set_skill("dragonstep", 150);
  map_skill("spells", "seashentong");
  map_skill("unarmed", "dragonfight");
  map_skill("force", "dragonforce");
  map_skill("spear", "bawang-qiang");
  map_skill("parry", "bawang-qiang");
  map_skill("dodge", "dragonstep");

        set("nkgain", 400);

  set("chat_chance_combat", 20);

        set("chat_msg_combat", ({
                (: cast_spell, "hufa" :),
                (: exert_function, "shield" :),
     (: exert_function, "roar" :),
        }) );

  setup();  

  carry_object("/d/obj/armor/yinjia")->wear();
  carry_object("/d/sea/obj/dragonspear")->wield();
  carry_object("/d/sea/obj/longzhu1");
}

int accept_fight(object me)
{
  command("jump");
  command("say 我最喜欢打架了。咱们比划比划！");
  return 1;
}


