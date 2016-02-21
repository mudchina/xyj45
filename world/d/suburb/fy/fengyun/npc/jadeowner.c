
inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("商玉龙", ({ "seller", "jadeseller" }) );
        set("gender", "男性" );
        set("age", 49);
	set("title", "玉龙珠宝");
        set("long", "这是一位肥肥胖胖店掌柜\n");
        set("combat_exp", 700000);
	set("str", 300);
        set("attitude", "friendly");
        set_skill("dodge", 100);
        set_skill("parry", 120);
        set("vendor_goods", ([
                __DIR__"obj/jade1":7,
                __DIR__"obj/jade2":7,
                __DIR__"obj/jade3":7,
                __DIR__"obj/jade4":7,
        ]) );

        setup();
        carry_object("/obj/cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) {
                case 0:
                        say( " 店掌柜笑着道：这位"
                                + RANK_D->query_respect(ob)
                                + "，买玉吗？ \n");
                        break;
                case 1:
                        say( " 店掌柜笑着道：这位"
                                + RANK_D->query_respect(ob)
                                + "，玉是吉祥之物，买一块吧。 \n");
                        break;

        }
}



