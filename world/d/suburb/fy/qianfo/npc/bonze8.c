// 
// 

inherit NPC;
int give_qin();
void create()
{
        set_name("云海", ({ "yunhai" }) );
        set("gender", "男性" );
        set("class", "bonze");
	set("title","兴国禅寺云字辈大师");
        set("age", random(40)+20);
        set("cor", 24);
        set("cps", 29);
        set("int", 25);
        set("long", "他是兴国禅寺中颇有威望的云字辈大师\n");
        set("combat_exp", 6000000);
        set("attitude", "friendly");
        set("max_force", 500);
        set("force", 500);
        set("force_factor", 5);
        set("chat_chance", 1);
        set("chat_msg", ({
                "云海说道：你想归依佛门吗？\n",
        }) );
        set("inquiry", ([
		"归依佛门" : (: give_qin :),
		"femen" : (: give_qin :),
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
command("say 我帮不到你很多，但我不入地狱，谁入地狱！！这个你拿去吧！\n");
obj = new(__DIR__"obj/shoe2");
command("give shoes to "+this_player()->query("id"));
set("given",1);
        }
else
command("say 我也帮不到你！\n");
        return 1;
}

void reset()
{
delete("given");
}

