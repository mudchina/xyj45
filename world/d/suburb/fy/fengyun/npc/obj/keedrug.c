// medicine.c

inherit ITEM;

void create()
{
	set_name("云南白药",({"baiyao"}));
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long",
     	        "一包云南白药，可以用（ｕｓｅ）来治伤 。\n");
	    set("unit","包");
	    set("value", 2000);
	}
}

void init()
{
  if(this_player()==environment())
	add_action("apply_medicine","yong");
}

int apply_medicine()
{
	int value = 20;
	int diff;

	if(this_player()->is_fighting())
	    return notify_fail("战斗中不能用药！！\n");
	diff = this_player()->query("max_kee")-this_player()->query("eff_kee");
	if(!(diff))    return notify_fail("你没有受伤！\n");
	if(value > diff) value = diff;
	    
	message_vision("$N用云南白药疗伤 ．\n",this_player());
	this_player()->add("eff_kee",value);
	destruct(this_object());
	return 1;
}


