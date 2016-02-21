// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by mon

inherit NPC;

int say_mifa(object me);
int say_chumo(object me);
int say_qujing(object me);
int do_leave();

void create()
{
  set_name("二郎真君", ({"er lang","erlang","er"}));
  set("gender", "男性");
  set("age", 40);
  set("long", @LONG
他就是大名鼎鼎的显圣二郎真君，据传是当年玉帝的妹妹
思凡下界，与杨君所生的孩子。只见他：

  仪容清俊貌堂堂，两耳垂肩目有光。
  头戴三山飞凤帽，身穿一领淡鹅黄。

LONG
);
  set("combat_exp", 10000000);
  set("per", 100);
  set_skill("dodge", 200);
  set("max_sen",1000);
  set("max_gee",1000);
  set("max_gin",1000);
  set("force",1000);
  set("max_force",1000);
  set("max_mana",1000);
  set("force_factor",200);
  set_skill("spells",200);
  set_skill("stick",200);
  set("inquiry",([
    "得道秘法": (: say_mifa :) ,
    "得道": (: say_mifa :),
    "道行": (: say_mifa :),
    "秘法": (: say_mifa :),
    "join": (: say_mifa :),
    "除魔": (: say_chumo :),
    "降妖": (: say_chumo :),
    "取经人": (: say_qujing :),
    "取经": (: say_qujing :),
//    "leave": (: do_leave :),
//    "不灵": (: do_leave :),
  ]));
  set("chat_chance",2);
  set("chat_msg",({
    "真君自言自语道：这求道之术，除了勤学苦练，若能得我这得道秘法．．．\n",
    "真君对你说：除魔降妖，可是能得道升天的啊！\n",
    "真君说道：当今取经之风日盛，取经人嘛，虽说龙蛇混杂，可毕竟．．．\n",
    "真君说道：我这法儿要是不灵，尽管来找我。\n",
  }));

  setup();

}

void init()
{ object me=this_player();
  ::init();
//  add_action("do_agree","agree");
//  add_action("do_listen","listen");
  me->delete_temp("pkgroup");

}

int say_mifa(object dummy)
{ object me=this_player();
  message_vision("二郎真君嘿嘿一笑，说："
  +"你若能够杀死其他求道之人，自可吸取其道行，化为己有。\n"
  +"不过你也会成为别人的目标，确是凶险已极。\n",me);
// 你如有意，当附耳上来(listen)。\n",me);
  me->set_temp("pkgroup/listen",1);
  return 1;
}

int say_chumo(object me)
{
  message_vision("二郎真君说道："
  +"降妖除魔，乃上上之道，若能依我之秘法，对你的道行可是大有好处。\n",me);
  return 1;
}

int say_qujing(object me)
{
  message_vision("二郎真君说道："
  +"这取经之人乃金蝉子化身，若能依我之秘法，杀而食之，可是受益匪浅哪。\n",me);
  return 1;
}

int do_leave()
{
  object me=this_player();
  int gain,lose;

  if(!me->query("kill")) return 0;

//  gain=me->query("pkgroup/gain");
//  lose=me->query("pkgroup/lose");
//  if(gain==1 && lose==1) {
//    message_vision("二郎真君朝$N飞起一脚，骂道："+
//      RANK_D->query_rude(me)+"又没试过，怎知不灵？！\n",me);  
//  } else {
//    if(5*gain>4*lose) {
    if(me->query("PKS")) {
//      message_vision("二郎真君对$N说：你这道行不是增加了吗？谁说不灵！不能退。\n",me);
        message_vision("二郎真君对$N说：你行凶杀了人，我也不能护着你了．．．\n",
     me);
    } else {
      message_vision("真君对$N叹了口气：你这不中用的"+
        RANK_D->query_rude(me)+"！你走吧，再也别来见我！\n",me);
//      me->add("combat_exp",-me->query("pkgroup/join_bonus"));
//      if(me->query("combat_exp")<0) me->set("combat_exp",0);
      me->delete("kill");
      me->save();
    }
//  }
  return 1;
}

int do_listen(string arg)
{ object me=this_player();
  if(me->query("pkgroup/gain")) {
    write("二郎真君哼了一声，没理你。\n");
    return 1;
  }
  if(me->query_temp("pkgroup/listen")) {
   if(me->query_temp("pkgroup/paid")) {
     message_vision("$N上前走了几步，真君在$N耳边悄声说了些什么。\n",me);
     write("二郎真君说：从此以后，你可以杀死who -k所显示的玩家，并"
       +"\n能得到他们的一部分道行，当然，他们也可以杀死你，你同意吗(agree)？\n");
     me->set_temp("pkgroup/agree",1);
   } else {
     message_vision("真君搓了搓手指，对$N阴笑道：这位"
     +RANK_D->query_respect(me)
     +"可知什么是人事吗？\n",me);
   }
   return 1;
  } else return 0;
}

int do_agree(string arg)
{  object me=this_player();
   int dx,dx1;

   if(me->query_temp("pkgroup/agree")) {
     message_vision("真君对$N说道：好！你好自为之吧！\n",me);
     me->delete_temp("pkgroup/agree");
     me->set("pkgroup/lose",1);
     me->set("pkgroup/gain",1);

     //temporary bonus for joining pk.
     if(!me->query("pkgroup_left")) {
     dx=me->query("combat_exp");
     dx1=220-dx;
     if(dx1>0) {
       me->set("combat_exp",220);
       me->set("pkgroup/join_bonus",dx1);
       write("你的道行增加了！\n");
     }
     }

     me->save();
     return 1;
   }
   return 0;
}

int accept_object (object who, object ob)
{
//  if((!ob)||ob->value()<100000) {
//    message_vision("真君抬头瞧了$N一眼，没说什么。\n",who);
//    return 1;
//  } else {
    who->set_temp("pkgroup/paid",1);
    message_vision("真君朝$N点点头：这还差不多。\n",who);
    return 1;
//  }
}


