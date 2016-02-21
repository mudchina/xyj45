// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// monkey1.c

inherit NPC;

void create()
{
   set_name("小猴子", ({ "xiao houzi","xiaohouzi","monkey","hou" }) );
   set("race", "野兽");
   set("age", 6);
   set("long", "一只顽皮的小猴子。\n");
   
   set("str", 30);
   set("cor", 26);   
   set("combat_exp",50);
            set_skill("dodge",20);
            set_skill("unarmed",10);
   set("limbs", ({ "头部", "身体", "前爪", "后脚", "尾巴" }) );
   set("verbs", ({ "bite", "claw" }) );

   set("chat_chance", 6);
   set("chat_msg", ({
     (: call_other, this_object(), "random_move" :),
     "小猴子对你做了个鬼脸。\n",
     "啪地一声！小猴子扔来一颗野果，正好砸中你的鼻子。\n",
     "小猴子对你吱吱吱地叫了几声。\n",
     "小猴子抓耳挠腮地，围着你跳来跳去。\n" }) );
     
//   set_temp("apply/attack", 20);
//   set_temp("apply/defense", 50);
//   set_temp("apply/armor", 3);

   setup();
}

int accept_object(object who, object ob)
{
   if( ob->id("mihou tao")||ob->id("huasheng")||ob->id("jiudai")) {
     set_leader(who);
     who->set("pending/haha", 5);
     message("vision", name() + "高兴得抓耳挠腮，直翻跟头。\n", environment());
     return 1;
   }
}
void init()
{
        add_action("do_let", "let");
}

int do_let(string arg)
{
        if( !this_player()->query("pending/haha") ) 
        return notify_fail("小猴子口中呜呜两声，好像不愿理你！\n");
   
   if(!arg )
   return notify_fail("小猴子好象不懂你说什么！\n");

   message_vision("$N对$n做了个手势。\n", this_player(), this_object());
   command("bite");
   command("bite none");
   this_player()->add("pending/haha", -1);
   return 1;
}
