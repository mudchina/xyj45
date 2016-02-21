// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// bishu.c 碧鼠精
// 9-2-97 pickle

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

/************************************************************/

// function and global variable declaractions

int attempt_apprentice(object me);
int recruit_apprentice(object me);
int prevent_learn(object me, string skill);
int accept_object(object me, object ob);
void bishu_leave(object me);
/************************************************************/

void create()
{
  set_name("碧鼠精", ({"bi shu", "bi", "shu", "bishu", "monster"}));
  set("gender", "女性");
  set("age", 19);
  set("long",
"虽然她看起来弱不禁风，但听说她天赋及佳，是块修仙的好料子。\n"
"自从入无底洞以来，她的武功进步及快，颇有赶过玉鼠的架式。\n");
  set("title", "无底洞大弟子");
  set("nickname", HIR"九死一生"NOR);
  set("combat_exp", 800000);
  set("attitude", "heroic");
  create_family("陷空山无底洞", 2, "弟子");
  set_skill("unarmed", 100);
  set_skill("dodge", 100);
  set_skill("parry", 100);
  set_skill("stealing", 150);
  set_skill("spells", 100);
  set_skill("sword", 30);
  set_skill("qixiu-jian", 30);
  set_skill("yinfeng-zhua", 30);
  set_skill("lingfu-steps", 100);
  set_skill("force", 100);
  set_skill("blade", 100);
  set_skill("kugu-blade", 100);
  set_skill("yaofa", 30);
  set_skill("huntian-qigong", 30);
  map_skill("force", "huntian-qigong");
  map_skill("blade", "kugu-blade");
  map_skill("unarmed", "yinfeng-zhua");
  map_skill("spells", "yaofa");
  map_skill("sword", "qixiu-jian");
  map_skill("parry", "qixiu-jian");
  map_skill("dodge", "lingfu-steps");
  
  set("cor", 50);
  set("str", 30);
  set("per", 30);
  set("max_kee", 900);
  set("max_sen", 900);
  set("force", 650);
  set("max_force", 650);
  set("force_factor", 20);
  set("mana", 650);
  set("max_mana", 600);
  set("mana_factor", 25);
  set("inquiry", ([
                   "name": "本姑娘就是地涌夫人的开山大弟子！",
                   "here": "你瞎了眼啦？这里就是鼎鼎大名的陷空山无底洞！",
        "rumors": "不知道！找别人问去。",
        "人肉包子": "你瞎了眼啦？本姑娘又不是厨子！",
                 ]) );  

  setup();
  carry_object("/d/obj/weapon/blade/blade.c")->wield();
  carry_object("/d/obj/cloth/nichang")->wear();
}
int attempt_apprentice(object me)
{
  string myname=RANK_D->query_rude(me);
  string myid=me->query("id");
  command("look "+myid);
  command("consider");
  if (me->query("combat_exp")<100000)
  {
    command("say "+myname+"有什么用？就这么点本事还不够给本姑娘提鞋！");
    return 1;
  }
  if (me->query("wudidong/sell_reward") < 5000)
  {
    command("say "+myname+"多久没给厨房进货了？！本姑娘等人肉包子都等烦了！");
    command("say 先去给厨房送点新鲜人肉！那时候本姑娘一高兴，说不定就收下你了。");
    return 1;
  }
  command("grin");
  command("say 本姑娘最爱吃人肉包子了。"+myname+"别忘了多给厨房弄点原料！");
  command("recruit "+myid);
  return 1;
}
int prevent_learn(object me, string skill)
{
  string myname=RANK_D->query_rude(me);

  if(skill == "kugu-blade")
  { 
    message_vision(CYN"碧鼠精怒道：没门儿！不教！\n", me);
    return 1;
  }
  return 0;
}
int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob))
  {
    ob->set("class", "yaomo");
  }
}
/************************************************************/

int accept_object(object me, object ob)
{
    if (ob->query("name_recognized") != "白骨令")
   return notify_fail(CYN"碧鼠怒道：混帐，我又不是收破烂的！\n"NOR);
    remove_call_out("bishu_leave");
    call_out("bishu_leave", 1, me);
    return 1;
}
void bishu_leave(object me)
{
    command("say 这、这、这，这可怎么办是好？");
    command("sigh");
    command("say 既然夫人有令在此，我还是赶紧回去一趟吧！");
    message_vision("碧鼠精抓了一把土，向空中一抛，喝声：走！借土遁去了。\n", me);
    destruct(this_object());
    return;
}
