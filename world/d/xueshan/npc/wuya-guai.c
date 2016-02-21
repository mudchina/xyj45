// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// wuya-guai.c...weiqi, 97.09.15.

inherit NPC;

string give_map(object me);
string help_fly(object me);
int do_yes(string arg);

void create()
{
   set_name("乌鸦先生", ({"wuya xianshen", "wuya", "xianshen"}));
   set("gender", "男性" );
   set("age", 43);
   set("per", 112);//no rongmao description.

   set("long", "这位乌鸦先生来自遥远的大雪山。乃是大鹏明王座下有名的高手之一。\n他远看还不错，走近了才发现他长着长长的一张乌鸦嘴。\n");
   set("class", "yaomo");
   set("combat_exp", 100000);
   set("attitude", "peaceful");
   create_family("大雪山", 3, "弟子");
   set_skill("unarmed", 50);
   set_skill("yingzhaogong", 50);
   set_skill("cuixin-zhang", 20);
   set_skill("dodge", 50);
   set_skill("xiaoyaoyou", 50);
   set_skill("parry", 50);
   set_skill("blade", 50);
   set_skill("bingpo-blade", 50);
   set_skill("force", 50);   
   set_skill("ningxie-force", 50);
   set_skill("literate", 30);
   set_skill("spells", 50);
   set_skill("dengxian-dafa", 50);
   map_skill("spells", "dengxian-dafa");
   map_skill("force", "ningxie-force");
   map_skill("unarmed", "yingzhaogong");
   map_skill("blade", "bingpo-blade");
   map_skill("dodge", "xiaoyaoyou");

   set("max_kee", 500);
   set("max_sen", 400);
   set("force", 400);
   set("max_force", 400);
   set("mana", 500);
   set("max_mana", 400);   
   set("force_factor", 35);
   set("mana_factor", 20);

   set("eff_dx", -25000);
   set("nkgain", 150);

   set("inquiry", ([
     "name" : "问什么问，张着眼睛是看的，长着脑袋是想的。\n",
     "here" : "管它呢！反正比不上我们大雪山。\n",
     "怎么去" : "飞过去最快，走也能到。\n",
     "怎么走" : "好像是从昆仑山往北走。\n",
     "怎么飞" : (: help_fly :),      
     "大雪山" : (: give_map :),
   ]) );

   set("no_map", 0);

   setup();
   carry_object("/d/obj/cloth/xueshan-pao")->wear();
   carry_object("/d/obj/weapon/blade/iceblade")->wield();
}

void attempt_apprentice(object ob)
{

   if( (string)ob->query("family/family_name")=="大雪山" ){
     if( (int)ob->query("family/generation") < 3  ){
        command("say 不敢，不敢。我该拜" + RANK_D->query_respect(ob) + "您为师才是。\n");
     }
     else if( (int)ob->query("family/generation") ==3  ){
        command("say 你这个" + RANK_D->query_rude(ob) + "别来消遣大爷我了！\n");
     }
     else {
        command(":D");
        command("say 你这个" + RANK_D->query_rude(ob) + "早就该来拜我为师！你那个破师父什么都不懂...\n");
        command("recruit " + ob->query("id") );
     }
   }

   else{
     command(":D ");
     command("say 好，到我们大雪山来学艺，又找了个好师父，只要能活下来，" + RANK_D->query_respect(ob) + "可以说是前途无量啊！\n");
     command("recruit " + ob->query("id") );
   }

   return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "yaomo");
}

string help_fly(object me)
{
   me=this_player();
   if( me->query("combat_exp")<30000 ){
/*
     message_vision("乌鸦先生道：马上就叫你飞...闭上眼睛！\n", me);
     message_vision("只见乌鸦先生嘴里念叨了几句，一脚踢中$N的屁股，$N腾云驾雾般飞了出去...\n", me);
     me->move("/d/xueshan/binggu");
     tell_room( environment(me),"只听劈啪！一声，一个人从空中飞过来，死猪般地摔在地上。\n", ({me}));
     return "嘿嘿！\n";
*/
     return "赶紧学吧！\n";
   }
   else{
     return "你现在头脑不清醒，别摔死了！\n";
   }
}

string give_map(object me)
{
   me=this_player();
   me->set_temp("need_map", 1);
   return "大雪山，那可是个好地方，你想去吗(yes)？\n";
}

void init()
{
   add_action("do_yes", "yes");
}

int do_yes(string arg)
{
   object me;

   me=this_player();
   
   if(me->query_temp("need_map")) 
   {
     message_vision("$N答道：想去！\n\n", me);
     if( query("no_map") == 0 )
     {
        message_vision("乌鸦先生说道：好！那我给你一张地图吧！\n", me);
        me->set_temp("need_map", 0);

        carry_object("/d/obj/misc/xueshan-map");
        command("give xueshan map to " + me->query("id"));
        set("no_map", 1);
        call_out("regenerate", 480);
     }
     else
     {
        message_vision("乌鸦先生说道：我本来想给你一张地图的，但是刚才发完了。\n", me);
     }

     return 1;
   }
   return 0;
}

int regenerate()
{
   set("no_map", 0);
   return 1;
}

