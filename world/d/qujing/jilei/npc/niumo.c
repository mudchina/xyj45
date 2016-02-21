// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// created 12/18/1997 by snowcat

inherit NPC;

void create()
{
  set_name("牛魔王", ({ "niumo wang", "niumo", "wang" }));
  set("title", "大力王");   
  set("long", "一位身材魁伟力大无比的魔王，一双牛蛋眼正煞神一般瞪着你。\n");
  set("gender", "男性");
  set("age", 70);
  set("attitude", "heroism");
  set("per", 30);
  set("max_kee", 1700);
  set("max_gin", 1700);
  set("max_sen", 1700);
  set("force", 1700);
  set("max_force", 1700);
  set("force_factor", 125);
  set("max_mana", 1700);
  set("mana", 1700);
  set("mana_factor", 45);
  set("combat_exp", 1250000);
  set_skill("spells", 100);
  set_skill("buddhism", 100);
  set_skill("unarmed", 150);
  set_skill("jienan-zhi", 150);
  set_skill("dodge", 40);
  set_skill("lotusmove", 80);
  set_skill("parry", 45);
  set_skill("force", 90);
  set_skill("lotusforce", 90);
  map_skill("spells", "buddhism");
  map_skill("unarmed", "jienan-zhi");
  map_skill("dodge", "lotusmove");
  map_skill("force", "lotusforce");
  set("nb_heads",10);
  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
  call_out ("riding",1);
}

void riding ()
{
  command ("mount jinjing shou");
}

void destruct_me (object me)
{
  destruct (me);
}

int check_heads (object me, object ob)
{
  int nb_heads = query("nb_heads")-1;
  object weapon;
  object head;

  me->set("nb_heads",nb_heads);
  if (! ob)
    return nb_heads;
  if (nb_heads <= 0)
    return nb_heads;

  weapon = ob->query_temp("weapon");

  if (! weapon)
    message_vision ("\n$N大喝一声扑向$n，以排山倒海之势将$n的牛头扳了下来。\n",ob,me);
  else if (weapon->query("skill_type") == "axe")
    message_vision ("\n$N高高举起$n，排山倒海地大喝一声，将牛头劈了下来。\n",ob,weapon);
  else if (weapon->query("skill_type") == "blade")
    message_vision ("\n$N高高举起$n，排山倒海地大喝一声，将牛头砍了下来。\n",ob,weapon);
  else if (weapon->query("skill_type") == "sword")
    message_vision ("\n$N高高举起$n，排山倒海地大喝一声，将牛头削了下来。\n",ob,weapon);
  else if (weapon->query("skill_type") == "dagger")
    message_vision ("\n$N高高举起$n，排山倒海地大喝一声，将牛头割了下来。\n",ob,weapon);
  else if (weapon->query("skill_type") == "fork")
    message_vision ("\n$N高高举起$n，排山倒海地大喝一声，将牛头叉了下来。\n",ob,weapon);
  else if (weapon->query("skill_type") == "hammer")
    message_vision ("\n$N高高举起$n，排山倒海地大喝一声，将牛头砸了下来。\n",ob,weapon);
  else if (weapon->query("skill_type") == "spear")
    message_vision ("\n$N高高举起$n，排山倒海地大喝一声，将牛头挑了下来。\n",ob,weapon);
  else if (weapon->query("skill_type") == "staff")
    message_vision ("\n$N高高举起$n，排山倒海地大喝一声，将牛头扫了下来。\n",ob,weapon);
  else if (weapon->query("skill_type") == "stick")
    message_vision ("\n$N高高举起$n，排山倒海地大喝一声，将牛头扫了下来。\n",ob,weapon);
  else if (weapon->query("skill_type") == "throwing")
    message_vision ("\n$N高高举起$n，排山倒海地大喝一声，将牛头射了下来。\n",ob,weapon);
  else if (weapon->query("skill_type") == "whip")
    message_vision ("\n$N高高举起$n，排山倒海地大喝一声，将牛头抽了下来。\n",ob,weapon);
  else if (weapon->query("skill_type") == "mace")
    message_vision ("\n$N高高举起$n，排山倒海地大喝一声，将牛头抽了下来。\n",ob,weapon);
  else
    message_vision ("\n$N大喝一声扑向$n，以排山倒海之势将$n的牛头扳了下来。\n",ob,me);
  
  head = new ("/d/qujing/jilei/obj/head");
  head->move(environment(me));
  return nb_heads;
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");

  if (check_heads (me, ob) > 0)
  {
    set("kee", 1700);
    set("gin", 1700);
    set("sen", 1700);
    set("eff_kee", 1700);
    set("eff_gin", 1700);
    set("eff_sen", 1700);
    set("force", 1700);
    set("mana", 1700);
    message_vision ("\n只见牛腔里摇摇晃晃又钻出一个牛头来！\n",me);
    if (ob)
      message_vision ("\n$N精神抖擞地又向$n发起攻击！\n",me,ob);
    return;
  }

  if (ob)
  {
    ob->set_temp("obstacle/jilei_niumo_killed",1);
    call_out ("li_appearing",1,ob);
  }
  message_vision ("\n天上托塔李天王大吼一声：牛魔归佛也！\n",me);
  message_vision ("\n$N闻声软了下来，还原成一只大白牛，喘着热气。\n",me);
  message_vision ("李天王走过来，用金链拴在牛鼻子上，将$N牵走了。\n",me);
  load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",3,me);
}

void li_appearing (object who)
{
  object li = new ("/d/qujing/jilei/npc/li");

  li->announce_success (who);
  destruct (li); 
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

int test_player (object who)
{
  string *names;
  string name;

  names = who->query_temp("apply/name");
  if (! names)
    return 0;

  if (sizeof(names) < 1)
    return 0;

  name = names[0];

  if (name == "铁扇公主")
    return 1;
//  if (name == "玉面公主")
//    return 1;
  return 0;
}

void kill_ob (object ob)
{
  object me = this_object();
  object where = environment (me);
  object yumian = present ("yumian gongzhu", where);

  if (! test_player (ob))
  {
    message_vision ("$N一双牛蛋眼瞪着你，大吼一声：你！你！滚！\n",me);
    message_vision ("$N现了大白牛的原形向$n扑来，疯狂地低头一顶！\n",me,ob);
    message_vision ("$N一个措手不及，凌空飞起！\n",ob);
    ob->move("/d/qujing/jilei/shidong");
    message_vision ("“轰”地$N摔将下来！\n",ob);
    ob->unconcious();
    return;
  }
  message_vision ("\n$N大怒：哪个泼贼子冒充俺浑家！\n",me);

  set_temp("my_killer",ob);
  call_out ("checking",1,me,ob);  
  ::kill_ob(ob);
  if (yumian && (! interactive(yumian)) && !yumian->is_fighting())
    yumian->kill_ob(ob);
}

void checking (object me, object ob)
{
  object fabao = present ("fabao",me);

  if (me->is_fighting())
  {
    remove_call_out ("checking");  
    call_out ("checking",1,me,ob);  
  }
  else
  {
    int i = 50 - ob->query("kar");

    if (i < 10)
      i = 10;
    me->set("nb_heads",i);
  }
}


