// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat
// quest.c

inherit F_CLEAN_UP;

#include <ansi.h>
#include <dbase.h>
#include <origin.h>

void create()
{
        seteuid(getuid());
}

int quest_give (object me, object who, object ob)
{
   if (me->query("quest/pending/give/name") != who->query("name") ||
            me->query("quest/pending/give/id")   != who->query("id"))
     return 0;

   if (me->query("quest/pending/give/objectname") != ob->query("name") ||
            me->query("quest/pending/give/objectid") != ob->query("id"))
     return 0;

   me->set("quest/pending/give/done",1);
   return 1;
}

string quest_ask (object me, object who, string topic)
{

   if (me->query("quest/pending/ask/name") != who->query("name") ||
            me->query("quest/pending/ask/id")   != who->query("id"))
     return 0;
   
   if (me->query("quest/pending/ask/topic") != topic)
     return 0;

   me->set("quest/pending/ask/done",1);
   return me->query("quest/pending/ask/acknowledge");
}

void quest_kill (object me)
{
   object killer = me->query_temp("last_damage_from");

   if (! killer)
     return;

   if (killer->query("quest/pending/kill/name") != me->query("name") ||
            killer->query("quest/pending/kill/id")   != me->query("id"))
     return 0;
   
   killer->set("quest/pending/kill/done",1);
}

