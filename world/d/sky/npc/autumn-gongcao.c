// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// 秋值功曹
//created 4-8-97 pickle
inherit NPC;
 
void create()
{
        set_name("日值功曹", ({ "rizhi gongcao", "ri", "day",
"gongcao" }) );
        set("gender", "男性" );
        set("long","
四值功曹乃是托塔李天王帐前猛将。因经验不足而
出战失利，被罚为巡逻官。四人因志同道合而结为
金兰兄弟。日值功曹是老三，入天宫前在地府充当
勾魂使者，所以他作战经验远在老大和老二之上。\n"
        );
        set("age",35);
        set("str",28);
        set("int",28);
        set("max_kee",1100);
        set("kee",1100);
        set("max_sen",800);
        set("sen",800);
        set("combat_exp",650000);
        set("force",1200);
        set("max_force",1000);
        set("mana",1500);
        set("max_mana",1000);
        set("force_factor", 60);
        set("mana_factor", 60);

        set("eff_dx", 250000);
        set("nkgain", 350);
   
   set_skill("spells", 100);
        set_skill("unarmed",120);
        set_skill("parry",120);
        set_skill("dodge",110);
        set_skill("stick",110);
        set_skill("kusang-bang",110);
   set_skill("moshenbu", 110);
        set_skill("force",120);
        set_skill("jinghun-zhang",100);
   map_skill("dodge", "moshenbu");
   map_skill("unarmed", "jinghun-zhang");
        map_skill("parry","kusang-bang");
   map_skill("stick", "kusang-bang");
        set("inquiry", ([
                "name" : "在下就是日值功曹，乃托塔天王帐前大将。",
                "here" : "这里就是天宫。下官奉天王将令，在此巡查。",
        ]) );
        setup();
        carry_object("/d/obj/weapon/stick/wuchangbang")->wield();
        carry_object("/d/obj/armor/yinjia")->wear();
}
