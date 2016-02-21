// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */

// dealer.c 商人
// This is a inheritable object.
// Each dealer should support buy, sell, list, value 4 commands

#include <dbase.h>

string is_vendor_good(string arg)
{
	string *goods;
	object ob;
	int i;

	if (arrayp(goods = query("vendor_goods"))) 
		for (i = 0; i < sizeof(goods); i++) 
			if (goods[i]->id(arg))
				return goods[i];
	return "";
}

int do_value(string arg)
{
	object ob;
	int value;

	if (!arg || !(ob = present(arg, this_player())))
		return notify_fail("你要估什么的价？\n");
	
	if (ob->query("money_id"))
		return notify_fail("你没用过钱啊？\n");

	value = ob->query("value");
	if (value < 1)
		write(ob->query("name") + "一文不值！\n");
	else 
		write(ob->query("name") + "值" + 
		MONEY_D->price_str(value * 70 / 100) + "。\n");
	return 1;
}

int do_sell(string arg)
{
	object ob;
	int value;
	
	if (!arg || !(ob = present(arg, this_player())))
		return notify_fail("你要卖什么？\n");

	if (ob->query("money_id"))
		return notify_fail("你想卖「钱」？？\n");

	if (stringp(ob->query("no_drop")))
		return notify_fail("这样东西不能卖。\n");

	if (is_vendor_good(arg) != "") 
		return notify_fail("卖给你好不好？\n");

	if (ob->query("food_supply"))
		return notify_fail("剩菜剩饭留给您自己用吧。\n");
	
        if (ob->query("shaolin"))
                return notify_fail("小的只有一个脑袋，可不敢买少林庙产。\n");
	
	value = ob->query("value");
	if (value < 30)
		write(ob->query("name") + "一文不值！\n");
	else {
		message_vision("$N卖掉了一" + ob->query("unit") + 
		ob->query("name") + "给$n。\n", this_player(), this_object());
		MONEY_D->pay_player(this_player(), value * 70 / 100);
		if (value < 50)
			destruct(ob);
		else
			ob->move(this_object());
	}
	return 1;
}

int do_list()
{
	string *goods;
	object *inv;
	int i;

	inv = all_inventory(this_object());

	if (!sizeof(inv) && !arrayp(goods = query("vendor_goods")))
		return notify_fail("目前没有可以卖的东西。\n");
	
	printf("你可以向%s购买下列物品：\n", query("name"));
	for (i = 0; i < sizeof(inv); i++) 
		if (!inv[i]->query("equipped") && !inv[i]->query("money_id"))
		printf("%30-s：%s\n", inv[i]->short(),
		MONEY_D->price_str(inv[i]->query("value") * 6 / 5));
	if (arrayp(goods = query("vendor_goods")))
		for (i = 0; i < sizeof(goods); i++)
			printf("%30-s：%s\n", goods[i]->short(),
			MONEY_D->price_str(goods[i]->query("value")));
	return 1;
}	

int do_buy(string arg)
{
	int value, val_factor;
	string ob_file;
	object ob;
//	mapping fam;

//      if ( (fam = this_player()->query("family")) && fam["family_name"] == "丐帮" ) 
//		return notify_fail("你是个穷叫化，买什麽东西！\n");
	
	if (!arg)
		return notify_fail("你想买什么？ 1\n");
	else if (!(ob = present(arg, this_object())))
		if ((ob_file = is_vendor_good(arg)) == "")
			return notify_fail("你想买什么？ 2\n");

	if (!ob) {
		ob = new(ob_file);
		val_factor = 10;
	}
	else {
		if (ob->query("equipped"))
			return notify_fail("你想买什么？ 3\n");
		val_factor = 12;
	}

        if (query_temp("busy"))
                return notify_fail("哟，抱歉啊，我这儿正忙着呢……您请稍候。\n");

	
	switch (MONEY_D->player_pay(this_player(), ob->query("value") *  val_factor / 10)) {
	case 0:
		return notify_fail("穷光蛋，一边呆着去！\n");
	case 2:
		return notify_fail("您的零钱不够了，银票又没人找得开。\n");
	default:
        	set_temp("busy", 1);
		message_vision("$N从$n那里买下了一" + ob->query("unit") + 
		ob->query("name") + "。\n", this_player(), this_object());
		ob->move(this_player());
	}
        remove_call_out("enough_rest");
        call_out("enough_rest", 1);

	return 1;
}

void enough_rest()
{
        delete_temp("busy");
}


