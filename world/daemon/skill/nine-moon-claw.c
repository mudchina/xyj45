#include <ansi.h>

inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N使出一招「穿心百抓」，右手抓向$n的$l",
                "dodge":                -300,
                "parry":                -110,
                "force":                200,
                "damage_type":  "抓伤"
        ]),
        ([      "action":               
"$N使出一招「残天九连抓」，左手化指为爪，连续击向$n的$l",
                "dodge":                -100,
                "parry":                -200,
                "force":                170,
                "damage_type":  "抓伤"
        ]),
        ([      "action":               
"$N使出九阴白骨爪的「爪底亡魂」，如鬼魅般欺至$n身前，一爪勾向$n的$l",
                "dodge":                -300,
                "parry":                -220,
                "force":                150,
                "damage_type":  "抓伤"
        ]),
        ([      "action":               
"$N双臂一错，使出「戕帝狂爪」，对准$n的$l连续抓出",
                "dodge":                -510,
                "parry":                -200,
                "force":                290,
                "damage_type":  "抓伤"
        ]),
        ([      "action":               
"$N左手指甲暴突，奋力推出，一招「九阴腐万象」，抓向$n$l",
                "dodge":                -200,
                "parry":                -200,
                "force":                170,
                "damage_type":  "抓伤"
        ]),
        ([      "action":               
"$N使出「九阴穿两仪」，双手同时向$n的$l出爪攻击",
                "dodge":                -100,
                "parry":                -100,
                "force":                180,
                "damage_type":  "抓伤"
        ]),
        ([      "action":               
"$N吐气扬声，一招「邪巫神天爪」双臂并力递出",
                "parry":                -400,
                "force":                320,
                "damage_type":  "抓伤"
        ]),
});

int valid_learn(object me)
{
        if( (string)me->query("gender") != "女性" )
                return notify_fail("九阴白骨爪是只有女子才能练的武功。\n");
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("练九阴白骨爪必须空手。\n");
        if( (int)me->query_skill("nine-moon-force", 1) < 10 )
                return 
notify_fail("你的九阴心经火候不足，无法练九阴白骨爪。\n");
        if( (int)me->query("max_force") < 100 )
                return notify_fail("你的内力太弱，无法练九阴白骨爪。\n");
        return 1;
}

int valid_enable(string usage) { return usage=="unarmed"; }
int effective_level() { return 20;}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30 )
                return notify_fail("你的体力不够了，休息一下再练吧。\n");
        if( (int)me->query("force") < 5 )
                return notify_fail("你的内力不够了，休息一下再练吧。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( damage_bonus < 110 ) return 0;

        if( random(damage_bonus/10) > victim->query_str() ) {
                victim->receive_wound("kee", (damage_bonus - 100) / 2 );
                switch(random(3)) {
                        case 0: return "你听到「喀啦」一声轻响，竟似是骨碎的声音！\n";
                        case 1: return "$N劲力一吐，$n的$l发出「喀」地一声爆响！\n";
                        case 2: return "只听见$n的$l「喀」地一声 ...\n";
                }
        }
}
 
string perform_action_file(string action)
{
        return CLASS_D("ninemoon") + "/ninemoonclaw/" + action;
}

void skill_improved(object me)
{
        if( (int)me->query_skill("nine-moon-claw", 1)  % 10 == 0 ) {
                tell_object(me,
                        RED "\n你突然觉得一股阴气冲上心头，只觉得想杀人....\n\n"
 NOR);
                me->add("bellicosity", 2000);
        } else
                me->add("bellicosity", 200);
}


string *parry_msg = ({
        "$n伸出两指，一招「金石为开」，将$N的$w牢牢的夹在指中！\n",
	"$n后退一步，双手向下连抓，$N手中的$w似乎突然沉重起来，几乎连拿都拿不稳。\n",
	"$n向地上凌空一抓，一招「阴河倒卷」，整个人象一片枯叶一样在$N$w的气流中飘荡。\n",
	"$n双爪劲力一吐一吸，一招「阴毒敷骨」，竟将$N手中的$w吸于双爪之上！\n",
});

string *unarmed_parry_msg = ({
        "$n双臂暴长，一招「阴爪搜魂」，将$N双臂所有大穴全不罩于爪下！\n",
	"$n左臂一转，从$N意想不到的角度猛然回击，一招「阴龙咋现」将$N逼退。\n",
	"$n中指微弹，一招「无孔不入」，一股阴森森的指风直刺$N的面门。\n",
	"$n双手交错，一招「天地皆阴」将$N圈于爪风之下。\n",	
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int learn_bonus()
{
	return 20;
}
int practice_bonus()
{
	return 10;
}
int black_white_ness()
{
	return -30;
}

