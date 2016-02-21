// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// 夏值功曹
//created 4-8-97 pickle
inherit NPC;
 
void create()
{
        set_name("月值功曹", ({ "yuezhi gongcao", "yue", "month",
"gongcao" }) );
        set("gender", "男性" );
        set("long","
四值功曹乃是托塔李天王帐前猛将。因经验不足而
出战失利，被罚为巡逻官。四人因为志同道合结为
金兰兄弟。月值功曹排行老二。他出师月宫，一手
灵活的雪山剑法，且在百花掌上有极深的造旨。\n"
        );
        set("age",38);
        set("str",20);
        set("int",30);
        set("max_kee",1050);
        set("kee",1050);
        set("max_sen",900);
        set("sen",900);
        set("combat_exp",550000);
        set("force",1500);
        set("max_force",900);
        set("mana",1450);
        set("max_mana",850);
        set("force_factor", 60);
        set("mana_factor", 50);

        set("eff_dx", 200000);
        set("nkgain", 340);

        set_skill("unarmed",110);
        set_skill("parry",100);
        set_skill("dodge",100);
        set_skill("sword",110);
        set_skill("snowsword",115);
        set_skill("force",100);
   set_skill("moshenbu", 110);
   set_skill("baihua-zhang", 90);
   set_skill("spells", 100);
   map_skill("unarmed", "baihua-zhang");
   map_skill("dodge", "moshenbu");
        map_skill("parry","snowsword");
   map_skill("sword", "snowsword");
        set("inquiry", ([
                "name" : "在下就是月值功曹，乃托塔天王帐前大将。",
                "here" : "这里就是天宫。下官奉天王将令，在此巡查。",
        ]) );
        setup();
        carry_object("/d/obj/weapon/sword/qingfeng")->wield();
        carry_object("/d/obj/armor/yinjia")->wear();
}
