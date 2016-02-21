#include <ansi.h>
inherit SSERVER;
int curse(object me, object target)
{
	string msg;
	int damage, ap, dp;
	int extradam;
        if((int)me->query_skill("cursism") < 100 )
                return notify_fail("你的降头术不够高！\n");

	if((int)me->query("kee") < 100 )
		return notify_fail("你的气血不够！\n");

        write("你想拘谁的魂？");
        input_to( (: call_other, __FILE__, "select_target", me :));
	return 1;
}

void select_target(object me, string name)
{
	mapping ob_list;
        object ob,new;
	string msg;
	object room;
	string *list;
	int i,HERE = 0;
        if( !name || name=="" ) {
                write("中止施法。\n");
                return;
        }

                ob = find_living(name);
		room = environment(me);
	me->receive_wound("kee",100);
        if( !ob || !me->visible(ob) || userp(ob) || present(ob, room)){
		write("你无法感受到这个人的鬼魂。\n");
		return; }
        msg = HIW "$N双手向上一挥，一阵浓雾从地下卷出．．．\n" ;
        ob_list = room->query("objects");
	list = keys(ob_list);
	for(i=0;i<sizeof(list);i++)
		if(list[i] == base_name(ob) || list[i] == base_name(ob)+".c")
			{HERE=1;break;}
	if(HERE) {
			seteuid(geteuid(me));
			new = new(base_name(ob));
			new->be_ghost(1);
			new->set("combat_exp", ((int) new->query("combat_exp"))*10);
			new->move(room);	
			new->set("title",HIB "拘魂"NOR);
	msg +=  "浓雾似乎在$N身边渐渐得浓缩成一个黑影．．．\n" NOR;
		new->start_call_out((: call_other, __FILE__, "melt", new :), 
(int)me->query_skill("cursism")/10 + 5);
		}
	else
	msg += "浓雾立刻消失了．．．\n"NOR;
	message_vision(msg, me);
}

void melt(object ob)
{
	message_vision("$N渐渐的虚化，消失了．．．\n",ob);
	destruct(ob);
}
