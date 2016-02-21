// garrison.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("方玉飞", ({ "fang", "fangyufei" }) );
        set("long",
"银鹞子方玉飞是银钩赌坊大老板的小舅子，吃喝嫖赌样样精通\n");
        set("attitude", "heroism");
	set("title", HIW "银鹞子" NOR);
        set("str", 27);
        set("cor", 26);
        set("cps", 25);
	set("per", 30);
        set("combat_exp", 100000);

        set_skill("unarmed", 70+random(100));
        set_skill("sword", 70+random(100));
        set_skill("parry", 70+random(100));
        set_skill("dodge", 70+random(100));
        set_skill("move", 100+random(100));

        set_temp("apply/attack", 70);
        set_temp("apply/defense", 70);
        set_temp("apply/damage", 30);
        set_temp("apply/armor", 70);
        set_temp("apply/move", 100);

        setup();

        carry_object(__DIR__"obj/yincloth")->wear();
}
