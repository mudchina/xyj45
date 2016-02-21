// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat 

inherit NPC;

#include <quest_wp.h>
#include <reporting.h>

int test_player();

void create()
{
  set_name("相公", ({"xiang gong", "xiang", "gong"}));
  set("gender", "男性");
  set("title", "御赐");
  set("age", 80);
  set("per", 25);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 20000);
  set_skill("unarmed", 20);
  set_skill("dodge", 20);
  set_skill("parry", 20);
  set("max_gin",400);
  set("max_kee",400);
  set("max_sen",400);
  set("max_force",100);
  set("max_mana",100);
  set("force_factor",10);
  set("chat_chance",10);
  set("chat_msg",({
    "相公喜形于色地说：近来各类武器征集了不少，找个时间派人送到京城。\n",
    "相公自言自语道：武器精品将不期进贡给皇宫。\n",
    "相公呐呐地说道：军机大臣派人催问可否弄得武器佳品。\n",
    "相公说：什么兵器都要，可以改良或仿制也。\n",
    "相公低声说道：收集的武器该分类处置。\n",
    "相公自言道：好，各路英雄豪杰都纷纷前来献宝。\n",
  }));
  set("inquiry", ([
        "here":   "此乃御赐相府也，老夫被御准在此收集武器。\n",
        "name":   "姓相名良也。\n",
        "weapon":   (: test_player() :),
        "武器":   (: test_player() :),
        "兵器":   (: test_player() :),
        "法宝":   (: test_player() :),
        "收集":   (: test_player() :),
        "征集":   (: test_player() :),
        "宝":   (: test_player() :),
      ]));
  setup();
  carry_object("/d/obj/cloth/choupao")->wear();
}

void rewarding (object who, object ob);

void init ()
{
  call_out ("check_player",1,this_player());
}

int test_player()
{
  string *strs = ({
    "$N略有所思，然后对$n说道：老夫正想请人去找",
    "$N想了一下，对$n说道：老夫听说军务处想要",
    "$N对$n说道：军机大臣已托人传话，说是近来需要什么",
    "$N对$n说道：老夫即将遣人送兵器去京城，尚缺",
    "$N对$n一点头说道：老夫清点了一下兵器库，发现还少",
    "$N想想对$n说道：最近有些兵器来货不足，尤其是少了",
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
                    "，老夫见你身上祥云环绕，何不去从速赴长安进宫请赏？\n",me,who);
    return 1;
  }

  if (who->query("quest/pending/weapon"))
  {
    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                    "，老夫还盼着您的"+who->query("quest/pending/weapon/name")+"呢！\n",me,who);
    return 1;
  }

  quest_keys = me->query_temp("quest_keys");
  if (! quest_keys)
  {
    quest_keys = sort_quests (quests_weapon);
    me->set_temp("quest_keys",quest_keys);
  }
  i = quest_accurate_index (quest_keys, who->query("combat_exp"));
  i = quest_random_index (quest_keys, i, who, "quest/cache/weapon");
  if (i == -1)
  {
    message_vision ("$N对$n叹气说道：这位"+RANK_D->query_respect(who)+
                    "该做的事做了不少，老夫看您还是以后再来吧。\n",me,who);
    return 1;
  }
  delay = MAXDELAY * i / sizeof(quest_keys) + DELAY_CONST + uptime();
  quest = quests_weapon[quest_keys[i]];
  who->set("quest/pending/weapon/index", i);
  who->set("quest/pending/weapon/daoxing", quest_keys[i]);
  who->set("quest/pending/weapon/name", quest[IDX_NAME]);
  who->set("quest/pending/weapon/id", quest[IDX_ID]);
  who->set("quest/pending/weapon/time", delay);
  str = strs[random(sizeof(strs))]+quest[IDX_NAME]+
        "，\n这位"+RANK_D->query_respect(who)+
        "能否帮老夫个忙？\n";
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

  if (! who->query("quest/pending/weapon"))
    return;

  ob = present (who->query("quest/pending/weapon/id"),who);
  if (! ob || ! ob->query("no_give"))
    return;

  if (who->query("quest/pending/weapon/name") != ob->query("name"))
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
                    "，老夫见你身上祥云环绕，何不去从速赴长安进宫请赏？\n",me,who);
    return 0;
  }

  if (! who->query("quest/pending/weapon"))
  {
    message_vision ("$N对$n说道：老夫不需要这个。\n",me,who);
    return 0;
  }

  if (ob->is_character()) return 0;
  
  if (who->query("quest/pending/weapon/name") != ob->query("name"))
  {
    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                    "，老夫盼着您的"+who->query("quest/pending/weapon/name")+
                    "，您倒却给老夫"+ob->query("name")+"，咳咳。\n",me,who);
    return 0;
  }

  if (who->query("quest/pending/weapon/id") != ob->query("id"))
  {
    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                    "，老夫盼着您的"+who->query("quest/pending/weapon/name")+
                    "，东西倒挺象，但不是同一个货；老夫要的是("+
                    who->query("quest/pending/weapon/id")+")，您给的是("+
                    ob->query("id")+")！\n",me,who);
    return 0;
  }

  t = who->query("quest/pending/weapon/time");

  if (t > uptime() && (t-MAXDELAY) <= uptime())
  {
    message_vision ("$N对$n摇头道：这么快就回来了？老夫怕是有假。\n",me,who);
    message_vision ("$N又吩咐道：您再花个"+chinese_number((t-uptime())/60+1)+
                    "分钟去寻寻。\n",me,who);
    if (! DEBUG)
      return 0;
    else
      tell_object (who,"NOW DEBUG MODE: 让相公要下东西。\n");
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
                  reason+"老夫感激不尽！\n",me,who);
  reward = quest_reward(who, quests_weapon, "weapon");
  who->add("quest/reward",reward);
  who->set("quest/reason",reason);
  who->add("quest/weapon/times",1);
  who->add("quest/weapon/reward",reward);
  reporting (who,reason, reward, "奖分");
  who->delete("quest/pending/weapon");
  call_out ("quest_done",1,who);
}



