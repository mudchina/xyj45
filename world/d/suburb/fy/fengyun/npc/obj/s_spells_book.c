// s_spells_book.c

inherit ITEM;

void create()
{
        set_name("茅山道术入门", ({ "necrobook" }));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
                        
"这是一本茅山道术的入门，通过这本书，你可以初步领略到茅山术的奥妙\n"
                );
                set("value", 12260);
                set("material", "paper");
                set("skill", ([
                        "name":     "necromancy",    // name of the skill  
                    "exp_required": 500, // minimum combat experience equired 
                        "sen_cost":  30, // gin cost every time study this
                      "difficulty":  10,//the base int to learn this skill
        // modify is gin_cost's (difficulty - int)*5%
                    "max_skill":  20 // the maximum level you can learn
                                                                               
        // from this object.
                ]) );
        }
}
 
