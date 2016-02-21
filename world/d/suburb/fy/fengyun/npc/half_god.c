inherit NPC;
#include <ansi.h>
inherit F_MASTER;
inherit F_QUEST;

void create()
{
	set_name(HIY "天机老人" NOR, ({ "tianji", "Tian ji", "Tian" }) );

	set("gender", "男性");
	set("age", 99);
	set("long",
		"天机老人年过六甲，鹤发童颜。在兵器谱上排名第一，
尤在上官，小李之上．天机老人收徒极挑剔．．．．\n");
	set("attitude", "peaceful");
        set("skill_public",1);
	set("str", 26000);
	set("cor", 30);
	set("int", 24);
	set("cps", 30);
        set("chat_chance", 1);
        set("chat_msg", ({
                "天机老人拿起旱烟抽了几口．．．．\n",
        }) );

	set("force", 40000);
	set("max_force", 80000);
	set("force_factor", 1000);

	set("combat_exp", 10000000);
	set("score", 200000);

	set_skill("unarmed", 120);
	set_skill("force", 100);
	set_skill("iron-cloth", 100);
	set_skill("yiqiforce", 30);
	set_skill("dagger",200);
	set_temp("apply/attack",300);
	set_temp("apply/damage",30000);
	map_skill("iron-cloth", "yiqiforce");
        map_skill("force", "yiqiforce");
        map_skill("unarmed", "yiqiforce");

	create_family("潇遥派", 1, "祖师");
	set("title", "闲云野鹤");
	setup();

	carry_object(__DIR__"obj/jade-ring")->wear();
	carry_object(__DIR__"obj/jade-pin")->wear();
	carry_object(__DIR__"obj/jade-boots")->wear();
	carry_object(__DIR__"obj/jade-cloth")->wear();
	carry_object(__DIR__"obj/hanyan")->wield();
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
int accept_object(object who, object ob)
{
        int  exp, pot, score, val;
	string test;
	mapping quest;
	val = ob->value();
	if (val && val >10000 && val < 20000)
	{
		       who->set("quest", 0 );
       	 	tell_object(who,"天机老人说道：好吧，这个任务就算了吧．．\n");
		who->delete_temp("quest_number");
		return 1;
	}
        if(!(quest =  who->query("quest")))
	{
        tell_object(who,"天机老人说道：这不是我想要的。\n");
	return 0;
	}
        if( (string)ob->query("name") != quest["quest"])
        {
        tell_object(who,"天机老人说道：这不是我想要的。\n");
        return 0;
        }
	if( ob->is_character())
        {
        tell_object(who,"天机老人说道：这不是我想要的。\n");
        return 0;
        }
        if ((int) who->query("task_time") < time() )
        {
        tell_object(who,"天机老人说道：真可惜！你没有在指定的时间内完成！\n");
                        return 1;
        }
        else
        {
        tell_object(who,"天机老人说道：恭喜你！你又完成了一项任务！\n");
	exp = quest["exp_bonus"]/2 + random(quest["exp_bonus"]/2)+1;
// put a cap
	if(exp > 150) exp = 150;
	exp = exp * (int) who->query_temp("quest_number");
	pot = exp / 5 + 1;
//	due to weekly quest, each quet worth 20
//	score = quest["score"]/2 + random(quest["score"]/2);
	score = 1;
	who->add("combat_exp",exp);
	who->add("potential",pot);
	who->add("score",score);
        tell_object(who,HIW"你被奖励了：\n" +
	chinese_number(exp) + "点实战经验\n"+
	chinese_number(pot) + "点潜能\n" +
	chinese_number(score)+"点综合评价\n"NOR);
	who->set("quest", 0 );
                        return 1;
        }
                return 1;
}
void attempt_apprentice(object me)
{
	switch(random(4)) {
		case 0:
message_vision("$N对$n笑问道：什么是心剑？\n", this_object(),me);
			break;
		case 1:
message_vision("$N对$n笑问道：什么是＂敌不动，我不动；敌一动，我先动？＂\n", this_object(),me);	
			break;
		case 2:
message_vision("$N对$n笑问道：＂有形，无形＂是什么？\n", this_object(),me);		
			break;
		case 3:
message_vision("$N对$n笑问道：武学的最高境界是什么？\n", this_object(),me);
			break;
	}
                        return;

}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "xianren");
}

