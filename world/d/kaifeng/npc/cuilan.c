// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat 

inherit NPC;

#include <quest_fn.h>
#include <reporting.h>

int test_player();

void create()
{
  set_name("翠兰", ({"cui lan", "cui", "lan"}));
  set("gender", "女性");
  set("age", 23);
  set("per", 28);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 4000);
  set_skill("unarmed", 35);
  set_skill("dodge", 35);
  set_skill("parry", 35);
  set_skill("force", 35);
  set_skill("spells", 35);
  set_skill("baihua-zhang", 35);
  set_skill("moondance", 35);
  set_skill("moonshentong", 35);
  map_skill("spells", "moonshentong");
  map_skill("unarmed", "baihua-zhang");
  map_skill("force", "moonforce");
  map_skill("spells", "moonshentong");
  set("max_gin",400);
  set("max_kee",400);
  set("max_sen",400);
  set("max_force",200);
  set("max_mana",200);
  set("force_factor",20);
  set("chat_chance",10);
  set("chat_msg",({
    "翠兰咯咯一笑：募捐来的家什可不少呀。\n",
    "翠兰宛尔一笑说道：家具摆了一后院，那些个想成家的穷人们可不用愁了。\n",
    "翠兰又说道：好了好了，姑娘这有好多家什可以送给最需要的人家了。\n",
    "翠兰说：明儿派人去通知那些穷家子来挑选如意家具什物也。\n",
  }));
  set("inquiry", ([
        "here":   "此乃高姓兰亭府也，姑娘在此募捐家什。\n",
        "name":   "高家小姐翠兰也。\n",
        "furniture":   (: test_player() :),
        "募捐":   (: test_player() :),
        "家具":   (: test_player() :),
        "家什":   (: test_player() :),
        "捐":   (: test_player() :),
      ]));
  setup();
  carry_object("/d/obj/cloth/pinkskirt")->wear();
  carry_object("/d/obj/cloth/shoes")->wear();
}

void rewarding (object who, object ob);

void init ()
{
  call_out ("check_player",1,this_player());
}

int test_player()
{
  string *strs = ({
    "$N对$n一笑：姑娘想起有人想要",
    "$N对$n咯咯地笑道：正好正好，姑娘募捐，听说有人打听能否寻得",
    "$N对$n说道：哦，对了，姑娘想帮人找一找什么",
    "$N对$n点头笑着说道：谢谢啦，姑娘想替人找",
    "$N微笑着对$n一点头说道：有人曾打听是否有",
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
                    "，姑娘见你身上祥云环绕，何不去从速赴长安进宫请赏？\n",me,who);
    return 1;
  }

  if (who->query("quest/pending/furniture"))
  {
    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                    "，姑娘还盼着您的"+who->query("quest/pending/furniture/name")+"呢！\n",me,who);
    return 1;
  }

  quest_keys = me->query_temp("quest_keys");
  if (! quest_keys)
  {
    quest_keys = sort_quests (quests_furniture);
    me->set_temp("quest_keys",quest_keys);
  }
  i = quest_accurate_index (quest_keys, who->query("combat_exp"));
  i = quest_random_index (quest_keys, i, who, "quest/cache/furniture");
  if (i == -1)
  {
    message_vision ("$N对$n叹气说道：这位"+RANK_D->query_respect(who)+
                    "该做的事做了不少，姑娘看您还是以后再来吧。\n",me,who);
    return 1;
  }
  delay = MAXDELAY * i / sizeof(quest_keys) + DELAY_CONST + uptime();
  quest = quests_furniture[quest_keys[i]];
  who->set("quest/pending/furniture/index", i);
  who->set("quest/pending/furniture/daoxing", quest_keys[i]);
  who->set("quest/pending/furniture/name", quest[IDX_NAME]);
  who->set("quest/pending/furniture/id", quest[IDX_ID]);
  who->set("quest/pending/furniture/time", delay);
  str = strs[random(sizeof(strs))]+quest[IDX_NAME]+
        "，\n这位"+RANK_D->query_respect(who)+
        "能否替姑娘想个办法？\n";
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

  if (! who->query("quest/pending/furniture"))
    return;

  ob = present (who->query("quest/pending/furniture/id"),who);
  if (! ob || ! ob->query("no_give"))
    return;

  if (who->query("quest/pending/furniture/name") != ob->query("name"))
    return;

  message_vision ("$N见$n手上拿着"+ob->query("name")+"，笑着连忙接了过去。\n",me,who);
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
                    "，姑娘见你身上祥云环绕，何不去从速赴长安进宫请赏？\n",me,who);
    return 0;
  }

  if (! who->query("quest/pending/furniture"))
  {
    message_vision ("$N对$n说道：姑娘暂时不需要这个。\n",me,who);
    return 0;
  }

  if (ob->is_character()) return 0;

  if (who->query("quest/pending/furniture/name") != ob->query("name"))
  {
    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                    "，姑娘说过需要"+who->query("quest/pending/furniture/name")+
                    "，您倒给姑娘"+ob->query("name")+"，好玩好玩。\n",me,who);
    return 0;
  }

  if (who->query("quest/pending/furniture/id") != ob->query("id"))
  {
    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                    "，姑娘是想要"+who->query("quest/pending/furniture/name")+
                    "，东西倒挺象，但不是同一个货；姑娘要的是("+
                    who->query("quest/pending/furniture/id")+")，您给的是("+
                    ob->query("id")+")！\n",me,who);
    return 0;
  }

  t = who->query("quest/pending/furniture/time");

  if (t > uptime() && (t-MAXDELAY) <= uptime())
  {
    message_vision ("$N对$n摇头道：这么快就回来了？姑娘想要真货也。\n",me,who);
    message_vision ("$N又吩咐道：您再花个"+chinese_number((t-uptime())/60+1)+
                    "分钟去寻寻。\n",me,who);
    if (! DEBUG)
      return 0;
    else
      tell_object (who,"NOW DEBUG MODE: 让姑娘要下东西。\n");
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

  reason = "替"+me->query("name")+"寻得"+ob->query("name")+"，";
  message_vision ("$N对$n说道：多谢这位"+RANK_D->query_respect(who)+
                  reason+"姑娘好个开心！\n",me,who);
  reward = quest_reward(who, quests_furniture, "furniture");
  who->add("quest/reward",reward);
  who->set("quest/reason",reason);
  who->add("quest/furniture/times",1);
  who->add("quest/furniture/reward",reward);
  reporting (who,reason, reward, "奖分");
  who->delete("quest/pending/furniture");
  call_out ("quest_done",1,who);
}




