// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// snowcat 12 14 1997

inherit NPC;

#include <obstacle.h>

#define DEBUG 0

#define LEVEL_NONE 0
#define LEVEL_ASKED 1

int reward_player ();
int recover_death ();

void create()
{
  set_name("如来佛", ({ "rulai fo", "rulai", "fo" }));
  set("title", "佛祖多陀阿伽陀");
  set("long", "大慈大悲灵山雷音古刹佛祖多陀阿伽陀如来佛爷。\n");
  set("gender", "男性");
  set("age", 10000);
  set("attitude", "peaceful");
  set("rank_info/self", "贫僧");
  set("rank_info/respect", "佛祖爷爷");
  //set("class", "bonze");
  set("str",100);
  set("per",100);
  set("max_kee", 10000);
  set("max_gin", 10000);
  set("max_sen", 10000);
  set("force", 10000);
  set("max_force", 10000);
  set("force_factor", 500);
  set("max_mana", 10000);
  set("mana", 10000);
  set("mana_factor", 500);
  set("combat_exp", 4000000);
  set_skill("literate", 300);
  set_skill("spells", 300);
  set_skill("buddhism", 300);
  set_skill("unarmed", 300);
  set_skill("jienan-zhi", 300);
  set_skill("dodge", 300);
  set_skill("lotusmove", 300);
  set_skill("parry", 300);
  set_skill("force", 300);
  set_skill("lotusforce", 300);
  set_skill("staff", 300);
  set_skill("lunhui-zhang", 300);
  map_skill("spells", "buddhism");
  map_skill("unarmed", "jienan-zhi");
  map_skill("dodge", "lotusmove");
  map_skill("force", "lotusforce");
  map_skill("parry", "lunhui-zhang");
  map_skill("staff", "lunhui-zhang");
  set("chat_chance_combat", 80);
  set("chat_msg_combat", ({
   (: cast_spell, "bighammer" :),
  }) );
  set("inquiry", ([
    "die" : (: recover_death :),
    "death" : (: recover_death :),
    "recover" : (: recover_death :),
    "起死回生" : (: recover_death :),
    "复生" : (: recover_death :),
    "死" : (: recover_death :),
    "生" : (: recover_death :),
    "qujing" : (: reward_player :),
    "obstacle" : (: reward_player :),
    "obstacles" : (: reward_player :),
    "取经" : (: reward_player :),
    "经" : (: reward_player :),
  ]) );

  set("my_level",LEVEL_NONE);
  setup();
  carry_object("/d/obj/cloth/jia_sha")->wear();
}

void init ()
{
  add_action("do_back", "back");
}

void announce (object me, string str)
{
  if (DEBUG)
  { 
    object snowcat = find_player ("snowcat");
    if (snowcat && wizardp(snowcat))
      tell_object (snowcat,"◆ "+str+"\n");
  }
  else
  {
    CHANNEL_D->do_channel(me,"chat",str);
  }
}

int recover_death()
{
  object me = this_object();
  object who = this_player();

  if (who->query("obstacle/mud_age") > who->query("death/mud_age"))
  {
    message_vision ("$N对$n摇了摇头：老夫未闻死迅也。\n",me,who);
    return 1;
  }
  if (! who->query("obstacle/reward"))
  {
    message_vision ("$N对$n摇了摇头：你先去西域过关吧。\n",me,who);
    return 1;
  }
  if (who->query("obstacle/rebirth") >= 3)
  {
    message_vision ("$N对$n摇了摇头：你三根救命毫毛已用尽也。\n",me,who);
    return 1;
  }
  who->add("obstacle/rebirth",1);
  message_vision ("\n$N拔出一根救命毫毛，佛手一扬……。\n",me);
  message_vision ("\n$N顿觉天悬地转乾坤倒置，刹那间禁不住浑身颤抖！\n",who);
  if (who->query("death/combat_exp_loss"))
  {
    tell_object (who,"你突然发现你的道行全部恢复了！\n");
    who->add("combat_exp", (int)who->query("death/combat_exp_loss"));
  }
  if (who->query("death/skill_loss"))
  {
    tell_object (who,"你突然发现你的武功全部恢复了！\n");
    who->skill_death_recover();
  }
  who->delete("death");
  who->save();
  return 1;

}

