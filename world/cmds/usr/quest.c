
#include <ansi.h>

inherit F_CLEAN_UP;
int time_period(int timep, object me);
int main(object ob, string arg)
{
	int nowtime = time();
	object me;
	mapping quest;
	if (!wizardp(ob) || arg == "") me = ob;
	else
	{
	if( arg ){
	me = present(arg, environment(ob));
	if (!me) me =  find_player(arg);
	if (!me) return notify_fail("你要察看谁的任务？请使用quests来察看解迷系统。\n");
			}
			else
				me = ob;
	}
	
	if(!(quest =  me->query("fy_quest")))
               return notify_fail("你现在没有风云任务，请使用quests来察看解迷系统。\n");
	write("你现在的风云任务是" + quest["quest_type"] +
 "『" + quest["quest"] + "』。\n");
	nowtime = (int) me->query("task_time") - time();
	if( nowtime  > 0 )
		time_period(nowtime, me);
	else
		write("但是你已经没有足够的时间来完成它了。\n");

	return 1;
}
int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "天";
        else time = "";

        if(h) time += chinese_number(h) + "小时";
        if(m) time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";
        tell_object(me,"你还有" + time + "去完成它。\n");
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : quest
 
这个指令可以显示出你当前的风云任务。请使用quests来察看
解迷系统的所有任务。

HELP
        );
        return 1;
}
