// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// liu-yuanshuai.c

inherit NPC;

void create()
{
        set_name("流元帅", ({"liu yuanshuai","liu","yuanshuai","hou","mahou"}));
        set("gender", "男性" );
        set("age", 45);
        set("long", "一只身强体壮的大马猴。\n");
        set("combat_exp", 90000);
        set("attitude", "peaceful");
        set("str",40);
        set_skill("unarmed", 80);
        set_skill("dodge", 110);
        set_skill("parry", 80);
        set_skill("force", 50);   
        set("per", 10);
        set("max_kee", 600);
        set("max_gin", 100);
        set("max_sen", 300);
        set("max_force", 400);
        set("force",400);
        set("max_mana",200);
        set("mana",200);
        set("force_factor", 20);
        setup();
}

int accept_fight(object me)
{
        return 0;
}

