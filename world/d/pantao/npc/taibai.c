// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// created 5/30/1997 by snowcat
#include <ansi.h>

inherit NPC;

#define DEBUG 0

#define MYFILE "/d/pantao/npc/taibai.c"

#define MAXPOSITION 7

#define LEVEL_NONE 0
#define LEVEL_ASKED 1
#define LEVEL_RANKED 2
#define LEVEL_FEAST 3

int interval_set = 0;
string YAOCHI = 0;

void create()
{
  string saying = "太白金星自言自语道：";

  set_name("太白金星", ({"tai bai", "tai", "bai" }));
  set("title", "长庚");
  set("gender", "男性");
  set("age", 10000);
  set("per", 30);
  set("long", "西方长庚太白金星。\n");
  set("combat_exp", 500000);
  set_skill("force", 100);
  set_skill("spells", 100);
  set_skill("unarmed", 100);
  set_skill("dodge", 100);
  set_skill("parry", 100);
  set("gin", 5000);
  set("max_gin", 5000);
  set("kee", 5000);
  set("max_kee", 5000);
  set("sen", 5000);
  set("max_sen", 5000);
  set("force", 1500);
  set("max_force", 1500);
  set("mana", 1500);
  set("max_mana", 1500);
  set("force_factor", 100);
  set("chat_chance",3);
  set("chat_msg",({
    saying+"诸仙如不识老夫，可问问老夫help一事便是。\n",
    saying+"届时蟠桃会封神排榜公开宴请，若是诸仙在下界，使accept便可。\n",
    saying+"若是有意打听蟠桃会封神榜，请问便是。\n",
    saying+"诸仙若想入封神榜，先带老夫见天神，再fight挑战。\n",
    saying+"天神但获御准排定新榜后，封神台便是拜榜请宴之处。\n",
    saying+"封神台拜新榜后便可赴蟠桃宴，使feast便是了。\n",
    saying+"若是诸仙欲回返下界使back便可，老夫亲身相送。\n",
    saying+"蟠桃会后诸仙如有意谢恩散席，使finish报请王母娘娘恩准。\n",
  }));
  setup();
}

int execute_help();
int execute_ask();
int qualified(object me); 
//More than 1/4 of real players with 10k+ experience is required
//to attend the meeting. Modified by Wuliao

void init()
{
  ::init();
  add_action("do_fight", "fight");
  add_action("do_kill", "kill");
  add_action("do_steal", "steal");
  add_action("do_cast", "cast");
  add_action("do_exert", "exert");
  add_action("do_perform", "perform");
  add_action("do_bian", "bian");
  add_action("do_confirm", "confirm");
  add_action("do_feast", "feast");
  add_action("do_back", "back");
  add_action("do_finish", "finish");
  set("inquiry", ([
        "here":   "此乃瑶池蟠桃园七大天神殿，各路仙人圣贤天神年年聚此切磋神艺列榜封神，王母娘娘岁岁在此设蟠桃胜会宴请众仙神。\n",
        "?":      (: execute_help() :),
        "help":   (: execute_help() :),
        "蟠桃":   (: execute_ask() :),
        "蟠桃会": (: execute_ask() :),
        "蟠桃宴": (: execute_ask() :),
        "封神":   (: execute_ask() :),
        "封神榜": (: execute_ask() :),
      ]));
  if (YAOCHI == 0)
  {
    /*
    YAOCHI = __DIR__;
    YAOCHI[strlen(YAOCHI)-4] = 0;
    YAOCHI = YAOCHI + "yaob";
    */
    YAOCHI = "/d/pantao/yaob";
  }
}

string randomize (string *strs)
{
  return strs[random(sizeof(strs))];
}

string get_name (object who)
{
  return who->query("name");
}

