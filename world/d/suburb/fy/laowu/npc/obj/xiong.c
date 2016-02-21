// medicine.c

inherit ITEM;

void create()
{
	set_name("熊掌",({"xiong"}));
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long",
     	        "一小块熊掌， 可以用（ｕｓｅ）来增神 。\n");
	    set("unit","块");
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
	diff = this_player()->query("max_sen")-this_player()->query("eff_sen");
	if(!(diff))    return notify_fail("你没有受伤！\n");
	if(value > diff) value = diff;
	    
	message_vision("$N用熊掌增神．\n",this_player());
	this_player()->add("eff_sen",value);
	destruct(this_object());
	return 1;
}


