// 
// 

inherit NPC;
inherit F_VENDOR;
void create()
{
	set_name("中药店老板", ({ "medman" }) );
	set("gender", "男性" );
	set("age", 45);
	set("long",
		"
一个正忙得不可开交的中药店老板，他正在煮汤．
\n");
	set("combat_exp", 5);
	set("attitude", "friendly");
	set("per",1);
        set("vendor_goods", ([
                __DIR__"obj/astragalt" : 10,
                __DIR__"obj/dioscoreae" : 10,
                __DIR__"obj/codonopsis" : 12,
                __DIR__"obj/pilosulae" : 10,
                __DIR__"obj/lycii" : 10,
        ]) );
        set("inquiry", ([
                "当归补血鱼汤" : "那你可要买：北芪，淮山，党参，杞子，和当归．\n",
		"soup" : "那你可要买：北芪，淮山，党参，杞子，和当归．\n",
        ]));

	setup();
	carry_object("/obj/cloth")->wear();
}

void init()
{	
	object ob;

	::init();
	add_action("do_vendor_list", "list");
}
