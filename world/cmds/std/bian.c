// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// bian.c
// by mon. 1/3/97

#include <ansi.h>

int do_bian(object me);

int main(object me, string arg)
{
      string id;
      object who,obj;
      int mana,spells,dmana;

      seteuid(getuid());

      if( me->is_fighting() )
        return notify_fail("你正在战斗，无暇变身。\n");
      if( me->is_busy() || me->query_temp("pending/exercising"))
   return notify_fail("你正忙着呢，没工夫变身。\n");
 
      if (!arg || arg=="me" || arg==me->query("id")) 
   who=me;
      else {
   if(!objectp(who=present(arg,environment(me)))) 
      return notify_fail("你想变成谁？\n");
      }

      if(who==me) {
   me->delete_temp("spellslevel");
   me->delete_temp("apply/name");
   me->delete_temp("apply/id");
   me->delete_temp("apply/short");
   me->delete_temp("apply/long");
        if(me->query_temp("d_mana")) {
     me->delete_temp("d_mana");
     while( environment(me)->is_character() )
        me->move(environment(environment(me)));
        //mon 9/25/97. to prevent being carried by another player
        //after bianed back.
          message_vision(HIY "$N口念咒语，身形一晃，现了真身。\n"
       NOR,me);
        } else {
     return notify_fail("你想变成谁？\n");
        }
      }
      else {
        spells=me->query_skill("spells");
   mana=me->query("mana");
   if (me->query("combat_exp") < 30000) 
      return notify_fail("你的道行还不够。\n");
   if (spells<25)
      return notify_fail("你的法术不够。\n");
        if (mana<150)
      return notify_fail("你的法力不足。\n");
        if (wizardp(who) && !wizardp(me))
      return notify_fail("你的法术不足以变成巫师。\n");
   
   dmana=15+400/(spells-20); 
   
   message_vision(HIY "$N手捻口诀，念动真言，摇身一变，变得和$n一模一样！\n" NOR,me,who);
        me->set_temp("spellslevel",spells);
   me->set_temp("apply/name",({who->name()}));
   me->set_temp("apply/id",who->parse_command_id_list());
   me->set_temp("apply/short", ({who->short()}));
   me->set_temp("apply/long", ({who->long()}));
   me->add("mana",-100);
        me->set_temp("is_character",who->is_character());
        me->set_temp("is_living",living(who));
   me->set_temp("gender",who->query("gender"));
   me->set_temp("age",who->query("age"));
   me->set_temp("race",who->query("race"));
   me->set_temp("family",who->query("family"));
   me->set_temp("unit",who->query("unit"));

   if (!me->query_temp("d_mana")) call_out("do_bian",5,me);
   me->set_temp("d_mana",dmana);
      }

      return 1;
}

int do_bian(object me)
{  
    int dmana,mana,spells;

    if(!me) return 1;

    dmana=me->query_temp("d_mana");
    spells=me->query_temp("spellslevel");
   
//    tell_object(me,"Mana, d_mana, spells:"+me->query("mana")+
//     ","+dmana+","+spells+"\n");

    mana=me->query("mana");
    if ((mana-dmana)>50 && spells>0 && dmana>0) {
      me->add("mana",(-dmana));
      call_out("do_bian",5,me);
    }
    else {
      mana=mana-dmana;
      if (mana<20) mana=20;
      me->set("mana",mana);
      me->delete_temp("spellslevel");
      me->delete_temp("d_mana");
      me->delete_temp("apply/name");
      me->delete_temp("apply/id");
      me->delete_temp("apply/short");
      me->delete_temp("apply/long");
      while( environment(me)->is_character() )
                   me->move(environment(environment(me)));
      if (dmana>0) 
        message_vision(HIY
        "只见$N面色苍白，一个恍惚之间，已经现了原形。\n" NOR,me);
    }

    return 1;
}

int help(object me)
{
   write(@HELP

指令格式 ： bian [<人物>|<NPC>|<me>]

变身术，这个指令让你变化成其他人物的模样。是否能变，还要取决于
你的法术和法力大小。

其他相关指令： observe。
HELP
   );
   return 1;
}



