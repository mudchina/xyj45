// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// literate.c

inherit ITEM;

void create()
{
        set_name("〖刀法入门〗", ({"blade book", "book"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
     set("value", 1000);
        set("material", "paper");
        set("skill", ([
                        "name": "blade",
                        "exp_required": 100,
                        "sen_cost": 20,
                        "difficulty": 20,
                        "max_skill": 20,
]) );
        }
}

