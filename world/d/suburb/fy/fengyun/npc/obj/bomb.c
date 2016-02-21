
inherit ITEM;

void create()
{
	set_name("火炮丸", ({ "bomb" , "火炮丸"}) );
	set_weight(5000);
	set("explosive",1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一个有强大爆炸力的火炮丸\n");
		set("value", 1000);
	}
}



