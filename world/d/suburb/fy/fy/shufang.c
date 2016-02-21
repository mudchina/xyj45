inherit ROOM;
void create()
{
        set("short", "知府书房");
        set("long", @LONG
这书室庭户虚敞，正中挂一幅名人山水。供一个古铜香炉，炉里香烟飘渺。左边
设一张湘妃竹榻，右边架上堆满若干图书。沿窗一只几上，摆列文房四宝。窗外庭中
种植许多花木，铺设得十分清雅，凡朝廷命官都可在这发号令（ａｒｒｅｓｔ）。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"govern",
]));
        set("objects", ([
        __DIR__"npc/governor" : 1,
                        ]) );

        setup();
}
void init()
{
add_action("do_arrest","arrest");
add_action("do_loan" ,"loan");
add_action("do_withdraw", "withdraw");
add_action("do_balance","balance");
add_action("do_deposit", "deposit");
add_action("do_convert","convert");
}
int gethim(object target,object me)
{
        message_vision("$N一句话不说，匆匆忙忙地离开了。\n",target);
        target->move(this_object());
        message_vision("$N被官兵押了进来。\n",target);
	if(me){
	me->kill_ob(target);
	target->kill_ob(me);
		}
        return 1;
}
int do_loan(string arg) {return 1;}
int do_withdraw(string arg) {return 1;}
int do_deposit(string arg) {return 1;}
int do_convert(string arg) {return 1;}
int do_balance(string arg) {return 1;}
int do_arrest(string arg)
{
	object me, target;
	int exp, stra,leader,factor;
	if(!arg)
	return notify_fail("你要下令缉拿谁？\n");
	me = this_player();
	if((string) me->query("class") != "official" )
	return notify_fail("你不是朝廷官员，不可缉拿疑犯！\n");
	if((int) me->query("sen") < 50 )
	return notify_fail("你的心神不够！\n");	
	me->add("sen",-50);
	if(!objectp(target = find_living(arg)))
	return notify_fail("找不到你想要的疑犯！\n");
	if( interactive(target))
	return notify_fail("找不到你想要的疑犯！\n");
	if( target->query("no_arrest") )
	return notify_fail("找不到你想要的疑犯！\n");
	message_vision("$N大声下令道：来人那．．把$n给我拿来！！\n",me,target);
	exp = (int) target->query("combat_exp");
	stra = (int) me->query_skill("strategy",1);
	leader = (int) me->query_skill("leadership",1);
	factor = stra * stra * leader * leader;
	factor = (factor + ((int) me->query("combat_exp") ) - 2000 )/1000;			
	if( random(factor) <= exp)
	return notify_fail("以你现在的能力，还不足以缉拿"+target->query("name")+"！\n");
	call_out("gethim",5,target,me);
	return 1;
}
