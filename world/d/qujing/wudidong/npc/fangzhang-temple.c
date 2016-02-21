// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// fangzhang.c
// created by mes, updated 6-21-97 pickle

#include <ansi.h>
inherit NPC;

void create()
{
  set_name("圆清",({"yuan qing", "yuan", "qing", "fang zhang", "monk", "yuanqing"}));
  set("title","方丈");
  set("gender", "男性");
  set("age", 80);
  set("long","一个白白胖胖的老和尚，和昔日牢房那模样简直是判若两人。\n");
  set("combat_exp",5000);
  set("str",30);
  set("per",30);
  set("int",30);
  set("attitude", "peaceful");
  set("inquiry", ([
        "name" : "老纳是这里的主持，法号圆清。\n",
        "井" : "不知为和，院里那口井有时发出“咕咚咕咚”的怪声音，\n
寺里没人会水，所以也无法下去看个明白。",
        "石井" : "不知为何，院里那口井有时发出“咕咚咕咚”的怪声音，\n
寺里没人会水，所以也无法下去看个明白。",
        ]));
  set("chat_chance",2);
  set("chat_msg",({
    "圆清自言自语，说道：“院里的石井中了邪了。”\n",
 }));
  setup();
  carry_object("/obj/cloth")->wear();
}
void init()
{
  object me;

  ::init();
  if( interactive(me = this_player()) && !is_fighting() ) {
    remove_call_out("greeting");
    call_out("greeting", 1, me);
  }
}
void greeting(object me)
{
  if( !me || environment(me) != environment() ) return;
  say(CYN "圆清念了声佛，喜道：“原来是恩公驾到，请上坐，请上坐。”\n" NOR);
}
 

