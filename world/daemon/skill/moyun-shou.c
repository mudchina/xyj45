// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//摩云手


inherit SKILL;

mapping *action = ({
   ([   "action":     "$N一招『螳螂捕蝉式』，左手抓向$n的丹田，就在$n回身自防的一瞬间，右手却已掐上了$n的$l",
     "dodge":     10,
     "parry":     10,
     "force":     160,
     "damage_type":   "刺伤",
                        "weapon":     "右手食指",
   ]),
   ([   "action": "$N双手一翻，出『梅花五朵』，双手如穿花蝴蝶一般上下翻飞。\n$n看花了眼，刹那间$N已欺身到了眼前",
     "dodge":     5,
     "parry":     -15,
     "force":     180,
     "damage_type":   "内伤",
                        "weapon":     "右手",
   ]),
   ([   "action":     "只见$N一转身，一指由胁下穿出，疾刺$n的$l，却正是一招『穿针引线』",
     "dodge":     5,
     "parry":     10,
     "force":     100,
     "damage_type":   "刺伤",
                        "weapon":     "左手食指",
   ]),
   ([   "action":     "$N双掌一错，掌心向外横推而出，这一招『力士推山』带着一股罡风扑向$n的$l",
     "dodge":     20,
     "parry":     20,
     "force":     140,
     "damage_type":   "内伤",
                        "weapon":     "左手", 
   ]),
            ([   "action":     "$N一招『乌龙翻江』，左手在空中虚划了个半弧，拍向$n的$l",
     "dodge":     30,
     "parry":     10,
     "force":     70,
     "damage_type":   "内伤",
                        "weapon":     "左手",
   ]),
            ([   "action":     "忽听$N一声怒吼，右手高高举起，一式『力劈华山』，砍向$n的$l",
     "dodge":     10,
     "parry":     -10,
     "force":     220,
     "damage_type":   "砍伤",
                        "weapon":     "右手",
   ]),
});

int valid_learn(object me)
{
   
   if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
     return notify_fail("练摩云手必须空手。\n");
   return 1;
}

int valid_enable(string usage)
{
   return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
   return action[random(sizeof(action))];
}

int practice_skill(object me)
{
   if( (int)me->query("mud_age") > 100 )
     return notify_fail("摩云手只能学，不能练。\n");
   
   return 1;
}
void skill_improved(object me)
{
        if ((int)me->query_skill("kugu-blade", 1) % 10 == 0 ) {
                tell_object(me, "\n你高兴之余，忽觉一口真气提不上来，腿一软，坐到了地上。\n\n");
                me->add("max_force", -10);
     me->start_budy(5+random(2));
        }
}

