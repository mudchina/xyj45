// shoe.c

#include <armor.h>

inherit BOOTS;

void create()
{
        string *order=({"粗布", "棉布", "蓝布", "洗得发白的",
"青布","紫布","黑布","白布"});
        set_name((order[random(8)]) +"僧鞋", ({ "monk shoes", "shoes"}) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
                set("material", "cloth");
                set("armor_prop/move", 1);
        }
        setup();
}
