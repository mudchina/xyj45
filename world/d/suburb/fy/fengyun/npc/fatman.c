// tea_waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("大胖子", ({ "fatman" }) );
        set("gender", "男性" );
        set("age", 40);
        set("long",
                "一个白白胖胖的矮胖子．\n");
	set("combat_exp", 5);
        set("chat_chance", 2);
        set("chat_msg", ({
                "大胖子指着你讥笑道：你．．你比我还胖还矮．．\n",
		"大胖子哼道：月圆之夜，紫禁之巅，叶城主赢定了．．\n",
        }) );

        set("attitude", "friendly");
        set("rank_info/respect", "胖哥");
        set("vendor_goods", ([
                __DIR__"obj/dogmed":10,
        ]) );
        setup();
        carry_object("/obj/cloth")->wear();

}

void init()
{
        add_action("do_vendor_list", "list");
}

