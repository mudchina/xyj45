// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// dao
inherit SKILL;

string type() { return "knowledge"; }

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
        if( (int)me->query_skill("spells") <= (int)me->query_skill("mo") )
        return notify_fail("你的法术修为还不够高深，无法学习天魔大法。\n");
        return 1;
}

string cast_spell_file(string spell)
{
        return CLASS_D("yaomo") + "/mo/" + spell;
}


