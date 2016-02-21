// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat 11/6/1997

inherit NPC;

int test_player (object me);
object copy_yao(object ob);

void create()
{
  set_name("国王", ({"guo wang", "wang", "king"}));
  set("long", "朱紫国的国王，头戴朱金冠，手执紫金杖。\n");
  set("title", "朱紫国");
  set("gender", "男性");
  set("rank_info/respect", "陛下");
  set("age", 46);
  set("per", 30);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 200000);
  set_skill("unarmed", 100);
  set_skill("dodge", 100);
  set_skill("parry", 100);
  set("max_gin",800);
  set("max_kee",800);
  set("max_sen",800);
  set("max_force",1000);
  set("max_mana",1000);
  set("force_factor",120);
  set("eff_dx",15000);
  set("nkgain",90);
  set("inquiry", ([
        "name":   "朕乃朱紫国国王也，近来身体不适，久医难愈。",
        "王后":   "朕之后，唯金圣宫后已别三年矣。",
        "金圣宫": "金圣宫不在已三年矣。",
        "不适":   (: test_player :),
        "病":     (: test_player :),
        "医":     (: test_player :),
        "医治":   (: test_player :),
        "医疗":   (: test_player :),
        "药":     (: test_player :),
        "吃药":   (: test_player :),
      ]));

  setup();
  carry_object("/d/obj/cloth/longpao")->wear();
}

void throw_player (object who)
{
  object me = this_object();

  message_vision ("$N喝了一声：送客！\n", me, who);
  message_vision ("几位太监走来二话不说架起$N就走。\n", who);
  who->move("/d/qujing/zhuzi/hugong1");
  call_out ("in_river",1,who);
  me->start_busy(1,1);
}

void in_river (object who)
{
  message_vision ("$N缓过神来，发现自己被扔在冰冷的护宫河水里。\n", who);
}

void inform_player (string msg, object who)
{
  object me = this_object();

  message_vision (msg, me, who);
}

int test_player (object me)
{
  object who = this_player();
  string msg = "$N说道：这位"+RANK_D->query_respect(who);

  if (who->query("combat_exp")<10000)
  {
    inform_player (msg+"道行不够，怕是庸医也！\n",who);
    call_out("throw_player",1,who);
    return 1;
  }  

  if (who->query("obstacle/zhuzi") == "done" ||
      who->query_temp("obstacle/zhuzi_cured"))
  {
    inform_player (msg+"，多谢多谢，朕再拜顿首！\n",who);
    return 1;
  }  

  if (this_object()->query_temp("cured"))
  {
    inform_player (msg+"不必多虑，朕已康复！\n",who);
    return 1;
  }  

  inform_player (msg+"，可否为朕寻得乌金丹？\n",who);
  who->set_temp("obstacle/zhuzi_asked",1);
  call_out ("wait_player",300,who);
  return 1;
}

void wait_player (object who)
{
  if (who)
    who->set_temp("obstacle/zhuzi_waited",1);
}

int accept_object (object who, object ob)
{
  object me = this_object();
  object ob2;
  string msg = "$N说道：这位"+RANK_D->query_respect(who);

  if (ob->query("id") != "yao")
  {
    inform_player (msg+"，朕已拥有江山社稷，岂可用这小恩惠打动朕心！\n",who);
    call_out("throw_player",1,who);
    call_out("destroy_object",1,ob);
    return 1;    
  }

  if (who->query("combat_exp")<10000)
  {
    inform_player (msg+"道行不够，怕是假药也！\n",who);
    call_out("throw_player",1,who);
    call_out("destroy_object",1,ob);
    return 1;
  }  

  if (who->query("obstacle/zhuzi") == "done" ||
      who->query_temp("obstacle/zhuzi_cured"))
  {
    inform_player (msg+"，多谢多谢，朕再拜顿首！\n",who);
    call_out("destroy_object",1,ob);
    return 1;
  }  

  if (this_object()->query_temp("cured"))
  {
    inform_player (msg+"不必多虑，朕已康复！\n",who);
    call_out("destroy_object",1,ob);
    return 1;
  }  

  if (! who->query_temp("obstacle/zhuzi_waited"))
  {
    inform_player (msg+"，乌金丹乃贵重之药，久寻才可得，这药怕是有假！\n",who);
    call_out("delayed_vision",1,"$N将药往旁边玉桶里一扔。\n",me);
    call_out("destroy_object",1,ob);
    return 1;
  }  

  message_vision ("$N接下药，对$n连声道谢。\n",me,who);
  call_out("delayed_vision",3,
           "早有几位宫女进来，伺候着$N将药用无根水服下。\n",me); 
  ob2 = copy_yao(ob);
  call_out("eat_drug",1,me,ob2,who);
  return 1;
}

void delayed_vision (string msg, object me)
{
  message_vision (msg,me);  
}

void destroy_object (object ob)
{
  destruct (ob);
}

void eat_drug (object me, object ob, object who)
{
  int i = who->query_temp("obstacle/zhuzi_given");

  if (! ob->query_temp("is_ready"))
  {
    message_vision ("$N突然一阵子腹痛，不禁大声呻吟起来。\n",me,who);
    message_vision ("$N说道：假药，假药也！\n",me,who);
    call_out("throw_player",1,who);
    destruct (ob);
    return;
  }
  if (i < 2)
  {
    message_vision ("少顷，$N渐觉心胸宽泰，气血调和一些了。\n",me);
    me->command_function("thank "+who->query("id"));
  }
  else
  {
    message_vision ("$N终于吐出一些秽物，精神抖擞起来，脸色也恢复了。\n",me);
    message_vision ("\n$N对$n说道：恩人情重如山，寡人酬谢不尽！\n",me,who);
    me->set_temp("cured",1);
    who->set_temp("obstacle/zhuzi_cured",1);
    call_out("say_more",5,me,who);
  }
  who->set_temp("obstacle/zhuzi_given",i+1);
  destruct (ob);
}

void say_more (object me, object who)
{
  message_vision ("\n$N说道：方才吐出的秽物，乃三年之积滞也。\n",me);
  message_vision ("$N又说道：三年了，朕无昼无夜地思念金圣宫。\n",me);
  call_out("say_more2",3,me,who);
}

void say_more2 (object me, object who)
{
  message_vision ("\n$N想想对$n说道：恩人可否替朕救金圣王后回宫？\n",me,who);
}

// by wuliao.
// since the give command destruct the object quickly, we need get a new object
// with the same attributes
object copy_yao ( object me )
{
   object who = new ( "/d/qujing/zhuzi/obj/yao.c");

   who -> set("name", me->query("name"));
   who -> set_temp("is_ready", me->query_temp("is_ready") );
   who -> move(this_object());
   
   return who;
