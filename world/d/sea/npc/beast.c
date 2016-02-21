// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 

inherit NPC;
string *first_name = ({ "花皮", "背苍", "八爪金角", "金尾虬髯"});
string *name_words = ({ "龙"});


void create()
{
        string name;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];


        set_name(name,({"dragon"}));


   set("race", "野兽");
        set("long", "一只模样高大，极有气势的龙。\n");
        set("str", 40);
        set("cor", 30);
        set("con", 30);
        set("cps", 30);
        set("spi", 30);
        set("int", 30);
        set_temp("apply/damage", 25);
        set_temp("apply/armor", 50);
        set("max_kee", 800);
        set("max_sen", 800);
        set("force", 1000);
        set("max_force", 500);
        set("force_factor", 25);
        set("mana", 1000);
        set("max_mana", 500);
        set("mana_factor", 25);
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("dragonfight", 50);
        set_skill("dragonstep", 50);
        map_skill("unarmed", "dragonfight");
        map_skill("dodge", "dragonstep");
        set("combat_exp", 100000);
        set("limbs", ({ "头部", "身体", "前爪", "尾巴", "肚皮", "后爪"}) );
        set("verbs", ({ "bite", "claw"}) );
        set_weight(500000);
   set("bellicosity",1000);

   setup();
}
void init()
{
        ::init();
        add_action("do_train", "train");
}

int do_train()
{
   object me,who;
   me =this_object();
   who=this_player();

   if(me->is_fighting())
     return notify_fail("这只龙正在战斗。\n");
   if((string)who->query("family/family_name")!="东海龙宫")
     return notify_fail("什么？\n");
   
   call_out("reset_skill",1,who);

   message_vision("$N对$n大喊一声：孽畜，看你猖狂到几时！\n\n", who,me);
   message_vision("$n一生长吟，扑上来和$n扭打到一起。\n",me,who);
   me->kill_ob(who);
   who->kill_ob(me);
        COMBAT_D->do_attack(me, who, query_temp("weapon"));
   me->set("owner",who->query("id"));
   return 1;
}

int reset_skill(object who)
{
   object me=this_object();
   int exp,i;
   exp=(int)who->query("combat_exp");


        if( exp > 1000000) {  
                i=190;
        }else if( exp >900000){
                i=180;
        }else if( exp >800000){
                i=170;
        }else if( exp >700000){
                i=160;
        }else if( exp >600000){
                i=150;
        }else if( exp >500000){
                i=140;   
        }else if( exp >400000){
                i=130;
        }else if( exp >300000){
                i=120;
        }else if( exp >200000){
                i=110;
        }else if( exp >100000){
                i=100;
        }else if( exp >90000){
                i=90;
        }else if( exp >80000){
                i=80;
        }else if( exp >70000){ 
                i=70;
        }else if( exp >60000){
                i=60;
        }else if( exp >50000){
                i=50;
        }else{
      i=50;
   }
   me->set("combat_exp", (int)who->query("combat_exp")*12/10);
   me->set_skill("dodge", i+random(10));
        me->set_skill("parry", i+random(10));
        me->set_skill("unarmed", i+random(10));
        me->set_skill("dragonfight", i+random(10));
        me->set_skill("dragonstep", i+random(10));
   me->set("force_factor", i/3);
  me->set("eff_sen", (int)me->query("max_sen"));
  me->set("sen", (int)me->query("max_sen"));
  me->set("eff_gin", (int)me->query("max_gin"));
  me->set("gin", (int)me->query("max_gin"));
  me->set("eff_kee", (int)me->query("max_kee"));
  me->set("kee", (int)me->query("max_kee"));



   return 1;
}

void die()
{
   string owner;
   object owner_ob;

   owner = query("owner");
   if(owner) owner_ob= find_player(owner);

   if(owner_ob &&  (object)query_temp("last_damage_from") == owner_ob ) {
     if( (int)owner_ob->query_skill("seashentong",1) <=180 
     && (int)owner_ob->query_skill("spells",1) <=180 ) {
     tell_object(owner_ob, "\n你驯服了恶龙，并且从中悟到了一些咒术的道理。\n");
     owner_ob->improve_skill("spells", random(owner_ob->query("spi"))+1);
     owner_ob->improve_skill("seashentong", random(owner_ob->query("spi"))+1);
     owner_ob->set_temp("dragonforce_practice", owner_ob->query("spi")*5);
     message_vision("$N低头缩尾，以示降服。\n",this_object());
     destruct(this_object());
     return;
     }
   }
   ::die();
}
