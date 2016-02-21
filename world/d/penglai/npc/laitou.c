// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;

void create()
{
        set_name("癞头和尚", ({"laitou heshang","heshang"}));
        set("long", "一位游方和尚，头上布满大大小小的伤疤。\n");

        set("gender", "男性");
        set("attitude", "peaceful");
        set("class", "bonze");
        set("age", 30);
        set("str", 25);
        set("int", 30);
   set("per", 15);
        set("con", 25);
   set("env/wimpy", 70);
        set("max_kee", 800);
        set("max_sen", 800);
   set("max_force", 500);
   set("force", 500);
   set("force_factor", 20);
   set("max_mana", 400);
   set("mana", 400);
   set("mana_factor", 20);
        set("combat_exp", 100000);

        set("chat_chance", 5);
        set("chat_msg", ({
   "癞头和尚不屑的说道：长安也不过如此景色吗，那里比得上仙境！\n",
                (: random_move :)
        }));
set("inquiry", ([
"仙境" : "海中有蓬莱，方丈，瀛洲三座仙岛，果是不凡！\n",
"蓬莱" : "我，我干吗要告诉你！\n",
"方丈" : "我，我干吗要告诉你！\n",
"瀛洲" : "我，我干吗要告诉你！\n",
]) );


        set_skill("force", 50);
        set_skill("unarmed", 50);
        set_skill("dodge", 79);
        set_skill("parry", 79);
   set_skill("staff", 50);
   set_skill("lotusforce", 50);
   set_skill("lunhui-zhang", 79);
   set_skill("jienan-zhi", 50);
   set_skill("lotusmove", 79);
   map_skill("dodge", "lotusmove");
   map_skill("unarmed", "jienan-zhi");
   map_skill("staff", "lunhui-zhang");
   map_skill("parry", "lunhui-zhang");
   map_skill("force", "lotusforce");
        setup();
   add_money("silver", 15);
        carry_object("/d/obj/cloth/sengyi")->wear();
   carry_object("/d/penglai/npc/obj/sengxie")->wear();
   carry_object("/d/obj/weapon/staff/chanzhang")->wield();
        setup();
}

