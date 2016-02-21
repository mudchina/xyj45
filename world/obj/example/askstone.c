#include <ansi.h>
#include <combat.h>

inherit ITEM;

void create()
{
	set_name("问路石" , ({ "askstone" }) );
        set_weight(600);
        set("unit", "块");
        set("long", "这是一块载有绝世神通，有问必答的易筋石．\n");
        set("value", 0);
}

void init()
{
        add_action("askabout", "askabout");
}
int askabout ( string arg)
{
        object me, weapon;
        mapping my;
        string thing, skill_type, parry_type, who, shifo;
	int attackp, dodgep, parryp;

        if(!arg) return notify_fail("Usage: askabout thing of who\n");
        if( sscanf(arg, "%s of %s", thing, who)==2);
        else return notify_fail("Usage: askabout thing of who\n");
	me = present(who, environment(this_player()));
        if(!objectp(me)) return notify_fail("No such person!\n");
	switch(thing) {
        case "self":
       		my = me->query_entire_dbase();
        	printf( BOLD "%s" NOR "%s\n\n", RANK_D->query_rank(me), me->short(1));
		shifo = "";
        	if( mapp(my["family"]) ) {
                	if( my["family"]["master_name"] )
                        	shifo = sprintf("%s",my["family"]["master_name"] );
	        }
        	printf(
		" 年龄：[%d]     经验：[%d]     杀气：[%d]     师父：%s\n"
                " 膂力：[%d,%d]  胆识：[%d,%d]  悟性：[%d,%d]  灵性：[%d,%d]\n"
                " 定力：[%d,%d]  容貌：[%d,%d]  根骨：[%d,%d]  福缘：[%d,%d]\n\n",
		me->query("age"),
		me->query("combat_exp"),
		me->query("bellicosity"),
		shifo,
                my["str"], me->query_str(),
                my["cor"], me->query_cor(),
                my["int"], me->query_int(),
                my["spi"], me->query_spi(),
                my["cps"], me->query_cps(),
                my["per"], me->query_per(),
                my["con"], me->query_con(),
                my["kar"], me->query_kar());
		break;
        case "power":
	        if( objectp(weapon = me->query_temp("weapon")) ) {
       	        	skill_type = weapon->query("skill_type");
                	parry_type = "parry";
        	}
        	else {
                	skill_type = "unarmed";
                	parry_type = "unarmed";
        	}
		attackp = COMBAT_D->skill_power(me, skill_type, SKILL_USAGE_ATTACK);   
        	dodgep = COMBAT_D->skill_power(me, "dodge", SKILL_USAGE_DEFENSE);
        	parryp = COMBAT_D->skill_power(me, parry_type, SKILL_USAGE_DEFENSE);
		printf("攻击力：%d\t躲闪力：%d\n招架力：%d\n",
			attackp, dodgep, parryp);
		break;
        default:
		printf("What are you asking for??\n");
        }
        return 1;
}

