// earth-warp.c

#include <ansi.h>
#include <command.h>
#include <login.h>

inherit F_CLEAN_UP;

int scribe(object me, object sheet, string arg)
{
        object newsheet;
        string err;

        if((int)me->query_skill("scratching") < 20 )
                return notify_fail("你的符之术不够高！\n");

        if( sheet->name() != "桃符纸" )
                return notify_fail("阴界传送符要画在桃符纸上！\n");

        if( (int)me->query("mana") < 50 ) 
		return notify_fail("你的法力不够了！\n");

        sheet->set_amount((int)sheet->query_amount() - 1);
        me->save();
        seteuid( geteuid(me));
        newsheet = new("/obj/magic_seal");
        newsheet->set_name(YEL "阴界传送符" NOR, 
		({ "earth-warp sheet", "sheet"}) );    
        newsheet->set("burn_func", (: call_other, __FILE__, "do_warp":));
        newsheet->move(me);
        me->add("mana", -50);
        me->receive_damage("sen", 10);
        me->save();
        message_vision("$N写了一道阴界传送符。\n" NOR, me);
        return 1;
}

int do_warp(string target, object who)
{
        object env;

        if( who && who!=this_player() )
                return notify_fail("阴界传送符只能对自己使用。\n");

        env = environment(this_player());
        message("vision",
                HIB + this_player()->name() + "祭起一张阴界传送符。\n"
"忽然四周吹起了一阵凉飕飕的阴风，阴风之中彷佛有许多人影在晃动...\n"
                "然後一阵火光突然爆起！\n" NOR, env);
        message("vision", "可是...." + this_player()->name() + 
"已经不见了。\n", environment(this_player()), ({this_player()}));
        message("vision",
                CYN 
"你只觉得身子不断下坠，一直下坠，一直下坠，一直下坠，一直下坠 .....\n"
                NOR     
"不知道什麽时候，你发现你其实一直都站在坚硬的地面上，可是四周的景物\n"
                        "却不一样了....\n", this_player() );
        this_player()->move(DEATH_ROOM);
        return 1;
}
 
