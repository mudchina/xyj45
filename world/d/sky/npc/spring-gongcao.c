// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// 春值功曹
//created 4-8-97 pickle
inherit NPC;
 
void create()
{
        set_name("年值功曹", ({ "nianzhi gongcao", "nian", "year",
"gongcao" }) );
        set("gender", "男性" );
        set("long","
四值功曹乃是托塔李天王帐前猛将。因经验不足而
出战失利，被罚为巡逻官。四人因志同道合而结为
金兰兄弟。年值功曹乃是大哥，一身道家功夫非同
小可。\n"
        );
        set("age",41);
        set("str",28);
        set("int",25);
        set("max_kee",1100);
        set("kee",1100);
        set("max_sen",1000);
        set("sen",1000);
        set("combat_exp",580000);
        set("force",1500);
        set("max_force",1000);
        set("mana",1700);
        set("max_mana",1000);
        set("force_factor", 60);
        set("mana_factor", 50);

        set("eff_dx", 220000);
        set("nkgain", 350);

        set_skill("unarmed",120);
        set_skill("parry",120);
        set_skill("dodge",110);
        set_skill("stick",110);
        set_skill("qianjun-bang",100);
        set_skill("force",120);
   set_skill("puti-zhi", 100);
   set_skill("moshenbu", 110);
   set_skill("spells", 100);
   map_skill("unarmed", "puti-zhi");
   map_skill("dodge", "moshenbu");
   map_skill("stick", "qianjun-bang");
        map_skill("parry","qianjun-bang");
        set("inquiry", ([
                "name" : "在下就是年值功曹，乃托塔天王帐前大将。",
                "here" : "这里就是天宫。下官奉天王将令，在此巡查。",
        ]) );
        setup();
        carry_object("/d/obj/weapon/stick/wuchangbang")->wield();
        carry_object("/d/obj/armor/yinjia")->wear();
}
