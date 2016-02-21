// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;

void create()
{
        set_name("五爪金龙", ({ "golden dragon", "dragon" }) );
        set("race", "野兽");
        set("gender", "雄性");
        set("age", 100);
        set("long", "一只满身金甲的五爪金龙。\n");
        set("attitude", "peaceful");
        set("looking", "威风凛凛，气势逼人。");
        set("str", 40);
        set("con", 40);
        set("max_kee", 2000);
        set("max_sen", 2000);
   set("max_force", 1000);
   set("force", 1500);
   set("max_mana", 1000);
   set("mana", 1500);
   set("force_factor", 50);
   set("mana_factor", 50);
        set("limbs", ({ "头部", "身体", "前爪", "后爪", "尾巴"}) );
        set("verbs", ({ "bite", "claw"}) );
        set("combat_exp", 1400000);
   set("eff_dx", -500000);
   set("nkgain", 500);
        set_skill("dodge", 179);
        set_skill("parry", 179);
        set_skill("force", 179);
   set_skill("spells", 179);
        set_skill("unarmed", 179);
        set_temp("apply/damage", 40);
   set_temp("apply/armor", 60);   
   set_weight(5000000);
        setup();
}
void init()
{
        object ob;

        ::init();
        set("chat_chance", 5);
        set("chat_msg", ({
       "五爪金龙在半空中盘旋了几圈。\n",
            "五爪金龙发出一阵龙吟。\n",
        }) );
}


int heal_up()
{

        if( environment() && !is_fighting() ) {
                call_out("leave", 0);
                return 1;
        }
        return ::heal_up() + 1;
}

void leave()
{       object obj;
   this_object()->add("time", 1);
   if( (int)this_object()->query("time") < 6 )  return;

        message("vision",name() + "空中身形一变，又变成龙王模样。\n", environment(), this_object() );
                seteuid(getuid());
                obj=new("/d/qujing/bibotan/npc/longwang");
                obj->move(environment(this_object()));
        destruct(this_object());
}

