// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//puti.c
inherit NPC;

void create()
{
       set_name("青衣小童", ({"xiao tong", "xiao", "tong"}));
       set("gender", "男性");
       set("age", 10);
       set("attitude", "peaceful");
       set("shen_type", 1);
       set("per", 30);
       set("combat_exp", 100);

setup();

//        carry_object("/d/lingtai/obj/pao")->wear();
//        carry_object("/d/lingtai/obj/shoe")->wear();
//        carry_object("/d/lingtai/obj/putibang")->wield();
}

