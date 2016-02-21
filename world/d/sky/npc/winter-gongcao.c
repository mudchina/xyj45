// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// 冬值功曹
//created 4-8-97 pickle
inherit NPC;
 
void create()
{
        set_name("时值功曹", ({ "shizhi gongcao", "shi", "hour",
"gongcao" }) );
        set("gender", "男性" );
        set("long","
四值功曹乃是托塔李天王帐前猛将。因经验不足而
出战失利，被罚为巡逻官。四人因志同道合而结为
金兰兄弟。时值功曹排行老么，身份最是神秘。他
功夫在众兄弟中最高，但最缺乏经验。\n"
        );
        set("age",35);
        set("str",25);
        set("int",25);
        set("max_kee",1000);
        set("kee",1000);
        set("max_sen",1000);
        set("sen",1000);
        set("combat_exp",490000);
        set("force",1000);
        set("max_force",800);
        set("mana",1500);
        set("max_mana",900);
        set("force_factor", 50);
        set("mana_factor", 50);

        set("eff_dx", 200000);
        set("nkgain", 300);

        set_skill("unarmed",110);
        set_skill("parry",100);
        set_skill("dodge",100);
        set_skill("spear",100);
        set_skill("bawang-qiang",100);
   set_skill("moshenbu", 100);
        set_skill("force",100);
   set_skill("spells", 100);
        set_skill("dragonfight",90);
   map_skill("unarmed", "dragonfight");
   map_skill("dodge", "moshenbu");
   map_skill("spear", "bawang-qiang");
        map_skill("parry","bawang-qiang");
        set("inquiry", ([
                "name" : "在下就是时值功曹，乃托塔天王帐前大将。",
                "here" : "这里就是天宫。下官奉天王将令，在此巡查。",
        ]) );
        setup();
        carry_object("/d/obj/weapon/spear/biyuqiang")->wield();
        carry_object("/d/obj/armor/yinjia")->wear();
}
