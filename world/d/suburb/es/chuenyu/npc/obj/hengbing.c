#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name( HIW "������" NOR, ({ "sword" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ������ɫ�ĵĳ�����������Լ��ʮ�������ҡ�\n");
                set("value", 50000);
                set("material", "crimsonsteel");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unequip_msg", "$N�����е�$n���뱳��Ľ��ʡ�\n");
        }
        init_sword(70);
        setup();
}