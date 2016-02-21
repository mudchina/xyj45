// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// rewritten by snowcat on 4/12/1997
#include "cloudfog.h"

inherit NPC;
inherit F_MASTER;

void create()
{
  set_name("雾里云", ({"fog cloud", "fog"}));
  set("long", "红孩儿手下六健将，其中又是云里雾"+
              "和雾里云最受红孩儿的喜爱，洞中的群妖都受过他俩的指导。\n");
  set("gender", "男性");
  set("age", 20);
  set("attitude", "heroism");
  set("shen_type", 1);
  set("con", 30+random(5));
  set("max_kee", 500);
  set("max_gin", 500);
  set("max_sen", 500);
  set("force", 500);
  set("max_force", 500);
  set("force_factor", 20);
  set("max_mana", 500);
  set("mana", 500);
  set("combat_exp", 240000);
  set_skill("unarmed", 50);
  set_skill("dodge", 50);
  set_skill("parry", 50);
  set_skill("stick", 50);
  set_skill("spells", 30);
  set_skill("force", 50);
  create_family("翠云山芭蕉洞",3,"弟子");
  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
}

void attempt_apprentice(object ob)
{
  return; // disabled
  command("recruit " + ob->query("id") );
}

void init()
{
  ::init();
  set("inquiry", ([
        "princess" :   (: test_player :),
        "铁扇公主" :   (: test_player :),
        "公主"     :   (: test_player :),
      ]));
}


