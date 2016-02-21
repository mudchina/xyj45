#include <dbase.h>
#include <login.h>
#include <ansi.h>

int time_period(int timep, object me);
string sysmsg;

int give_quest(string arg)
{
	mapping quest ;
	object me;
	int j, combatexp, timep, lvl=0;
        mixed *local;
        int  t;
	string tag = "40000000";
 string *levels = ({
                        "0",
                        "4000",
                        "8000",
                        "16000",
                        "32000",
                        "64000",
                        "128000",
                        "256000",
                        "512000",
                        "1024000",
                        "1536000",
                        "2304000",
                        "3456000",
                        "5184000",
                        "7776000",
                        "11664000",
                        "17496000",
                        "26244000",
			"40000000"
        });
	if( ! arg || !sscanf(arg, "%d", lvl))
	lvl = 0;
	if(lvl<0) lvl=0;
	me = this_player();
// Let's see if this player is a ghost
        local = localtime(time()*60);
        t = local[2] * 60 + local[1];       
	if( t < 240 || t > 1380)
	{
		write("夜深了．．还要什么任务！！\n");
		return 1;
	}
	if((int) me->is_ghost())
	{
		write("鬼魂不可要任务．\n");
		return 1;
	}

// Let's see if this player still carries an un-expired task
        if((quest =  me->query("fy_quest")))
	{
	if( ((int) me->query("task_time")) >  time() )
		return 0;
	else
		me->set("kee", me->query("kee")/2+1);
		me->delete_temp("quest_number");
	}
	combatexp = (int) me->query("combat_exp");
        for(j= sizeof(levels) - 1 ; j>=0; j--)
        {
                if( atoi(levels[j])  <= combatexp )
                        {
                                tag = levels[j];
				if(j < (sizeof(levels)- lvl)) tag = levels[j+lvl];
                                break;
                        }
        }
        if(!random(40) ) tag = "_new";
	if(!random(10) ) tag = "_common";
	quest = QUEST_D(tag)->query_quest();
//	to use less mem...
//	timep = quest["time"];	
	timep = 600;   // each quest give 10 mins.
// A factor here to make time random
	timep = random(timep/2)+timep/2;
	time_period(timep, me);
	if (quest["quest_type"] == "寻")
	{
        tell_object(me,"找回『"+quest["quest"]+"』给天机老人。\n" NOR);
	sysmsg +="找回『"+quest["quest"]+"』。";
	}
	        if (quest["quest_type"] == "杀")
        {
        tell_object(me,"替天机老人杀了『"+quest["quest"]+"』。\n" NOR);
	sysmsg +="杀了『"+quest["quest"]+"』。";
        }
 	me->set("fy_quest", quest);
	me->set("task_time", (int) time()+(int) timep);
	if((int)me->query_temp("quest_number") < 5)
	me->add_temp("quest_number",1);
	CHANNEL_D->do_channel(this_object(), "qst", sprintf("%s(%s)：%s", 
	me->query("name"),me->query("id"),sysmsg));

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

        tell_object(me,HIW + sprintf("%s",this_object()->name()) +"说道：\n请在" + time + "内");
	sysmsg = "在" + time + "内";
        return 1;
}
