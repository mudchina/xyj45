inherit NPC;
int direct();
void create()
{
        set_name("曲无容", ({ "wurong" }) );
        set("gender", "女性" );
        set("age", 22);
	set("str",40);
        set("long",
                "一个全身黑袍的女孩子．．\n");
	set("combat_exp", 5000000);
        set("chat_chance", 2);
        set("chat_msg", ({
                "曲无容指着姬冰雁道：你．．你真的不肯走？！！\n",
		"曲无容哼道：中原一点红，他真的爱我？？\n",
        }) );
        set("inquiry", ([
                "石观音" : (: direct :),
                "master guanyin" : (: direct :)

        ]));


        set("attitude", "friendly");
        setup();
        carry_object(__DIR__"obj/bcloth")->wear();

}

int direct()
{
	object me;
	object room;
	me = this_player();
	message_vision("$N对$n冷笑一声：你想见我师父？
那我就成全你！！\n",this_object(),me);
	room = load_object("/d/suburb/fy/guanyin/mirror");
	message_vision("$N脚下一松，整个人不见了！\n",me);
	me->move(room);	
	return 1;
}
