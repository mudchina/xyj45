// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// dog.c

inherit NPC;

void create()
{
        set_name("呼雷豹", ({"hulei bao", "hulei", "horse", "ma"}));
        set("race", "野兽");
        set("age", 20);

   set("combat_exp", 10000);
        set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
        set("verbs", ({ "bite"}));

   set("ride/msg", "骑");
        set("ride/dodge", 18);
        set_temp("apply/attack", 10);
        set_temp("apply/armor", 20);

        setup();
}

