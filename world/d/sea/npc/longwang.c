// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//Changed by sjmao, 09-10-97
#include <skill.h>

inherit NPC;
inherit F_MASTER;

string expell_me(object me);

void create()
{
          set_name("敖广", ({"ao guang", "ao","guang","longwang","wang"}));

   set("long","敖广是东海的龙王，其兄弟分别掌管东，西，南，北四海。
由余其水族众多，声势浩大，俨然独霸一方。\n");
          set("gender", "男性");
          set("age", 66);
   set("title", "东海龙王");
   set("class","dragon");
          set("attitude", "peaceful");
          set("shen_type", 1);
        set("combat_exp", 1260000);
        set("rank_info/respect", "陛下");
          set("per", 20);
          set("str", 30);
          set("max_kee", 3000);
          set("max_gin", 400);
          set("max_sen", 800);
          set("force", 3000);
          set("max_force", 1500);
          set("force_factor", 120);
          set("max_mana", 800);
          set("mana", 1600);
          set("mana_factor", 40);
/*   set("chat_msg", ({
     "龙王气愤地说道：该死的孙猴子，把我们东海龙宫的定海神针给抢走了。\n",
     "龙王长叹一声：不知何时才能将镇宫之宝收回啊！\n",
     "龙王悄悄对你说：听说孙猴子把它藏在花果山的石洞里，不知是否属实。\n",
     "龙王叹道：若有人能将其送还，龙宫上下定将感激不尽！\n",
}));
   set("chat_chance", 5);
*/
          set("combat_exp", 1200000);
          set_skill("unarmed", 200);
          set_skill("dodge", 150);
          set_skill("force", 180);
          set_skill("parry", 180);
          set_skill("fork", 150);
          set_skill("spells", 150);
   set_skill("seashentong", 150);
   set_skill("dragonfight", 200);
   set_skill("dragonforce", 150);
   set_skill("fengbo-cha", 180);
   set_skill("dragonstep", 150);
   map_skill("spells", "seashentong");
   map_skill("unarmed", "dragonfight");
   map_skill("force", "dragonforce");
   map_skill("fork", "fengbo-cha");
   map_skill("parry", "fengbo-cha");
   map_skill("dodge", "dragonstep");

        set("inquiry", ([ "离宫": (: expell_me :),
     "leave": (: expell_me :), ]) );

        create_family("东海龙宫", 1, "水族");
   set_temp("apply/armor",50);
   set_temp("apply/damage",25);
   setup();

        carry_object("/d/sea/obj/longpao")->wear();
}
void init()
{
   ::init();
   add_action("do_agree", "agree");
   add_action("do_learn", "xuexi");
}

/*
int accept_object(object who, object ob)
{
   if ((string)ob->query("id") == "jingubang" ) {
     command("sigh");
     call_out("destroy", 1200, ob);
                if ( who->query("combat_exp") < 400000 || who->query_skill("unarmed", 1) <150 ) {
                   command("say 一根破棍子，哪比得我东海龙宫的镇宫之宝啊！\n");
        command("say 他日" + RANK_D->query_respect(who) + "若能找回真的定海神针，小王定要重谢。\n");
        return 1;
     }
     command("say 虽然不是真的宝物，" + RANK_D->query_respect(who) + "也算是有心人了。\n");
     command("say 我可以传授一些基本拳脚功夫，" + RANK_D->query_respect(who) + "还要抓紧学(xuexi)才是！\n");
     who->set_temp("temp/learn", 1);
     call_out("unsetlearn", 1200, who);
     return 1;
     }
   else return notify_fail("龙王摇摇头，好象不屑一顾的样子。\n");
}
*/

void destroy(object ob)
{
        destruct(ob);
        return;
}

void unsetlearn(object ob)
{
   if (find_player(ob->query("id"))) {
     ob->set_temp("temp/learn", 0);
     ob->save();
     }
}


string *reject_msg = ({
   "说道：您太客气了，这怎么敢当？\n",
   "像是受宠若惊一样，说道：请教？这怎么敢当？\n",
   "笑著说道：您见笑了，我这点雕虫小技怎够资格「指点」您什么？\n",
});

int do_learn(string arg)
{
   string skill, teacher, master;
   object me= this_player(), ob;
   int master_skill, my_skill, sen_cost;

   if(!arg || sscanf(arg, "%s from %s", skill, teacher)!=2 )
     return notify_fail("指令格式：xuexi <技能> from <某人>\n");

   if( me->is_fighting() )
     return notify_fail("临阵磨枪？来不及啦。\n");

   if( !(ob = present(teacher, environment(me))) || !ob->is_character())
     return notify_fail("你要向谁求教？\n");

   if( !living(ob) )
     return notify_fail("嗯．．．你得先把" + ob->name() + "弄醒再说。\n");

   if( !master_skill = ob->query_skill(skill, 1) )
     return notify_fail("这项技能你恐怕必须找别人学了。\n");

   if (skill != "unarmed" || !me->query_temp("temp/learn") ) 
     return notify_fail( ob ->name() + reject_msg[random(sizeof(reject_msg))] );

   notify_fail(ob->name() + "不愿意教你这项技能。\n");
   if( ob->prevent_learn(me, skill) )
     return 0;

   my_skill = me->query_skill(skill, 1);
   if( my_skill >= master_skill )
     return notify_fail("这项技能你的程度已经不输你师父了。\n");

   notify_fail("依你目前的能力，没有办法学习这种技能。\n");
   if( !SKILL_D(skill)->valid_learn(me) ) return 0;

   sen_cost = 250 / (int)me->query_int();

   if( !my_skill ) {
     sen_cost *= 2;
     me->set_skill(skill,0);
   }

   if( (int)me->query("learned_points") >= (int)me->query("potential") )
     return notify_fail("你的潜能已经发挥到极限了，没有办法再成长了。\n");
   printf("你向%s请教有关「%s」的疑问。\n", ob->name(),
     to_chinese(skill));

   if( ob->query("env/no_teach") )
     return notify_fail("但是" + ob->name() + "现在并不准备回答你的问题。\n");

   tell_object(ob, sprintf("%s向你请教有关「%s」的问题。\n",
     me->name(), to_chinese(skill)));

   if( (int)ob->query("sen") > sen_cost/5 + 1 ) {
     if( userp(ob) ) ob->receive_damage("sen", sen_cost/5 + 1);
   } else {
     write("但是" + ob->name() + "显然太累了，没有办法教你什么。\n");
     tell_object(ob, "但是你太累了，没有办法教" + me->name() + "。\n");
     return 1;
   }
     

   if( (int)me->query("sen") > sen_cost ) {
     if( (string)SKILL_D(skill)->type()=="martial"
     &&   my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) {
        printf("也许是道行不够，你对%s的回答总是无法领会。\n", ob->name() );
     } else {
        printf("你听了%s的指导，似乎有些心得。\n", ob->name());
        me->add("learned_points", 1);
        me->improve_skill(skill, random(me->query_int()));
     }
   } else {
     sen_cost = me->query("sen");
     write("你今天太累了，结果什么也没有学到。\n");
   }

   me->receive_damage("sen", sen_cost );

   return 1;
}

void attempt_apprentice(object ob)
{   
        if (((int)ob->query("combat_exp") < 100000)) {
   command("say " + RANK_D->query_respect(ob) +
     "还是先到小儿或小女处把基础打好了再来我这儿吧。\n");
   return;
   }   
        command("smile");
        command("say 难得" + RANK_D->query_respect(ob) +
     "有此心志，还望日后多加努力，为我东海龙宫争光。\n");
        command("recruit " + ob->query("id") );
   return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "dragon");
}

