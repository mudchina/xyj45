// 
// 

inherit NPC;
int give_qin();
void create()
{
        set_name("云流", ({ "yunliu" }) );
        set("gender", "男性" );
        set("class", "bonze");
	set("title","兴国禅寺云字辈大师");
        set("age", random(40)+20);
        set("cor", 24);
        set("cps", 29);
        set("int", 25);
        set("long", "他是兴国禅寺中颇有威望的云字辈大师\n");
        set("combat_exp", 600000);
        set("attitude", "friendly");
        set("max_force", 500);
        set("force", 500);
        set("force_factor", 5);
        set("chat_chance", 1);
        set("chat_msg", ({
                "云流瞪了你一眼，对你全身上下狂摸一气道：
你是千年难遇的练武奇材！！
我听说南方的大莽林中有一异人，你可去拜他为师！！\n",
        }) );
        set("inquiry", ([
                "异人" : "我听说要想见异人，先需会弹琴．．\n",
                "yiren" : "我听说要想见异人，先需会弹琴．．\n",
		"弹琴" : (: give_qin :),
		"tanqin" : (: give_qin :),
	]));
        setup();
        carry_object(__DIR__"obj/monk_cloth")->wear();
        carry_object(__DIR__"obj/shoe2")->wear();
}
int accept_fight(object me)
{
        command("say 阿弥陀佛！贫僧武功低微，施主不要开这种玩笑。\n");
        return 0;
}

int give_qin()
{
        object obj;
if( !query("given"))
        {
command("say 这把古琴你拿去练吧！！\n");
obj = new(__DIR__"obj/qin");
obj->move(this_player());
set("given",1);
        }
else
command("say 我的古琴已送人了！\n");
        return 1;
}

void reset()
{
delete("given");
}

