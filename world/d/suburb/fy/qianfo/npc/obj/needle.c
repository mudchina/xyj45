// 
// 

#include <weapon.h>
inherit DAGGER;
void create()
{
	string *order=({"红", "绿", "黄", "白","黑"});
        set_name((order[random(5)]) +"色的细针", ({ "needle", "long needle"}) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "支");
		set("long", "一根细长的银针，上面刻着＂金木水火土＂几个蝇头小字\n");
		set("value", 50);
		set("material", "steel");
	}
	init_dagger(10);
	set("wield_msg", "$N从怀中摸出一支$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n藏入怀中。\n");
	setup();
}
