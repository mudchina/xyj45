// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit ITEM;

void create()
{
        set_name("逍遥袋", ({ "xiaoyao dai","bag","dai" }) );
        set_weight(10000);
        set_max_encumbrance(50000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "口");
                set("long", "这是一个锦绣的蓝缎子口袋，拿在手上却相当的沉，并相当的韧。\n");
                set("value", 0);
     set("no_sell",1);
        }
}

int is_container() { return 1; }

