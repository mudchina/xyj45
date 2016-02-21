// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// lancaihe.c...weiqi, 98.02.24.

inherit NPC;
void create()
{
   set_name("蓝采和", ({"lan caihe", "lan", "caihe"}));
   //set("title", "");
   set("gender", "男性" );
   set("age", 18);
   set("per", 20);
   set("long", "一位面腆和善的少年。\n");
   set("class", "xian");
   set("combat_exp", 120000);
   set("attitude", "peaceful");
   create_family("五庄观", 3, "弟子");
   set_skill("unarmed", 60);
   set_skill("wuxing-quan", 60);
   set_skill("dodge", 80);
   set_skill("baguazhen", 80);
   set_skill("parry", 80);
   set_skill("blade", 90);
   set_skill("yange-blade", 100);
   set_skill("force", 70);   
   set_skill("zhenyuan-force", 70);
   set_skill("literate", 80);
   set_skill("spells", 80);
   set_skill("taiyi", 80);
   map_skill("spells", "taiyi");
   map_skill("force", "zhenyuan-force");
   map_skill("unarmed", "wuxing-quan");
   map_skill("blade", "yange-blade");
   map_skill("dodge", "baguazhen");

   set("max_kee", 500);
   set("max_sen", 500);
   set("force", 1000);
   set("max_force", 800);
   set("mana", 1600);
   set("max_mana", 800);   
   set("force_factor", 40);
   set("mana_factor", 40);

   setup();
   carry_object("/d/obj/cloth/linen")->wear();
   carry_object("/d/obj/weapon/blade/yanblade")->wield();
}

void attempt_apprentice(object ob)
{
   if( (string)ob->query("family/family_name")=="五庄观" )
   {
     if( (int)ob->query("family/generation") < 3  )
     {
        if ( (string)ob->query("gender") == "男性" ) command("say 师叔见笑了。\n");
        else command("say 师姑见笑了。\n");
     }
     else if( (int)ob->query("family/generation") ==3  )
     {
        if ( (string)ob->query("gender") == "男性" ) command("say 师兄太客气了。\n");
        else command("say 师妹太客气了。\n");
     }
     else 
     {
        command("consider");
        command("say 是你自己要拜的，你师父打上门来我可得拿你挡。\n");
        command("recruit " + ob->query("id") );
     }
   }

   else
   {
     command("say 好，那我就勉为其难吧。\n");
     command("recruit " + ob->query("id") );
   }

   return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "xian");
}




