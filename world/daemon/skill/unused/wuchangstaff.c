// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <ansi.h>

inherit SKILL;

mapping *action = ({
        ([      "name":                 "魂不守舍",
                "action":
"$N挥动$w，一招「魂不守舍」击向$n的$l。$n只觉没精打采，万念俱灰，竟是无意抵挡",
                "dodge":                -10,
                "damage":               20,
                "damage_type":  "擦伤"
        ]),
        ([      "name":                 "行尸走肉",
                "action":
"$N一招「行尸走肉」，手中$w恍恍惚惚，隐隐约约，若有若无地向$n砸下",
                "dodge":                -50,
                "damage":               20,
                "damage_type":  "砸伤"
        ]),
        ([      "name":                 "倒行逆施",
                "action":
"$N手中$w疾横，斗地点出，这招「倒行逆施」轻灵飘逸，迳刺$n的$l",
                "dodge":                -40,
                "damage":               25,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "穷途末路",
                "action":
"$N手中$w向$n兜头击落，兵器未至，已将$n各处退路封死，好一招「穷途末路」",
                "dodge":                -40,
                "damage":               20,
                "damage_type":  "擦伤"
        ]),   
        ([      "name":                 "无中生有",
                "action":
"$N使出「无中生有」，$w从$n意想不到的地方使出，弄得$n一时手足无措",
                "dodge":                -40,
                "damage":               30,
                "damage_type":  "刺伤"
        ]),   
        ([      "name":                 "饮恨吞声",
                "action":
"$N脸上突现煞气，举起手中$w，猛向$n$l击落，这一招「饮恨吞声」出手又快又狠",
                "dodge":                -40,
                "damage":               40,
                "damage_type":  "砸伤"
        ]),   
});


int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 100 )
                return
notify_fail("你的内力不够，没有办法学无常杖法，等内力提高了再来吧。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "staff" )
                return
notify_fail("你必须先找一条禅杖才能学无常杖法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="staff"||usage="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 5 )
                return
notify_fail("你的内力或气不够，没有办法练习无常杖法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("你按著所学练了一遍无常杖法。\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