void do_reward (object who)
{
  object me = this_object();
  int size1 = sizeof(obstacles);
  int size2;
  string *strs = values(obstacles);
  mapping skills = who->query_skills();
  int i;

  if (! interactive (who))
    return;

  if (who->query("obstacle/reward"))
    return;

  if (who->query_temp("no_move"))
    return;

  if (who->query("obstacle/number") < size1)
    return;

  size2 = sizeof(skills);

  message_vision ("宝殿里紫霞缭绕金光万道，$N见到如来真身浑身一软拜倒在地！\n",
                  who);
  message_vision ("\n$N对$n说："+RANK_D->query_respect(who)+
                  "一路上历经灾愆患难，万里迢迢苦尽功成也。\n",me,who);
  i = (size1+size2+2)*3;
  who->start_busy(i,i);
  who->set_temp("no_move",1);

  strs = (string *)sort_array (strs, 1);
  for (i = 0; i < size1; i++)
  {
    call_out("rewarding1",(i+1)*3,me,who,strs[i]);
  }
  call_out("rewarded1",(size1+1)*3,me,who);
  strs = keys(skills);
  for (i = 0; i < size2; i++)
  {
    call_out("rewarding2",(size1+i+2)*3,me,who,strs[i]);
  }
  call_out("rewarded2",(size1+size2+2)*3,size2,me,who);
}

void rewarding1 (object me, object who, string str)
{
  int i = 600+random(who->query("kar")*30);

  who->add("obstacle/reward",i);
  who->add("potential",i);
  message_vision ("\n$N说道："+str+"一关，奖$n"+chinese_number(i)+
                  "点潜能！\n",me,who);
  tell_object(who,"你的潜能增加了"+chinese_number(i)+"点！\n");
}

void rewarded1 (object me, object who)
{
  int i = who->query("obstacle/reward");

  remove_call_out("rewarding1");
  message_vision ("\n$N一点头：共计"+chinese_number(i)+"点潜能！\n",me);
  announce (me,who->query("name")+"西天取经历经灾愆，奖励"+
            chinese_number(i)+"点潜能！\n");
}

void rewarding2 (object me, object who, string str)
{
  int i = who->query_skill(str,1);
  string name = to_chinese(str);

  who->set_skill(str,i+1);
  message_vision ("\n$N说道：奖励一级"+name+"！\n",me,who);
  tell_object(who,"你的"+name+"增加了一级！\n");
}

void rewarded2 (int size, object me, object who)
{
  remove_call_out("rewarding2");
  message_vision ("\n$N一点头：共计"+chinese_number(size)+"级技能！\n",me);
  announce (me,who->query("name")+"西天取经功德无量，奖励"+
            chinese_number(size)+"级技能！\n");
  call_out("informing",1,me,who);
}

void informing (object me, object who)
{
  who->interrupt_me();
  who->set_temp("no_move",0);
  who->save();
  me->set("my_level",LEVEL_NONE);
  me->delete_temp("invite");
  message_vision ("\n$N对$n说：起身，可去宝阁取真经一本。\n",me,who);
  message_vision ("\n$N又补充道：日后若有不测，可来大雄宝殿起死回生三次。\n",
                  me);
}

