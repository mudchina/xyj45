// keeper.c

inherit NPC;
string mark_you();
void create()
{
        set_name("李霞", ({ "lixia" }) );
        set("gender", "女性" );
        set("age", 24);
	set("per",5);
        set("long",
                
"这个女人看起来二十多岁了，看著她粗壮的身形，你觉得．．．。\n");
        set("combat_exp", 1);
        set("chat_chance", 1);
        set("chat_msg", ({
"李霞说道：给我百两黄金，牌就是你的．\n",
        }) );

        set("attitude", "friendly");
        setup();
}
int accept_object(object who, object ob)
{
        int val;

        val = ob->value();
        if( !val )
                return 0;
        if( val >= 100000 ) 
	{
        say( "李霞说道：这位" + RANK_D->query_respect(who)
                + "，你去冰河，把它炸（ｂｏｍｂ）出来．\n");
	who->set("marks/李霞",1);
        return 1;
	}
	return 0;
}
