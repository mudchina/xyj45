// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;

void create()
{
        set_name("天波儿笑", ({"tianboer xiao", "xiao"}));
        set("long", "他是乱石山碧波潭的小妖。\n");
        set("age", 30);
   set("title", "泥鳅精");
        set("attitude", "friendly");
        set("gender", "男性");
   set("class", "dragon");
        set("str", 30);
        set("int", 20);
        set("per", 10);
        set("con", 30);
        set("max_kee",1200);
        set("max_sen", 1000);
        set("combat_exp", 400000);
        set("force", 1200);
        set("max_force", 1200);
        set("mana",400);
        set("max_mana", 700);
        set("force_factor", 40);
        set("mana_factor", 20);
        set_skill("unarmed", 120);
        set_skill("force", 120);
        set_skill("spells", 120);
        set_skill("dodge", 120);
   set_skill("whip", 120);
   set_skill("hellfire-whip", 100);
   set_skill("parry", 120);
   map_skill("whip", "hellfire-whip");
   map_skill("parry", "hellfire-whip");
        setup();
        carry_object("/d/obj/armor/tenjia")->wear();
   carry_object("/d/obj/weapon/whip/tielian")->wield();
}
void relay_emote(object ob,string verb)
{
   if( ob->query("name")!="笑波儿天" ) return;
        switch(verb) {
        case "kick":
                        command("say 狗腿又发痒了...\n");
                break;
        case "wake":
                        command("wake");
     break;
        case "poke":  
                        command("poke xiao");                                        
                break;
        case "consider":  
                        command("poor tian");                                        
                break;
        case "grin":  
                        command("hehe tian");                                        
                break;
   case "lazy":
        command("lazy xiao");
     break;
        }
}

