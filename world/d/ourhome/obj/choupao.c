// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// choupao.c

inherit EQUIP;

void create()
{
        set_name("绸袍", ({"choupao","cloth", "pao"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("value", 500);
                set("material", "cloth");
                set("armor_type", "cloth");
                set("armor_prop/armor", 1);
             }
}
