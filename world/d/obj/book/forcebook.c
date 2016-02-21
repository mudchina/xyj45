// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// literate.c

inherit ITEM;

void create()
{
        set_name("〖伏魔山心经〗", ({"fumo book", "book"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
   set("long", "一个油布皮的小册子，后一半却不知什么原因被扯掉。\n");
        set("material", "paper");
        set("skill", ([
                        "name": "force",
                        "exp_required": 200,
                        "sen_cost": 25,
                        "difficulty": 25,
                        "max_skill": 30,
]) );
        }
}

