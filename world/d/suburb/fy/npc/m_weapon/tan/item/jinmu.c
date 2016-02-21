//jinmu.c
inherit ITEM;

void init();
int do_see();

void init()
{
	add_action("do_see","see");
}

void create()
{
        set_name( "海底金母", ({ "jin mu","jin","mu"}));
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long","这是一块海底金母，泛着紫悠悠的光，看起来沉甸甸的，\n"
		    "似乎是制造兵器的绝好材料。\n");
                set("value", 0);
                set("material", "iron");
              }
}



int do_see()
{
	write("xixi");
        return(0);
}
