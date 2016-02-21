// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;
string *first_name =
({"赤","红","黄","绿","青","蓝","紫","乌","黑","银","白","金","灰","金","木","水","火","土"});
string *name_words =({"兔","狐","龙","蛟","虎", "豹","马", 
"鹿","羊","蛇","獐","鸡","狗","狼","猿","猴","鼠","牛", "獬","燕","猪","蝠"});

string *last_words=({"鬼"}); 
void create()
{
         string name;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];
   name += last_words[random(sizeof(last_words))];
        set_name(name, ({ "ghost"}) );
        set("gender", "男性" );
        set("age",40);
        set("str", 30);
        set("int", 20);
        set("con", 30);
        set("spi", 20);
        set("per", 15);
        set("class", "ghost");
        set("attitude", "heroism");
        set("combat_exp", 500000);
        set("max_kee", 1000);
        set("max_sen", 1000);
        set("force",800);
        set("max_force",800);
        set("force_factor", 130);
        set("mana", 800);
        set("max_mana", 800);
        set("mana_factor", 40);
        set_skill("whip",150);
        set_skill("dodge",150);
        set_skill("parry",150);
   set_skill("hellfire-whip", 150);
   set_skill("ghost-steps",150);
   map_skill("dodge","ghost-steps");
   map_skill("parry", "hellfire-whip");
   map_skill("whip", "hellfire-whip");
   set("HellZhen", 2);
        setup();
        carry_object("/d/obj/armor/shoupi")->wear();
   carry_object("/d/obj/weapon/whip/tielian")->wield();
}

void invocation(object who)
{
   object me=this_object();
   COMBAT_D->do_attack(me, who, query_temp("weapon"));
   destruct(me);
}
