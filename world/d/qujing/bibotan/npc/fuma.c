// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;
void create()
{
       set_name("九头驸马", ({"jiutou fuma","fuma"}));

        set("long","九头驸马原在北冥大泽泽中修练，后被招为驸马。\n");
       set("gender", "男性");
       set("age", 20);
        set("int", 25);
       set("attitude", "heroism");
        set("combat_exp", 1200000);

        set("eff_dx", -50000);
        set("nkgain", 500);

       set("class","yaomo");
       set("per", 10);
   set("str", 30);
       set("max_kee", 1600);
       set("max_sen", 1600);
       set("force", 2000);
       set("max_force", 2000);
       set("force_factor", 70);
       set("max_mana", 1600);
       set("mana", 3000);
       set("mana_factor", 60);
       set_skill("unarmed", 120);
       set_skill("dodge", 150);
       set_skill("force", 150);
       set_skill("parry", 150);
       set_skill("spells", 120);
   set_skill("fork", 180);
    set_skill("yueya-chan", 180);
   map_skill("parry", "yueya-chan");
   map_skill("fork", "yueya-chan");
        setup();
   carry_object("/d/qujing/bibotan/obj/moonstaff")->wield();
        carry_object("/d/qujing/bibotan/obj/zhanpao")->wear();
}


int recognize_apprentice(object who)
{   who= this_player();
   if( who->query("family/family_name")=="乱石山碧波潭" 
     && who->query("can_learn_staff") ) { 
           return 1;
   }
   return 0;
}

