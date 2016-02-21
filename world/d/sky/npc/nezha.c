// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// created 4/12/1998 by bbs
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
  set_name("哪吒", ({ "nezha santaizi", "nezha", "santaizi" }));
  set("title", "三坛海会之神");
  create_family("陷空山无底洞", 2, "弟子");
  set("class", "xian");
  set("long", "一位唇红齿白的美少年。\n");
  set("gender", "男性");
  set("age", 16);
  set("attitude", "heroism");
  set("rank_info/respect", "小太子");
  set("rank_info/rude", "乳臭未干的小儿");
  set("per", 40);
  set("str", 30);
  set("cor", 40);
  set("int", 40);
  set("spi", 40);
  set("cps", 40);
  set("kar", 40);
  set("max_kee", 1800);
  set("max_gin", 1800);
  set("max_sen", 1800);
  set("force", 2600);
  set("max_force", 2600);
  set("force_factor", 100);
  set("max_mana", 2700);
  set("mana", 2700);
  set("mana_factor", 120);
  set("combat_exp", 1200000);
  set_skill("spells", 180);
  set_skill("dao", 180);
  set_skill("unarmed", 170);
  set_skill("yinfeng-zhua", 170);
  set_skill("dodge", 180);
  set_skill("lingfu-steps", 170);
  set_skill("parry", 190);
  set_skill("force", 180);
  set_skill("huntian-qigong", 170);
  set_skill("spear", 170);
  set_skill("huoyun-qiang", 150);
  set_skill("blade", 170);
  set_skill("sword", 160);
  map_skill("spells", "dao");
  map_skill("unarmed", "yinfeng-zhua");
  map_skill("spear", "huoyun-qiang");
  map_skill("parry", "huoyun-qiang");
  map_skill("dodge", "lingfu-steps");
  map_skill("force", "huntian-qigong");
  set("inquiry", ([
   "name": "我乃托塔天王三太子哪吒是也。",
   "here": "这里是托塔天王府。",
   "rumors": "玉帝敕封家严为降魔大元帅，在下为三坛海会之神，专管降妖除魔。",
   "玉鼠精": "无底洞的玉鼠精？那是我爹的义女。",
   ]));
  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
  carry_object("/d/qujing/jindou/obj/qiang")->wield();
  if ("/d/obj/fabao/huntian-ling"->in_mud())
    carry_object("/d/obj/fabao/huntian-ling");
  else
    carry_object("/d/obj/fabao/huntian-fake");
  if ("/d/obj/fabao/qiankun-quan"->in_mud())
    carry_object("/d/obj/fabao/qiankun-quan");
  else
    carry_object("/d/obj/fabao/qiankun-fake");
}

void attempt_apprentice(object ob)
{
  command("say 我年纪尚小，徒弟我是不收的。");
  if ((string)ob->query("family/family_name")=="陷空山无底洞") {
   command("say "+RANK_D->query_respect(ob)+"若愿意学，看在我妹子的份上，我到可以点拨一二。");
  }
  else {
   command("sorry");
  }
}

int prevent_learn(object me, string skill)
{
  int myyaofa=me->query_skill("yaofa",1);

  if (skill == "dao") {
   if(myyaofa!=0) {
     command("sigh");
     command("say "+RANK_D->query_respect(me)+"妖气太重，不能学道家仙法。");
     return 1;
   }
  }
  return 0;
}

