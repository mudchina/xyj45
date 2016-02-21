// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("苏红儿", ({ "suhong" }) );
	set("gender", "女性" );
	set("age", 21);
	set("title", "老板娘");
	set("long",
		"这位老板娘正斜依在柜台边，笑咪咪地望着你。\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("per",30);
	set("vendor_goods", ([
		__DIR__"obj/yxrs":12,
		__DIR__"obj/cddt":12,
	        __DIR__"obj/frsp":12,
                __DIR__"obj/ssqy":12,
                __DIR__"obj/ylzp":12,
                __DIR__"obj/pwym":12,
                __DIR__"obj/cwgp":12,
                __DIR__"obj/ychz":12,
                __DIR__"obj/jxyz":12,
                __DIR__"obj/zypg":12,
                __DIR__"obj/rxcy":12,
                __DIR__"obj/qcsh":12,
                __DIR__"obj/hyjp":12,
                __DIR__"obj/szpc":12,
                __DIR__"obj/glyc":12,
                __DIR__"obj/xcfs":12,
                __DIR__"obj/cpcy":12,
                __DIR__"obj/gzyq":12,
                __DIR__"obj/qcxr":12,
                __DIR__"obj/jymj":12,
                __DIR__"obj/glxj":12,
                __DIR__"obj/cpdx":12,
                __DIR__"obj/pxhy":12,
                __DIR__"obj/kzmt":12,
                __DIR__"obj/hhdq":12,

	]) );
	set_skill("unarmed",50);
	set_skill("tenderzhi",50);
	set_skill("dodge",50);
	set_skill("stormdance",50);
	map_skill("dodge","stormdance");	
	map_skill("unarmed","tenderzhi");
	setup();
	carry_object(__DIR__"obj/pink_cloth")->wear();
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
	switch( random(3) ) {
		case 0:
message_vision("$N眼角含笑，有意无意的瞟了$n一眼。\n",this_object(),ob);
			break;
		case 1:
message_vision("$N纤腰微摆，露出羊脂般的玉臂，向$n招了招手。\n",this_object(),ob);
			break;
		case 2:
message_vision("$N望了$n一眼，用玉手掩着樱桃小嘴轻笑起来。\n",this_object(),ob);
			break;
	}
}
