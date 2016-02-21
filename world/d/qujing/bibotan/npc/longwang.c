// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;

void create()
{
        set_name("万圣龙王", ({"wansheng longwang", "longwang", "long"}));
        set("long", "他是乱石山碧波潭的老龙王。\n");
        set("age", 68);
        set("attitude", "peaceful");
        set("gender", "男性");
   set("class", "dragon");
        set("str", 30);
        set("int", 30);
        set("per", 10);
        set("con", 30);
        set("max_kee",1000);
        set("max_sen", 1000);
        set("combat_exp", 700000);
        set("force", 1000);
        set("max_force", 1000);
        set("mana", 800);
        set("max_mana", 800);
        set("force_factor", 40);
        set("mana_factor", 40);
        set_skill("unarmed", 100);
        set_skill("parry", 100);
   set_skill("force", 100);
   set_skill("spells", 100);
        set_skill("dodge", 100);
        set_skill("dragonfight", 100);
        set_skill("dragonstep", 100);
        map_skill("unarmed", "dragonfight");
        map_skill("dodge", "dragonstep");
        setup();
        carry_object("/d/sea/obj/longpao")->wear();

}

void unconcious()
{
        object me,obj;   
        if( !me = query_temp("last_damage_from") )
     me= this_player(1);
        if( environment() ) {
        message("sound", "\n\n万圣龙王怒道：你竟敢欺人太甚！\n\n", environment());
        message("sound", "\n万圣龙王半空中一转，现了真身！竟是一条五爪金龙！\n\n", environment());
                seteuid(getuid());
                obj=new("/d/qujing/bibotan/npc/dragon"); 
                obj->move(environment(me));
     obj->kill_ob(me);
     me->fight_ob(obj);
        }

        destruct(this_object());
}

void die()
{
        object me,obj;

        if( !me = query_temp("last_damage_from") )
                me= this_player(1);
        if(environment() ) {
        message("sound", "\n\n万圣龙王怒道：你竟敢欺人太甚！\n\n", environment());
        message("sound", "\n万圣龙王半空中一转，现了真身！竟是一条五爪金龙！\n\n", environment());
                seteuid(getuid());
                obj=new("/d/qujing/bibotan/npc/dragon");
                obj->move(environment(me));
                obj->kill_ob(me);
                me->fight_ob(obj);
        }

        destruct(this_object());
}

