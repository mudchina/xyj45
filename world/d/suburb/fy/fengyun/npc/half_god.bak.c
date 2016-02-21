inherit NPC;
#include <ansi.h>
int time_period(int timep, object me);
string sysmsg;
void create()
{
	set_name(HIY "朱" NOR + HIG "半" NOR + HIM "仙" NOR, ({ "halfgod", "half god", "half-god" }) );

	set("gender", "男性");
	set("age", 99);
	set("long",
		"朱半仙年过六甲，鹤发童颜。\n");
	set("attitude", "peaceful");
        set("skill_public",1);
	set("str", 26000);
	set("cor", 30);
	set("int", 24);
	set("cps", 30);

	set("force", 40000);
	set("max_force", 80000);
	set("force_factor", 1000);

	set("combat_exp", 1000000);
	set("score", 200000);

//        set("chat_chance", 4);
//        set("chat_msg", ({
//                (: random_move :)
//        }) );

	set_skill("unarmed", 100);
	set_skill("force", 100);
	set_skill("iron-cloth", 100);
	set_skill("yiqiforce", 30);

	map_skill("iron-cloth", "yiqiforce");
        map_skill("force", "yiqiforce");
        map_skill("unarmed", "yiqiforce");

	create_family("潇遥派", 1, "祖师");

	setup();

	carry_object(__DIR__"obj/jade-ring")->wear();
	carry_object(__DIR__"obj/jade-pin")->wear();
	carry_object(__DIR__"obj/jade-boots")->wear();
	carry_object(__DIR__"obj/jade-cloth")->wear();
}
int accept_fight(object me)
{
        command("say 生命可贵！不要自寻死路！");
        return 0;
}
void init()
{
        add_action("give_quest", "quest");
}

int give_quest()
{
	mapping quest ;
	object me;
	int j, combatexp, timep, r_kar;
	string tag = "1000000";
 string *levels = ({
                        "0",
                        "500",
                        "1000",
                        "1500",
                        "2000",
                        "3000",
                        "5000",
                        "8000",
                        "10000",
                        "13000",
                        "17000",
                        "22000",
                        "40000",
                        "50000",
                        "60000",
                        "80000",
                        "100000",
                        "200000",
                        "400000",
                        "800000",
                        "1000000"
        });
	me = this_player();
// Let's see if this player is a ghost
	if((int) me->is_ghost())
	{
		write("鬼魂不可要任务．\n");
		return 1;
	}
// Let's see if this player still carries an un-expired task
        if((quest =  me->query("quest")))
	{
	if( ((int) me->query("task_time")) >  time() )
		return 0;
	else
	{
		message_vision("朱半仙向$N一甩袍袖，说道： 
真没用！不过看在你还回来见老夫的份上，就在给你一次机会．\n", me);
		me->set("kee", me->query("kee")/2+1);
	}
	}
	combatexp = (int) me->query("combat_exp");
// palyer say quest too hard!
	combatexp = combatexp * 2 / 3 ;
	r_kar = random((int) me->query("kar"));
        for(j= sizeof(levels) - 1 ; j>=0; j--)
        {
                if( atoi(levels[j])  <= combatexp )
                        {
                                tag = levels[j];
				if ( r_kar > 15 && j > 0) tag = levels[j-1];
				if ( r_kar < 3 && j < (sizeof(levels) -1)) tag = levels[j+1];
                                break;
                        }
        }
	quest = QUEST_D(tag)->query_quest();
	timep = quest["time"];	
// A factor here to make time random
	timep = timep / (random(2)+1);
	time_period(timep, me);
	if (quest["quest_type"] == "寻")
	{
        tell_object(me,"找回『"+quest["quest"]+"』给我。\n" NOR);
	sysmsg +="找回『"+quest["quest"]+"』。";
	}
	        if (quest["quest_type"] == "杀")
        {
        tell_object(me,"替我杀了『"+quest["quest"]+"』。\n" NOR);
	sysmsg +="杀了『"+quest["quest"]+"』。";
        }
 	me->set("quest", quest);
	me->set("task_time", (int) time()+(int) timep);
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

        tell_object(me,HIW "朱半仙沉思了一会儿，说道：\n请在" + time + "内");
	sysmsg = "在" + time + "内";
        return 1;
}
int accept_object(object who, object ob)
{
        int bonus, exp, pot, score, val;
	string test;
	mapping quest;
	val = ob->value();
	if (val)
	{
		if( val < (33 - random((int)who->query("kar"))) * 10000)
	tell_object(who,"朱半仙在你耳边悄悄说道：这．．这太少了点儿吧．．\n");
		else
		{
		       who->set("quest", 0 );
       	 	tell_object(who,"朱半仙说道：好吧，这个任务就算了吧．．\n");
	
		}
		return 1;
	}
        if(!(quest =  who->query("quest")))
	{
        tell_object(who,"朱半仙说道：这不是我想要的。\n");
	return 0;
	}
        if( ob->name() != quest["quest"])
        {
        tell_object(who,"朱半仙说道：这不是我想要的。\n");
        return 0;
        }
	if( ob->is_character())
        {
        tell_object(who,"朱半仙说道：这不是我想要的。\n");
        return 0;
        }
        if ((int) who->query("task_time") < time() )
        {
        tell_object(who,"朱半仙说道：真可惜！你没有在指定的时间内完成！\n");
                        return 1;
        }
        else
        {
        tell_object(who,"朱半仙说道：恭喜你！你又完成了一项任务！\n");
	exp = quest["exp_bonus"]/2 + random(quest["exp_bonus"]/2)+1;
	pot = quest["pot_bonus"]/4 + random(quest["pot_bonus"]/4)+1;
//	due to weekly quest, each quet worth 20
//	score = quest["score"]/2 + random(quest["score"]/2);
	score = 20;
        bonus = (int) who->query("combat_exp");
        bonus += exp;
        who->set("combat_exp", bonus);
	bonus = (int) who->query("potential");
	bonus = bonus - (int) who->query("learned_points");
        bonus = bonus + pot;
	if( bonus > 100) bonus = 100;
	bonus += (int) who->query("learned_points");
        who->set("potential", bonus );
	bonus = (int) who->query("score");
	bonus += score;
        who->set("score", bonus);
        tell_object(who,HIW"你被奖励了：\n" +
	chinese_number(exp) + "点实战经验\n"+
	chinese_number(pot) + "点潜能\n" +
	chinese_number(score)+"点综合评价\n"NOR);
	who->set("quest", 0 );
                        return 1;
        }
                return 1;
}
