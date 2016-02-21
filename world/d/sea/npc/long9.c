// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// long1.c
// created 6-6-97 pickle

#include <skill.h>

inherit NPC;
//inherit F_MASTER;

void create()
{
  set_name("椒图",({"shu tu","shu","tu","long","shutu","dragon"}));
  set("long","龙生九子不成龙，各有所好：椒图乃第九子，平生好闭。\n");
  set("gender", "男性");
  set("age", 41);
  set("title", "龙王九子之");
  set("class","dragon");
  set("attitude", "peaceful");
  set("max_kee", 1200);
  set("max_sen", 900);
  set("force", 900);
  set("max_force", 900);
  set("force_factor", 80);
  set("max_mana", 900);
  set("mana", 900);
  set("force_factor",50);

  set("str",30);
  set("con",30);
  set("per",10+random(10));
  set("bellicosity",500);
  set("cor",30);

  set("combat_exp", 900000+random(100000));
  set_skill("unarmed", 140);
  set_skill("dodge", 140);
  set_skill("force", 140);
  set_skill("parry", 140);
  set_skill("sword", 150);
  set_skill("spells", 120);
  set_skill("seashentong", 120);
  set_skill("dragonfight", 140);
  set_skill("dragonforce", 140);
  set_skill("sanqing-jian", 150);
  set_skill("dragonstep", 150);
  map_skill("spells", "seashentong");
  map_skill("unarmed", "dragonfight");
  map_skill("force", "dragonforce");
  map_skill("sword","sanqing-jian");
  map_skill("parry", "sanqing-jian");
  map_skill("dodge", "dragonstep");

        set("nkgain", 400);

  setup();  

  carry_object("/d/obj/armor/yinjia")->wear();
  carry_object("/d/sea/obj/dragonsword")->wield();
  carry_object("/d/sea/obj/longzhu9");
}

int accept_fight(object me)
{
  command("fear");
  command("say 俺就喜欢在屋里躲着，从来不喜欢打架。");
  command("say 不过既然" + RANK_D->query_respect(me) + "想比划两招，俺也只好奉陪了。");
  return 1;
}





