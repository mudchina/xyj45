// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// xunshi.c

inherit NPC;
void create()
{
   set_name("冰谷巡使", ({"xunshi", "shi"}));
   set("gender", "男性" );
   set("age", 33);
   set("long", "雪山门下有很多巡使。因为外人很少能到这里，\n在谷内的巡使大多武功不高，至于大雪山的法术则基本上不会。\n这位巡使身披白袍，腰跨弯刀。白袍当胸绣着一只飞扬欲脱的大鹏鸟。\n弯刀看起来晶莹透明，好像是以寒冰制成。\n");
   set("class", "yaomo");
   set("combat_exp", 25000);
   set("attitude", "peaceful");
   create_family("大雪山", 4, "弟子");
   set_skill("unarmed", 30);
   set_skill("yingzhaogong", 30);
   set_skill("dodge", 30);
   set_skill("parry", 30);
   set_skill("blade", 30);
   set_skill("bingpo-blade", 30);
   set_skill("xiaoyaoyou", 30);
   set_skill("force", 30);   
   set_skill("ningxie-force", 30);
   map_skill("force", "ningxie-force");
   map_skill("blade", "bingpo-blade");
   map_skill("dodge", "xiaoyaoyou");
   map_skill("unarmed", "yingzhaogong");

   set("per", 19);
   set("max_kee", 300);
   set("max_sen", 300);
   set("force", 300);
   set("max_force", 250);
   set("force_factor", 5);

   set("eff_dx", -8000);
   set("nkgain", 60);

   setup();
   carry_object("/d/obj/cloth/xueshan-pao")->wear();
   carry_object("/d/obj/weapon/blade/iceblade")->wield();
}

