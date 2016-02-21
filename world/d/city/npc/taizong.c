// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <ansi.h>

inherit NPC;

void create()
{
   set_name(HIY"唐太宗"NOR, ({ "tang taizong", "tang", "emperor" }));
   set("gender", "男性");
   set("age", 50);
   set("per", 30);
   set("str", 20);
   set("dex", 20);
   set("long", "唐太宗李世民，丰姿英伟，步履端详。\n");
   set("combat_exp", 60000);
   set("attitude", "heroism");
   set("rank_info/respect", "万岁爷");
   set("rank_info/rude", "无道昏君");

   set_skill("unarmed", 80);
   set_skill("force", 80);
   set_skill("sword", 80);
   set_skill("dodge", 80);
   set_skill("parry", 80);
   set_temp("apply/attack", 50);
   set_temp("apply/defense", 50);
   set_temp("apply/armor", 50);
   set_temp("apply/damage", 15);

   set("force", 500); 
   set("max_force", 500);
   set("enforce", 10);

   setup();
   carry_object(__DIR__"obj/longpao")->wear();
        add_money("gold", 1);

}
