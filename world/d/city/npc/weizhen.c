// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;

void create()
{
   set_name("魏征", ({ "wei zheng", "wei", "chengxiang" }));
   set("title", "当朝宰相");
   set("gender", "男性");
   set("age", 45);
   set("str", 20);
   set("dex", 20);
   set("long", "他就是当朝丞相魏征，性格刚正不阿，以敢于直谏闻名。\n");
   set("combat_exp", 60000);
   set("attitude", "heroism");

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
   carry_object(__DIR__"obj/choupao")->wear();
        add_money("gold", 1);

}
