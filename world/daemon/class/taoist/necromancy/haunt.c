// hsunt.c   write by sb 97.11.14

#include <ansi.h>
#include <command.h>
#include <login.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int scribe(object me, object sheet, string arg)
{ object env;
        if( me->is_fighting() ) return notify_fail("你正在战斗中！\n");
        
        if( (int)me->query("mana") < 50 ) return 
notify_fail("你的法力不够了！\n");
        if( (int)me->query("sen") < 10 ) return 
notify_fail("你的精神不够集中！\n");
        destruct(sheet);
sheet=new("/obj/sbaa/seal2.c");
            sheet->move(me);
                    sheet->set_name(YEL "僵尸追魂符" NOR, ({ "earth-warp sheet", 
"sheet"}) );   
   
        me->add("mana", -50);
        me->receive_damage("sen", 10);

        return 1;
}