string get_respect (object who)
{
    if(!who) return " ";
  return "这位"+RANK_D->query_respect(who);
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

int do_fight(string arg)
{
  object who = this_player();
  object me = this_object();

  if (arg && present(arg,environment(who))==me)
  {
    message_vision ("$N对$n摇摇头："+get_respect(who)+
                    "，天堂非同下界，不可随便动粗！\n",me,who);
    return 1;
  }
  return 0;
}

int do_kill(string arg)
{
  object who = this_player();
  object me = this_object();

  if (arg && present(arg,environment(who))==me)
  {
    message_vision ("$N对$n摇摇头："+get_respect(who)+
                    "，天堂非同下界，不可随便妄念杀人！\n",me,who);
    return 1;
  }
  return 0;
}

int do_cast(string arg)
{
  object who = this_player();
  object me = this_object();

  if (arg == "transfer")
    return 0;

  message_vision ("$N对$n摇摇头："+get_respect(who)+
                  "，天堂非同下界，怎可随便乱施法术！\n",me,who);
  return 1;
}

int do_exert(string arg)
{
  object who = this_player();
  object me = this_object();

  if (arg != "sheqi tai bai" &&
      arg != "sheqi tai" &&
      arg != "sheqi bai")
    return 0;

  message_vision ("$N对$n摇摇头："+get_respect(who)+
                  "，天堂非同下界，怎可随便乱施内功！\n",me,who);
  return 1;
}

int do_perform(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision ("$N对$n摇摇头："+get_respect(who)+
                  "，天堂非同下界，怎可随便乱施外功！\n",me,who);
  return 1;
}

int do_steal(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision ("$N对$n摇摇头："+get_respect(who)+
                  "，天堂非同下界，怎可随便光天化日施盗行窃！\n",me,who);
  return 1;
}

int do_bian(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision ("$N对$n摇摇头："+get_respect(who)+
                  "，天堂非同下界，怎可随便变人变鬼！\n",me,who);
  return 1;
}

int execute_help ()
{
  object who = this_player();
  object me = this_object();

  switch (me->query_temp("pantao/level"))
  {
    case LEVEL_NONE:
    {
      message_vision ("$N对$n说道："+get_respect(who)+
                      "若有意打听蟠桃会封神榜，请问便是。\n",me,who);
      break;
    }
    case LEVEL_ASKED:
    {
      message_vision ("$N对$n说道："+get_respect(who)+
                      "不妨带老夫去见日月金木水火土天神，"+
                      "若有意挑战使fight便是了。\n",me,who);
      break;
    }
    case LEVEL_RANKED:
    {
      message_vision ("$N说道：诸仙中若有仙人意欲继续挑战天神，"+
                      "带老夫去见日月金木水火土天神便可。\n",me,who);
      message_vision ("$N又补充道：封神新榜已获御准排定，也请新任天神"+
                      "细问诸仙，若诸仙皆无意再战便共去封神台拜榜请宴。"+
                      "封神台上使feast便是了。\n",me,who);
      break;
    }
    case LEVEL_FEAST:
    {
      message_vision ("$N对$n说道："+get_respect(who)+
                      "若有意回返下界使back，"+
                      "若有意集体谢宴共返下界，使finish报请王母娘娘恩准。\n",
                      me,who);
      break;
    }
  }
  return 1;
}

void reset_interval ()
{
  interval_set = 0;
}

int execute_ask ()
{
  object who = this_player();
  object me = this_object();

  if (who->query("combat_exp") < 200000)
  {
    message_vision ("$N对$n摇摇头："+get_respect(who)+
                    "虽是仙客，却道行不足，难以授仙录封天神。\n",me,who);
    return 1;
  }

  if (me->query_temp("pantao/is_busy"))
  {
    message_vision ("$N对$n摇摇头："+get_respect(who)+
                    "，老夫正忙难以奉陪。\n",me,who);
    return 1;
  }

  if(me->query_temp("pantao/level") < LEVEL_ASKED)
  {
    if (interval_set)
    {
      message_vision ("$N对$n摇摇头："+get_respect(who)+
                      "，蟠桃胜会时辰未到，请下次再来吧。\n",me,who);
      return 1;
    }

    message_vision ("$N对$n说："+get_respect(who)+
                    "，蟠桃胜会须有封神排榜演礼在先方可；\n"+
                    "此乃大事非同小可，老夫须先启奏玉帝，"+
                    get_respect(who)+"若愿意请使confirm。\n",me,who);
    me->set_temp("pantao/confirm",1);
    return 1;  
  }
  // LEVEL_ASKED, LEVEL_RANKED
  if(me->query_temp("pantao/level") < LEVEL_FEAST)
  {
    remove_call_out ("continue_asked");
    call_out ("continue_asked",1,me,who);
    return 1;  
  }
  message_vision ("$N对$n说道："+get_respect(who)+
                  "，蟠桃会已经开宴。\n",me,who);
  return 1;
}

int do_confirm ()
{
  object who = this_player();
  object me = this_object();

  if (! me->query_temp("pantao/confirm"))
    return notify_fail("什么？\n");

  me->set_temp("pantao/confirm",0);
  message_vision ("$N回答愿意。\n",who);

  announce (me,who->query("name")+get_respect(who)+"有请了！\n");
  message_vision ("$N对$n说道："+get_respect(who)+
                  "，老夫这就启奏玉帝，邀请各路仙人圣贤天神上天来封神排榜。"+
                  "再报请王母娘娘蟠桃胜会请宴新客！\n",me,who);
  message_vision ("祥云飘起，$N离去。\n",me);
  //me->set("env/invisibility",9);
  me->set_temp("pantao/reappear",environment(me));
  load_object("/obj/empty");
  me->move("/obj/empty");
  remove_call_out ("make_asked");
  call_out ("make_asked",10,me,who);
  return 1;
}

void make_asked (object me, object who)
{
  int i;
  object *list;

  if (!who ||
      !environment(who) ||
      environment(who) != me->query_temp("pantao/reappear"))
  {
    me->move(me->query_temp("pantao/reappear"));
    message_vision ("祥云飘落，$N跳出云来。\n",me);
    return;
  }

  announce (me,"玉帝御旨：邀请各路仙人圣贤上天来封神排榜演礼！");
  announce (me,"封榜演礼之后，王母娘娘恩设蟠桃大会请宴新客！\n");
  announce (me,"诸位下界仙贤若想赴会，使accept tai bai便可，老夫亲身相迎！\n");

  interval_set = 1;
  call_out ("reset_interval", 28800); // 8h
  me->set_temp("no_return",1);
  me->set_temp("pantao/level",LEVEL_ASKED);
  //me->set("env/invisibility",0);
  me->move(me->query_temp("pantao/reappear"));
  message_vision ("祥云飘落，$N跳出云来。\n",me);
  remove_call_out ("continue_asked");
  call_out ("continue_asked",1,me,who);

  me->set_temp("invite","public");
  list = users();
  i = sizeof(list);
  while  (i--)
  {
    reset_eval_cost();
    if (!environment(list[i]))
      continue;
    list[i]->set_temp("accept",0);
  }
  remove_call_out ("inviting");
  call_out ("inviting",1,me);
}

void continue_asked (object me, object who)
{
    if(!who) return;

  message_vision ("$N对$n说道："+get_respect(who)+
                  "可带老夫去见七位天神，"+
                  "若觉合意便可与天神会战。\n",me,who);
  message_vision ("$N缓步跟上，决定与$n同行。\n",me,who);
  who->set_leader(me);
  me->set_leader(who);
}

void inviting (object me)
{
  int i;
  object *list;

  if (me->query_temp("pantao/level") == LEVEL_NONE)
    return;

  if (DEBUG)
    return;

  remove_call_out ("inviting");
  call_out ("inviting",4+random(4),me);

  if (me->query_temp("pantao/is_busy"))
  {
    return;
  }

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

    message_vision("$N说道：请稍候，老夫奉旨迎接"+list[i]->query("name")+
                   "赴会，即返。\n",me);
    list[i]->set_temp("accept",0);
    list[i]->set("pantao/from",there);
    message_vision("一团祥云飘起，$N飞去……。\n",me);
    //me->move(there);
    message_vision("只见一团祥云飘下，太白金星从里面走出。\n",list[i]);
    message_vision("太白金星对$N说道：老夫奉旨迎接$N赴会！\n",list[i]);
    message_vision("祥云拥着太白金星和$N腾空而起，徐徐飞去……。\n",list[i]);
    //me->move(here);
    list[i]->move(here);
    message_vision("……祥云徐徐降落，$N和$n从里走出。\n",me,list[i]);
    list[i]->set_leader(me);
    break;
  }
}

