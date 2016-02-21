// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// lao ren, 9-28-97 pickle

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string kick_back();

void create()
{
  set_name("白发老人", ({ "lao ren", "lao", "laoren","ren", "baifa", "immortal", "master", "shifu" }));

  set("gender", "男性");
  set("age", 100);

  set("str", 20);
  set("per", 130);
  set("cor", 30);
  set("cps", 75);
  set("kar", 100);
  set("int", 40);
  set("con", 40);
  set("spi", 40);

  set("long","
这是一位鹤发童颜的老人。他看起来似乎很老的样子，
但偏又是红光满面。看到你打量他，他对你和蔼地笑了
一笑。

");
  set("title", "神仙");
  set("combat_exp", 2000000);

  set_skill("literate", 150);
  set_skill("unarmed", 100);
  set_skill("force", 100);
  set_skill("lengquan-force", 100);
  set_skill("axe", 150);
  set_skill("sword", 100);
  set_skill("dodge", 100);
  set_skill("parry", 100);
  set_skill("sanban-axe", 180);
  set_skill("xiaofeng-sword", 100);
  set_skill("spells", 160);
  set_skill("baguazhou", 160);
  set_skill("yanxing-steps", 100);
  map_skill("force", "lengquan-force");
  map_skill("spells", "baguazhou");
  map_skill("axe", "sanban-axe");
  map_skill("parry", "sanban-axe");
  map_skill("dodge", "yanxing-steps");
  map_skill("sword", "xiaofeng-sword");

  set("max_sen", 4500);
  set("max_kee", 3500);
  set("force", 1500); 
  set("max_force", 1500);
  set("force_factor", 40);
  set("max_mana", 3000);
  set("mana", 3000);
  set("mana_factor", 50);

  set("inquiry", ([
   "name"    : "我是谁？我也不记得了。",
   "here"    : "这是一场梦。",
   "rumors"  : "消息？你不专心学艺，又来打听什么消息？",
   "回去"    : (: kick_back :),
   "return"  : (: kick_back :),
]) );

  create_family("将军府", 1, "蓝");

  setup();
  carry_object("/d/obj/weapon/axe/huafu")->wield();
  carry_object("/d/obj/cloth/linen")->wear();
}

string kick_back()
{
    object me=this_player();

    message_vision(CYN"$n抬手朝$N的前额猛的一拍，喝声「去！」\n"NOR, me, this_object());
    message_vision(CYN"$N的身影渐渐淡去了．．．\n"NOR, me);
    me->move("/d/jjf/guest_bedroom");
    message_vision("$N突然惊醒坐起，原来是南柯一梦．．．\n", me);
    return "";
}
int accept_fight(object me)
{
  command("say 唉，年轻人，火气就是大。别动粗别动粗！");
  return 0;
}

void attempt_apprentice(object me)
{
  int effstr=(int)(me->query("str")+me->query_skill("unarmed",1)/10-2);
  string myrespect=RANK_D->query_respect(me);

  if (wizardp(me) && me->query("env/override"))
  {
   command("recruit "+me->query("id"));
   return;
  }
  if (me->query("family/master_id") != "cheng yaojin"
   || !me->query_temp("jjf/白发有缘"))
  {
   command("say 这。。。老夫素来不收无缘之人，"+myrespect+"还是回去吧。");
   return;
  }
  if (effstr<30)
  {
      command("say "+myrespect+"的臂力低了些，恐怕难以学斧。");
      return;
  }
  command("nod");
  command("say 看来"+myrespect+"与我有缘，老夫就收下你吧！\n");
  command("recruit " + me->query("id") );
  return;
}
int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob) )
    ob->set("class", "fighter");
}
