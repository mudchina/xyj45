// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;

void create()
{
        set_name("杏仙", ({"xing xian", "xian"}));
        set("long",
"她青姿装翡翠，丹脸赛胭脂，星眼光还彩，蛾眉秀又齐。\n");
        set("age", 20);
   set("attitude", "friendly");
        set("gender", "女性");
   set("class", "yaomo");
   set("nickname", "天台妲姬");
        set("str", 20);
        set("int", 20);
        set("per", 30);
        set("con", 20);
        set("max_kee",900);
        set("max_sen", 900);
        set("combat_exp", 400000);

   set("eff_dx", -150000);
        set("nkgain", 400);

        set("force", 500);
        set("max_force", 500);
        set("mana",400);
        set("max_mana", 400);
        set("force_factor", 40);
        set("mana_factor", 30);
        set_skill("unarmed", 100);
        set_skill("force", 100);
        set_skill("dodge", 100);
   set_skill("sword", 100);
   set_skill("parry", 100);
   set_skill("snowsword", 80);
   set_skill("moondance", 80);
   set_skill("baihua-zhang", 80);
   set_skill("spells", 100);
   map_skill("sword", "snowsword");
   map_skill("parry", "snowsword");
   map_skill("dodge", "moondance");
   map_skill("unarmed", "baihua-zhang");
        setup();

   carry_object("/d/qujing/jingjiling/obj/xingzhi")->wield();
   carry_object("/d/qujing/jingjiling/obj/armor")->wear();
   carry_object("/d/obj/cloth/pinkskirt")->wear();
}
