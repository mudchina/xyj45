// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 

inherit NPC;
inherit F_MASTER;
string expell_me(object me);
void create()
{
  set_name("秦琼", ({ "qin qiong", "qin", "shubao", "qiong", "qin shubao", "master", "shifu" }));
  set("title", "开国元勋");
  set("gender", "男性");
  set("age", 43);
  set("str", 30);
  set("per", 26);
  set("int", 30);
  set("cor", 50);
  set("cps", 50);
  set("long", "秦叔宝是大唐国开国名臣，更是一位出名的武将。\n");
  set("combat_exp", 1200000);
  set_skill("literate", 60);
  set_skill("spear", 120);
  set_skill("force", 120);
  set_skill("dodge", 180);
  set_skill("parry", 150);
  set_skill("mace", 200);
  set_skill("throwing", 100);
  set_skill("wusi-mace", 180);
  set_skill("yanxing-steps", 150);
  set_skill("bawang-qiang", 100);
  set_skill("lengquan-force", 120);
  set_skill("unarmed", 160);
  set_skill("changquan", 120);
  map_skill("mace", "wusi-mace");
  map_skill("force", "lengquan-force");
  map_skill("unarmed", "changquan");
  map_skill("spear", "bawang-qiang");
  map_skill("parry", "bawang-qiang");
  map_skill("dodge", "yanxing-steps");
  set("max_sen", 2800);
  set("max_kee", 4400);
  set("force", 2000);
  set("max_force", 1800);
  set("force_factor", 80);
  set("inquiry", ([
        "转业": (: expell_me :),
        "leave": (: expell_me :),
        ]) );

  create_family("将军府", 2, "蓝");
  setup();
  carry_object("/d/obj/weapon/spear/yinqiang")->wield();
  carry_object("/d/obj/armor/tiejia")->wear();
}

int accept_fight(object me)
{
  command("say 老夫久未和江湖人动手过招了，今日也不想破例。\n");
  return 0;
}
int attempt_apprentice(object me)
{
  string myname=RANK_D->query_respect(me);
  if ((int)me->query("combat_exp")< 100000)
    {
      command("say 这位"+myname+"还是先去跟本府家将打打基础吧！");
      return 0;
    }
  command("haha");
  command("say 很好，时下正是用人之际，"+myname+"多加努力，他日必定有成。\n");
  command("recruit " + me->query("id") );
  return 1;
}
int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob) )
    ob->set("class", "fighter");
}
int prevent_learn(object me, string skill)
{
  string myname=RANK_D->query_respect(me);

  if (me->query("combat_exp") < 100000)
    {
      command("emote 皱了皱眉头，说道："+myname+"还欠修练，老夫所教"+myname+"恐怕难以理解。");
//      return notify_fail("还是等道行高点再来试试吧！\n");
      return 1;
    }
  return 0;
}

string expell_me(object me)
{
  me=this_player();
  if((string)me->query("family/family_name")=="将军府")
    {
      me->set_temp("betray", 1);
      command("sigh");
      return ("按我大唐律法，却须受罚，你可愿意(agree)？");
    }
  return ("去问问袁先生吧，或许他知道！");
}
void init()
{
  add_action("do_agree", "agree");
}
int do_agree(string arg)
{
  if(this_player()->query_temp("betray"))
    {
      message_vision("$N答道：弟子愿意。\n\n", this_player());
      command("say 那你便去吧，江湖险恶，好自为之。。。");
      this_player()->add("betray/count", 1);
      this_player()->add("betray/jjf", 1);
      this_player()->set("combat_exp", this_player()->query("combat_exp")*95/100);
      this_player()->delete("family");
      this_player()->delete("class");
      this_player()->set("title", "普通百姓");
      this_player()->set_temp("betray", 0);
      this_player()->save();
      return 1;
    }
  return 0;
}
