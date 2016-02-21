// yitian-jian 倚天剑

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name("倚天剑",({ "yitian jian", "yitian", "sword", "jian" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 10000000);
                set("material", "steel");
                set("long", "这是一柄四尺来长的古剑，剑鞘上金丝镶着两个字“倚天”。
整个剑身隐隐发出一层青气，剑未出鞘，已可见其不凡。\n");
                set("wield_msg", HIY "$N“唰”的一声抽出$n挽了个剑花，但见寒芒吞吐，
电闪星飞。 ....$N不由得从心底升起一股凌云豪气。\n" NOR);
                set("unwield_msg", HIY "倚天剑幻作一道白光，「唰」地飞入剑鞘。\n" NOR);
                set("unequip_msg", HIY "倚天剑幻作一道白光，「唰」地飞入剑鞘。\n" NOR);
        }
        init_sword(1000);
        setup();
}
