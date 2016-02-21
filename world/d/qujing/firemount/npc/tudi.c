// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// rewritten by snowcat on 4.12.1997

inherit NPC;

void create()
{
  set_name("土地", ({"tudi","tu di"}));
  set("gender", "男性");
  set("age", 100);
  set("long","专管火焰山方园八百里的老土地爷爷。"+
      "他本是老君兜率宫中看炉的道士，因失职而被罚下凡界。\n");
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

  carry_object("/d/gao/obj/changpao")->wear();
  add_money("coin", 100);

}

int allow_search()
{
  object me = this_object();
  object who = this_player();

  who->set_temp("know_palm_bone",1);
  message_vision("$N说：芭蕉骨就在翠云山里，可以去找(search)。\n",me,who);
  return 1;
}

void init()
{
  object ob;

  ::init();
  set("inquiry", ([
       "here": "这儿有火焰山，铁扇公主，铁扇，芭蕉骨。\n",
       "火焰山": "火焰山八百里大火，凡人实是插翅难飞。\n",
       "铁扇公主": "她就住在翠云山中，真是一个女菩萨。\n",
       "芭蕉骨": (: allow_search :),
      ]));

  if (interactive(ob = this_player()) && !is_fighting()&&       
     ob->query_temp("push_nixiang")>0)
  {
    remove_call_out("greeting");
    call_out("greeting", 1, ob);
  }       
}

void greeting(object ob)
{
  if (!ob || environment(ob) != environment())
    return;
  say ("土地作了作揖：不知"+RANK_D->query_respect(ob)+"召老朽来有何贵干？\n");
}

