#include <ansi.h>
inherit SKILL;
mapping *quest = ({
        ([      "quest":                "´¿½ðÒ¶×Ó",
                "quest_type":           "Ñ°",
                "time":                 300,
                "exp_bonus":            30,
        ]),
});
mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

