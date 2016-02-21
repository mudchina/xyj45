// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// pao.c

inherit EQUIP;

void create()
{
        set_name("皂罗袍", ({"purple cloth", "cloth"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("value", 10000);
                set("material", "cloth");
                set("armor_type", "cloth");
                set("armor_prop/armor", 20);
                set("armor_prop/dodge", 8);
                set("armor_prop/spells", 10);
             }
}
