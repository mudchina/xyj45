// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
 
inherit NPC;
 
void create()
{
 
        set_name("神兵", ({ "shen bing", "bing"}) );
        set("gender", "男性" );
        set("long","托塔李天王帐下神兵，膀阔腰圆，力大无穷。\n");
        set("age",40);
        set("str", 30);
        set("int", 20);
   set("con", 30);
   set("spi", 20);
        set("per", 15);
   set("class", "xian");
   set("attitude", "heroism");
        set("combat_exp", 300000);
   set("max_kee", 800);
   set("max_sen", 800);
        set("force",300);
        set("max_force",300);
   set("force_factor", 15);
   set("mana", 600);
   set("max_mana", 300);
   set("mana_factor", 15);
        set_skill("unarmed",119);
        set_skill("dodge",119);
        set_skill("parry",119);
   set_skill("sword", 119);
   set_skill("force", 119);
   set_skill("spells", 119);
    set_skill("dao", 50);
   map_skill("spells", "dao");
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: cast_spell, "light" :),
                (: cast_spell, "thunder" :)
        }) );

        setup();
        carry_object("/d/obj/armor/tongjia")->wear();
   carry_object("/d/obj/weapon/sword/changjian")->wield();
}
 

