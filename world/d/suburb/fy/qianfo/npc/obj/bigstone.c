#include <weapon.h>
inherit HAMMER;
void create()
{
        set_name("大黑石", ({ "blackstone" }) );
        set_weight(800000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", "这是一块相当沉的大黑石\n");
                set("value", 3);
                set("material", "iron");
        }
        init_hammer(65);
        setup();
}
