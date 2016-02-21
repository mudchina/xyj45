// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// jiading.c 家丁

inherit NPC;

void create()
{
   set_name("家丁", ({ "jia ding", "jia" }));
   set("gender", "男性");
   set("age", 35);

   set("combat_exp", 4000);
        set_skill("dodge", 20);
        set_skill("unarmed", 20);
        set_temp("apply/attack",  10);
        set_temp("apply/defense", 10);
   setup();
}
   
