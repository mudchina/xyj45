// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;

void create()
{
        set_name("白鹤", ({ "bai he", "he" }) );
        set("race", "野兽");
        set("age", 30);
        set("long", "一只黑腿丹顶浑身洁白的白鹤。\n");

        set("str", 30);
        set("dex", 30);
   set("int", 30);
   set("con", 30);
   set("cor", 50);
   set("spi", 50);

        set("limbs", ({ "头部", "身体", "腿部", "左翅", "右翅", "尾巴" }) );
        set("verbs", ({ "bite"}) );

   set("combat_exp", 800000);
   set_skill("unarmed", 180);
   set_skill("parry", 180);
   set_skill("dodge", 180);
   set_skill("force", 180);
   set_skill("spells", 180);

   set("max_kee", 1000);
   set("max_sen", 1000);
   set("mana", 2000);
   set("max_mana", 1000);
   set("mana_factor", 60);
   set("force", 2000);
   set("max_force", 1000);
   set("force_factor", 120);

        set_temp("apply/attack", 100);
        set_temp("apply/armor", 10);
   set_temp("apply/unarmed", 100);
   set_temp("apply/damage", 50);
   set_temp("apply/dodge", 100);
        setup();
}


