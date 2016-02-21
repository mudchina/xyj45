// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat 

inherit NPC;

#include <quest_am.h>
#include <reporting.h>

int test_player();

void create()
{
  set_name("相婆", ({"xiang po", "xiang", "po"}));
  set("gender", "女性");
  set("title", "御赐");
  set("age", 75);
  set("per", 28);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 15000);
  set_skill("unarmed", 10);
  set_skill("dodge", 25);
  set_skill("parry", 25);
  set("max_gin",300);
  set("max_kee",300);
  set("max_sen",300);
  set("max_force",100);
  set("max_mana",100);
  set("force_factor",10);
  set("chat_msg",({
    "相婆高兴地说：相公也说啦，奇货征集了不少，可近期派人将盔甲护具送到京城。\n",
    "相婆说道：皇宫里人说我们相府收集了不少好盔甲护具。\n",
    "相婆又说道：魏大人也说上次送的盔甲护具里不少上乘品。\n",
    "相婆说：有些盔甲护具可以加以改良。\n",
    "相婆说道：相府征集盔甲护具，真是做了好事也。\n",
    "相婆自言道：个别征来的盔甲残缺不全，还需努力征集。\n",
  }));
  set("inquiry", ([
        "here":   "此乃御赐相府也，妾身在此专门收集盔甲。\n",
        "name":   "相良之妻也。\n",
        "armor":   (: test_player() :),
        "盔甲护具":   (: test_player() :),
        "盔甲":   (: test_player() :),
        "护具":   (: test_player() :),
        "收集":   (: test_player() :),
        "征集":   (: test_player() :),
      ]));
  setup();
  carry_object("/d/obj/cloth/skirt")->wear();
}

void rewarding (object who, object ob);

void init ()
{
  call_out ("check_player",1,this_player());
}

int test_player()
{
  string *strs = ({
    "$N想想对$n说道：今天妾身正准备请人去找",
    "$N细想了一下对$n说道：魏大人托话，说是京城有人想要什么",
    "$N对$n说道：听说长安有兵器护具坊需要",
    "$N对$n点头说道：相公刚说了，让妾身征集什么",
    "$N对$n一点头说道：这里尚缺些",
    "$N想想对$n说道：可否帮相府寻得",
  });  
  string str;
  object me = this_object();
  object who = this_player();
  int *quest_keys;
  string *quest;
  int delay;
  int i;

  if (who->query("quest/reward") > 0)
  {
    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                    "，妾身见你身上祥云环绕，何不去从速赴长安进宫请赏？\n",me,who);
    return 1;
  }

  if (who->query("quest/pending/armor"))
  {
    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                    "，妾身还盼着您的"+who->query("quest/pending/armor/name")+"呢！\n",me,who);
    return 1;
  }

  quest_keys = me->query_temp("quest_keys");
  if (! quest_keys)
  {
    quest_keys = sort_quests (quests_armor);
    me->set_temp("quest_keys",quest_keys);
  }
  i = quest_accurate_index (quest_keys, who->query("combat_exp"));
  i = quest_random_index (quest_keys, i, who, "quest/cache/armor");
  if (i == -1)
  {
    message_vision ("$N对$n叹气说道：这位"+RANK_D->query_respect(who)+
                    "该做的事做了不少，妾身看您还是以后再来吧。\n",me,who);
    return 1;
  }
  delay = MAXDELAY * i / sizeof(quest_keys) + DELAY_CONST + uptime();
  quest = quests_armor[quest_keys[i]];
  who->set("quest/pending/armor/index", i);
  who->set("quest/pending/armor/daoxing", quest_keys[i]);
  who->set("quest/pending/armor/name", quest[IDX_NAME]);
  who->set("quest/pending/armor/id", quest[IDX_ID]);
  who->set("quest/pending/armor/time", delay);
  str = strs[random(sizeof(strs))]+quest[IDX_NAME]+
        "，\n这位"+RANK_D->query_respect(who)+
        "能否帮相府个忙？\n";
  message_vision (str,me,who);
  informing (me,who,str);
  return 1;
}

void check_player (object who)
{
  object me = this_object();
  object ob;

  if (!who || !visible(who))
      return;

  if (! who || environment(who)!=environment(me))
    return;

  if (who->query("quest/reward") > 0)
  {
    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                    "身上祥云环绕，请速赴长安进宫请赏！\n",me,who);
    return;
  }

  if (! who->query("quest/pending/armor"))
    return;

  ob = present (who->query("quest/pending/armor/id"),who);
  if (! ob || ! ob->query("no_give"))
    return;

  if (who->query("quest/pending/armor/name") != ob->query("name"))
    return;

  message_vision ("$N见$n手上拿着"+ob->query("name")+"，急忙双手接过去。\n",me,who);
  rewarding (who, ob);
  destruct (ob);
}

int accept_object(object who, object ob)
{
  object me = this_object();
  int t;

  if (who->query("quest/reward") > 0)
  {
    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                    "，妾身见你身上祥云环绕，何不去从速赴长安进宫请赏？\n",me,who);
    return 0;
  }

  if (! who->query("quest/pending/armor"))
  {
    message_vision ("$N对$n说道：相府不需要这个。\n",me,who);
    return 0;
  }

  if (ob->is_character()) return 0;

  if (who->query("quest/pending/armor/name") != ob->query("name"))
  {
    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                    "，妾身盼着您的"+who->query("quest/pending/armor/name")+
                    "，您倒却给妾身"+ob->query("name")+"，唉呀呀。\n",me,who);
    return 0;
  }

  if (who->query("quest/pending/armor/id") != ob->query("id"))
  {
    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                    "，妾身盼着您的"+who->query("quest/pending/armor/name")+
                    "，东西倒挺象，但不是同一个货；妾身要的是("+
                    who->query("quest/pending/armor/id")+")，您给的是("+
                    ob->query("id")+")！\n",me,who);
    return 0;
  }

  t = who->query("quest/pending/armor/time");

  if (t > uptime() && (t-MAXDELAY) <= uptime())
  {
    message_vision ("$N对$n摇头道：这么快就回来了？妾身怕是有假。\n",me,who);
    message_vision ("$N又吩咐道：您再花个"+chinese_number((t-uptime())/60+1)+
                    "分钟去寻寻。\n",me,who);
    if (! DEBUG)
      return 0;
    else
      tell_object (who,"NOW DEBUG MODE: 让相婆要下东西。\n");
  }
  rewarding (who, ob);
  call_out ("destruct_ob",1,ob);
  return 1;
}

void destruct_ob (object ob)
{
  destruct (ob);
}

void rewarding (object who, object ob)
{
  object me = this_object();
  string reason;
  int reward;

  reason = "不辞劳苦寻得"+ob->query("name")+"，";
  message_vision ("$N对$n说道：多谢这位"+RANK_D->query_respect(who)+
                  reason+"妾身感激不尽！\n",me,who);
  reward = quest_reward(who, quests_armor, "armor");
  who->add("quest/reward",reward);
  who->set("quest/reason",reason);
  who->add("quest/armor/times",1);
  who->add("quest/armor/reward",reward);
  reporting (who,reason, reward, "奖分");
  who->delete("quest/pending/armor");
  call_out ("quest_done",1,who);
}