int execute_approve_fight(object who, object ob)
{
  object *all, *list, *inv;
  int i, j;
  object me = this_object();

  if (who->query("combat_exp") < 50000)
  {
    message_vision ("$N对$n摇摇头："+get_respect(who)+
                    "道行不足，不可妄与天神较量。\n",me,who);
    return 0;
  }
  all = users();
  i = sizeof(filter_array(all, (:qualified:))); //modified by wuliao
  list = all_inventory(environment(me));
  j = sizeof(filter_array(list, (:qualified:))) - 1;
  // only interactive players count.

  if ((i/4-j) > 0 && (! DEBUG)) 
  {
    message_vision ("$N对$n摇摇头：西游记现有"+chinese_number(i)+"位高手，"
                    "此处仅有数位仙贤在邀，"+
                    get_respect(who)+"可否再邀"+chinese_number(i/4-j)+
                    "位仙贤赴会？\n",me,who);
    return 0;
  }
  announce (me,"封神榜演礼："+who->query("name")+"与"+ob->query("name")+
            "于"+environment(me)->query("short")+"争榜较量！\n");
  
  me->set_temp("pantao/is_busy",1);
  me->set_leader(0);
  return 1;
}

int execute_fight_result (object who, object ob, int success)
{
  object me = this_object();
  int i, y, d, h;

  reset_eval_cost();
  call_out("reset_is_busy",5,me);

  if (! success)
    return 1;
  if (!ob)
    return 1;
  if (!present(ob, environment(me)))
    return 1;

  announce (me,ob->query("name")+environment(me)->query("short")+
            "大战"+who->query("name")+"，夺榜获胜！\n");
  announce (me,"老夫诚奉御旨，封"+ob->query("name")+"为"+
            who->get_honor_str()+"！\n");
  i = ob->query("pantao/wins")+1;
  ob->set("pantao/wins",i);
  i = (10 + MAXPOSITION - who->get_position_int())*(999+random(9))/i;
  ob->add("combat_exp",i);
  y = i/1000;
  d = (i - y*1000) / 4;
  h = (i - y*1000 - d*4) * 3;
  if (y > 0)
    tell_object(ob,"你的道行增加了"+chinese_number(y)+"年"+
                chinese_number(d)+"天"+chinese_number(h)+"时辰！\n\n");
  else if (d > 0)
    tell_object(ob,"你的道行增加了"+
                chinese_number(d)+"天"+chinese_number(h)+"时辰！\n\n");
  else if (h > 0)
    tell_object(ob,"你的道行增加了"+
                chinese_number(h)+"时辰！\n\n");
  me->set_temp("pantao/current_player",ob->query("id"));
  me->set_temp("pantao/level",LEVEL_RANKED);
  message_vision ("$N满脸笑容地说道：若还有仙人意欲继续挑战天神，"+
                  "就此带老夫去见天神。\n",me);
  message_vision ("$N又道：玉皇大帝御准封神新榜，新任天神$n"+
                  "可询问诸仙各位，如皆无意再战可一同封神台拜榜请宴。"+
                  "去了封神台上使feast便可。\n",me,ob);
  message_vision ("$N缓步跟上，决定与$n同行。\n",me,ob);
  me->set_leader(ob);
  return 1;
}

