// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// yingwu-guai.c...weiqi, 97.09.15.
// drooler parts added by pickle 9-18-97

#include <ansi.h>
inherit NPC;

// from drooler file, some global variables

string *rnd_say = ({
   "我雪山派弟子各个神勇无比，天下无敌！",
   "「嘎～～嘎～～」",
   "杀入大雷音寺，抢了他的莲花宝座！",
   "你们都要好好练功！不要辜负了明王的一片苦心！",
   "大家好！",
});

varargs void drool(string msg, string who);

/************************************************************/
void create()
{
   set_name("鹦鹉将军", ({"yingwu jiangjun", "yingwu", "jiangjun"}));
   set("gender", "男性" );
   set("age", 23);
   set("per", 112);//no rongmao description.

   set("long", "雪山门下有名的高手之一鹦鹉将军。\n他远看还不错，走近了才发现他长着长长的一张鸟嘴。\n");
   set("class", "yaomo");
   set("combat_exp", 100000);
   set("attitude", "peaceful");
   create_family("大雪山", 3, "弟子");
   set_skill("unarmed", 50);
   set_skill("yingzhaogong", 50);
   set_skill("cuixin-zhang", 30);
   set_skill("dodge", 50);
   set_skill("xiaoyaoyou", 50);
   set_skill("parry", 50);
   set_skill("blade", 50);
   set_skill("bingpo-blade", 50);
   set_skill("force", 50);   
   set_skill("ningxie-force", 50);
   set_skill("literate", 80);
   set_skill("spells", 50);
   set_skill("dengxian-dafa", 50);
   map_skill("spells", "dengxian-dafa");
   map_skill("force", "ningxie-force");
   map_skill("unarmed", "cuixin-zhang");
   map_skill("blade", "bingpo-blade");
   map_skill("dodge", "xiaoyaoyou");

   set("max_kee", 500);
   set("max_sen", 400);
   set("force", 400);
   set("max_force", 400);
   set("mana", 300);
   set("max_mana", 300);   
   set("force_factor", 10);
   set("mana_factor", 15);

   // the following are from the drooler
   set("chat_chance", 30);
   set("chat_msg", ({
     (: drool :),
   }) );
   setup();
   if( clonep() ) CHANNEL_D->register_relay_channel("chat");

   carry_object("/d/obj/cloth/xueshan-pao")->wear();
   carry_object("/d/obj/weapon/blade/iceblade")->wield();
}

/************************************************************/

// things involving the menpai: apprentice, ......

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
     command("say 好，到我们大雪山来学艺，又找了个好师父。" + RANK_D->query_respect(ob) + "可以说是前途无量啊！\n");
     command("recruit " + ob->query("id") );
   }

   return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "yaomo");
}

/************************************************************/

// the following copies some functions of the drooler
// from /obj/example/drooler to allow the yingwu to
// repeat what a human says, as a 鹦鹉's nature is.

int add_phrase(string who, string msg)
{
   msg = replace_string(msg, "?", "");
   msg = replace_string(msg, "？", "");
   msg = replace_string(msg, "!", "");
   msg = replace_string(msg, "！", "");
   msg = replace_string(msg, "啊", "");
   msg = replace_string(msg, "吗", "");
   msg = replace_string(msg, "耶", "");
   msg = replace_string(msg, "吧", "");

   if( msg!="" ) {
     add("memory/" + who, ({ msg }));
     return 1;
   } else return 0;
}

string make_reply()
{
}

void relay_channel(object ob, string channel, string msg)
{
   string who, phrase;

   if( !userp(ob) || (channel != "chat") ) return;
   who = ob->query("name");

   // Don't process our own speech.
   if( ob==this_object() ) return;

   if( add_phrase(who, msg) &&   random(10) > 4 )
     drool(msg, ob->query("name"));
}

void relay_say(object ob, string msg)
{
   string who, phrase;

   if( !userp(ob) ) return;
   who = ob->query("name");

   // Don't process our own speech.
   if( ob==this_object() ) return;

   if( add_phrase(who, msg) &&   random(10) > 4 )
     drool(msg, ob->query("name"));
}

