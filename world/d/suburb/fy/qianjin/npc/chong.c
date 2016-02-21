
inherit NPC;

void create()
{
        set_name("萤火虫", ({ "cong" }) );
        set("race", "野兽");
        set("age", 1);
        set("long", "一只亮晶晶的萤火虫\n");
        set("max_kee", 1);
        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" }) );

        set_skill("dodge", 200);

        setup();
}

