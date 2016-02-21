// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// huguo-tianwang.c
//created 4-8-97 pickle
inherit NPC;
 
void create()
{
        set_name("魔礼山", ({ "huguo tianwang", "huguo", "tianwang", "wang" }) );
        set("gender", "男性" );
        set("long","
护国天王身担着保护后宫安全的重担，非同小可。他的武功
似乎属佛门一派，但除轮回杖法之外，护国天王还有另外的
杀手绝招，但没有人知道是什么。也许正因为如此，玉皇才
放心让他独担重任。\n"
        );
   set("class", "xian");
   set("title", "护国天王");
        set("age",43);
        set("str",30);
        set("int",37);
        set("max_kee",1200);
        set("kee",1100);
        set("max_sen",1100);
        set("sen",1100);
        set("combat_exp",1000000);
        set("force",2500);
        set("max_force",1500);
        set("mana",2500);
        set("max_mana",1500);
        set("force_factor", 70);
        set("mana_factor",80);

        set("eff_dx", 450000);
        set("nkgain", 450);

        set_skill("unarmed",140);
   set_skill("changquan", 150);
        set_skill("parry",140);
        set_skill("dodge",150);
        set_skill("staff",150);
   set_skill("spells", 140);
        set_skill("lunhui-zhang",150);
        set_skill("force",140);
   set_skill("moshenbu", 150);
   map_skill("dodge", "moshenbu");
        map_skill("staff","lunhui-zhang");
        map_skill("parry","lunhui-zhang");
   map_skill("unarmed", "changquan");
        set("inquiry", ([
                "name" : "在下就是护国天王，奉圣谕把守北天门。",
                "here" : "这里就是北天门，里面是后宫禁地。",
        ]) );
        setup();
        carry_object("/d/obj/weapon/staff/budd_staff")->wield();
        carry_object("/d/obj/armor/jinjia")->wear();
}
