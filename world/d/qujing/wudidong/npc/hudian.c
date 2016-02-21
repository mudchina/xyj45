// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// hudian.c
// created by mes, updated 6-20-97 pickle
#include <ansi.h>
inherit NPC;

void create()
{
  set_name("护殿妖", ({"hudian yao", "yao", "hu dian", "hudian", "monster"}));
  set("long","一个膀阔腰圆的护殿妖，看上去道行不浅。\n");
  set("gender", "男性");
  set("age", 20+random(15));
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 130000);
  set_skill("unarmed", 100);
  set_skill("parry", 100);
  set_skill("dodge", 100);
  set_skill("blade", 100);
  set_skill("kugu-blade", 100);
  map_skill("blade", "kugu-blade");
  map_skill("parry", "kugu-blade");

  setup();
  carry_object("/d/obj/weapon/blade/blade")->wield();
  carry_object("/d/obj/armor/tenjia")->wear();
}
void init()
{
  object me;

  ::init();
  if( interactive(me = this_player()) && !is_fighting() ) {
    call_out("greeting", 1, me);
  }
}

void greeting(object me)
{
  int myspells, mykar, diff;
  string npcname=this_object()->query("name");

  if( !me || environment(me) != environment() ) return;

  myspells=me->query_skill("spells");
  mykar=me->query_kar(); 
  diff=40-mykar;

  if(me->query("family/family_name") == "陷空山无底洞")
    return;
  if( member_array("tian shu",me->parse_command_id_list())==-1 &&
      member_array("yu shu",me->parse_command_id_list())==-1)
    {
      command("say 什么东西？竟敢在无底洞出入！");
      kill_ob(me);
      return;
    }
  if( random(myspells+mykar) > diff) return;
  else
    {
      message_vision(CYN ""+npcname+"对$N大喝道：呔！什么东西！？休想从老子眼下溜过去！\n"NOR, me);
      message_vision(npcname+"大喊一声：现！$N顿时现出原形，原来是"+me->query("name")+"！\n", me);
      me->delete_temp("spellslevel");
      me->delete_temp("d_mana");
      me->delete_temp("apply/name");
      me->delete_temp("apply/id");
      me->delete_temp("apply/short");
      me->delete_temp("apply/long"); 
      kill_ob(me);
      return;
    }
}









