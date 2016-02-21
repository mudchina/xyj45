inherit ROOM;
void create()
{
        set("short", "城隍庙");
        set("long", @LONG
阴暗潮湿，破旧不堪，每当狂风吹过，整座庙都在摇晃，似乎马上就会倒塌下来。
一支残烛在风中摇曳，忽明忽暗，鬼气森森。整个庙里布满灰尘，只有角落里的一个
暗红色的神龛（ｋａｎ）一尘不染。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west"  : __DIR__"nwind5", 
]));
        set("item_desc", ([
                "kan": "这个神龛开口很窄，正好可扔下一张纸(throw)。\n",
                "神龛" : "这个神龛开口很窄，正好可扔下一张纸(throw)。\n"
        ]) );

        setup();
}
void init()
{
	add_action("do_throw", "throw");
}

int do_throw(string arg)
{
	object *inv;
	object me, who;
	object paper;
	object killer;
	string target;
	int targetprice;
	int i;
	if (!arg) return notify_fail("你要放什么入神龛？\n");
	if( arg !="youzhi" && arg != "油油的纸")
		return notify_fail("你不可把"+arg+"放入神龛．\n");
	me = this_player();
	who = this_player();
	inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
			if( (string)(inv[i]->query("name")) == "油油的纸")
				{
					paper = inv[i];		
					break;
				}
		}
	if( !paper) return notify_fail("你没有油油的纸．\n");
	if( !stringp(paper->query("targetid")))
	return notify_fail("你的纸上没写字(print)．\n");
	who->start_busy(2);
	target = (string)paper->query("targetid");
	killer = new(__DIR__"npc/killer");
	killer->set("possessed",who);
	killer->set_leader(who);
	killer->set("haunttar", target); 
	targetprice = (int)paper->query("targetprice");
	destruct(paper);
	killer->set("combat_exp", targetprice/10 );
	targetprice = targetprice / 200000 + 1;
	killer->set_temp("apply/attack", targetprice);
	killer->set_temp("apply/move", targetprice);
	killer->set_temp("apply/dodge", targetprice);
	killer->set_temp("apply/damage", targetprice / 2 );
	message_vision("$N阴笑一声，面目阴陈的把纸放入神龛．\n",who);
	log_file("KILL_LOG",sprintf("(%s)%s雇了杀手杀%s\n",
		ctime(time()),
		who->query("id"),
		killer->query("haunttar")));
	call_out("gothim", 2, who,killer);
	return 1;
}

void gothim(object who, object killer)
{
	if(who && killer) {
       message_vision("一阵阴风掠过，$N不禁打了个冷战．\n",who);
        killer->move(environment(who));
        message_vision("$N向$n低声道：带我去．．\n",killer,who);
	}
	return;
}

