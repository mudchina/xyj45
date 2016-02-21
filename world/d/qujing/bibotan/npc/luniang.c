// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;
void create()
{
        set_name("芦娘", ({"lu niang"}));
        set("long",
"她头上插着几朵白色芦花，容颜虽然俏丽，却掩不住身上的妖气。\n");
        set("age", 20);
   set("title", "芦花精");
        set("attitude", "friendly");
        set("gender", "女性");
   set("class", "yaomo");
        set("str", 20);
        set("int", 20);
        set("per", 30);
        set("con", 30);
        set("max_kee",800);
        set("max_sen", 800);
   set_temp("apply/damage", 15);
   set_temp("apply/armor", 15);
        set("combat_exp", 160000);

   set("eff_dx", -60000);
        set("nkgain", 330);

        set("force", 600);
        set("max_force", 600);
        set("mana",300);
        set("max_mana", 500);
        set("force_factor", 30);
        set("mana_factor", 20);
        set_skill("unarmed", 80);
        set_skill("force", 80);
        set_skill("spells", 80);
        set_skill("dodge", 100);
   set_skill("parry", 80);
   set_skill("whip", 80);
   set_skill("moondance", 80);
   set_skill("snowwhip", 80);
   map_skill("whip", "snowwhip");
   map_skill("parry", "snowwhip");
   map_skill("dodge", "moondance");
        setup();
        carry_object("/d/obj/cloth/skirt")->wear();
   carry_object("/d/qujing/bibotan/obj/luhua")->wield();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 3, ob);
        }
}

void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
   
   if((string)ob->query("family/family_name")=="陷空山无底洞" 
   && (string)ob->query("family/family_name")=="乱石山碧波潭"
        && (string)ob->query("family/family_name")=="大雪山") {
   command("xixi " + ob->query("id"));
   return;
   }
   command("look " + ob->query("id") );
   command("say 又白又胖，正合老娘胃口。");
   command("chan " + ob->query("id") );
   kill_ob(ob);
   ob->fight_ob(this_object());

   return;
}

