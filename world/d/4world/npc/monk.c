// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 

inherit NPC;

void create()
{
       set_name("游方僧人", ({"monk"}));
       set("gender", "男性");
   set("long", "一位白净脸的大和尚。\n");
        set("combat_exp", 8000+random(2000));
   set("per", 18);
       set("age", 40);
       set("attitude", "peaceful");
       set("shen_type", 1);
       set_skill("unarmed", 25);
   set_skill("parry", 25);
   set_skill("dodge", 25);
        setup();
       add_money("coin", 20+random(50));
   carry_object("/d/obj/cloth/sengyi")->wear();
}

