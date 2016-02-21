// tea_waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("卖玩具的", ({ "wanfan" }) );
        set("gender", "男性" );
        set("age", 60);
        set("long",
                "一个让孩子们一见就觉得可亲的老翁．\n");
	set("combat_exp", 5);
        set("chat_chance", 1);
        set("chat_msg", ({
                "卖玩具的晃了晃手中的玩具，笑道：来，试试．．\n",
        }) );

        set("attitude", "friendly");
        set("vendor_goods", ([
                __DIR__"obj/windche":15,
		__DIR__"obj/niren":20,
        ]) );
        setup();
        carry_object("/obj/cloth")->wear();

}

void init()
{
        add_action("do_vendor_list", "list");
}

