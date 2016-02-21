// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// created 11/20/1997 by snowcat

inherit NPC;

void create()
{
  set_name("道士", ({ "dao shi", "dao", "shi" }));
  set("title", "黄花五公");   
  set("long", "一位欲神欲仙的黄花观五公道士。");
  set("gender", "男性");
  set("age", 40);
  set("attitude", "heroism");
  set("per", 29);
  set("max_kee", 1500);
  set("max_gin", 1500);
  set("max_sen", 1500);
  set("force", 1200);
  set("max_force", 1200);
  set("force_factor", 100);
  set("max_mana", 600);
  set("mana", 600);
  set("mana_factor", 80);
  set("combat_exp", 550000);
  set_skill("spells", 120);
  set_skill("dao", 100);
  set_skill("unarmed", 90);
  set_skill("puti-zhi", 85);
  set_skill("dodge", 10);
  set_skill("jindouyun", 70);
  set_skill("qianjun-bang", 70);
  set_skill("parry", 85);
  set_skill("force", 70);
  set_skill("wuxiangforce", 70);
  set_skill("staff", 50);
  map_skill("spells", "dao");
  map_skill("unarmed", "puti-zhi");
  map_skill("dodge", "jindouyun");
  map_skill("force", "wuxiangforce");
  map_skill("parry", "qianjun-bang");
  setup();
  carry_object("/d/obj/cloth/daopao")->wear();
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  if (ob && 
      ! ob->query_temp("obstacle/pansi_killed_"+me->query("name")))
  {
    ob->set_temp("obstacle/pansi_killed_"+me->query("name"),1);
    ob->add_temp("obstacle/pansi_killed",1);
  }
  if (ob &&
      ob->query_temp("obstacle/pansi_killed")>=15 &&
      ob->query("obstacle/pansi")!="done")
  {
    call_out ("daogu_appearing",1,ob);
  }
  message_vision ("\n$N扑倒在尘埃里，现身为一七尺蜈蚣精。\n",me);
  message_vision ("\n蜈蚣精化为一股青烟噌地消散了。\n",me);
  load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",3,me);
}

void daogu_appearing (object who)
{
  object daogu = new ("/d/qujing/pansi/npc/daogu");

  daogu->announce_success (who);
  destruct (daogu); 
}

void destruct_me(object me)
{
  destruct(me);
}

void unconcious ()
{
  die ();
}

/*
void fight_ob (object ob)
{
  object me = this_object();

  call_out ("recovering",1,me,ob);  
  call_out ("hurting",random(5)+5,me,ob);  
}
*/

int accept_fight(object ob)
{
  ob->apply_condition("killer", 100);
  kill_ob(ob);
  return 1;
}

void kill_ob (object ob)
{
  object me = this_object();

  set_temp("my_killer",ob);
  call_out ("recovering",1,me,ob);  
  call_out ("hurting",random(5)+5,me,ob);  
  ::kill_ob(ob);
}

void recovering (object me, object ob)
{
  object needle;

  if (! me)
    return;

  if (! ob)
    return;

  //if (! me->is_fighting())
  //   return;

  if (environment(ob) != environment(me))
    return;

  needle = present("xiuhua zhen",ob);
  if ((! needle ||
       needle != ob->query_temp("weapon")) &&
       (me->query("kee") < (me->query("max_kee")*3/4) ||
        me->query("sen") < (me->query("max_sen")*3/4)))
  {
    message_vision ("\n$N身上万道金光一闪，顿时精神气血尽回！\n",me);
    me->set("gin",me->query("max_gin"));
    me->set("kee",me->query("max_kee"));
    me->set("sen",me->query("max_sen"));
    me->set("eff_gin",me->query("max_gin"));
    me->set("eff_kee",me->query("max_kee"));
    me->set("eff_sen",me->query("max_sen"));
  }
  call_out ("recovering",1,me,ob);  
}

void hurting (object me, object ob)
{
  string *msgs = ({
    "$N将衣一掀，无数道金光向$n一射！\n",
    "$N一抬手，胁下千只眼睛金光闪闪射向$n！\n",
    "$N掀起胳膊下无数只眼睛迸出金光直射向$n！\n",
  });
  string *strs = ({
    "( $N一个趔趄不由自主地惨叫一声！ )\n",
    "( $N应声倒下，又勉强爬将起来！ )\n",
    "( $N痛苦地惨嚎了一声！ )\n",
  });
  object needle;
  int damage;

  if (! me)
    return;

  if (! ob)
    return;

  //if (! me->is_fighting())
  //  return;

  if (environment(ob) != environment(me))
    return;
 
  message_vision ("\n"+msgs[random(sizeof(msgs))],me,ob);
  
  needle = present("xiuhua zhen",ob);
  if (! needle ||
      needle != ob->query_temp("weapon") ||
      random(3) == 0)
  {
    message_vision (strs[random(sizeof(strs))],ob);
    damage = ob->query("max_kee")/(6+random(4));
    ob->add("kee",-damage); 
    ob->add("eff_kee",-damage); 
    ob->add("sen",-damage); 
    ob->add("eff_sen",-damage); 
  }
  else
  {
    message_vision ("但见$N手上绣花针一闪，"+
                    "$n嚎叫一声，胁下几只眼睛顿时灭去！\n",ob,me);
  }
  remove_call_out ("hurting");  
  call_out ("hurting",random(10)+10,me,ob);  
}
