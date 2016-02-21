// 
// 


#include <ansi.h>
inherit NPC;

void create()
{
	set_name("樊夫人", ({ "furen" }) );
	set("gender", "男性" );
	set("title", HIR "祭剑师" NOR);
	set("age", 52);
	set("long",
		"樊夫人本是三清宫的一个老道士，人到老年无所事事，
在这里给人祭剑。\n");
	set("combat_exp", 50000);
	set("str",200);
	set("attitude", "friendly");
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
	add_action("do_ji","ji");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(5) ) {
		case 0:
			say( "樊夫人笑道：这位" + RANK_D->query_respect(ob)
				+ "，你的宝刃看起来好象要血祭一下了。\n");
			break;
		case 1:
			say( "樊夫人说道：这位" + RANK_D->query_respect(ob)
				+ "，你的宝刃杀气不足，来血祭一下宝刃吧。\n");
			break;
	}
}

int  do_ji(string arg)
{
	object me, ob;
	object gold;
	int cost = 1;
	int i,j,base,current;
	string id,name ;	
	string file,newfile,filestring;
	me = this_player();
	id = me->query("id");
        if( !arg ) return notify_fail("你要祭什麽武器？\n");
        gold = present("gold_money", this_player());
        if( !gold) return notify_fail("你身上没有金子。\n");
        if( !objectp(ob = present(arg, me)) )
        return notify_fail("你身上没有这样东西。\n");
        if(me->is_busy())
        return notify_fail("你上一个动作还没有完成。\n");
        if( !ob->query("weapon_prop") )
        return notify_fail("你只能祭可当作武器的东西。\n");
        if( ob->query("equipped") )
        return notify_fail("你不可祭装备著了的武器。\n");
        if( !ob->query("owner") )
        return notify_fail("你只可祭自己打造的武器。\n");
	if( ob->query("skill_type") =="dagger") base= 5;
	else base= 30;
	current = (int) ob->query("weapon_prop/damage");
	for(j=1;j<=100;j++)
	{
		base = base + j;
		if(base >= current) break;
	}
	for(i=1; i<=j;i++)
			cost = cost * 2;
        if((int) gold->query_amount() < cost)
        return notify_fail("你身上没带够" + sprintf("%d",cost)+ "两金子。\n");
        gold->add_amount(-cost);
        me->start_busy(1);
	me->add("bellicosity",cost);
	file = base_name(ob) + ".c";
	filestring = read_file(file);
	filestring = replace_string( filestring, 
		sprintf("%d",current), sprintf("%d",current+j));
	newfile = DATA_DIR+"login/" + id[0..0] + "/" + id + "/" + id +
		sprintf("%d",time()) + ".c";	
        if( !write_file(newfile, filestring,1))
                return 0;
	ob->move(this_object());
	destruct(ob);
	rm(file);
	ob = new(newfile);
	name = ob->query("name");
	if(ob->move(me))	
	message_vision(sprintf("$N向%s上啐了一口带血的唾沫，说道：好了！\n",name),this_object());
	return 1;
}
