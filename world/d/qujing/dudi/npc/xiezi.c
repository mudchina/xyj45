// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// created 12/18/1997 by snowcat

inherit NPC;

void create()
{
  set_name("蝎子精", ({ "xiezi jing", "xiezi", "jing" }));
  set("title", "琵琶洞");   
  set("long", "一位艳色迷人的女妖精。\n");
  set("gender", "女性");
  set("age", 26);
  set("attitude", "heroism");
  set("per", 29);
  set("max_kee", 1500);
  set("max_gin", 1500);
  set("max_sen", 1500);
  set("force", 1200);
  set("max_force", 1200);
  set("force_factor", 30);
  set("max_mana", 600);
  set("mana", 600);
  set("mana_factor", 30);
  set("combat_exp", 450000);
  set_skill("spells", 50);
  set_skill("dao", 50);
  set_skill("unarmed", 45);
  set_skill("baihua-zhang", 45);
  set_skill("dodge", 80);
  set_skill("moondance", 70);
  set_skill("parry", 85);
  set_skill("force", 70);
  set_skill("fork", 80);
  set_skill("moonforce", 70);
  set_skill("fengbo-cha", 80);
  map_skill("spells", "dao");
  map_skill("unarmed", "baihua-zhang");
  map_skill("fork", "fengbo-cha");
  map_skill("parry", "fengbo-cha");
  map_skill("dodge", "moondance");
  map_skill("force", "moonforce");
  setup();
  carry_object("/d/obj/cloth/skirt")->wear();
  carry_object("/d/qujing/dudi/obj/cha")->wield();
}

int test_player (object who)
{
  string *names;
  string name;
  int len;

  if (! who)
    return 0;

  names = who->query_temp("apply/name");
  if (! names)
    return 0;

  if (sizeof(names) < 1)
    return 0;

  name = names[0];
  len = strlen (name);
  if (len < 1)
    return 0;

  if (name[len-2..len-1] != "鸡")
    return 0;

  return 1;    
}

void disappear_me (object me)
{
  message_vision ("\n$N往外一闪，逃得无影无踪！\n",me);
  destruct (me);
}

void destruct_me (object me)
{
  destruct (me);
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");

  if (! ob)
  {
    disappear_me(me);
    return;
  }

  if (! test_player(ob))
  {
    disappear_me(me);
    return;
  }

  ob->set_temp("obstacle/dudi_killed",1);
  call_out ("maoxiu_appearing",1,ob);
  message_vision ("\n$N浑身酥软趴在地上，原来是一只琵琶大小的毒蝎子。\n",me);
  message_vision ("\n天空闪过昴宿星官的影子，将蝎子拾起驾云而去。\n",me);
  load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",3,me);
}

void maoxiu_appearing (object who)
{
  object maoxiu = new ("/d/qujing/dudi/npc/maoxiu");

  maoxiu->announce_success (who);
  destruct (maoxiu); 
}

void unconcious ()
{
  die ();
}

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
  call_out ("disappearing",1,me,ob);  
  call_out ("hurting",random(5)+5,me,ob);  
  ::kill_ob(ob);
}

void disappearing (object me, object ob)
{
  if (! me)
    return;

  if (! ob)
    return;

  if (environment(ob) != environment(me))
    return;

  if ((! test_player(ob)) &&
       (me->query("kee") < (me->query("max_kee")/4) ||
        me->query("sen") < (me->query("max_sen")/4)))
  {
    disappear_me(me);
  }
  call_out ("discovering",1,me,ob);  
}

void hurting (object me, object ob)
{
  string *msgs = ({
    "$N将裙角一掀，抬起毒刺向$n一扎！\n",
    "$N一转身，一个倒马桩向$n刺去！\n",
    "$N跳起往$n的头上一扎！\n",
  });
  string *strs = ({
    "( $N大叫一声：好痛！ )\n",
    "( $N抱起肿起的头忍不住惨叫一声！ )\n",
    "( $N的头上立刻肿起一大块红红的脑门痈！ )\n",
  });
  int damage;

  if (! me)
    return;

  if (! ob)
    return;

  if (environment(ob) != environment(me))
    return;
 
  message_vision ("\n"+msgs[random(sizeof(msgs))],me,ob);
  
  if (! test_player(ob))
  {
    message_vision (strs[random(sizeof(strs))],ob);
    damage = ob->query("max_kee")/(7+random(3));
    ob->add("kee",-damage); 
    ob->add("eff_kee",-damage); 
    ob->add("sen",-damage); 
    ob->add("eff_sen",-damage); 
  }
  else
  {
    message_vision ("只见$N发出一声鸡叫，"+
                    "$n顿时慌乱地放下裙子收起倒马桩！\n",ob,me);
  }
  remove_call_out ("hurting");  
  call_out ("hurting",random(10)+10,me,ob);  
}
