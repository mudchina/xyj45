// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// tian-jiang.c
#include <ansi.h>
inherit NPC;
string *first_name = ({ "赵老大","钱有福","孙大通","李元彪","周天浩","吴广度","郑如海","王四海"});

varargs void drool(string msg, string who);

void create()
{
        string name, id;

        name = first_name[random(sizeof(first_name))];

        set_name(name, ({ "tian jiang", "tian", "jiang" }) );
        set("gender", "男性" );
        set("long", 
                "能在这里混上个天将的位子肯定会有两下子。\n"
                "他细腰乍臂，双肩抱拢，一看就知武艺高强。\n"
        );
   set("title", "天将");
        set("age", 25+random(10));
        set("str", 30);
        set("int", 25);
        set("combat_exp",300000+random(200000));
        set("force",500);
        set("max_force",500);
   set("force_factor", 20);
   set("max_kee", 800);
   set("max_sen", 600);
   set("max_mana", 400);
   set("mana", 400);
   set("mana_factor", 20);
        set_skill("unarmed",89);
        set_skill("dodge",89);
        set_skill("parry",89);
        set_skill("spear",89);
   set_skill("force",80);
        setup();
        carry_object("/d/obj/armor/yinjia")->wear();
        carry_object("/d/obj/weapon/spear/tieqiang")->wield();
}

