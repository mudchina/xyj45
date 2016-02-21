// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 

inherit NPC;

void create()
{
        set_name("寅将军", ({ "yin jiangjun", "yin", "jiangjun" }));
        set("gender", "男性");
        set("age", 35);
        set("str", 30);
   set("per", 10);
   set("long", "雄威身凛凛，猛气貌堂堂，电目飞光艳，雷声震四方。
锯牙舒口外，凿齿露腮旁，锦绣围身体，文斑露脊梁。
钢须稀见肉，钩爪利如霜，东海黄公俱，南山白额王。\n");
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
        carry_object("/d/westway/obj/pao1")->wear();
}

int accept_fight(object me)
{
   object xiong=present("xiong shanjun", environment(this_object()));
   object niu=present("te chushi", environment(this_object()));

   if(xiong){
     xiong->kill_ob(me);
   }
   if(niu){
     niu->kill_ob(me);
   }
   kill_ob(me);
   return 1;

}
void accept_kill(object me)
{
        object xiong=present("xiong shanjun", environment(this_object()));
        object niu=present("te chushi", environment(this_object()));
 
        if(xiong){
                xiong->kill_ob(me);
        }
        if(niu){
                niu->kill_ob(me);
        }
        return;

}

