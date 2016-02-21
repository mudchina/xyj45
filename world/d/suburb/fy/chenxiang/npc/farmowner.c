// 
// 

inherit NPC;
inherit F_VENDOR;
void create()
{
	set_name("农具店老板", ({ "owner" }) );
	set("gender", "男性" );
	set("age", 35);
	set("combat_exp", 50);
	set("attitude", "friendly");
	set("per",1);
	set("vendor_goods", ([
		 __DIR__"obj/b1" : 12,
		__DIR__"obj/b2" :6,
	]) );
        set("inquiry", ([
                "杀人案" : "那家伙有把刀，会喷火的刀，就是他杀的．\n",
		"murder" : "那家伙有把刀，会喷火的刀，就是他杀的．\n",
        ]));

	setup();
	carry_object("/obj/cloth")->wear();
}

void init()
{	

	::init();
	add_action("do_vendor_list", "list");
}
