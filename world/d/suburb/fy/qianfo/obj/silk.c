// 
// 

#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("七彩丝缎带", ({ "silk" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long","这条七彩丝缎带在烛光下闪着七种光茫，一看就是不凡之品．\n");
                set("material", "cloth");
		set("realsilk",1);
		set("value",50000);
                set("armor_prop/armor", 5);
                set("armor_prop/dodge", 5);
		set("armor_prop/spirituality",3);
        }
        setup();
}
