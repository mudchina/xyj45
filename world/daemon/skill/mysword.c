// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Genaric self-made skills.
// sword
// mon 1/16/98

/*
风回雪舞剑法    dodge  -20    parry  -10    damage  15
*/

inherit SKILL;


mapping *action1 = ({
   ([   "action":
"$N使一招「寒芳留照魂应驻」，手中$w化为一道疾光刺向$n的$l",
     "dodge":     -5,
                "parry":                -10,
     "damage":     10,
     "damage_type":   "刺伤"
   ]),
});

mapping *action = ({
   ([   "action":
"$N手中$w笨拙地刺向$n的$l",
     "dodge":     -5,
                "parry":                -10,
     "damage":     10,
     "damage_type":   "刺伤"
   ]),
});

int valid_learn(object me)
{
   object ob;

   if( (int)me->query("max_force") < 50 )
     return notify_fail("你的内力不够，没有办法练风回雪舞剑法。\n");

   if( (string)me->query_skill_mapped("force")!= "moonforce")
     return notify_fail("风回雪舞剑法必须配合昆仑山玉女峰的圆月心法才能练。\n");

   if( !(ob = me->query_temp("weapon"))
   ||   (string)ob->query("skill_type") != "sword" )
     return notify_fail("你必须先找一把剑才能练剑法。\n");

   return 1;
}

int valid_enable(string usage)
{
   return usage=="sword" || usage=="parry";
}

mapping query_action()
{
        object me=this_player();

   return action[random(sizeof(action))];
}

int practice_skill(object me)
{
   if( (int)me->query("kee") < 30
   ||   (int)me->query("force") < 3 )
     return notify_fail("你的内力或气不够，没有办法练习风回雪舞剑法。\n");
   me->receive_damage("kee", 30);
   me->add("force", -3);
   write("你按著所学练了一遍风回雪舞剑法。\n");
   return 1;
}
