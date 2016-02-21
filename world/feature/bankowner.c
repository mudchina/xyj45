// 
// 


//bankowner.c


int do_convert(string arg)
{
	string from, to;
	int amount, bv1, bv2;
	object from_ob, to_ob;
        if( this_player()->is_busy() )
                return notify_fail("你的动作还没有完成，不能兑换钱。\n");
	if( !arg || sscanf(arg, "%d %s to %s", amount, from, to)!=3 )
		return notify_fail("指令格式：convert <数量> <货币种类> to <货币种类>\n");

	from_ob = present(from + "_money", this_player());
	to_ob = present(to + "_money", this_player());
	if( !to_ob && file_size("/obj/money/" + to + ".c") < 0 )
		return notify_fail("你想兑换哪一种钱？\n");

	if( !from_ob )		return notify_fail("你身上没有这种货币。\n");
	if( amount < 1 )	return notify_fail("兑换货币一次至少要兑换一个。\n");
		
	if( (int)from_ob->query_amount() < amount )
		return notify_fail("你身上没有那麽多" + from_ob->query("name") + "。\n");

	bv1 = from_ob->query("base_value");
	if( !bv1 ) return notify_fail("这种东西不值钱。\n");

	bv2 = to_ob ? to_ob->query("base_value") : call_other("/obj/money/" + to, "query", "base_value" );

	if( bv1 < bv2 ) amount -= amount % (bv2 / bv1);
	if( amount==0 )	return notify_fail("这些" + from_ob->query("name") + "的价值太低了，换不起。\n");
        from_ob->add_amount(-amount);
	if( !to_ob ) {
		to_ob = new("/obj/money/" + to);
		to_ob->move(this_player());
		to_ob->set_amount(amount * bv1 / bv2);
	} else
		to_ob->add_amount(amount * bv1 / bv2);

	message_vision( sprintf("$N从身上取出%s%s%s，换成%s%s%s。\n",
		chinese_number(amount), from_ob->query("base_unit"), from_ob->query("name"),
		chinese_number(amount * bv1 / bv2), to_ob->query("base_unit"), to_ob->query("name")),
		this_player() );
	this_player()->start_busy(1);
	return 1;
}


int do_deposit(string arg)
{
	int bv,amount;
	int damount;
	string type;
	object type_ob;
        if( this_player()->is_busy() )
                return notify_fail("你的动作还没有完成，不能存钱。\n");
        if( !arg || sscanf(arg, "%d %s", amount, type)!=2 )
                return notify_fail("指令格式：deposit <数量> <货币种类>\n");
	if( amount <= 0)
		return notify_fail("指令格式：deposit <数量> <货币种类>\n");
	type_ob = present(type + "_money", this_player());
        if( !type_ob)          return notify_fail("你身上没有这种货币。\n");
        if( (int)type_ob->query_amount() < amount )
                return notify_fail("你身上没有那麽多" + type_ob->query("name") + "。\n");
        bv = type_ob->query("base_value");
        if( !bv ) return notify_fail("这种东西不值钱。\n");
	damount = (int) this_player()->query("balance");
	damount += amount * bv;
	this_player()->set("balance", damount);
	type_ob->add_amount(-amount);
	message_vision(sprintf("$N存入了%s%s%s。\n",
	chinese_number(amount), type_ob->query("base_unit"), type_ob->query("name")), this_player());
	this_player()->start_busy(1);
	return 1;

}
int do_balance(string arg)
{
	int value;
	value= (int) this_player()->query("balance");
        if(value == 0){
        tell_object(this_player(),"你现在没有存款。\n");
	return 1;
	}
	if(value > 0) 
	tell_object(this_player(),"你现在共有存款：\n");
	if(value < 0){
	tell_object(this_player(),"你现在共欠款：\n");
	value = -value;
	}
        if( value < 100 )
		{
		tell_object(this_player(),chinese_number(value)+"文钱．\n");
                return 1;
		}
        else
			{
		tell_object(this_player(), chinese_number(value/100) + "两"
	+ (value%100? "又" + chinese_number(value%100) + "文钱．": "") + "\n");
			return 1;
			}
}

void pay_player(object who, int amount)

{
	object ob;


	if( amount < 1 ) amount = 1;
        if( amount/1000000 ) {
                ob = new(TECASH_OB);
                ob->set_amount(amount/1000000);
                ob->move(who);
                amount %= 1000000;
        }
        if( amount/100000 ) {
                ob = new(THCASH_OB);
                ob->set_amount(amount/100000);
                ob->move(who);
                amount %= 100000;
        }
	if( amount/10000 ) {
		ob = new(GOLD_OB);
		ob->set_amount(amount/10000);
		ob->move(who);
		amount %= 10000;
	}
        if( amount/100 ) {
                ob = new(SILVER_OB);
                ob->set_amount(amount/100);
                ob->move(who);
                amount %= 100;
        }
	if( amount ) {
		ob = new(COIN_OB);
		ob->set_amount(amount);
		ob->move(who);
	}
}
int do_withdraw(string arg)
{
	int amount;
	int hamount;
        if( this_player()->is_busy() )
                return notify_fail("你上一个动作还没有完成，不能存钱。\n");
        if( !arg || sscanf(arg, "%d", amount)!=1 )
                return notify_fail("指令格式：withdraw <数量> \n");
	hamount = (int) this_player()->query("balance");
	if(amount <=0 )
		return notify_fail("指令格式：withdraw <数量> \n");
	if(amount>hamount) 
		return notify_fail("你没这么多存款 ！！\n");
	hamount -=amount;
	this_player()->set("balance", hamount);
	pay_player(this_player(), amount);
	tell_object(this_player(), "ＯＫ \n");
	this_player()->start_busy(1);
	return 1;

}
int do_loan(string arg)
{
        int amount;
        int hamount;
        if( this_player()->is_busy() )
                return notify_fail("你上一个动作还没有完成，不能借钱。\n");
        if( !arg || sscanf(arg, "%d", amount)!=1 )
                return notify_fail("指令格式：loan <数量> \n");
        hamount = (int) this_player()->query("balance");
	if(hamount > 0 ) return notify_fail("你还有存款！\n");
        if(amount <=0 )
                return notify_fail("指令格式：loan <数量> \n");
	if((int)this_player()->query("combat_exp") < amount - hamount)
			return notify_fail("你借不到这么多钱．．．\n");
        hamount -=amount;
        this_player()->set("balance", hamount);
        pay_player(this_player(), amount);
        tell_object(this_player(), "ＯＫ \n");
	this_player()->start_busy(1);
        return 1;

}

