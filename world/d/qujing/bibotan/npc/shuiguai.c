// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;
void create()
{
        set_name("水蛇怪", ({"shuishe guai", "guai"}));
        set("long", "一个身材细长的水蛇怪，吐着尺长的芯子，浑身发着恶臭。\n");
        set("age", 30);
        set("attitude", "aggressive");
        set("gender", "男性");
   set("class", "yaomo");
        set("str", 20);
        set("int", 20);
        set("per", 10);
        set("con", 30);
        set("max_kee",200);
        set("max_sen", 200);
   set_temp("apply/armor", 10);
   set("bellicosity", 2000);
        set("combat_exp", 15000);

   set("eff_dx", -5000);
        set("nkgain", 120);

        set("force", 60);
        set("max_force", 60);
        set("mana",30);
        set("max_mana",20);
        set("force_factor", 5);
        set("mana_factor", 5);
        set_skill("unarmed", 20);
        set_skill("force", 20);
        set_skill("spells", 20);
        set_skill("dodge", 20);
   set_skill("parry", 20);
   set_skill("cuixin-zhang", 20);
   map_skill("unarmed", "cuixin-zhang");
        setup();
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
   if( (int)this_object()->query("time") >= 6 ) {
        message("vision",name() + "“噗嗵”一声，跳回到水中。\n", environment(),this_object() );
        destruct(this_object());

   }
   return;
}

