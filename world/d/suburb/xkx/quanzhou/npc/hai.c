// hai.c 海公公
// Jay 4/6/96

inherit NPC;

string ask_for_zigong();

void create()
{
        set_name("海公公", ({"hai gonggong", "hai", "gonggong"}));
        set("title", "东厂千户");
        set("long",
                "他是东厂大太监海大富，乔装改扮成商人模样出京寻欢作乐，长得既像老头又像老太太。\n"
        );

        set("gender", "无性");
        set("rank_info/respect", "公公");

        set("attitude", "heroism");
        set("class", "eunach");

        set("inquiry",([
                "自宫"  : (: ask_for_zigong :),
        ]));

        set("age", 60);
        set("shen_type", -1);
        set("str", 25);
        set("int", 20);
        set("con", 20);
        set("dex", 25);
        set("max_kee", 500);
        set("max_gin", 100);
        set("force", 500);
        set("max_force", 500);
        set("jiali", 100);
        set("combat_exp", 15000);
        set("score", 100);
        set("apply/attack",  30);
        set("apply/defense", 30);

        set_skill("force", 50);
        set_skill("unarmed", 50);
        set_skill("sword", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("pixie-jian", 50);

        map_skill("dodge", "pixie-jian");
        map_skill("sword", "pixie-jian");

        setup();
        set("chat_chance", 15);
        set("chat_msg", ({
                (: random_move :)
        }) );

        carry_object("/d/obj/clone/weapon/changjian")->wield();
        carry_object("/d/obj/clone/misc/cloth")->wear();
        add_money("silver", 50);
}

void init()
{
        add_action("do_decide", "decide");
}

string ask_for_zigong()
{
        object me;

        me = this_player();

        if( (string)me->query("gender")=="无性" )
                return "你我同是阉人，何必开如此无聊的玩笑？\n";

        if( (string)me->query("gender") == "女性" )
                return "我虽已废，但一样可以给你这个小美人带来快乐，要不要试试？\n";
        if ((int)me->query_str() > 28 )
                return "这位好汉过于粗壮，自宫有碍观瞻，不妥，不妥。\n";

       me->set_temp("pending/zigong", 1);
        return "自宫？这位公子相貌堂堂，何必... 我真希望能有你的那个。自宫之后，不可后悔，你若决心已定(decide)，告诉我。\n";
}

int do_decide()
{
        if( !this_player()->query_temp("pending/zigong") )
                return 0;

        message_vision(
                "$N一咬牙，褪下中衣。（女玩家闭眼！）\n\n"
                "$n伸出长剑插到$N两腿之间，飞速一剜，……\n\n"
                "$N顿时惨叫一声昏了过去……\n\n",
                this_player(), this_object() );
        command("chat 嗨……");
        command("hehe");
        this_player()->delete_temp("pending/zigong");
        this_player()->set("gender","无性");
        this_player()->set("class", "eunach");
        this_player()->set("combat_exp",this_player()->query("combat_exp")+1000);
        this_player()->unconcious();
        return 1;
}

