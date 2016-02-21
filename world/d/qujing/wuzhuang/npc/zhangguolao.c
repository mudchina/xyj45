// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// zhangguolao.c...weiqi, 98.02.24.

inherit NPC;
void create()
{
   set_name("张果老", ({"zhang guolao", "zhang", "guolao"}));
   //set("title", "");
   set("gender", "男性" );
   set("age", 50);
   set("per", 20);
   set("long", "一位笑嘻嘻的滑稽老头。\n");
   set("class", "xian");
   set("combat_exp", 120000);
   set("attitude", "peaceful");
   create_family("五庄观", 3, "弟子");
   set_skill("unarmed", 60);
   set_skill("wuxing-quan", 60);
   set_skill("dodge", 80);
   set_skill("baguazhen", 70);
   set_skill("parry", 80);
   set_skill("hammer", 90);
   set_skill("kaishan-chui", 100);
   set_skill("force", 70);   
   set_skill("zhenyuan-force", 70);
   set_skill("literate", 50);
   set_skill("spells", 80);
   set_skill("taiyi", 80);
   map_skill("spells", "taiyi");
   map_skill("force", "zhenyuan-force");
   map_skill("unarmed", "wuxing-quan");
   map_skill("hammer", "kaishan-chui");
   map_skill("dodge", "baguazhen");

   set("max_kee", 500);
   set("max_sen", 500);
   set("force", 1000);
   set("max_force", 800);
   set("mana", 1600);
   set("max_mana", 800);   
   set("force_factor", 40);
   set("mana_factor", 40);

   set("maolu", 0);

   setup();
   carry_object("/d/obj/cloth/linen")->wear();
   carry_object("/d/obj/cloth/pobuxie")->wear();
   carry_object("/d/obj/weapon/hammer/jiuhulu")->wield();
}

void init()
{       
   object ob=this_player();
   object me=this_object();

   ::init();

   set("chat_chance", 10);
   set("inquiry", ([
     "name" : "呵呵！张果老是也。\n",
     "here" : "今儿个醉了，还真被你问倒了。\n",
    ]) );

   set("chat_msg", ({
     "张果老嘻嘻嘻地笑了几声。\n",   
     "张果老拿起酒葫芦又灌了一口，满意地咂了咂嘴。\n",
     "张果老打了个响指：哈哈，我的小毛驴就是听话。\n",
     (: random_move :)
   }) );

   if( query("maolu") == 0 )
   {
     call_out("qi_maolu", 1);
     set("maolu", 1);
   }

}

void qi_maolu()
{
   object maolu;

           maolu = new(__DIR__"xiaomaolu.c");
           maolu->move( environment(this_object()) );
   command("mount maolu");
   return;   
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
     command("say 好，好好干，张果老不行，徒弟可不能差了。\n");
     command("recruit " + ob->query("id") );
   }

   return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "xian");
}




