// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;

void create()
{
       set_name("索命鬼", ({"suoming gui", "gui"}));
       set("gender", "男性");
       set("age", 30);
   set("long", "一个青面獠牙的小鬼，身穿兽皮，手持铁链．
他的任务就是从阳间将死人的魂魄带回．\n");
       set("attitude", "peaceful");
       set("shen_type", 1);
       set("per", 10);
       set("combat_exp", 60000+random(30000));
   set("bellicosity", 300);
   set_skill("unarmed", 65);
   set_skill("dodge", 65);
   set_skill("whip", 65);
   set_skill("parry", 45);
   set("force", 300);
   set("max_force", 300);
   set("force_factor", 15);
   set("max_kee", 450);
set("inquiry", ([
"here": "这就是阴曹地府，哼，等着剥皮抽筋吧你！\n",
]) );

set("chat_chance", 8);
set("chat_msg", ({
"索命鬼的上上下下打量了你几眼。\n",
"索命鬼说道：阎王叫你三更死，不敢留你到五更！\n",
(: random_move :)
}) );

setup();

        carry_object("/d/obj/cloth/shoupi")->wear();
        carry_object("/d/obj/weapon/whip/tielian")->wield();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
   
   if ((string)ob->query("family/family_name")!="阎罗地府") {
   if (random((int)ob->query("age")) > 20 ){
   command("tell " + ob->query("id") + " 阎王爷叫我来勾你的魂，你却自己送上门来，跟我走吧！\n");
   kill_ob(ob);
   set_leader(ob);
   return;
   }
   return;
   }
return;
}
return;
}

int accept_fight(object me)
{
        command("say 你活得不耐烦了？\n");
        kill_ob(me);
        return 1;
}

