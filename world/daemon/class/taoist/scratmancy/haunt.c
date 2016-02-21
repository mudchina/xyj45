// haunt.c

#include <ansi.h>

inherit F_CLEAN_UP;

int scribe(object me, object sheet)
{
   	object newsheet;
  	string err;

        if((int)me->query_skill("scratching") < 10 )
                return notify_fail("你的符之术不够高！\n");

        if( sheet->name() != "桃符纸" )
                return notify_fail("僵尸追魂符要画在桃符纸上！\n");

        if( me->is_fighting() ) 
                return notify_fail("你正在战斗中！\n");
        
        if( (int)me->query("mana") < 20 ) 
                return notify_fail("你的法力不够了！\n");

        sheet->set_amount((int)sheet->query_amount() - 1);
        me->save();
        seteuid( geteuid(me));
        newsheet = new("/obj/magic_seal");
        newsheet->set_name(YEL "僵尸追魂符" NOR, 
                ({ "haunting sheet", "sheet"}));      
        newsheet->set("attach_func", (: call_other, __FILE__, "do_haunt" :));
        newsheet->move(me);
        me->add("mana", -20);
        me->receive_damage("sen", 10);
        me->save();
        message_vision("$N写了一道僵尸追魂符。\n" NOR, me);
        return 1;
}

int do_haunt(object sheet, object who)
{ 
        string target;
        object dest, owner;

        if( !who->is_zombie() )
                return notify_fail(YEL "僵尸追魂符" NOR 
"只能用在僵尸身上。\n");

	owner = who->query("possessed");
        if( objectp(owner) && owner!=this_player() )
                return notify_fail("你必须先用法力镇住" + who->name() + 
"才能使用这道符。\n");

        if( !(sheet->query("targetname")) )
                return notify_fail("你想用这道符" NOR 
"追谁的魂？\n");

        target = sheet->query("targetname");
        dest = present(target, environment(who));
        if( !dest ) dest = find_player(target);
        if( !dest ) dest = find_living(target);
        if( objectp(dest) ) {
		who->set("haunttar", dest);
                if( environment(dest)==environment(who) ) {
	                who->kill_ob(dest);
       			message_vision("$N眼睛忽然睁开，喃喃地说道：" RED 
"杀....死....$n....\n" NOR,
                        who, dest);
	                who->set_leader(dest);
                        dest->fight_ob(who);
                }
 		else {
			who->set("haunt", 1);
               }
        } else {
           message_vision("$N眼睛忽然睁开，喃喃地说道：" RED 
"杀....杀....杀....\n" NOR,
                        who);
                if( this_player() ) {
                        who->kill_ob(this_player());
                        who->set_leader(this_player());
                        this_player()->fight_ob(who);
                }
        }
        return 1;
}