string expell_me(object me)
{
  me=this_player();
  if((string)me->query("family/family_name")=="东海龙宫")
    {
      me->set_temp("betray", 1);
      command("sigh");
      return ("你要离开我也不能强留。只是按我东海规矩，却须受罚。
恐怕既是身非龙类，这龙神心法与博击并不能如前般运转，你可愿意(agree)?\n");
    }
  return ("去问问袁先生吧，或许他知道！\n");
}

int do_agree(string arg)
{
  object me;
  me = this_player();
  if(me->query_temp("betray"))
    {
      message_vision("$N答道：弟子愿意。\n\n", me);
      command("say 人各有志，既是" + RANK_D->query_respect(me) +
        "不愿留在东海，就请出宫去吧。只是江湖险恶，" + RANK_D->query_respect(me) +
   "当好自为之。。。\n");
      me->set_skill("dragonforce", (int)me->query_skill("dragonforce",1)/2);
      me->set_skill("dragonfight", (int)me->query_skill("dragonfight",1)/2);
      me->set("combat_exp", me->query("combat_exp")*95/100);
      me->delete("family");
      me->delete("class");
      me->set("title", "普通百姓");
      me->set_temp("betray", 0);
      me->add("betray/count", 1);
      me->add("betray/longgong", 1);
      me->save();
      return 1;
    }
  return 0;
}

