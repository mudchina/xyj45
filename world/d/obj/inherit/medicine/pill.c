// pill.c

inherit COMBINED_ITEM;

void setup()
{
}

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	string what = query("cure");
	int howmuch = query("amount");

	if (!id(arg))
		return notify_fail("你想吃什么？\n");

	if ((int)this_player()->query("eff_kee") == 
	    (int)this_player()->query("max_kee"))
		return notify_fail("你现在不需要用" + this_object()->name() + "。\n");
	else {
		this_player()->receive_curing("kee", 50);
		message_vision("$N吃下一包金创药，气色看起来好多了。\n", this_player());
		destruct(this_object());
		return 1;
	}
}