void relay_emote(object ob, string verb)
{
   if( !userp(ob) ) return;

   switch(verb) {
   case "kick":
     if( random(10)<5 ) {
        command("say 狗腿又发痒了...\n");
     }
     break;
   case "pat":
     if( random(10)<5 ) {
        command("say 不许拍！再拍你爷爷我把你的爪子剁下来！\n");
     }
     break;
   default:
     if( random(10)<5 )
        command(verb + " " + ob->query("id"));
     else
        drool();
   }
}

varargs void drool(string msg, string who)
{
   mapping mem;
   string *ob;

   mem = query("memory");
   if( !mapp(mem) ) return;

   if( !msg || !who) {
     ob = keys(mem);
     who = ob[random(sizeof(ob))];
     msg = mem[who][random(sizeof(mem[who]))];
   }

   if( (strsrch(msg, "为什么") >= 0) ) {
     if( sscanf(msg, "%*s为什么%s", msg)==2 ) msg = "为什么" + msg;
     switch(random(8)) {
     case 0: command("say " + who + "，你是在问我吗？"); break;
     case 1: command("say 关于" + msg + "……"); break;
     case 2: command("say 呃……"); drool(); break;
     case 3: command("say 这个问题嘛……"); break;
     case 4: command("say " + who + "，知道这个问题的答案对你那么重要吗？"); break;
     case 5: command("say " + msg + "？"); break;
     case 6: command("say " + who + "你能不能说清楚一点？"); break;
     case 7: command("say " + who + "，我不懂你问的问题。"); break;
     }
   }
   else if( (strsrch(msg, "你") >= 0)
   ||   (strsrch(msg, "drooler") >= 0)
   ||   (strsrch(msg, "Drooler") >= 0)) {
     if( sscanf(msg, "%*s你%s", msg) == 2 ) msg = "你" + msg;
     msg = replace_string(msg, "你", "我");
     switch(random(10)) {
     case 0:   command("say " + who + "，你是说" + msg + "吗？");   break;
     case 1:   command("say 你确定" + msg + "？");   break;
     case 2:   command("say " + msg + "跟你有什么关系？");   break;
     case 3:   command("say 嗯……" + who + "说得好"); break;
     case 4:   command("say " + who + "你为什么对" + msg + "这么有兴趣？"); break;
     case 5:   command("say 为什么你认为" + msg + "？"); break;
     case 6:   command("say 换个话题吧。"); drool(); break;
     case 7:   command("say 才怪！"); break;
     case 8:   command("say 不一定吧？"); break;
     case 9:   command("say 有这个可能……"); break;
     }
   }
   else if( (strsrch(msg, "我") >= 0)) {
     if( sscanf(msg, "%*s我%s", msg) == 2 ) msg = "我" + msg;
     msg = replace_string(msg, "我", "你");
     msg = replace_string(msg, "?", "");
     switch(random(8)) {
     case 0:   command("say 你是说" + msg + "吗？"); break;
     case 1:   command("say 真的？" + msg + "？");   break;
     case 2:   command("say 如果" + msg + "，我能帮你什么忙吗？");   break;
     case 3:   command("hmm");   break;
     case 4:   command("say 你认为" + msg + "？"); break;
     case 5:   command("say 我有同感"); break;
     case 6:   command("say 你说的「" + msg + "」我不能苟同！"); break;
     case 7:   command("say 有关「" + msg + "」的话题到此为止好吗？"); break;
     }
   } else {
     switch(random(20)) {
        case 0: command("say 为什么说" + msg + "？"); break;
        case 1: command("say 「" + msg + "」是什么意思？"); break;
        case 2: command("say " + msg + "？"); break;
        case 3: command("hehe"); break;
        case 4: command("sister"); break;
        case 5: command("?"); break;
        case 6: command("say ……"); break;
        case 7: command("hmm"); break;
        case 8: command("say " + rnd_say[random(sizeof(rnd_say))]); break;
        case 9: command("say 你怎么知道" + msg + "？"); break;
        case 10: command("say 刚刚" + who + "不是说了，" + msg); break;
        case 11: command("say 我当然知道，" + msg); break;
        case 12: command("say 然后呢？"); break;
        case 13: command("say 真的吗？"); break;
        case 14: command("say 我不这么认为。"); break;
        default:
          break;
     }
   }
}

void reset()
{
   delete("memory");
}
