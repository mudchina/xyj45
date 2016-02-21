// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// created 4/5/1997 by snowcat
#include <ansi.h>
#define NAME "西梁披霜仙后"

inherit NPC;

void create()
{
  set_name(NAME, ({"xiliang xianhou", "queen"}));
  set("title", "晨曦女神");
  set("gender", "女性");
  set("age", 23);
  set("long", "西梁披霜仙后晨曦女神。\n");
  set("combat_exp", 1000000);
  set_skill("snowsword", 100);
  set_skill("sword", 100);
  set_skill("unarmed", 100);
  set_skill("dodge", 120);
  set_skill("parry", 120);
  set_skill("dragonstep", 120);
  map_skill("dodge", "dragonstep");
  map_skill("sword", "snowsword");
  map_skill("parry", "snowsword");
  set("force", 900);
  set("max_force", 900);
  set("force_factor", 10);

  setup();
  carry_object("/d/obj/cloth/skirt")->wear();
  carry_object("/d/obj/weapon/sword/feijian")->wield();
}

void init()
{
  ::init();
}

void announce_success(object who, string reason)
{
  int i;

  i = random(500);
  message_vision (HIY NAME+"在一阵白雾中徐徐降临。\n" NOR,who);
  who->add("obstacle/number",1);
  who->set("obstacle/nuerguo","done");
  who->add("combat_exp",i+3000);
  command("chat "+who->query("name")+reason+"，顺利闯过西行一关！");
  command("chat 西梁上下奔走相告！");
tell_object(who,"你赢得了"+chinese_number(3)+"年"+chinese_number(i/4)+"天"+chinese_number((i-(i/4)*4)*3)+"时辰的道行！");
  //command("chat "+who->name()+"赢得了"+chinese_number(i)+"时辰的道行！");
  who->save();
  message_vision (HIY NAME+"在一阵白雾中徐徐消失。\n" NOR,who);
}

void refuse_player(object who)
{
  string name;
  name = who->name();

  message_vision (HIY NAME+"突然从白雾中闪出向$N摇摇头："+
                  "您已闯过西梁这一关了。快去西天取经吧。\n" NOR,who);
  message_vision (HIY "说罢"+NAME+"在一阵白雾中徐徐消失。\n" NOR,who);
}

void stop_access(object who)
{
  string name;
  name = who->name();

  message_vision (HIY NAME+"从一团白雾中显出，告诉$N："+
                  "您尚未闯过西梁这一关，对不起。\n" NOR,who);
  message_vision (HIY "说罢白雾拥着"+NAME+"在空中慢慢地消失。\n" NOR,who);
}
