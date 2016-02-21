// 
// 

int give_silk();
inherit NPC;
void create()
{
        set_name("老实和尚", ({ "lao shi", "lao"}) );
        set("gender", "男性" );
        set("age", 32);
        set("long", 
"老实和尚整天疯疯癫癫，怪里怪气的．他的功夫也是如此．
老实和尚从来不说谎话，所以得名＂老实和尚＂\n");
        set("combat_exp", 100000);
        set("attitude", "friendly");
        set_skill("unarmed", 5+random(350));
	set_skill("notracesnow",70);
	set_skill("dodge", 40);
	set_skill("force",4);
	map_skill("dodge","notracesnow");
        set("force",10);
        set("force_factor",2);
        set("max_force",100);
        set("chat_chance", 5);
        set("chat_msg", ({
"老实和尚叹道：请佛祖罚我，我又去逛了千金楼！\n",
"老实和尚捶了捶自己的头，＂出家人决不打诳语！\n",
"老实和尚骂道：这个该死的四条眉，把这烫手的差事又给了我！\n",
		(: random_move :),
        }) );
        set("inquiry", ([
                "七彩丝缎带" : (: give_silk:),
                "silk" : (: give_silk:)

        ]));
	
	setup();
	carry_object(__DIR__"obj/monk_cloth")->wear();
}
int give_silk()
{
if( (int)query("given") >= 7 )
{
command("say 你晚了，都给光了．．．\n");
return 1;
}
command("say 你也想在月圆之夜，去看那紫禁之巅的旷世决战吗？\n");
command("say 那我得考考你，看你够不够格．\n");
this_player()->set_temp("marks/laoshi",1);
return 1;
}

void win_enemy(object loser)
{
command("say 这位" + RANK_D->query_respect(loser)+ "，你还不够格！\n");
}
void lose_enemy( object winner)
{
object silk;
command("say 这位" + RANK_D->query_respect(winner)+ "，你的功夫不错！\n");
silk = new(__DIR__"obj/silk");
silk->move(this_object());
command("give silk to " + winner->query("id"));
add("given",1);
}

int accept_fight(object me)
{
	if(me->query_temp("marks/laoshi"))
	{
	command("say 好，你赢了我，这丝带就是你的．\n");
	me->delete_temp("marks/laoshi");
        return 1;
	}
	else
	{
        command("say 阿弥陀佛！贫僧武功低微，施主不要开这种玩笑。\n");
        return 0;
	}
}
void reset()
{
delete("given");
}