void reset_is_busy(object me)
{
  me->set_temp("pantao/is_busy",0);
}

int is_tian_shen (object who)
{
  int i;

  for (i = 1; i <= MAXPOSITION; i++)
  {
    string npc = __DIR__"tian"+sprintf("%d",i);
    object ob = find_object(npc);
    reset_eval_cost();
    if (! ob ||
        ! ob->restore())
      ob = new (npc);
    if (ob->query("current_player") == who->query("id"))
      return 1;
  }
  return 0;
}

int do_feast ()
{
  object me = this_object();
  object who = this_player();

  message_vision("$N请求$n秉报王母开宴。\n",who,me);
  if (me->query_temp("pantao/level") == LEVEL_FEAST)
  {
    message_vision ("$N说道：蟠桃会已经开始了。\n",me);
    return 1;
  }
  if (me->query_temp("pantao/level") != LEVEL_RANKED)
  {
    message_vision ("$N说道：封神新榜尚未御准，老夫怎敢惊动王母娘娘。"+
                    "$n可否愿与七大天神教量？"+
                    "若是赢了，老夫立刻奏请玉皇大帝御准。\n",me,who);
    return 1;
  }
  if (! is_tian_shen(who))
  {
    message_vision ("$N说道：$n非天神也，可否请新任天神来拜榜请宴？\n",me,who);
    return 1;
  }
  if (environment(me)->query("short")!="封神台")
  {
    message_vision ("$N道：诸仙各位可否同去封神台先拜榜再请宴？\n",me);
    return 1;
  }
  message_vision ("$N对$n说道："+get_respect(who)+
                  "，老夫这就秉报请王母娘娘蟠桃胜会请宴新客！\n",me,who);
  message_vision ("祥云飘起，$N离去。\n",me);
  //me->set("env/invisibility",9);
  me->set_temp("pantao/reappear",environment(me));
  load_object("/obj/empty");
  me->move ("/obj/empty");
  remove_call_out ("make_feast");
  call_out ("make_feast",5,me,who);
  return 1;
}

