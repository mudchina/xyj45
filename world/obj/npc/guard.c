// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// hell_guard.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("护法夜叉", ({"yecha"}));
        set("long", "这是一位来自海底的守护神，专门担任护法之责。\n");
        set("attitude", "friendly");

        set("max_gin", 800);
        set("max_kee", 800);
        set("max_sen", 800);

        set("max_atman", 100);
        set("atman", 100);
        set("max_mana", 100);
        set("mana", 100);
   set("force", 500);
   set("max_force", 500);
   set("force_factor", 5);
        set("str", 40);
        set("cor", 30);
        set("cps", 25);

        set("combat_exp", 100000);


        set_skill("fork", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);

        setup();

        carry_object("/d/ourhome/obj/ironarmor")->wear();
        carry_object(__DIR__"obj/steel_fork")->wield();
}

int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
}

void leave()
{
        message("vision",
                HIB + name() +
"说道：末将奉法主召唤，现在已经完成护法任务，就此告辞！\n\n"
                + name() + "的身下涌出一股清泉，身影立时消失了．\n" NOR,
environment(),
                this_object() );
        destruct(this_object());
}

void invocation(object who)
{
        int i;
        object *enemy;

        message("vision",
                HIB
"一道水波从地底升起，波中出现一个手执钢叉、面目狰狞的夜叉。\n\n"
                + name() + "说道：末将奉法主召唤，特来护法！\n" NOR,
                environment(), this_object() );
        enemy = who->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        kill_ob(enemy[i]);
                        if( userp(enemy[i]) )
enemy[i]->fight_ob(this_object());
                        else enemy[i]->kill_ob(this_object());
                }
        }
        set_leader(who);
}

