// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;

#include <quest_fd.h>
#include <reporting.h>

int test_player();

void create()
{
  set_name("猪八戒", ({ "zhu bajie", "zhu", "bajie" }));
  set("age", 600);
  set("gender", "男性");
  set("long", "嘿嘿，连老猪都不认识啦？\n");
  set("attitude", "peaceful");
  set("str", 50);
  set("per", 10);
  set("combat_exp", 1200000);
  set("max_kee", 1500);
  set("max_sen", 1500);
  set("max_force", 1500);
  set("force", 1500);
  set("force_factor", 150);
  set("mana_factor", 150);
  set_skill("unarmed", 90);
  set_skill("dodge", 60);
  set_skill("parry", 60);
  set_skill("rake", 150);
  set_skill("force", 80);
  set_skill("spells", 80);
  set_skill("baguazhou", 80);
  set_skill("yanxing-steps", 70);
  set_skill("skyriver-rake", 180);
  map_skill("force", "lengquan-force");
  map_skill("spells", "baguazhou");
  map_skill("rake", "skyriver-rake");
  map_skill("parry", "skyriver-rake");
  map_skill("dodge", "yanxing-steps");
  set("chat_chance",10);
  set("chat_msg",({
    "猪八戒乐呵呵地说道：西天归来，老猪便是天下美食家也。\n",
    "猪八戒想想说：乡下发大水灾了，老猪该当救济饥民。\n",
    "猪八戒说道：老猪要寻遍天下美酒佳肴，再请世人来俺帅府品尝品尝。\n",
    "猪八戒说道：不是老猪贪嘴，俺老猪想凑个美宴，请平民百姓也能尝个新鲜。\n",
    "猪八戒自言自语地说：俺老猪不是为自己，老猪想收集世上美食，让大唐人都能来尝尝。\n",
    "猪八戒扭过身去捧起澡盆大的金饭盆吧嗒吧嗒大嚼了起来。\n",
    "猪八戒弯腰捧起水桶大的银酒壶咕咚咕咚地灌了下去。\n",
  }));
  set("inquiry", ([
        "here":   "此乃天蓬帅府也，老猪西天归来后唐太宗御赐在此开府，专事饮食慈善业。\n",
        "name":   "猪八戒，谁人不知也。\n",
        "food":   (: test_player() :),
        "美食":   (: test_player() :),
        "美酒":   (: test_player() :),
        "美宴":   (: test_player() :),
        "佳肴":   (: test_player() :),
        "食物":   (: test_player() :),
        "饮水":   (: test_player() :),
        "吃":   (: test_player() :),
        "喝":   (: test_player() :),
      ]));
  setup();
  carry_object("/d/kaifeng/obj/jiuchipa")->wield();
  carry_object("/d/obj/armor/tongjia")->wear();
}

void rewarding (object who, object ob);

void init ()
{
  call_out ("check_player",1,this_player());
}