void make_feast (object me, object who)
{
  int i;
  object *list;

  if (!environment(who) ||
      environment(who) != me->query_temp("pantao/reappear"))
  {
    me->move(me->query_temp("pantao/reappear"));
    message_vision ("祥云飘落，$N跳出云来。\n",me);
    return;
  }

  announce (me,"众仙人贤圣天神封神台拜榜！\n");
  announce (me,"王母娘娘恩准开设蟠桃大会请宴新客！\n\n");

  me->set_temp("pantao/level",LEVEL_FEAST);
  me->set_leader(0);
  //me->set("env/invisibility",0);
  me->move(me->query_temp("pantao/reappear"));
  message_vision ("祥云飘落，$N跳出云来。\n",me);

  remove_call_out ("execute_start_feast");
  call_out ("execute_start_feast",1,me);
}

void execute_start_feast (object me)
{
  int i;
  object *list;

  message_vision ("$N说道：请诸位仙贤跟老夫去瑶池宝阁。\n",me);
  me->set_temp("no_return",0);
  //command ("north");
  //command ("north");
  //command ("north");
  //command ("north");
  //command ("north");
  //command ("north");
  //command ("north");
  //command ("north");

  message_vision("只见一团祥云慢慢聚起，你和众神徐徐飞起……。\n",me);
  list = all_inventory(environment(me));
  i = sizeof(list);
  message_vision("……祥云缓缓降下。\n",me);
  while  (i--)
  {
    reset_eval_cost();
    if (!interactive(list[i]))
      continue;

    list[i]->move(YAOCHI);
    message_vision("$N从祥云中走了出来。\n",list[i]);
  }
  message_vision("$N踏出祥云，祥云慢慢地散了。\n",me);
  me->move(YAOCHI);
  me->set_temp("pantao/is_busy",1);
  remove_call_out ("continue_feast");
  call_out ("continue_feast",10,me);
}

void continue_feast (object me)
{

  command ("sigh");

  message_vision ("$N说道：诸位息怒，王母娘娘正在大发脾气不能主宴。\n",me);
  //message_vision ("$N犹疑了一下又说道：…雪豹这厮…把蟠桃全都偷吃了！\n",me);

  remove_call_out ("give_gifts");
  call_out ("give_gifts",2,me);
  remove_call_out ("bring_girls");
  call_out ("bring_girls",5,me);
  remove_call_out ("auto_activities");
  call_out ("auto_activities",10,me);
  remove_call_out ("auto_gifts");
  call_out ("auto_gifts",20,me);
  remove_call_out ("auto_guests");
  call_out ("auto_guests",30,me);
  remove_call_out ("auto_signs");
  call_out ("auto_signs",40,me);
  remove_call_out ("end_feast");
  call_out ("end_feast",300,me);
  remove_call_out ("execute_auto_finish");
  call_out ("execute_auto_finish",600,me);
}

