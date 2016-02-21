// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// bianfu.c 蝙蝠精
// 9-18-97 pickle

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

/************************************************************/

// function and global variable declaractions

int attempt_apprentice(object me);
int recruit_apprentice(object me);
void transform();
string ask_me();
void transform_back();
void mie_kou(object me);

/************************************************************/

void create()
{

  set_name("穷汉", ({"qiong han", "qiong", "han", "poor man","man"}));
  set("title", "普通百姓");
  set("long",
"他看起来一付穷困潦倒的样子，浑身没一件象样的衣服，瘦骨嶙峋的，\n"
"就象三年没吃过一顿饱饭似的。虽说长安城里这样的人比比皆是，但你\n"
"看他就是觉得不顺眼。仔细端详一番，你发现原来他全身长着一层淡淡\n"
"的茸毛。\n");
  set("combat_exp", 3000);
  set("attitude", "peaceful");
  set("gender", "男性");
  set("age", 39);
  create_family("陷空山无底洞", 2, "弟子");

  set_skill("unarmed", 80);
  set_skill("dodge", 80);
  set_skill("parry", 80);
  set_skill("stealing", 50);
  set_skill("spells", 80);
  set_skill("sword", 80);
  set_skill("qixiu-jian", 30);
  set_skill("yinfeng-zhua", 30);
  set_skill("lingfu-steps", 80);
  set_skill("force", 80);
  set_skill("yaofa", 30);
  set_skill("huntian-qigong", 30);

  set("str", 20);
  set("cor", 100);
  set("int", 20);
  set("spi", 30);
  set("cps", 100);
  set("per", 10);
  set("con", 40);
  set("kar", 20);
  
  set("env/wimpy", 70);

  set("max_kee", 400);
  set("max_sen", 400);
  set("force", 350);
  set("max_force", 350);
  set("mana", 350);
  set("max_mana", 300);
  set("inquiry", ([
                   "name": "这个……我这穷汉的名字对你又有什么用了？",
                   "here": "这里？你问我我问谁去？",
        "rumors": "听说最近附近有些老鼠精在长安城出没。唉。",
        "老鼠精": "我听说他们是个什么什么山什么什么洞的，也不知咋回事。",
        "陷空山": (: ask_me :),
        "无底洞": (: ask_me :),
                 ]) );  

  setup();
  carry_object("/d/obj/cloth/pobuyi")->wear();
}
/************************************************************/

// the menpai settings, but only useful after npc transforms.

int attempt_apprentice(object me)
{
  string myid=me->query("id");
  if (!query("wudidong_state")     // if not ready to accept dizi then return
   && !query("accept_dizi"))
   return 0;
  command("spank "+myid);
  command("say 不错不错。");
  command("say 但你要经得起考验才能真正学到我无底洞的高深武功。");
  command("recruit "+myid);
}
int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob))
  {
    ob->set("class", "yaomo");
  }
}
/************************************************************/

// since this npc stands in the middle of chang an, he can't
// be in his normal 妖怪 form. so he is usually a 穷汉 until
// somebody asks THE question. hehe...

string ask_me()
{
    object me=this_player();

    if (me->query("family/family_name") == "陷空山无底洞")
    {
   command("nod");
   command("recruit "+me->query("id"));
   return "这你还用问我？！";   // if already in wudidong, no point
    }
    if(!query("wudidong_state"))   // if not in bianfu form, ask person
    {             // whether they wanna join anyway.
   command("hehe");
   command("say 实话告诉你吧！大爷我就是无底洞的上仙！");
   set("accept_dizi", 1);     // here, be ready to accept dizi
   command("say "+me->name()+"，你可愿意入我无底洞？");
   command("recruit "+me->query("id"));
   call_out("mie_kou", 60, me);   // give him 5 min, if still not, 灭口
   return "嘿嘿，你若是不愿，可莫怪我心狠手辣！";
    }
    command("say 若是想拜我无底洞，尽管说！");   // if in bianfu form, recruit
    command("recruit "+me->query("id"));   // also set miekou condition
    remove_call_out("transform_back");     // note one thing: our bianfu
    call_out("mie_kou", 60, me);     // will not transform back into
    return "否则就别怪我杀人灭口了！";     // human coz he needs to kill
}
void transform()
{
  object weapon;
  if(!interactive())
    return;
  set_name("蝙蝠精", ({"bian fu", "bianfu", "fu", "bat", "monster"}));
  set("title", "上仙");
  set("long",
"这明明是一只巨大的蝙蝠，但不知为何竟然会说人话！\n");
  set("combat_exp", 300000);
  weapon=new("/d/obj/weapon/sword/changjian");
  weapon->move(this_object());
  command("wield sword");
  command("enable force huntian-qigong");
  command("enable unarmed yinfeng-zhua");
  command("enable spells yaofa");
  command("enable sword qixiu-jian");
  command("enable parry qixiu-jian");
  command("enable dodge lingfu-steps");
  set("wudidong_state", 1);
  message_vision(HIY"穷汉摇身一变，现了原形。原来是只蝙蝠！\n"NOR, this_object());
}
void mie_kou(object me)
{
    string myid=me->query("id");
    if (!interactive()) return;
    if (me->query("family/family_name") == "陷空山无底洞")
    {
   command("pat "+myid);        // if he has bai in meantime
   command("say 不错，识时务者俊杰！");   // don't kill him, compliment him
   call_out("transform_back", 300);   // change back to human
   return;
    }
    if (!present(myid, environment()))
    {
   command("sneer");        // laugh at the cowards
   command("say 幸亏"+me->name()+"溜得快。否则，哼！哼！哼！");
   call_out("transform_back", 300);
   return;
    }
    if (!query("wudidong_state"))     // if still in human form
   transform();          // change into bianfu form to kill
    command("say "+me->name()+"，你既然执迷不悟，那就纳命来吧！");
    command("kill "+myid);        // kill!
    call_out("transform_back", 180);     // assume fight over in 3 min
    return;             // at which time change back
}
void transform_back()
{
    object weapon, me=this_object();

    if(!query("wudidong_state"))     // if already in human form, no point.
   return;
    if(!interactive())          // can't change back if fainted
    {               // give another 30 sec
   remove_call_out("transform_back");
   call_out("transform_back", 30);
   return;
    }
    if (is_fighting())          // obviously can't change back
    {               // if still fighting, so give
   remove_call_out("transform_back");   // it another 3 min
   call_out("transform_back", 180);
   return;
    }
  if (objectp(weapon=present("sword", me)))
    destruct(weapon);
  message_vision(HIY"$N摇身一变，变成了个穷汉！\n"NOR, this_object());
  set_name("穷汉", ({"qiong han", "qiong", "han", "poor man","man"}));
  set("title", "普通百姓");
  set("long",
"他看起来一付穷困潦倒的样子，浑身没一件象样的衣服，瘦骨嶙峋的，\n"
"就象三年没吃过一顿饱饭似的。虽说长安城里这样的人比比皆是，但你\n"
"看他就是觉得不顺眼。仔细端详一番，你发现原来他全身长着一层淡淡\n"
"的茸毛。\n");
  set("combat_exp", 3000);
  set("attitude", "peaceful");
  delete("wudidong_state");
  command("enable parry none");
  command("enable dodge none");
  command("enable force none");
  command("enable sword none");
  command("enable spells none");
  return;
}
