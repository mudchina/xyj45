// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// cloudstaff.c

inherit SKILL;

mapping *action = ({
   ([   "action":     "$N使一招「迎门三不过」，手中$w连续刺向$n面门，哽嗓，前心！",
     "damage":     40,
     "dodge":     10,
     "parry":     -10,
     "damage_type":   "刺伤"
   ]),
   ([   "action":     "$N抖起$w，一招「拨草寻蛇」刺向$n$l！",
     "damage":     30,
     "dodge":     20,
     "parry":     -10,
     "damage_type":   "刺伤"
   ]),
   ([   "action":     "$N手中$w一顺，使出「巧女纫针」刺向$n$l！",
     "damage":     35,
     "dodge":     20,
     "parry":     -20,
     "damage_type":   "刺伤"
   ]),
   ([   "action":     "$N一转身，使出一招「回马枪」，$w一挺刺向$n$l！",
     "damage":     50,
     "dodge":     10,
     "parry":     -30,
     "damage_type":   "刺伤"
   ]),
});

int valid_learn(object me)
{
   object ob;

   if( (int)me->query("max_force") < 100 )
     return notify_fail("你的内力不够，没有办法练魔家枪法。\n");
   if( !(ob = me->query_temp("weapon"))
   ||      (string)ob->query("skill_type") != "spear" )
                return notify_fail("你必须先找一柄枪才能练枪法。\n");

   return 1;
}

int valid_enable(string usage)
{
   return (usage=="spear") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
   return action[random(sizeof(action))];
}

int practice_skill(object me)
{
   object weapon;

   if( !objectp(weapon = me->query_temp("weapon"))
   ||   (string)weapon->query("skill_type") != "staff" )
     return notify_fail("你必须先找一柄长枪或者是类似的武器，才能练枪法。\n");

   if( (int)me->query("kee") < 30 
   ||    (int)me->query("force") < 5  )
     return notify_fail("你的体力不够练这门枪法，还是先休息休息吧。\n");
   me->receive_damage("kee", 30);
   me->add("force", -5);
        write("你按著所学练了一遍千钧棒法。\n");
   return 1;
}
