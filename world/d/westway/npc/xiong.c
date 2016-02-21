// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 

inherit NPC;

void create()
{
        set_name("熊山君", ({ "xiong shanjun", "xiong", "shanjun" }));
        set("gender", "男性");
        set("age", 35);
        set("str", 30);
   set("per", 10);
   set("long", "雄豪多胆量，轻健夯身躯，涉水唯凶力，跑林逞怒威。
向来符吉梦，今独露英姿，绿树能攀折，知寒善御时。
准灵惟显处，故此号山君。\n");
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
        carry_object("/d/westway/obj/pao2")->wear();
}

int accept_fight(object me)
{
        object yin=present("yin jiangjun", environment(this_object()));
        object niu=present("te chushi", environment(this_object()));

        if(yin){
                yin->kill_ob(me);
        }
        if(niu){
                niu->kill_ob(me);
        }
        kill_ob(me);
        return 1;

}
void accept_kill(object me)
{
        object yin=present("yin jiangjun", environment(this_object()));
        object niu=present("te chushi", environment(this_object()));
 
        if(yin){
                yin->kill_ob(me);
        }
        if(niu){
                niu->kill_ob(me);
        }
        return;

}

