// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 

inherit NPC;

void create()
{
       set_name("妇人", ({"woman"}));
       set("gender", "女性");
        set("combat_exp", 500);
   set("per", 19);
       set("age", 36);
       set("attitude", "peaceful");
       set("shen_type", 1);
       set_skill("unarmed", 5);
        setup();
       add_money("silver", 1);
}

