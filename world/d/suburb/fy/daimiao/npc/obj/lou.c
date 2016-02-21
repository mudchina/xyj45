#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name( HIG "小楼一夜听春雨" NOR, ({ "springrain blade", "blade" }) );
        set_weight(14000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",
                        "＂小楼一夜听春雨＂又名＂小楼听雨＂。是西方神教两大掌门信物之一。\n"
                        "此刀极邪，又削铁如泥。\n");
                set("value", 350000);
                set("material", "sapphire");
		set("rigidity", 500000);
		set("no_get",1);
		set("no_drop",1);
                set("wield_msg", "$N「刷」地一声抽出一柄闪著寒光的$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
                set("weapon_prop/agility", 5);
        }

        init_blade(95);
        setup();
}

void owner_is_killed(object killer)
{
	message_vision(HIR"\n \n 小楼一夜听春雨 " NOR +"落在地上，又弹入$N的怀中！\n\n",killer);
	this_object()->move(killer);
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
	me->add("bellicosity",10+random(30));
        return HIR "$N的眼里映着＂小楼一夜听春雨＂闪出的诡异红光．．．\n" NOR;
}

