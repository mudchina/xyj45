// medicine.c

inherit ITEM;

void create()
{
	set_name("野人参",({"renshen"}));
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long",
     	        "一株野人参， 可以用（ｕｓｅ）来补精 。\n");
	    set("unit","株");
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
	diff = this_player()->query("max_gin")-this_player()->query("eff_gin");
	if(!(diff))    return notify_fail("你没有受伤！\n");
	if(value > diff) value = diff;
	    
	message_vision("$N用野人参补精 ．\n",this_player());
	this_player()->add("eff_gin",value);
	destruct(this_object());
	return 1;
}


