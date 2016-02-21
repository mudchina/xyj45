// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// haunt.c

#include <ansi.h>

inherit F_CLEAN_UP;

int scribe(object me, object sheet, string arg)
{
   if( me->is_fighting() )   return notify_fail("你正在战斗中！\n");
   
   if( (int)me->query("mana") < 20 ) return notify_fail("你的法力不够了！\n");

   if( !arg ) return notify_fail("你要在这张符上写谁的名字？\n");

   sheet->set_name(YEL "僵□追魂符" NOR, ({ "haunting sheet", "sheet"}) );   
   sheet->set("attach_func", (: call_other, __FILE__, "do_haunt", arg :) );
   me->add("mana", -20);
   me->receive_damage("sen", 10);

   return 1;
}

int do_haunt(string target, object who)
{
   object dest;

   if( !who->is_zombie() )
     return notify_fail(YEL "僵□追魂符" NOR "只能用在僵□身上。\n");

   if( !who->query("possessed") )
     return notify_fail("你必须先用法力镇住" + who->name() + "才能使用这道符。\n");

   dest = present(target, environment(who));
   if( !dest ) dest = find_player(target);
   if( !dest ) dest = find_living(target);
   if( objectp(dest) ) {
     who->kill_ob(dest);
     who->set_leader(dest);
     message_vision("$N眼睛忽然睁开，喃喃地说道：" RED "杀....死....$n....\n" NOR,
        who, dest);
     if( environment(dest)==environment(who) ) {
        dest->fight_ob(who);
     }
   } else {
     message_vision("$N眼睛忽然睁开，喃喃地说道：" RED "杀....杀....杀....\n" NOR,
        who);
     if( this_player() ) {
        who->kill_ob(this_player());
        who->set_leader(this_player());
        this_player()->fight_ob(who);
     }
   }
   return 1;
}
