// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat

inherit NPC;

#include <reporting.h>

void create()
{
  set_name("段志贤", ({ "duan zhixian", "duan", "zhixian", "da chen" }));
  set("title", "大臣");
  set("gender", "男性");
  set("age", 60);
  set("per", 30);
  set("combat_exp", 300000);
  set_skill("force", 80);
  set_skill("spells", 80);
  set_skill("unarmed", 80);
  set_skill("dodge", 80);
  set_skill("parry", 80);
  set("gin", 3000);
  set("max_gin", 3000);
  set("kee", 3000);
  set("max_kee", 3000);
  set("sen", 3000);
  set("max_sen", 3000);
  set("force", 1000);
  set("max_force", 1000);
  set("mana", 1000);
  set("max_mana", 1000);
  set("force_factor", 80);
  setup();
  carry_object("/d/obj/cloth/jinpao")->wear();
}

void reward (object who)
{
  object me = this_object ();
  int points = who->query("quest/reward");
  string channel = "sldh";
  string *channels = who->query("channels");

  if ( !pointerp(channels) || !sizeof(channels) )
    channels = ({ channel });
  else if (member_array(channel, channels) == -1)
    channels += ({ channel });

  who->set("channels",channels);

  if( points > 150 ) {
    points = 140+random(10);
  }

  message_vision ("$N对$n一拜：陛下有旨，赐"+RANK_D->query_respect(who)+
                  chinese_number(points)+"点潜能！\n",me,who);
/*
  command (channel+" "+who->query("name")+who->query("quest/reason")+"陛下有旨，赐"+
           chinese_number(points)+"点潜能！");
*/                  
  who->add("quest/gain/potential",points);
  reporting (who, who->query("quest/reason"), points, "点潜能");
  who->add("potential",points);
}


