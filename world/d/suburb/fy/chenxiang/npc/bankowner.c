// banker.c

#include <ansi.h>

inherit NPC;
inherit F_BANKOWNER;
void create()
{
        set_name("南宫十三", ({ "nangong" }) );
        set("title", RED "钱庄掌柜" NOR);
        set("gender", "男性" );
        set("age", 52);
        set("long",
                
                "中原南宫世家，家财万贯，产业不可胜数，南宫十三也是南宫世家
的族人\n");

        set("attitude", "friendly");

        set("max_atman", 1000);         set("atman", 1000);             
set("atman_factor", 3);
        set("max_force", 1000);         set("force", 1000);             
set("force_factor", 3);
        set("max_mana", 1000);          set("mana", 1000);              
set("mana_factor", 3);

        set_skill("dodge", 10);
	set_skill("parry",100);
        setup();
        carry_object("/obj/cloth")->wear();

        add_money("gold", 1);
}

void init()
{
	::init();
        add_action("do_convert", "convert");
        add_action("do_deposit", "deposit");
        add_action("do_balance", "balance");
        add_action("do_withdraw", "withdraw");
	add_action("do_loan","loan");
}
