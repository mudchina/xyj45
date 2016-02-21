// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// kulou.c 骷髅
// created 9-15.97 pickle

/************************************************************/
// global declaractions etc.

#include <ansi.h>
inherit NPC;

int accept_object(object me, object ob);
/************************************************************/

void create()
{
  set_name("骷髅", ({"ku lou", "yao", "kulou", "skeleton", "monster"}));
  set("long","这明明是一付干枯的骸骨，但不知怎么他竟然是活的！\n");
  set("gender", "男性");
  set("age", 20+random(15));
  set("attitude", "peaceful");
  set("combat_exp", 100000);
  set_skill("unarmed", 100);
  set_skill("parry", 100);
  set_skill("dodge", 100);
  set_skill("blade", 100);
  set_skill("kugu-blade", 100);
  map_skill("blade", "kugu-blade");
  map_skill("parry", "kugu-blade");
  map_skill("dodge", "kugu-blade");
  set("chat_chance", 1);
  set("chat_msg", ({
   "骷髅道：唉，也不知在这里睡了多久了。\n",
   "骷髅道：都忘了人肉是什么味儿了。\n",
   }) );
  set("inquiry", ([
   "name":     "名字？什么名字？我早就不记得了。",
   "here":     "这里？这里是个破洞。要不是那个混帐绿毛老鼠叫我看着，我早出去吃人肉，享清福了！",
   "rumors":   "嘿嘿，我都在这里睡这么多年了，还能知道点什么？",
   "人肉":     "唉。能吃上点人肉就好了。",
   ]));

  setup();
  carry_object("/d/obj/weapon/blade/blade")->wield();
}

/************************************************************/

void init()
{
    object ob;
    ::init();

    if (interactive(ob=this_player()) && !is_fighting())
    {
   remove_call_out("greeting");
   call_out("greeting", 1, ob);
    }
}

void greeting(object me)
{
    string myrude=RANK_D->query_rude(me);
    command("hehe "+me->query("id"));
    command("say 你这"+myrude+"来干什么？是不是带好东西孝敬我来着？");
    return;
}
/************************************************************/
int accept_object(object me, object ob)
{
    if (ob->query("name_recognized") == "人肉包子")
    {
//   if (!me->query_temp("wudidong/received_renroubao"))
//   {
//       message_vision(CYN"骷髅皱了皱眉道：这东西你哪搞来的？味道不对！\n"NOR, me);
//       return 2;
//   }
   command("say 不错不错，你小子果然还没忘了我！");
   me->add_temp("wudidong/gave_bookguard_baozi", 1);
   return 1;
    }
    command("say 什么破烂？");
    return 0;
}
/************************************************************/

void die()
{
    string msg;

    msg="骷髅散成一堆白骨，滚了开去。\n";
    msg+=CYN"四面八方传来阵阵惨笑：想杀死一具枯骨，你真是痴心妄想！我会回来的！\n"NOR;
    if(environment())
   message("vision", msg, environment());
    destruct(this_object());
}