int test_player()
{
  string *strs = ({
    "$N略有所思地点点头对$n说道：俺老猪想给大唐人凑个美宴，正缺",
    "$N对$n说道：老猪我四处寻求天下美味佳肴，正要找",
    "$N对$n说道：对了乡下发大水灾，有几个灾民想要什么",
    "$N对$n说道：京城客到，在开封府上，其中有一官人让老猪我代寻什么",
    "$N对$n点头说道：水陆大会即将开宴请各路法师到会，听说有法师想要什么",
    "$N对$n一点头说道：俺老猪救济饥民，听说正需要",
    "$N想想说：有人倒是想让俺老猪给找个什么什么",
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
                    "，俺见你身上祥云环绕，何不去从速赴长安进宫请赏？\n",me,who);
    return 1;
  }

  if (who->query("quest/pending/food"))
  {
    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                    "，俺还等着您的"+who->query("quest/pending/food/name")+"呢！\n",me,who);
    return 1;
  }

  quest_keys = me->query_temp("quest_keys");
  if (! quest_keys)
  {
    quest_keys = sort_quests (quests_food);
    me->set_temp("quest_keys",quest_keys);
  }
  i = quest_accurate_index (quest_keys, who->query("combat_exp"));
  i = quest_random_index (quest_keys, i, who, "quest/cache/food");
  if (i == -1)
  {
    message_vision ("$N对$n叹气说道：这位"+RANK_D->query_respect(who)+
                    "该做的事做了不少，俺看您还是以后再来吧。\n",me,who);
    return 1;
  }
  delay = MAXDELAY * i / sizeof(quest_keys) + DELAY_CONST + uptime();
  quest = quests_food[quest_keys[i]];
  who->set("quest/pending/food/index", i);
  who->set("quest/pending/food/daoxing", quest_keys[i]);
  who->set("quest/pending/food/name", quest[IDX_NAME]);
  who->set("quest/pending/food/id", quest[IDX_ID]);
  who->set("quest/pending/food/time", delay);
  str = strs[random(sizeof(strs))]+quest[IDX_NAME]+
        "，\n这位"+RANK_D->query_respect(who)+
        "可否赏老猪个大脸设法子去给弄来？\n";
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

  if (! who->query("quest/pending/food"))
    return;

  ob = present (who->query("quest/pending/food/id"),who);
  if (! ob)
    return;
  if (! ob->query("no_give"))
    return;

  if (who->query("quest/pending/food/name") != ob->query("name"))
    return;

  message_vision ("$N见$n手上拿着"+ob->query("name")+"，便赶紧伸手接过去。\n",me,who);
  rewarding (who, ob);
  destruct (ob);
}

int accept_object(object who, object ob)
{
  object me = this_object();
  int t;

/*
  if (! ob->query("food_remaining") &&
      ! ob->query("liquid/remaining"))
  {
     message_vision ("$N摇摇头：俺老猪现在只须要吃的喝的。\n",me);
     return 0;
  }
*/

  if (who->query("quest/reward") > 0)
  {
    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                    "，俺见你身上祥云环绕，何不去从速赴长安进宫请赏？\n",me,who);
    return 0;
  }

  if (! who->query("quest/pending/food"))
  {
    message_vision ("$N对$n说道：您给老猪这干什么？俺老猪尽管贪嘴也不受不义之财也。\n",me,who);
    return 0;
  }

  if(ob->is_character()) return 0;

  if (who->query("quest/pending/food/name") != ob->query("name"))
  {
    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                    "，俺等着您的"+who->query("quest/pending/food/name")+
                    "，您却给俺"+ob->query("name")+"，这……\n",me,who);
    return 0;
  }

  if (who->query("quest/pending/food/id") != ob->query("id"))
  {
    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                    "，俺等着您的"+who->query("quest/pending/food/name")+
                    "，东西倒挺象，但不是同一个货；俺要的是("+
                    who->query("quest/pending/food/id")+")，您给的是("+
                    ob->query("id")+")！\n",me,who);
    return 0;
  }

  t = who->query("quest/pending/food/time");

  if (t > uptime() && (t-MAXDELAY) <= uptime())
  {
    message_vision ("$N对$n摇头道：这么快就回来了？俺老猪不要假货。\n",me,who);
    message_vision ("$N又吩咐道：您再花个"+chinese_number((t-uptime())/60+1)+
                    "分钟去寻寻。\n",me,who);
    if (! DEBUG)
      return 0;
    else
      tell_object (who,"NOW DEBUG MODE: 让老猪要下东西。\n");
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

  reason = "为唐人美宴寻得"+ob->query("name")+"，";
  message_vision ("$N对$n说道：多谢这位"+RANK_D->query_respect(who)+
                  reason+"真是为大唐天下民众造福哇！\n",me,who);
  reward = quest_reward(who, quests_food, "food");
  who->add("quest/reward",reward);
  who->set("quest/reason",reason);
  who->add("quest/food/times",1);
  who->add("quest/food/reward",reward);
  reporting (who,reason, reward, "奖分");
  who->delete("quest/pending/food");
  call_out ("quest_done",1,who);
}


