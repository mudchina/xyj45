// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// entrance.c

#include <login.h>
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "国宾馆大厅");
        set("long", @LONG

大厅相当的大，能容几百人开宴会。大厅内各国使节往来不断，不
同方言充斥耳间。桌上摆了各种新鲜水果，美味佳肴，招待着四方
来客。一群舞女随着节拍翩翩起舞，娥娜多姿。
LONG);

        set("exits", ([
                "north" : "/d/wiz/system",
                "east": "/d/city/xuanwu-n3",
         ]) );
        set("no_fight", 1);
        set("no_magic", 1);
        set("valid_startroom", 1);

        setup();
        call_other( "/obj/board/query_b", "???" );
}
/*
int valid_leave(object me, string dir)
{
     
   if(me->query("id")=="clock") return ::valid_leave(me, dir);
   if(me->query("id")=="net") return ::valid_leave(me, dir);
   if(me->query("id")=="weiqi") return ::valid_leave(me, dir);
   //temp access for future wiz.

        if( dir=="north" && !wizardp(me) )
                return notify_fail("那里只有巫师才能进去。\n");
        return ::valid_leave(me, dir);
}

void init()
{
        add_action("do_accuse", "accuse");
}

int do_accuse(string arg)
{
        object ob;
        string s;

        if( ob = find_player(arg) ) {
                if( ob==this_player() )
                        return notify_fail("你要检举自己？\n");
                if( ob->is_ghost() )
                        return notify_fail( ob->name(1) +
"已经死了，放他一马吧。\n");
                if( wizardp(ob) )
                        return notify_fail("你不能检举巫师。\n");
                tell_object(ob, HIW + this_player()->name(1) +
"检举你是个机器人，请你接受一个小小的测验。\n" NOR);
                ROBOT_CHECK->test_me(ob);
                write("Ok. 已经将你检举的对象送去做测验。\n");

write("为了避免有人用机器人乱检举骚扰别人，请你也接受相同的测验。\n");
                ROBOT_CHECK->test_me(this_player());
                log_file("robot_accuse",
                        sprintf("%s accused %s on %s.\n",
this_player()->query("id"), ob->query("id"), ctime(time())));
                return 1;
        }
        return notify_fail("目前线上并没有这位玩家。\n");
}
*/
