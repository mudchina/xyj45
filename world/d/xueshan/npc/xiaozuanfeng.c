// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//xiaozuanfeng.c

inherit NPC;
void create()
{
   set_name("小钻风", ({"xiao yao", "xiaoyao", "yao"}));
   set("gender", "男性" );
   set("age", 16);
   set("long", "小钻风原是狮驼山的巡山小妖。\n跟着青狮老魔到大雪山后改当厨师了。\n不过他好个吃喝，在这里近水楼台先得月，倒也逍遥快活。\n");
   set("class", "yaomo");
   set("combat_exp", 5000);
   set("attitude", "peaceful");
   set("title", "小妖");
   set_skill("unarmed", 20);
   set_skill("dodge", 20);
   set_skill("parry", 10);

   set("per", 11);
   set("max_kee", 150);
   setup();
   carry_object("/d/obj/armor/shoupi")->wear();
}

void init()
{       
   object ob=this_player();
   object me=this_object();

   ::init();
   if ( ((string)ob->query("family/family_name") == "大雪山") && ((string)environment(me)->query("short")=="厨房") )
   {
     command("say 还没到吃饭时间呢！一天到晚就知道吃，吃...\n");
     command("kick ");
   }
}

