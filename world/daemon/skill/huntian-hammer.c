// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//【混天锤】??

/*
  dodge  15    parry  -15    damage  30
其锤法直来直去，招招为实，势大力猛，招架抵挡
甚为不易，一但碰上则伤害极大。但不足是不够轻
盈。
*/

inherit SKILL;

mapping *action = ({
   ([   "action":   "$N手中$w一转，卷着一股强劲的风力挥向$n的$l，
这一下又急又猛，势大力狠，眼见就到了$n身前",
     "dodge":   10,
     "parry":   -10,
     "damage":   30,
     "damage_type":   "砸伤",
   ]),
   ([   "action":   "$N双手一震，手中$w夹带着闷雷般的响声，劈头盖脸地就向$n砸了过去",
     "dodge":   15,
     "parry":   -15,
     "damage":   30,
     "damage_type":   "砸伤",
   ]),
   ([   "action":   "$N将$w高举过肩，蓄紧力发，对准$n的$l发出雷霆一击",
     "dodge":   20,
     "parry":   -20,
     "damage":   35,
     "damage_type":   "砸伤",
   ]),
   ([   "action":   "$N身走轻灵，手中$w忽上忽下，令人捉摸不清去路，
就在$n一恍惚间，“唰”地砸向$n的$l",
     "dodge":   0,
     "parry":   -10,
     "damage":   25,
     "damage_type":   "砸伤",
   ]),
   ([   "action":   "$N趁与$n错身之机，倒转$w，锤把戳向了$n，
这一下如白蛇吐芯，悄无声息的点上了$n的$l",
     "dodge":   10,
     "parry":   -10,
     "damage":   20,
     "damage_type":   "戳伤",
   ]),
   ([   "action":   "$N紧握$w猛挥了个大圆，卷的周身长内沙土尘扬，
趁$n不能辨物之记，手中$w斜斜地砸向$n的$l",
     "dodge":   20,
     "parry":   -25,
     "damage":   30,
     "damage_type":   "砸伤",
   ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的内力不够，没有办法练混天锤。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "hammer" )
                return notify_fail("你必须先找一柄大锤才能练混天锤。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="hammer" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 50
        ||      (int)me->query("force") < 50 )
                return
notify_fail("你的内力或气不够，没有办法练习混天锤。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("你按着所学练了一遍混天锤。\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

