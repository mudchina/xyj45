// shoe.c

#include <armor.h>

inherit BOOTS;

void create()
{
        set_name("ÔÆÓÎÉ®Ð¬", ({ "shoes" }) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ë«");
                set("material", "cloth");
                set("armor_prop/move", 1);
        }
        setup();
}
