// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// rewritten by snowcat on 4.12.1997

inherit NPC;

int give_fajian();

void create()
{
  set_name("白髯土地", ({"tu di", "tu", "di"}));
  set("gender", "男性");
  set("age", 100);
  set("attitude", "friendly");
  set("combat_exp", 250000);
  set("per", 25);
  set_skill("dodge", 60);
  set("max_sen",600);
  set("max_gee",600);
  set("max_gin",600);
  set("force",800);
  set("max_force",800);
  set("max_mana",800);
  set("force_factor",25);
  set_skill("spells",60);
  set_skill("stick",60);
  setup();

  set("inquiry", ([
       "here": "这儿是隐雾山，亦有连环洞在此。\n",
       "隐雾山": "隐雾山乃有连环洞之去处，多加小心为是。\n",
       "连环洞": "连环洞在隐雾山下连环相衔，有两个入口也。\n",
       "name": "隐雾山土地也，老夫别无他物，只有一宝。\n",
       "宝": "老夫有一法简，乃一锦一禅师所赠。\n",
       "法简": (: give_fajian :),
       "fajian": (: give_fajian :),
      ]));
  carry_object("/d/obj/cloth/choupao")->wear();

}

int give_fajian()
{
  object me = this_object();
  object who = this_player();
  object fajian;

  if (who->query("combat_exp") < 10000 ||
      present("fa jian",who))
  {
    command ("shake");
    return 1;
  }

  fajian = new ("/d/qujing/yinwu/obj/fajian");
  fajian->move(me);
  command("hmm");
  command("give "+who->query("id")+" fa jian"); 
  who->set_temp("obstacle/yinwu_fajian",1);
  return 1;
}

void init()
{
  object ob;

  ::init();
}

void call_out_announce_success (object who)
{
  call_out ("say_hi",1,who);
  call_out ("announce_success",2,who);
  call_out ("destruct_me",3,this_object());
}

void say_hi (object who)
{
  message_vision ("\n白髯土地向$N抱了一抱拳。\n",who);
}

void destruct_me (object me)
{
  message_vision ("$N往地下一钻便消失了。\n",me);
  destruct (me);
}

void announce_success (object who)
{
  int i;

  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/yinwu") == "done")
    return;
  if (! who->query_temp("obstacle/yinwu_fajian"))
    return;
  if (! who->query_temp("obstacle/yinwu_yaowang"))
    return;
  i = random(800);
  who->add("obstacle/number",1);
  who->set("obstacle/yinwu","done");
  who->add("combat_exp",i+3000);
  command("chat "+who->query("name")+"隐雾山施法，连环洞灭妖邪！");
  command("chat "+who->query("name")+"顺利闯过西行又一关！");
  tell_object (who,"你赢得了"+chinese_number(3)+"年"+
               chinese_number(i/4)+"天"+
               chinese_number((i-(i/4)*4)*3)+"时辰的道行！\n");
  who->save();
}
