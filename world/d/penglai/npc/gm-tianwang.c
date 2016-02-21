// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;

void create()
{
        set_name("魔礼红", ({ "guangmu tianwang","guangmu", "tianwang" }) );
        set("gender", "男性" );
   set("title", "广目天王");
        set("long","广目天王喜动不喜静，不愿在天上守门。
玉帝便派他巡游四方，保卫众仙家安全。\n");
        set("age",40);
        set("str",30);
        set("int",25);
   set("class", "xian");
        set("max_kee",1500);
        set("kee",1500);
        set("max_sen",1000);
        set("sen",1000);
        set("combat_exp",900000);

        set("force",3000);
        set("max_force",1500);
        set("mana",3000);
        set("max_mana",1500);

        set("force_factor", 100);
        set("mana_factor",70);

        set_skill("unarmed",150);
        set_skill("parry",150);
        set_skill("dodge",150);
        set_skill("spear",150);
        set_skill("bawang-qiang", 150);
        set_skill("force",150);
   set_skill("spells", 150);
   set_skill("moshenbu", 150);

   map_skill("dodge", "moshenbu");
        map_skill("spear","bawang-qiang");
        map_skill("parry","bawang-qiang");
        setup();
        carry_object("/d/obj/weapon/spear/jinqiang")->wield();
        carry_object("/d/obj/armor/jinjia")->wear();
}
