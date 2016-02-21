// 
// 

inherit NPC;
void create()
{
        string *order=({"龙", "凤", "无刀", "无剑",
"虎","宣","肥","兽"});
        set_name("天" + (order[random(8)]), ({ "dashi", "heshang"}) );
        set("gender", "男性" );
        set("class", "bonze");
	set("title","兴国禅寺天字辈大师");
        set("age", random(40)+20);
        set("cor", 24);
        set("cps", 29);
        set("int", 25);
        set("long", "他是兴国禅寺中颇有威望的天字辈大师\n");
        set("combat_exp", random(1000000)+1000);
        set("attitude", "friendly");
        set("max_force", 500);
        set("force", 500);
        set("force_factor", 5);
        set("chat_chance", 10);
        set("chat_msg", ({
                (: random_move :)
        }) );
        setup();
        carry_object(__DIR__"obj/monk_cloth")->wear();
        carry_object(__DIR__"obj/shoe2")->wear();
}
int accept_fight(object me)
{
        command("say 阿弥陀佛！贫僧武功低微，施主不要开这种玩笑。\n");
        return 0;
}