int reward_player ()
{
  object me = this_object();
  object who = this_player();
  object *all, *list;
  int size1 = sizeof(obstacles);
  int i, j;

  if (me->query("my_level") == LEVEL_ASKED)
  {
    message_vision ("$N对$n摇头说道：老夫正忙。\n",me,who);
    return 1;
  }

  if (who->query("obstacle/reward"))
  {
    message_vision ("$N对$n说道：你不是已经来过了吗？\n",me,who);
    return 1;
  }

  if (who->query_temp("no_move"))
  {
    message_vision ("$N对$n摇摇头。\n",me,who);
    return 1;
  }

  if (who->query("obstacle/number") < size1)
  {
    message_vision ("$N对$n摇头说道：你尚未历尽难关。\n",me,who);
    return 1;
  }

  if (me->query("last_player") != who)
  {
    me->set("last_player",who);
    me->set_temp("invite","public");
    announce (me,who->query("name")+"不远万里前来取真经！");
    announce (me,"诸位仙贤如愿观礼，使accept rulai fo便可！\n");
    remove_call_out ("inviting");
    call_out ("inviting",1,me);
    return 1;
  }

  all = users();
  i = sizeof(all);
  list = all_inventory(environment(me));
  j = sizeof(filter_array(list, (:userp:))) - 1;

  if ((i/4-j) > 0)
  {
    message_vision ("$N对$n摇摇头：西游记现有"+chinese_number(i)+"位玩家，"
                    "此处仅有数位仙贤在邀，可否再邀"+chinese_number(i/4-j)+
                    "位仙贤前来观礼？\n",me,who);
    if (! DEBUG)                 
      return 1;
  }
  announce (me,"西游记西天取真经观礼："+who->query("name")+"大雄宝殿拜礼！\n");

  me->set("my_level",LEVEL_ASKED);
  do_reward (who);
  return 1;
}

void inviting (object me)
{
  int i;
  object *list;

  if (! me->query_temp("invite"))
    return;
  
  remove_call_out ("inviting");
  call_out ("inviting",4+random(4),me);

  list = users();
  i = sizeof(list);
  while  (i--)
  {
    string here, there;

    reset_eval_cost();
    if (!environment(list[i]))
      continue;
    if (environment(list[i])->query("unit")) // not a room
      continue;
    if (list[i]->is_fighting())
      continue;
    if (list[i]->is_busy())
      continue;
    if (list[i]->query_temp("no_move"))
      continue;
    if (!living(list[i]))
      continue;
    if ((string)list[i]->query_temp("accept")!=me->query("id"))
      continue;

    list[i]->set_temp("accept",0);
    here = (string)environment(me);
    there = (string)environment(list[i]);
    if (here == there)
      continue;

    message_vision("$N若有所思地向远方伸出手……\n",me);
    list[i]->set_temp("accept",0);
    list[i]->set_temp("lingshan/from",there);
    message_vision("一团祥云飘来，云中伸出一只巨大的佛手将$N轻轻托起，消失在天空。\n",list[i]);
    list[i]->move(here);
    message_vision("……$N轻轻一翻掌，$n稳稳地跳下来落在地上。\n",me,list[i]);
    break;
  }
}

int do_back(string arg)
{
  object who = this_player();
  object me = this_object();
  string here = (string)environment(me);
  string there = who->query_temp("lingshan/from");

  message_vision("$N请求$n送$N回返。\n",who,me);
  //if (!there)
  //  there = "/d/city/kezhan";
  there = "/d/city/kezhan";

  who->set_temp("accept",0);
  message_vision("$N的手掌轻轻托起$n向远方伸去……\n",me,who);
  who->move(there);
  message_vision("……云中伸出一只巨大的佛手轻轻一翻，只见$N从里面跳出来。\n",who);
  
  return 1;
}

void die()
{
  if (environment())
    message("sound", "\n\n如来缓缓一点头：佛法无边！\n\n", environment());

  set("eff_kee", 10000);
  set("eff_gin", 10000);
  set("eff_sen", 10000);
  set("kee", 10000);
  set("gin", 10000);
  set("sen", 10000);
  set("force", 10000);
  set("mana", 10000);
}

void unconcious()
{
  die ();
}

