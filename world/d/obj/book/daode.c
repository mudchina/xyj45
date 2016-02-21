// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// literate.c

inherit ITEM;

void create()
{
        set_name("〖道德经〗", ({"daodejing", "book"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
        set("material", "paper");
   set("value", 100);
   set("long", "道家经典－－道德经");
        set("skill", ([
                        "name": "spells",
                        "exp_required": 2000,
                        "sen_cost": 25,
                        "difficulty": 25,
                        "max_skill": 50,
]) );
        }
}

