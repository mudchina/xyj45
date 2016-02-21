// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;
void create()
{
        set_name("柳树精", ({"liushu jing", "jing"}));
        set("long", "一个模样极象树桩子的妖怪，手里提着一截树干。\n");
        set("age", 30);
        set("attitude", "aggressive");
        set("gender", "男性");
   set("class", "yaomo");
        set("str", 20);
        set("int", 20);
        set("per", 10);
   set("looking", "浑身上下就是木头，那里有什么容貌。");
        set("con", 30);
        set("max_kee",600);
        set("max_sen", 600);
   set_temp("apply/armor", 30);
   set("bellicosity", 2000);
        set("combat_exp", 60000);

   set("eff_dx", -20000);
        set("nkgain", 200);

        set("force", 600);
        set("max_force", 600);
        set("mana",300);
        set("max_mana",200);
        set("force_factor", 10);
        set("mana_factor", 10);
        set_skill("unarmed", 40);
        set_skill("force", 40);
        set_skill("spells", 40);
        set_skill("dodge", 40);
   set_skill("parry", 40);
   set_skill("staff", 40);
        setup();
   carry_object("/d/obj/weapon/staff/shugan")->wield();
}
int heal_up()
{

        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
}

void leave()
{
   object stone;
   
   this_object()->add("time", 1);
   if( (int)this_object()->query("time") >= 15 ) {
        message("vision",name() + "一个纵身，跳回到树上。\n", environment(),this_object() );
        destruct(this_object());

   }
   return;
}

