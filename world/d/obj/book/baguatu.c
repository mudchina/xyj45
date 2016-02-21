// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// literate.c

inherit ITEM;

void create()
{
        set_name("〖伏羲八卦图〗", ({"bagua tu", "tu", "book"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
     set("value", 0);
     set("no_sell", 1);
     set("no_put", 1);
     set("no_give", 1);
   set("long","一张画有伏羲八卦的锦纶。\n");
        set("material", "paper");
        set("skill", ([
                        "name": "baguazhou",
                        "exp_required": 40000,
                        "sen_cost": 40,
                        "difficulty": 40,
                        "max_skill": 100,
]) );
        }
}

