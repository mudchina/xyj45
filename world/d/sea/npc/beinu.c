// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;
string *first_name = ({ "青", "黄", "白", "紫", "银", "金"});
string *name_words = ({ "贝宫女"});

void create()
{
   string name;
   name = first_name[random(sizeof(first_name))];
   name += name_words[random(sizeof(name_words))];

       set_name(name, ({"gong nu", "nu"}));
       set("gender", "女性");
       set("age", 20+random(5));
   set("long", "一个身后背有彩贝的宫女。\n");
   set("per", 30);
   set("str", 20);
       set("attitude", "heroism");
       set("shen_type", 1);
        set("combat_exp", 70000+random(10000));
        set_skill("parry", 70);
        set_skill("dodge", 70);
   set_skill("unarmed", 70);
   set_skill("force", 50);
   set_skill("spells", 50);
   set("force", 200);
   set("max_force", 200);
        set("force_factor",5);
   set("mana", 100);
   set("max_mana", 100);
   set("mana_factor", 10);
   set("max_kee", 800);
   set("max_sen", 400);
        setup();
        carry_object("/d/obj/cloth/skirt")->wear();
   carry_object("/d/sea/obj/bei")->wear();
}

