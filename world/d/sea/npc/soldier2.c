// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;

void create()
{
        set_name("蟹将", ({"xie jiang", "xie"}));
        set("long","一个穿着盔甲的大螃蟹，正走来走去维护秩序．\n");
        set("gender", "男性");
        set("age", 20);
        set("per", 10);
        set("attitude", "heroism");
        set("combat_exp", 30000);
        set_skill("parry", 35);
        set_skill("dodge", 35);
   set_skill("unarmed", 30);
   set_skill("fork", 30);
   set("max_kee", 350);
   set("max_sen", 350);
   set("max_force", 200);
   set("force", 200);
   set("force_factor", 5);
        setup();
        carry_object("/d/obj/armor/tenjia")->wear();
        carry_object("/d/obj/weapon/fork/gangcha")->wield();
}

