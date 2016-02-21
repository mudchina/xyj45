// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//qingfeng.c

inherit NPC;
void create()
{
   set_name("清风", ({"qing feng", "qingfeng"}));
   set("gender", "男性" );
   set("age", 16);
   set("long", "一个机灵的小仙童，在五庄观上下很是吃得开。\n");
   set("class", "xian");
   set("combat_exp", 10000);
   set("attitude", "peaceful");
   set("title", "小仙童");
   set_skill("unarmed", 40);
   set_skill("dodge", 40);
   set_skill("parry", 40);

   set("per", 20);
   set("max_kee", 200);
   setup();
   carry_object("/d/obj/cloth/xianpao")->wear();
}

void init()
{       
   object ob=this_player();
   object me=this_object();

   ::init();

   if ( ((int)ob->query("env/invisibility")  == 0) && ((string)environment(me)->query("short")=="正殿") )
   {
     remove_call_out("greeting");
     call_out("greeting", 1, ob);
   }
}

void greeting(object ob)
{
   if( !ob || environment(ob) != environment() ) return;

   if ( (int)ob->query("combat_exp")>500000 )
     command("say 这位" + RANK_D->query_respect(ob) + "失迎了，快请上坐！请到东殿用香茶！\n");
   else if ( (int)ob->query("combat_exp")>100000 )
     command("say 这位" + RANK_D->query_respect(ob) + "失迎了，快请坐！请到东殿用茶！\n");
   else if ( (int)ob->query("combat_exp")>10000 )
     command("say 这位" + RANK_D->query_respect(ob) + "，请坐！用茶！\n");
   else if ( (int)ob->query("combat_exp")>1000 )
     command("hi " + ob->query("id"));   
   else
     return;
}
