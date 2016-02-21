// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;

void create()
{
        set_name("大肚虾婆", ({"xia po", "po"}));
        set("long", "一个挺着肚子走来走去的老虾婆。\n");
        set("age", 50);
        set("attitude", "peaceful");
        set("gender", "女性");
        set("str", 20);
        set("int", 20);
        set("per", 10);
        set("con", 30);
        set("max_kee",500);
        set("max_sen", 500);
        set("combat_exp", 5000);
   set("eff_dx", -2000);
   set("nkgain", 200);
        set("force", 200);
        set("max_force", 200);
        set("mana", 60);
        set("max_mana", 50);
        set("force_factor", 10);
        set("mana_factor", 10);
        set_skill("unarmed", 20);
        set_skill("force", 20);
        set_skill("spells", 20);
        set_skill("dodge", 20);
   set_skill("hammer", 20);
   set("chat_chance", 10);
   set("chat_msg", ({   
   "大肚虾婆挺了挺肚子。\n",
   (: random_move :)
}));
        setup();
   add_money("silver", random(2)+1);
        carry_object("/d/obj/cloth/skirt")->wear();
}

