// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;

void create()
{
        set_name("赤身鬼使", ({"guard"}));
        set("long", "一个青面獠牙的红须赤身鬼使。\n");
        set("age", 30);
   set("attitude", "heroism");
        set("gender", "男性");
        set("str", 25);
        set("int", 20);
        set("per", 10);
        set("con", 30);
        set("max_kee",800);
        set("max_sen", 800);
        set("combat_exp", 100000);
        set("force", 500);
        set("max_force", 500);
        set("mana",50);
        set("max_mana", 50);
        set("force_factor", 10);
        set("mana_factor", 10);
        set_skill("unarmed", 60);
        set_skill("force", 60);
        set_skill("dodge", 60);
   set_skill("fork", 60);
   set_skill("yueya-chan", 30);
   map_skill("fork", "yueya-chan");
   map_skill("parry", "yueya-chan");
        setup();

   carry_object("/d/obj/weapon/fork/gangcha")->wield();
}
