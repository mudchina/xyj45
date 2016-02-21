// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */

// tiyunzong.c 梯云纵

inherit SKILL;

string *dodge_msg = ({
	"只见$n一招「白鹤冲天」，身体向上笔直地纵起丈余，躲过了$N这一招。\n",
	"$n一个「鹞子翻身」，向后纵出数丈之远，避开了$N的凌厉攻势。\n",
	"$n使出「大鹏展翅」，向一旁飘然纵出，轻轻着地。\n"
//        "但是$n身形飘忽，轻轻一纵，早已避开。\n",
//       "$n身随意转，倏地往一旁挪开了三尺，避过了这一招。\n",
//        "可是$n侧身一让，$N这一招扑了个空。\n",
//        "却见$n足不点地，往旁窜开数尺，躲了开去。\n",
//        "$n身形微晃，有惊无险地避开了$N这一招。\n"
});

int valid_enable(string usage) { return (usage == "dodge") || (usage == "move"); }

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 40 )
                return notify_fail("你的体力太差了，不能练梯云纵。\n");
        me->receive_damage("kee", 30);
        return 1;
}

