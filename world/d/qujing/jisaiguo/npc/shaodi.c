// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;

void create()
{
       set_name("小和尚", ({"heshang", "heshang"}));
       set("gender", "男性");
       set("age", 16);
        set("long", "一个头儿光光的小和尚。\n");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("per", 18);
   set("str", 25);
       set("combat_exp", 1500);
        set_skill("unarmed", 15);
   set_skill("stick", 15);
        set_skill("dodge", 15);
        set_skill("parry", 15);
setup();
   carry_object("/d/lingtai/obj/shaoba")->wield();
   carry_object("/d/obj/cloth/sengyi")->wear();
}
int heal_up()
{

        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
}

void leave()
{
   switch( random(3) ) {
   case 0:
               say("小和尚拿着把大竹扫帚，在地下划拉了两下。\n");
   break;
   case 1:
     say("小和尚摸了摸光头，「嘻嘻嘻」地笑出了声。\n");
   break;
   }
}

