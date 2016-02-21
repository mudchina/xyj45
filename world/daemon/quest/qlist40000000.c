#include <ansi.h>
inherit SKILL;
mapping *quest = ({
        ([      "quest":                "ÒóÕýÁ®",
                "quest_type":           "É±",
                "exp_bonus":            150,
        ]),
        ([      "quest":                "Öª¸®ÍÅÁú¹Ù·þ",
                "quest_type":           "Ñ°",
                "exp_bonus":            150,
        ]),
        ([      "quest":                "ÔÆ¿Õ",
                "quest_type":           "É±",
                "exp_bonus":            150,
        ]),
        ([      "quest":                "Ò¶¹Â³Ç",
                "quest_type":           "É±",
                "exp_bonus":            150,
        ]),
        ([      "quest":               HIR "±»ÏÊÑª½þÍ¸µÄ²¼Ìõ" NOR,
                "quest_type":           "Ñ°",
                "exp_bonus":            150,
        ]),
        ([      "quest":               "ÑÅÎÚ¹Å½£",
                "quest_type":           "Ñ°",
                "exp_bonus":            150,
        ]),
        ([      "quest":               HIW "µãµãÑª°ßµÄ°×ÅÛ" NOR,
                "quest_type":           "Ñ°",
                "exp_bonus":            150,
        ]),
});
mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

