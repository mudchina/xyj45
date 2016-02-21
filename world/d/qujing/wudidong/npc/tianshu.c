// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// guanjia.c
// 9-2-97 pickle

inherit NPC;
inherit F_MASTER;
string expell_me(object me);
void create()
{
  set_name("田鼠精", ({"tian shu", "tian", "shu", "tianshu", "monster"}));
  set("gender", "女性");
  set("age", 23);
  set("long",
"她就是无底洞的大管家。想当年她和玉鼠一齐修仙成了人形，\n"
"但因资质太差，成正果终究是无望。照顾着当年的交情，玉鼠\n"
"安排她做了这洞的管家。\n");
  set("title", "大管家");
  set("cor", 25);
  set("combat_exp", 200000);
  set("attitude", "heroic");
  create_family("陷空山无底洞", 2, "弟子");
  set_skill("unarmed", 55);
  set_skill("parry", 55);
  set_skill("spells", 55);  
  set_skill("sword", 55);  
  set_skill("qixiu-jian", 55);
  set_skill("yinfeng-zhua", 55);
  set_skill("lingfu-steps", 55);
  set_skill("dodge", 55);
  set_skill("force", 55);
  set_skill("yaofa", 55);
  set_skill("huntian-qigong", 55);
  map_skill("force", "huntian-qigong");
  map_skill("unarmed", "yinfeng-zhua");
  map_skill("spells", "yaofa");
  map_skill("sword", "qixiu-jian");
  map_skill("parry", "qixiu-jian");
  map_skill("dodge", "lingfu-steps");
  
  set("str", 30);
  set("per", 30);
  set("max_kee", 300);
  set("max_sen", 300);
  set("force", 350);
  set("max_force", 350);
  set("force_factor", 20);
  set("mana", 550);
  set("max_mana", 500);
  set("mana_factor", 25);
  set("inquiry", ([
                   "叛门": (: expell_me :),
                   "leave": (: expell_me :),
        "name": "本姑娘就是这无底洞的大总管！",
        "here": "你瞎了眼啦？这里就是鼎鼎大名的陷空山无底洞！",
        "rumors": "不知道！找别人问去。",
        "人肉包子": "你瞎了眼啦？本姑娘又不是厨子！",
                 ]) );  
  setup();
  carry_object("/d/obj/weapon/blade/blade.c")->wield();
  carry_object("/d/obj/cloth/yuanxiang")->wear();
  carry_object("/d/obj/cloth/nichang")->wear();
}
int attempt_apprentice(object me)
{
  string myname=RANK_D->query_rude(me);
  string myid=me->query("id");
  command("look "+myid);
  command("consider");
  if (me->query("combat_exp")>200000)
  {
    command("say "+myname+"来干什么？想来抢老娘的位子？\n");
    return 1;
  }
  if (me->query("wudidong/sell_reward")<1000)
  {
    command("say "+myname+"要想来无底洞，先提几颗人头来孝敬我！\n");
    return 1;
  }
  command("grin");
  command("say 老娘最爱吃人肉包子了。"+myname+"别忘了多给厨房弄点原料！");
  command("recruit "+myid);
  return 1;
}
int prevent_learn(object me, string skill)
{
  string myname=RANK_D->query_rude(me);

}
string expell_me(object me)
{
  me=this_player();

  if((string)me->query("family/family_name")=="陷空山无底洞")
  {
    me->set_temp("wudidong/betray", 1);
    return ("什么？想要离开？那你就别怪老娘惩罚！(jieshou)\n");
  }
  return ("你是哪里来的！滚！\n");
}
void init()
{
    add_action("do_accept", "jieshou");
}
int do_accept(string arg)
{
    object me=this_player();
    if (arg) return notify_fail("你要干什么？\n");
    if (!me->query_temp("wudidong/betray")) return notify_fail("你要接受什么？\n");
    message_vision("$N道：不错，我要离开无底洞这耗子窝！\n", me);
    me->add("betray/count", 1);
    me->add("betray/wudidong", 1);
    me->delete("family");
    me->delete("class");
    me->set("title", "普通百姓");
    if (me->query_skill("yaofa"))
    {
   me->set_skill("yaofa", me->query_skill("yaofa")/2);
   if (me->query_skill("yaofa")>30) me->set_skill("yaofa", 30);
    }
    if (me->query_skill("huntian-qigong"))
    {
   me->set_skill("huntian-qiong", me->query_skill("huntian-qigong")/2);
   if (me->query_skill("huntian-qigong")>30) me->set_skill("huntian-qigong", 30);
    }
    me->save();
    return 1;
}
int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob))
  {
    ob->set("class", "yaomo");
  }
}
