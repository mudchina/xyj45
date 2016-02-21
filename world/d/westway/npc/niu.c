// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 

inherit NPC;

void create()
{
        set_name("特处士", ({ "te chushi", "te", "chushi"}));
        set("gender", "男性");
        set("age", 35);
        set("str", 30);
   set("per", 10);
   set("long", "嵯峨双角冠，端肃耸肩背，性服青衣稳，蹄步多迟滞。
宗名父做牿，原号母称龇，能为田者功，因名特处士。\n");
        set("combat_exp", 490000);
        set("attitude", "peaceful");
        set_skill("unarmed", 140);
        set_skill("force", 140);
        set_skill("dodge", 140);
        set_skill("parry", 140);
   set_skill("parry", 140);
   set("max_kee", 1300);
   set("max_sen", 1300);
        set("force", 600); 
        set("max_force", 600);
        set("force_factor", 30);
   set("max_name", 600);
   set("mana", 600);
   set("mana_factor", 30);
   set_temp("apply/armor", 50);
        setup();
        carry_object("/d/westway/obj/pao3")->wear();
}
int accept_fight(object me)
{
        object xiong=present("xiong shanjun", environment(this_object()));
        object yin=present("yin jiangjun", environment(this_object()));

        if(xiong){
                xiong->kill_ob(me);
        }
        if(yin){
                yin->kill_ob(me);
        }
        kill_ob(me);
        return 1;

}
void accept_kill(object me)
{
        object xiong=present("xiong shanjun", environment(this_object()));
        object yin=present("yin jiangjun", environment(this_object()));
 
        if(xiong){
                xiong->kill_ob(me);
        }
        if(yin){
                yin->kill_ob(me);
        }
        return;

}

