// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;
void create()
{
        set_name("石头精", ({"shitou jing", "jing"}));
        set("long", "一个高有数丈的大顽石，只是多出了手脚和脑袋。\n");
        set("age", 30);
        set("attitude", "herosim");
        set("gender", "男性");
   set("class", "yaomo");
        set("str", 30);
        set("int", 20);
        set("per", 10);
   set("looking", "浑身上下就是石头，那里有什么容貌。");
        set("con", 30);
        set("max_kee",800);
        set("max_sen", 800);
   set_temp("apply/armor", 100);
        set("combat_exp", 200000);

   set("eff_dx", -100000);
        set("nkgain", 350);

        set("force", 600);
        set("max_force", 600);
        set("mana",300);
        set("max_mana",200);
        set("force_factor", 10);
        set("mana_factor", 10);
        set_skill("unarmed", 90);
        set_skill("force", 90);
        set_skill("spells", 90);
        set_skill("dodge", 90);
   set_skill("parry", 90);
   set_skill("hammer", 90);
   set_weight(500000);
        setup();
   carry_object("/d/qujing/firemount/obj/stone")->wield();
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
   if( (int)this_object()->query("time") >= 8 ) {
        message("vision",name() + "伸了个懒腰，又躺倒在地下。\n", environment(),this_object() );
   seteuid(getuid());
   if(stone=new("/d/qujing/bibotan/npc/stone"))
   stone->move(environment(this_object()));
        destruct(this_object());

   }
   return;
}

void relay_emote(object ob,string verb)
{
        switch(verb) {
        case "kick":
                        command("say 还踢！？来与大爷战上三百回合。\n");
        this_object()->fight_ob(ob);
        ob->fight_ob(this_object());
                break;
        }
}

