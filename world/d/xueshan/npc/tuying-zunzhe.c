// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// tuying-zunzhe.c...weiqi, 97.09.15.

#include <ansi.h>

inherit NPC;
string expell_me(object me);
void create()
{
   set_name("秃鹰尊者", ({"tuying zunzhe", "tuying", "zunzhe"}));
   set("title", "明王护法");
   set("gender", "男性" );
   set("age", 53);
   set("per", 112);//no rongmao description.

   set("long", "大鹏明王座下四护法尊者之一。额头高耸，一看就知道功力深厚。\n");
   set("class", "yaomo");
   set("combat_exp", 500000);
   set("attitude", "peaceful");
   create_family("大雪山", 2, "弟子");
   set_skill("unarmed", 80);
   set_skill("yingzhaogong", 150);
   set_skill("dodge", 120);
   set_skill("xiaoyaoyou", 120);
   set_skill("parry", 70);
   set_skill("blade", 70);
   set_skill("bingpo-blade", 70);
   set_skill("force", 90);   
   set_skill("ningxie-force", 90);
   set_skill("literate", 60);
   set_skill("spells", 90);
   set_skill("dengxian-dafa", 100);
   map_skill("spells", "dengxian-dafa");
   map_skill("force", "ningxie-force");
   map_skill("unarmed", "yingzhaogong");
   map_skill("blade", "bingpo-blade");
   map_skill("dodge", "xiaoyaoyou");
   set("max_kee", 800);
   set("max_sen", 600);
   set("force", 1600);
   set("max_force", 800);
   set("mana", 1000);
   set("max_mana", 500);   
   set("force_factor", 50);
   set("mana_factor", 25);

        set("eff_dx", -120000);
        set("nkgain", 300);

   set("inquiry", ([
     "leave": (: expell_me :),
     "name": "嘿嘿！\n",
     "here": "多看少说！\n",
   ]) );


   setup();
   carry_object("/d/obj/cloth/xueshan-pao")->wear();
   //carry_object("/d/obj/weapon/blade/iceblade")->wield();
}

void attempt_apprentice(object ob)
{

   if( (string)ob->query("family/family_name")=="大雪山" ){
     if( (int)ob->query("family/generation") < 2  ){
        command("say 不敢，不敢。我该拜" + RANK_D->query_respect(ob) + "您为师才是。\n");
     }
     else if( (int)ob->query("family/generation") ==2  ){
        command("say 你这个" + RANK_D->query_rude(ob) + "别来消遣大爷我了！\n");
     }
     else if( (int)ob->query("family/generation") ==3  ){
        command(":D");
        command("say 你这个" + RANK_D->query_rude(ob) + "早就该来拜我为师！你那个破师父什么都不懂...\n");
        command("recruit " + ob->query("id") );
     }
     else {
        if( (int)ob->query("combat_exp") >= 40000 ){
          command(":D ");
          command("say 好，到我这里来学艺，别的不说，保证" + RANK_D->query_respect(ob) + "你一双手练得是生裂虎豹！\n");
          command("recruit " + ob->query("id") );
        }
        else {
          command("say 你还是找鹦鹉，乌鸦他们先练着吧。\n");
        }
     }
   }

   else{
     command("hmm");
     command("say 这位" + RANK_D->query_respect(ob) + "，没有推荐人我可不能收你。\n");
   }

   return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "yaomo");
}

string expell_me(object me)
{       
   me=this_player();
   if((string)me->query("family/family_name")=="大雪山") {
     message_vision("秃鹰尊者面色一沉，道：现在正是本门危急之时...\n", me);
     me->set_temp("betray", 1);
     message_vision("秃鹰尊者阴森森地盯着$N，接着道：你真的想逃(true)？\n", me);
     return ("嘿嘿！\n");
   }
   return ("问什么问！自己想去！\n");
}

void init()
{
   add_action("do_true", "true");
}

int do_true(string arg)
{
   if(this_player()->query_temp("betray")) {
     message_vision("$N答道：弟子讲的真心话！\n\n", this_player());
     message_vision("秃鹰尊者叹了口气道：好！你从此便是本门的敌人了！\n", this_player());
     this_player()->add("betray/xueshan", 1);
     this_player()->add("betray/count", 1);
     this_player()->set("combat_exp", this_player()->query("combat_exp")*95/100);
     this_player()->delete("family");
     this_player()->delete("class");
     this_player()->add("betray/count", 1);
     this_player()->add("betray/xueshan", 1);
     this_player()->set("title", "普通百姓");
     this_player()->set_temp("betray", 0);
     this_player()->save();
     message_vision("秃鹰尊者一脚踢中$N的屁股，$N腾云驾雾般飞了出去...\n", this_player());
     this_player()->move("/d/xueshan/binggu");
     tell_room( environment(this_player()),"只听劈啪！一声，一个人从空中飞过来，死猪般地摔在地上。\n", ({this_player()}));
     return 1;
   }
   return 0;
}

