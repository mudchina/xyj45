// taoism_book.c

inherit ITEM;

void create()
{
        set_name("天师正道入门", ({ "taoismbook" }));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
                        
"这是一本天师正道的入门，只有学了天师正道，你才能进一步提高茅山术的等级.\n"
                );
                set("value", 12260);
                set("material", "paper");
                set("skill", ([
                        "name":     "taoism",    // name of the skill  
                    "exp_required": 500, // minimum combat experience equired 
                        "sen_cost":  30, // gin cost every time study this
                      "difficulty":  10,//the base int to learn this skill
        // modify is gin_cost's (difficulty - int)*5%
                    "max_skill":  20 // the maximum level you can learn
                                                                               
        // from this object.
                ]) );
        }
}
 
