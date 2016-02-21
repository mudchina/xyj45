// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;
int waiting(object me);
int checking(object me);

void create()
{
        set_name("魔礼红", ({ "mo lihong","mo", "guangmu", "tianwang", "wang" }) );
        set("gender", "男性" );
   set("title", "广目天王");
        set("long","广目天王喜动不喜静，不愿在天上守门。
玉帝便派他巡游四方，保卫众仙家安全。\n");
        set("age",40);
        set("str",30);
        set("int",25);

        set("max_kee",900);
        set("kee",900);
        set("max_sen",900);
        set("sen",900);
        set("combat_exp",900000);

        set("force",800);
        set("max_force",800);
        set("mana",600);
        set("max_mana",600);

        set("force_factor", 60);
        set("mana_factor",50);

        set_skill("unarmed",100);
        set_skill("parry",120);
        set_skill("dodge",120);
        set_skill("spear",120);
        set_skill("bawang-qiang", 120);
        set_skill("force",120);
   set_skill("moshenbu", 120);

   map_skill("dodge", "moshenbu");
        map_skill("spear","bawang-qiang");
        map_skill("parry","bawang-qiang");
        setup();
        carry_object("/d/obj/weapon/spear/jinqiang")->wield();
        carry_object("/d/obj/armor/jinjia")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                   remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
   object me;
   me=this_object();

        if( !ob || environment(ob) != environment() ) 
     return;
   if( (string)ob->query("id") == (string)me->query("revenge_target")){
     command("say 大胆" + ob->query("name") + "，胆敢谋害仙家，那里跑！\n");
     this_object()->kill_ob(ob);
     set_leader(ob);
     ob->fihgt_ob(this_object());
     call_out("checking", 0, me);
   }
   else
     call_out("waiting", 1, me);
   return;
}
int waiting(object me)
{
        object killer;
        killer = find_player(me->query("revenge_target"));

        if ( objectp(killer) )
        {
                if (killer->is_ghost())
                {
                        me->delete("revenge_target");
                        call_out("do_back", 1, me);
                        return 1;
                }else if (me->is_fighting() && present(killer, environment(me)))
                {
                        call_out("checking", 0, me);
                        return 1;
                }else if (living(me) && !environment(killer)->query("no_fight"))
                {
                        call_out("do_back", 1, me);
                        return 1;
                }
        }

        remove_call_out("waiting");
        call_out("waiting", 60, me);
    return 1;
}

int checking(object me)
{
        object ob;

        if (me->is_fighting()) 
        {
                call_out("checking", 1, me);
        return 1;
        }

        if( objectp(ob = present("corpse", environment(me)))
                 && ob->query("victim_name") == me->query("revenge_name") )
        {
                me->delete("waiting_target");
                call_out("do_back", 1, me);
        return 1;
        }

        call_out("waiting", 0, me);
        return 1;
}
int do_back(object me)
{
   message_vision("$N愤愤的哼了一声道：下次别让老子逮到！\n", me);
        return 1;
}

