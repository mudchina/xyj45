// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;

void create()
{
  set_name("唐太宗", ({"tang taizong", "tang", "tai zong", "zong", "king", "emperor"}));
  set("long", "大唐国之皇帝唐太宗。\n");
  set("title", "大唐国");
  set("gender", "男性");
  set("rank_info/respect", "陛下");
  set("age", 80);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("per", 30);
  set("int", 30);
  set("max_kee", 700);
  set("max_gin", 700);
  set("max_sen", 700);
  set("force", 800);
  set("max_force", 800);
  set("force_factor", 50);
  set("max_mana", 800);
  set("mana", 800);
  set("mana_factor", 40);
  set("combat_exp", 220000);
  set_skill("unarmed", 50);
  set_skill("dodge", 50);
  set_skill("parry", 50);
  set_skill("spells", 50);
  set_skill("force", 50);
  set_skill("seashentong", 50);
  set_skill("dragonforce", 50);
  set_skill("dragonstep", 50);
  set_skill("dragonfight", 50);
  map_skill("unarmed", "dragonfight");
  map_skill("dodge", "dragonstep");
  map_skill("force", "dragonforce");
  map_skill("spells", "seashentong");
  set_weight(5000000);  
  setup();
  carry_object("/d/obj/cloth/mangpao")->wear();
  
}

void init ()
{
  call_out ("test_player",1,this_player());
}

string *strs = ({
  "$N对$n惊叹道：",
  "$N对$n赞赏道：",
  "$N微笑着对$n说道：",
  "$N赞许地对$n说道：",
});

void test_player (object who)
{
  object me = this_object();
  object where = environment (me);
  object dachen;
  int i = 10;

  if (who->query("quest/reward") < 1)
    return;

  message_vision ("\n一进大殿，$N身上涌起淡淡的祥云。\n",who);
  while (i--)
  {
    string str = "da chen 1";

    // str[strlen(str)-1] = '1'+random(5);
    switch (random(32))
    // mon 4/5/98 changed range to 32 from 16
    {
      case 0: case 1: case 2: case 3: case 4: case 5: case 6:
      case 16: case 17: case 18: case 19: case 20: case 21: case 22: 
      {
        str = "duan zhixian";
        break;
      }
      case 7: case 8:
      {
        str = "du ruhui";       
        break;
      }
      case 9:
      {
        str = "zhang shiheng";  
        break;
      }
      case 10: case 11:
      {
        str = "meng ziru";
        break;
      }
      default:
      {
        str = "xu maogong";     
        break;
      }
    }
    dachen = present (str, where);

    if (! interactive (dachen))
      break;
  }

  if (! dachen)
    dachen = present ("da chen", where);

  if (! dachen ||
      interactive (dachen))
  {
    message_vision ("$N对$n说道：大臣们不在，"+RANK_D->query_respect(who)+
                    "稍候也。\n",me,who);
    return;
  }
  message_vision (strs[random(sizeof(strs))]+RANK_D->query_respect(who)+
                  "祥云缭绕，面生瑞气，朕果然有赏御赐与你！\n",me,who);
  message_vision ("\n$N走上前，赶紧在$n的殿前俯身跪下。\n",who,me);
  who->start_busy (3,3);
  call_out ("reward_player",2,me,who,dachen);
}

void reward_player (object me, object who, object dachen)
{
  message_vision ("\n旁边闪过大臣$N低声向$n说了几句，$n点了点头。\n",dachen,me);
  dachen->reward(who);
  message_vision ("\n$N连忙俯身一拜，小心翼翼地站起来。\n",who,me);
  who->delete("quest/reward");
  who->interrupt_me();
}

