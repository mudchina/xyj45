// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// created 12/18/1997 by snowcat

inherit NPC;

void create()
{
  set_name("黄眉老佛", ({ "huangmei laofo", "huangmei", "laofo", "fo" }));
  set("title", "小雷音寺");   
  set("long", "一位面无表情却又精神焕发的老佛。\n");
  set("gender", "男性");
  set("age", 80);
  set("attitude", "heroism");
  set("per", 30);
  set("max_kee", 1600);
  set("max_gin", 1600);
  set("max_sen", 1600);
  set("force", 1600);
  set("max_force", 1600);
  set("force_factor", 75);
  set("max_mana", 1600);
  set("mana", 1600);
  set("mana_factor", 75);
  set("combat_exp", 1450000);
  set_skill("spells", 75);
  set_skill("buddhism", 75);
  set_skill("unarmed", 75);
  set_skill("jienan-zhi", 75);
  set_skill("dodge", 75);
  set_skill("lotusmove", 75);
  set_skill("parry", 75);
  set_skill("force", 75);
  set_skill("staff", 75);
  set_skill("mace", 75);
  set_skill("lotusforce", 75);
  set_skill("lunhui-zhang", 75);
  set_skill("jinglei-mace", 75);
  map_skill("spells", "buddhism");
  map_skill("unarmed", "jienan-zhi");
  map_skill("dodge", "lotusmove");
  map_skill("force", "lotusforce");
  map_skill("parry", "jinglei-mace");
  map_skill("mace", "jinglei-mace");
  setup();
  carry_object("/d/obj/cloth/jia_sha")->wear();
  carry_object("/d/qujing/xiaoxitian/obj/mace")->wield();
  if ("/d/qujing/xiaoxitian/obj/baoreal"->in_mud())
    carry_object("/d/qujing/xiaoxitian/obj/baofake");
  else
    carry_object("/d/qujing/xiaoxitian/obj/baoreal");
}

void destruct_me (object me)
{
  destruct (me);
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  object fabao = present ("fabao",me);

  if (ob)
  {
    ob->set_temp("obstacle/xiaoxitian_killed",1);
    call_out ("mile_appearing",1,ob);
  }
  message_vision ("\n旋风出现，弥勒佛祖走了进来。\n",me);
  message_vision ("\n$N连忙慌着跪了下来，却还身作一黄眉小童。\n",me);
  message_vision ("弥勒佛祖领着黄眉小童走了出去",me);
  if (fabao)
  {
     message_vision ("，丢下一只$n。\n",me,fabao);
     fabao->move(environment(me));
  }
  else
    message_vision ("。\n",me);
  load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",3,me);
}

void mile_appearing (object who)
{
  object mile = new ("/d/qujing/xiaoxitian/npc/mile");

  mile->announce_success (who);
  destruct (mile); 
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
  call_out ("hurting",random(5)+5,me,ob);  
  ::kill_ob(ob);
}

void hurting (object me, object ob)
{
  object fabao = present ("fabao",me);

  if (fabao)
    fabao->ji_ob (ob);

  remove_call_out ("hurting");  
  call_out ("hurting",random(10)+10,me,ob);  
}

