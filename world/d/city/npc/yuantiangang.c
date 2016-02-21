// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;
void create()
{
        set_name("袁天罡", ({"yuan tiangang", "yuan"}));
        set("gender", "男性" );
        set("age", 33);
        set("long","袁天罡是天监台总管，听说他法术高深。
他为人正直仗义，脸上总是一股忧国忧民的神情。\n");
        set("int", 30);
   set("per", 25);
        set("combat_exp", 50000);
        set("attitude", "friendly");
   set("title", "天监台正先生");
        set_skill("unarmed", 60);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("spells", 100);
   set_skill("baguazhou", 100);
        set_skill("literate", 50);
        set_skill("sword", 60);  
        set_skill("changquan", 50);  

        map_skill("spells", "baguazhou");
        map_skill("unarmed", "changquan");

        set("per", 30);
        set("max_kee", 400);
        set("max_gin", 400);
        set("max_sen", 400);
        set("force", 450);
        set("max_force", 300);
        set("force_factor", 10);
        set("mana", 450);
        set("max_mana", 300);
        set("mana_factor", 5);

        setup();
   add_money("silver", 5);
        carry_object("/d/obj/cloth/baguapao")->wear();
        carry_object("/d/obj/weapon/sword/taomujian")->wield();
}
int accept_fight(object me)
{
        write("袁天罡凛然道：学武乃是为了强身，不是打打杀杀！\n");
        return 0;
}
int recognize_apprentice(object me)
{
        if((int)me->query("yuan-learn"))
        return 1;
        return notify_fail("袁天罡说道：您太客气了，这怎么敢当？\n");
}

int accept_object(object who,object ob)
{
        if (ob->query("id")=="fan he"){
     if (((string)who->query("family/family_name")=="将军府")){
        who->set("yuan-learn", 1);
        write("袁天罡笑道：将军看起来一表人才，以后定是人前出头之辈！
袁天罡略为沉思，又道：若将军有何问题，可随时和我商讨，天罡若是知晓，定会答复．\n");
        call_out("destroy", 1, ob);
        return 1;
     }
     if (((string)who->query("family/family_name")!="将军府")){
        command("say 多谢多谢，我正饿着哪！");
        command("give 1 silver to " + who->query("id"));        
        call_out("destroy", 1, ob);
                        return 1;
     }
   }
   else return 0;
}
void destroy(object ob)
{
        destruct(ob);
        return;
}

