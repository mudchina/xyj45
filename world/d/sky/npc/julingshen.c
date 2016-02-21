// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
 
inherit NPC;
 
void create()
{
 
        set_name("巨灵神", ({ "juling shen", "shen", "juling" }) );
        set("gender", "男性" );
        set("long","托塔李天王帐下先锋大将，膀阔腰圆，力大无穷。\n");
        set("age",40);
   set("title", "先锋大将");
        set("str", 40);
        set("int", 20);
   set("con", 30);
   set("spi", 20);
        set("per", 15);
   set("class", "xian");
   set("attitude", "heroism");
        set("combat_exp", 950000);
   set("max_kee", 1200);
   set("max_sen", 1000);
        set("force",1400);
        set("max_force",1400);
   set("force_factor", 60);
   set("mana", 1500);
   set("max_mana", 800);
   set("mana_factor", 40);

        set("eff_dx", 400000);
        set("nkgain", 400);

   set("mana_factor", 40);
        set_skill("unarmed",150);
        set_skill("dodge",100);
        set_skill("parry",170);
   set_skill("axe", 170);
   set_skill("force", 100);
   set_skill("spells", 100);
    set_skill("changquan", 150);
   set_skill("sanban-axe", 150);
   set_skill("baguazhou", 100);
   set_skill("moshenbu", 100);
   set_skill("lengquan-force", 150);
   map_skill("unarmed", "changquan");
   map_skill("force", "lengquan-force");
   map_skill("spells", "baguazhou");
   map_skill("axe", "sanban-axe");
   map_skill("parry", "sanban-axe");
   map_skill("dodge", "moshenbu");
        setup();
        carry_object("/d/obj/armor/tongjia")->wear();
   carry_object("/d/obj/weapon/axe/huafu")->wield();
}
 