void give_gifts (object me)
{
  int i;
  object *list;

  list = all_inventory(environment(me));
  i = sizeof(list);
  while  (i--)
  {
    object ob = list[i];
    object xianyao = new ("/d/obj/food/xianyao");
    object xianzhi = new ("/d/obj/food/xianzhi");
    reset_eval_cost();
    if (!interactive(ob))
      continue;
    if (me == ob)
      continue;

    xianyao->move(ob);
    xianzhi->move(ob);
    message_vision("$N给$n一金碗"+xianyao->query("name")+
                   "一玉壶"+xianzhi->query("name")+"。\n",me,ob);
  }
}

void bring_girls (object me)
{
  string *strs = ({
    "走了进来",
    "走进来施了个礼",
    "进来施礼",
    "进来向你施礼",
    "进来对着你施了个礼",
  });
  object where = environment(me);
  int i;
  string room_dir;

/*
  room_dir = __DIR__;
  room_dir[strlen(room_dir)-4] = 0;
*/
  room_dir = "/d/pantao/";
  message_vision ("外面喊道：彩衣仙女到！\n",me);
  for (i = 1; i < 7; i++)
  {
    string room = room_dir+"ting"+sprintf("%d",i);
    string npc = __DIR__"xiannu"+sprintf("%d",i);
    object ob;

    reset_eval_cost();;
    me->move(room);
    ob = present("xian nu",environment(me));

    if (! ob)
      ob = new (npc);
    message_vision ("$N走了出去。\n",ob);
    ob->set("previous_location",room);
    ob->move(where);
    message_vision ("$N"+randomize(strs)+"\n",ob);
  }
  me->move(where);
}

void auto_activities (object me)
{
  string *strs = ({
    "一班仙娥在歌声中翩翩起舞",
    "几位美姬和着节拍轻轻唱着起歌",
    "一阵阵凤箫玉管乐声缥缈",
    "风吹来，瑶池内琼香缭绕",
    "酒官送来一些仙酒",
    "仙女端进来几盘仙桃",
    "一位仙子进来奉上仙蕊仙花",
    "仙桌上的琼浆玉液散发着一阵酒香",
    "仙女唱道：半红半绿喷甘香",
    "仙女唱道：艳丽仙根万载长",
    "仙女唱道：堪笑武陵源上种",
    "仙女唱道：争如天府更奇强",
    "仙女唱道：紫纹娇嫩寰中少",
    "仙女唱道：缃核清甜世莫双",
    "仙女唱道：延寿延年能易体",
    "仙女唱道：有缘食者自非常",
  });

  if (me->query_temp("pantao/level") != LEVEL_FEAST)
    return;

  message_vision (randomize(strs)+"\n",me);
  remove_call_out ("auto_activities");
  call_out ("auto_activities",20+random(20),me);
}

void auto_gifts (object me)
{
  object where = environment(me);
  object ob, who, gift;
  object *list;
  int i;
  string room_dir;
  
/*
  room_dir = __DIR__;
  room_dir[strlen(room_dir)-4] = 0;
*/
  room_dir = "/d/pantao/";
  if (me->query_temp("pantao/level") != LEVEL_FEAST)
    return;

  list = all_inventory(environment(me));
  for (i = 0; i < 100; i++)
  {
    reset_eval_cost();
    ob = list[random(sizeof(list))];
    if (ob->query("id") == "xian nu")
      break;
    ob = 0;
  }
  if (! ob)
  {
    int j = random(7);
    string room = room_dir+"ting"+sprintf("%d",j);
    string npc = __DIR__"xiannu"+sprintf("%d",j);

    me->move(room);
    ob = present("xian nu",environment(me));

    if (! ob)
      ob = new (npc);
    ob->move(where);
    me->move(where);
    message_vision ("$N走了过来。\n",ob);
  }
  for (i = 0; i < 100; i++)
  {
    who = list[random(sizeof(list))];
    if (interactive(who))
      break;
    who = 0;
  }
  if (who)
  {
    if (random(2))
      gift = new ("/d/obj/drug/xiantao");
    else
      gift = new ("/d/obj/drug/xianjiu");
    gift->move(who);
    message_vision ("$N给$n一"+gift->query("unit")+
                    gift->query("name")+"\n",ob,who);
  }
  remove_call_out ("auto_gifts");
  call_out ("auto_gifts",30+random(30),me);
}

