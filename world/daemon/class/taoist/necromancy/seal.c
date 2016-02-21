// magic_seal.c

#include <ansi.h>
#include <command.h>
#include <login.h>

inherit F_CLEAN_UP;


inherit ITEM;

void create()
{
	set_name("符咒", ({"seal"}) );
	set_weight(5);
	set("long",
		"这是一张画好的符咒，用 burn 将它贴在某人(或某物)身上。\n");
	set("unit", "张");
}

int unequip()
{
	set("equipped", 0);
	return 1;
}
void init()
{
add_action("do_warp", "burn");
}


int do_warp(string tar)
{       
        object env,who;
       
       
        who=this_player();
    //  if( who && who!=this_player() )
          //  return notify_fail("阴界传送符只能对自己使用。\n");

    //  env = environment(this_player());
      message("vision",
              HIB + this_player()->name() + "祭起一张阴界传送符。\n\n"
                
   "忽然四周吹起了一阵凉飕飕的阴风，阴风之中彷佛有许多人影在晃动...\n\n"
                "然後一阵火光突然爆起！\n" NOR, env);
        //OP_CMD->main(this_player(), "all");
     
           who->move(DEATH_ROOM);
        message("vision",
                CYN "可是...." + who->name() + "已经不见了。\n" 
NOR, env);
        message("vision",
                CYN 
"你只觉得身子不断下坠，一直下坠，一直下坠，一直下坠，一直下坠 .....\n\n"
                NOR     
"不知道什麽时候，你发现你其实一直都站在坚硬的地面上，可是四周的景物\n\n"
                        "却不一样了....\n", this_player() );
        destruct(this_object());
        return 1;
}

/*
void init()
{
	add_action("do_attach", "burn");
}

int do_attach(string arg)
{
	string sheet, dest;
	object ob;
	function f;

	if( !arg || sscanf(arg, "%s to %s", sheet, dest)!=2 )
		return notify_fail("指令格式：attach <符咒> to <目标>\n");
	
	if( !id(sheet) ) return 0;

	ob = present(dest, this_player());
	if( !ob ) ob = present(dest, environment(this_player()));
	if( !ob ) return notify_fail("你要对什麽东西使用这张符咒？\n");

	if( !functionp(f = query("attach_func", 1)) )
		return notify_fail("这张符没有用。\n");

	if( evaluate(f, ob) ) {
		if( ob!=this_player() )
			message_vision("$N拿出一张" + name() + "往$n一贴。\n", this_player(), ob);
		if( ob && ob->is_character() ) {
			move(ob);
			set("equipped", "sealed");
			set("no_drop", "这样东西不能丢弃，必须用 detach。\n");
		} else destruct(this_object());
		return 1;
	} else 
		return 0;
}
*/