// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//cheng yaojin, updated 5/7/97, pickle

inherit NPC;
inherit F_MASTER;

string gloat();
string ask_me();

void create()
{
  set_name("程咬金", ({ "cheng yaojin", "cheng", "yaojin", "master", "shifu" }));
  set("title", "开国元勋");
  set("gender", "男性");
  set("age", 45);
  set("str", 30);
  set("per", 10);
  set("cor", 70);
  set("cps", 15);
  set("long","
程咬金是大唐开国出名的福将，曾从梦中学来一套威猛无匹的
宣花三斧，后来又曾拜倒过一面大旗。谈起他的福气，真的是
人人羡慕。
");
  set("combat_exp", 800000);
  set_skill("unarmed", 100);
  set_skill("force", 90);
  set_skill("lengquan-force", 50);
  set_skill("axe", 100);
  set_skill("dodge", 80);
  set_skill("parry", 80);
  set_skill("sanban-axe", 120);
  set_skill("spells", 40);
  set_skill("baguazhou", 40);
  set_skill("yanxing-steps", 40);
  map_skill("force", "lengquan-force");
  map_skill("spells", "baguazhou");
  map_skill("axe", "sanban-axe");
  map_skill("parry", "sanban-axe");
  map_skill("dodge", "yanxing-steps");
  set_temp("apply/armor", 10);
  set("max_sen", 300);
  set("max_kee", 2800);
  set("force", 500); 
  set("max_force", 500);
  set("force_factor", 40);
  set("max_mana", 200);
  set("mana", 200);
  set("mana_factor", 10);
  set("inquiry", ([
   "name"     : "我就是人称福将的程咬金！",
   "here"     : "这里是大唐国都长安府。",
   "rumors"   : "你看老程象是成天吃饱了撑的打听小道消息的么？",
   "福将"     : (: gloat :),
   "白发仙人" : "那白发仙人是我恩师，若想见他，需得有缘。",
   "有缘"     : (: ask_me :),
]) );

  create_family("将军府", 2, "蓝");

  setup();
  carry_object("/d/obj/weapon/axe/huafu")->wield();
  carry_object("/d/obj/armor/tongjia")->wear();
}

string gloat()
{
    command("say 嘿嘿，提起这个可挠到老程的痒处了！");
    command("say 老程最得意的就是当年那白发仙人梦中传我斧法。。。");
    return "你要是想沾着点老程的福气，就应该拜我为师。";
}
string ask_me()
{
    command("hehe");
    command("say 何为有缘？你若是能接住老程三斧不死，就是有缘人。");
    this_player()->add_temp("pending/jjf/to_be_hit", 1);
    return "你可愿意一试？(yuanyi)";
}

void init()
{
    ::init();

    add_action("do_agree", "yuanyi");
    add_action("do_agree", "agree");
}

int do_agree(string arg)
{
    object me=this_player(), npc=this_object(), ob;
    string myname=me->name(), myrude=RANK_D->query_rude(me);

    if (!me->query_temp("pending/jjf/to_be_hit"))
   return 0;
    me->delete_temp("pending/jjf/to_be_hit");
    set("force", 2*query("max_force"));
    set("force_factor", 200);
    if (!(ob=query_temp("weapon"))
     || ob->query_temp("skill_type") != "axe")
    {
   destruct(ob);
   ob=new("/d/obj/weapon/axe/huafu");
   ob->move(npc);
   command("wield axe");
    }
    command("say 哈哈，有胆子！");
    COMBAT_D->do_attack(npc, me, query_temp("weapon"));
    if(me->query("kee") < 0
    || !present(me, environment()))
    {
   command("say 嘿嘿，"+myrude+"一家伙都经不住，还是回去多练两年吧！");
   return 1;
    }
    command("say 不错，有点意思，再看这一招！");
    COMBAT_D->do_attack(npc, me, query_temp("weapon"));
    if(me->query("kee") < 0
    || !present(me, environment()))
    {
   command("say "+myrude+"能经住我一下子已经不容易了，我早就看出来这第二下子你受不了了！");
   return 1;
    }
    command("say 居然挺过了老程两家伙！");
    COMBAT_D->do_attack(npc, me, query_temp("weapon"));
    if(me->query("kee") < 0
    || !present(me, environment()))
    {
   command("say 唉，"+myrude+"的缘份比老程也就差了那么一丁点儿。");
   return 1;
    }
    me->add_temp("jjf/白发有缘", 1);
    command("say "+myname+"果然是有缘人。");
    command("say 你去找我师父吧！别忘了他是自己来到我梦中的，这种机会是可遇而不可求。");

    return 1;
}

int accept_fight(object me)
{
  command("say 老夫久未和江湖人动手过招了，今日也不想破例。");
  return 0;
}

void attempt_apprentice(object me)
{
  int effstr=(int)(me->query("str"));
  int myuna=me->query_skill("unarmed", 1)/10-2;
  string myrude=RANK_D->query_rude(me);

  if (myuna < 0) myuna=0;
  effstr+=myuna;
  if (effstr<30)
    {
      command("say "+myrude+"这点劲连只蚂蚁都捏不死，还能抡斧头？");
      return 0;
    }
  if (me->query_cor()<30)
    {
      command("say "+myrude+"见了血，还不得吓破了胆儿？不收！");
      return 0;
    }
  command("ah");
  command("say 想不到我老程这三脚猫本事也能收徒。\n");
  command("recruit " + me->query("id") );
  return;
}
int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob) )
    ob->set("class", "fighter");
}
int prevent_learn(object me, string skill)
{
  if (skill =="spells" || skill == "baguazhou")
    {
      command("say 老夫自己也搞不清楚怎么回事，哪里能教你呢？");
//      return notify_fail("看来从程咬金这里学不到这项本领了。");
      return 1;
    }
  return 0;
}