void auto_guests (object me)
{
  string name;
  int i;
  string *names = ({
    "菩提祖师",
    "云阳真人",
    "嫦娥",
    "观音菩萨",
    "惠岸使者",
    "地藏王菩萨",
    "白无常",
    "黑无常",
    "秦琼",
    "东海龙王敖广",
    "南海龙王敖钦",
    "北海龙王敖顺",
    "西海龙王敖闰",
    "太上老君",
    "赤脚大仙",
    "托塔李天王",
    "哪吒",
    "唐三藏",
    "孙悟空",
    "猪八戒",
  });

  if (me->query_temp("pantao/level") != LEVEL_FEAST)
    return;

  for (i = 0; i < 100; i++)
  {
    reset_eval_cost();
    name = randomize(names);
    if (! me->query_temp("pantao/invited_"+name))
      break;
    name = "none";
  }
  if (name == "none")
    return;

  me->set_temp("pantao/invited_"+name,1);
  message_vision ("只听得远远一声："+name+"前来赴宴！"+"\n",me);
  remove_call_out ("continue_guests");
  call_out ("continue_guests",3+random(3),me,name);
  remove_call_out ("auto_guests");
  call_out ("auto_guests",40+random(40),me);
}

void continue_guests (object me, string name)
{
  string msg;
  int i;
  string *msgs = ({
    "闻风而来赴宴，但因万事缠身，不便久留！",
    "前来谢宴，就此告辞！",
    "专程前来表敬，不便久留，各位有请！",
    "此乃前来申谢，告辞了！",
    "特来表敬，无意久留！",
    "匆匆赶来只为谢宴，不能传杯，失礼了！",
  });

  if (me->query_temp("pantao/level") != LEVEL_FEAST)
    return;

  message_vision (name+"走了进来。\n",me);
  message_vision (name+"说道："+name+randomize(msgs)+"\n",me);
  message_vision (name+"走了出去。\n",me);
}

void auto_signs (object me)
{
  string str;
  string *strs = ({
    "天空远处隐隐约约霞光万道，好象天上有什么胜大宴会……",
    "天上似乎团团瑞气飘过……",
    "你恍惚看见天光灿烂，好象有什么重大节日……",
    "一阵阵风吹来，传来天上凤箫玉管的声音……",
    "天上传来断断续续的音乐声……",
    "你好象听见天上金钟齐鸣……",
  });
  int i;
  object *list;

  if (me->query_temp("pantao/level") != LEVEL_FEAST)
    return;

  if (DEBUG)
    return;

  str = randomize(strs);
  list = users();
  i = sizeof(list);
  while  (i--)
  {
    string here, there;

    reset_eval_cost();
    if (!environment(list[i]))
      continue;
    if (!living(list[i]))
      continue;

    here = (string)environment(me);
    there = (string)environment(list[i]);
    if (here == there)
      continue;

    tell_object(list[i],str+"\n");
  }
  remove_call_out ("auto_signs");
  call_out ("auto_signs",60+random(60),me);
}

void end_feast (object me)
{
  me->set_temp("pantao/is_busy",0);
  message_vision ("$N说道：诸位仙贤，若有意回返下界使back便是，老夫相送。"+
                  "若有意集体谢宴共返下界，可让新任天神使finish"+
                  "请王母娘娘恩准。\n",me);
}

int execute_back(object me, object who)
{
  string here = (string)environment(me);
  string  there;

  if(!who) return 1;
  
  there = who->query("pantao/from");

  //if (!there)
  //  there = "/d/city/kezhan";
  there = "/d/city/kezhan";

  if (here == there)
    return 1;

  who->set_temp("accept",0);
  message_vision("只见祥云飘起，$N和$n腾空而起，慢慢飞去……。\n",me,who);
  //me->move(there);
  who->move(there);
  message_vision("只见一团祥云飘下，太白金星和$N从里面走出。\n",who);
  message_vision("太白金星复又纵起祥云缓缓飞离。\n",who);
  //me->move(here);
  message_vision("……祥云飞回，$N从里面走出。\n",me);
  
  return 1;
}

