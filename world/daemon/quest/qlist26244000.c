#include <ansi.h>
inherit SKILL;
mapping *quest = ({
        ([      "quest":                "Ð¡ÌúºÐ",
                "quest_type":           "Ñ°",
                "exp_bonus":            100,
        ]),
        ([      "quest":                "Ò¹Ã÷Öé",
                "quest_type":           "Ñ°",
                "exp_bonus":            100,
        ]),
        ([      "quest":                "»ÆÂé×Ó",
                "quest_type":           "É±",
                "exp_bonus":            100,
        ]),
        ([      "quest":                "÷½×Ó",
                "quest_type":           "Ñ°",
                "exp_bonus":            100,
        ]),
        ([      "quest":                "Òø¹³ÅÛ",
                "quest_type":           "Ñ°",
                "exp_bonus":            100,
        ]),
        ([      "quest":               HIY "¶«ÔÀ´óµÛ" NOR,
                "quest_type":           "É±",
                "exp_bonus":            100,
        ]),
        ([      "quest":                "ÀîÑ°»¶",
                "quest_type":           "É±",
                "exp_bonus":            100,
        ]),
        ([      "quest":                RED "Ð¡Àî·Éµ¶" NOR,
                "quest_type":           "Ñ°",
                "exp_bonus":            100,
        ]),
        ([      "quest":                 HIW "Ñ©°×³ñÉÀ" NOR,
                "quest_type":           "Ñ°",
                "exp_bonus":            100,
        ]),
        ([      "quest":                "³¤¸ËºµÑÌÇ¹",
                "quest_type":           "Ñ°",
                "exp_bonus":            100,
        ]),

});
mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

