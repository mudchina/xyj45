// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// fairygirl.c
// 1996/10/31 by none...modified:)

inherit NPC;

#include <ansi.h>

int send_back(object me);

void create()
{
   set_name("警幻仙姑", ({ "fairy girl", "fairy", "girl" }) );
   set("gender", "女性" );
   set("age", 18);
   set("long",
     "其素若何：春梅绽雪。其洁若何：秋兰披霜。
其静若何：松生空谷。其艳若何？霞映澄塘。
其文若何：龙游曲沼。其神若何：月射寒江。\n");
   set("combat_exp", 200000);
   set("attitude", "friendly");
   set("inquiry", ([
     "name" : "太虚幻境警幻仙姑是也。",
     "here" : "离恨天之上，灌愁海之中。",
     "太虚幻境" : "太虚则不虚，幻境即心境",
     "梦" : "庄生梦蝶乎？蝶梦庄生乎？",
     "做梦" : "庄生梦蝶乎？蝶梦庄生乎？",
     "醒" : "木头！木头！世人以你未醒，你道世人皆梦。",
     "梦醒" : "木头！木头！世人以你未醒，你道世人皆梦。",
     "回去" : (: send_back :),
     
   ]) );
   set_skill("literate", 100);
   set_skill("dodge", 100);
   setup();
   carry_object("/d/obj/cloth/skirt")->wear();
   carry_object("/d/obj/cloth/shoes")->wear();
}

int send_back(object me)
{
   me=this_player();
   command("sigh " + me->query("id"));
   command("say " + "又是一根木头...好，你这就去吧。\n");
   tell_object(me,"\n警幻仙姑轻舒长袖，在你眼前一拂...\n\n你揉揉眼睛，醒了过来。\n\n");
   if(!me->query("dream_place")) me->move("/d/changan/pinqiting");
   else me->move((string)me->query("dream_place"));
   return 1;
}