int do_back(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision("$N请求$n驾云送$N回返。\n",who,me);
  if (me->query_temp("pantao/is_busy"))
  {
    message_vision ("$N对$n摇摇头："+get_respect(who)+
                    "，老夫正忙，失礼了。\n",me,who);
    return 1;
  }
  execute_back (me,who);
  
  return 1;
}

int do_finish ()
{
  object me = this_object();
  object who = this_player();

  message_vision("$N请求$n秉报王母谢宴集体回返。\n",who,me);
  if (me->query_temp("pantao/is_busy"))
  {
    message_vision ("$N对$n摇摇头："+get_respect(who)+
                    "，老夫正忙，失礼了。\n",me,who);
    return 1;
  }

  if (me->query_temp("pantao/level") != LEVEL_FEAST)
  {
    message_vision ("$N说道：蟠桃会尚未开始，老夫怎敢惊动王母娘娘。\n",me);
    return 1;
  }
  if (! is_tian_shen(who))
  {
    message_vision ("$N说道：$n非天神也，可否请新任天神来谢宴？\n",me,who);
    return 1;
  }
  if (environment(me)->query("short")!="瑶池")
  {
    message_vision ("$N道：这里乃非瑶池，如何谢宴？\n",me);
    return 1;
  }
  message_vision ("$N对$n说道："+get_respect(who)+
                  "，老夫这就秉报请王母娘娘！\n",me,who);
  message_vision ("祥云飘起，$N离去。\n",me);
  //me->set("env/invisibility",9);
  me->set_temp("pantao/reappear",environment(me));
  load_object("/obj/empty");
  me->move ("/obj/empty");
  remove_call_out ("make_finish");
  call_out ("make_finish",3,me,who);
  return 1;
}

void make_finish (object me, object who)
{
    if(!who) return;

  if (!environment(who) ||
      environment(who) != me->query_temp("pantao/reappear"))
  {
    me->move(me->query_temp("pantao/reappear"));
    message_vision ("祥云飘落，$N跳出云来。\n",me);
    return;
  }

  announce (me,"蟠桃大会谢宴，王母娘娘送客！\n\n");

  //me->set("env/invisibility",0);
  me->move(me->query_temp("pantao/reappear"));
  message_vision ("祥云飘落，$N跳出云来。\n",me);

  me->delete_temp("pantao");
  me->delete_temp("invite");
  remove_call_out ("execute_finish");
  call_out ("execute_finish",1,me);
}

void execute_auto_finish (object me)
{
  if (me->query_temp("pantao/level") != LEVEL_FEAST)
  {
    return;
  }

  announce (me,"时辰已到，蟠桃大会谢宴，王母娘娘送客！\n\n");

  me->delete_temp("pantao");
  me->delete_temp("invite");
  remove_call_out ("execute_finish");
  call_out ("execute_finish",1,me);
}

int execute_finish (object me)
{
  int i, j;
  object *list;

  if (me == 0)
    me = this_object();
 
  list = all_inventory(environment(me));
  i = sizeof(list);
  while  (i--)
  {
    reset_eval_cost();
    if (!interactive(list[i]))
      continue;
    if (me == list[i])
      continue;

    j = random(100)+1;
    list[i]->add("potential",j);
    tell_object(list[i],"你的潜能增加了"+chinese_number(j)+"点！\n"); 
    call_out ("execute_back",i*2,me,list[i]);
  }
  remove_call_out ("send_back_girls");
  call_out ("send_back_girls",1,me);
}

void send_back_girls (object me)
{
  int i;
  object where;
  object *list;

  list = all_inventory(environment(me));
  i = sizeof(list);
  while (i--)
  {
    reset_eval_cost();
    if (interactive(list[i]))
      continue;
    if (list[i]->query("id") != "xian nu")
      continue;
    if (where = query("previous_location"))
      list[i]->move(where);
    else
      destruct (list[i]);
  }
}

int qualified(object me)
{
   if(!interactive(me))
     return 0;
   if(wizardp(me))
     return 0;
   if(me->query("combat_exp") < 10000)
     return 0;
   return 1;
}

