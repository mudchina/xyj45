// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// monkey1.c

inherit NPC;

void create()
{
   set_name("大马猴", ({ "mahou","monkey","hou" }) );
   set("race", "野兽");
   set("age", 26);
   set("long", "一只大马猴。\n");
   
   set("str", 35);
   set("cor", 26);   
   set("combat_exp",5000);
            set_skill("dodge",40);
            set_skill("unarmed",30);
   set("limbs", ({ "头部", "身体", "前爪", "后脚", "尾巴" }) );
   set("verbs", ({ "bite", "claw" }) );

   set("chat_chance", 6);
   set("chat_msg", ({
     (: call_other, this_object(), "random_move" :),
     "大马猴对你做了个鬼脸。\n",
     "啪地一声！大马猴扔来一颗野果，正好砸中你的鼻子。\n",
     "大马猴对你吱吱吱地叫了几声。\n",
     "大马猴抓耳挠腮地，围着你跳来跳去。\n" }) );
     
//   set_temp("apply/attack", 20);
//   set_temp("apply/defense", 50);
//   set_temp("apply/armor", 3);

   setup();
}

int accept_object(object who, object ob)
{
   if( ob->id("mihou tao")||ob->id("huasheng")||ob->id("jiudai")) {
     set_leader(who);
     message("vision", name() + "高兴得抓耳挠腮，直翻跟头。\n", environment());
     return 1;
   }
}
