
inherit NPC;

void create()
{
        set_name("郭嵩阳", ({ "guo", "yang"}) );
        set("gender", "男性" );
        set("age", 32);
        set("long", "这是一位兵器谱上有名的高手，但他现在没剑．．．\n");
	set("title", "嵩阳铁剑");
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set_skill("unarmed", 90);
	set_skill("dodge", 100);
	setup();
        carry_object(__DIR__"obj/jinzhuang")->wear();
}

