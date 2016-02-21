// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// gargoyle.c

#include <ansi.h>
#include <login.h>

inherit NPC;
inherit F_MASTER;
string *death_msg = ({
        HIB "黑无常说道：喂！新来的，你叫什么名字？\n\n" NOR,
        HIB "黑无常用奇异的眼光盯着你，好像要看穿你的一切似的。\n\n" NOR,
        HIB "黑无常「哼」的一声，从袖中掏出一本像帐册的东西翻看著。\n\n" NOR,
        HIB "黑无常合上册子，说道：咦？阳寿未尽？怎么可能？\n\n" NOR,
        HIB "黑无常搔了搔头，叹道：罢了罢了，你走吧。\n\n"
                "一股阴冷的浓雾突然出现，很快地包围了你。\n\n" NOR,
});

void create()
{
        set_name("黑无常", ({ "black gargoyle", "gargoyle" }) );
        set("long",

"黑无常伸着长长的舌头瞪着你，黝黑的脸上看不出任何喜怒哀乐。\n");
        set("attitude", "peaceful");
        set("chat_chance", 10);
        set("chat_msg", ({

"黑无常发出一阵像呻吟的声音，当他发现你正注视着他的时候，瞪了你一眼。\n",

"黑无常把长长的舌头伸出来，缓缓地舔了舔自己又黑又长的手指。\n"
        }) );
   set("per", 100);
   set("str", 25);
   set("int", 20);
        set("age", 217);
   set("class", "youling");
        set("combat_exp", 120000);
        set("max_kee", 800);
        set("max_sen", 800);
   set("max_gin", 400);
   set("force", 500);
   set("max_force", 500);
   set("force_factor", 20);
   set("max_mana", 500);
   set("mana", 500);
   set("mana_factor", 30);
        set("title", "送魂使者");
        set_temp("apply/damage", 10);
        set_skill("ghost-steps", 70);
        set_skill("dodge", 70);
        set_skill("unarmed", 80);
        set_skill("parry", 70);
     set_skill("kusang-bang", 70);
        set_skill("spells", 70);
        set_skill("gouhunshu", 70);
        set_skill("force", 70);
        set_skill("stick", 70);
        set_skill("tonsillit", 70);
        set_skill("jinghun-zhang", 80);
        map_skill("spells", "gouhunshu");
        map_skill("dodge", "ghost-steps");
        map_skill("force", "tonsillit");
   map_skill("stick", "kusang-bang");
   map_skill("parry", "kusang-bang");
        map_skill("unarmed", "jinghun-zhang");
   create_family("阎罗地府", 3, "你好");
        setup();
   carry_object("/d/obj/cloth/hei")->wear();
}

void init()
{
        ::init();
        if( !previous_object()
        ||      !userp(previous_object()) )
                return;
        call_out( "death_stage", 5, previous_object(), 0 );
}

void death_stage(object ob, int stage)
{
        if( !ob || !present(ob) ) return;

        if( !ob->is_ghost()) {
     if( visible(ob)&&(string)ob->query("family/family_name")!="阎罗地府" ){
                   command("say 喂！阳人来阴间做什么？难道是活的厌倦了吗？\n");
                   kill_ob(ob);
                    ob->fight_ob(this_object());
                   return;
           }
     return;
   }

        if ((int)ob->query("max_gin") <= 0 ||
            (int)ob->query("max_kee") <= 0 ||
            (int)ob->query("max_sen") <= 0)
                return;

        tell_object(ob, death_msg[stage]);
        if( ++stage < sizeof(death_msg) ) {
                call_out( "death_stage", 5, ob, stage );
                return;
        } else
                ob->reincarnate();
     ob->set("gin", (int)ob->query("max_gin"));
        ob->move(REVIVE_ROOM);
        message("vision",
                "你忽然发现前面多了一个人影，不过那人影又好像已经在那里\n"
                "很久了，只是你一直没发觉。\n", environment(ob), ob);
}
void attempt_apprentice()
{       object me;
        me = this_player();
        if ( (string)me->query("family/family_name")=="阎罗地府") {
        if (((int)me->query("combat_exp") < 10000 )) {
        command("say " + RANK_D->query_rude(me) + "的心还不够黑，老夫不屑收你！\n");
        return;
        }
        command("grin");
        if(me->is_ghost() ){
        me->reincarnate();
   me->set("gin", (int)me->query("max_gin"));
        }
        command("say 很好，" + RANK_D->query_respect(me) +
"多加努力，他日必定有成。\n");
       command("recruit " + me->query("id") );
        return;
        }
        command("shake");
        command("say " + RANK_D->query_rude(me) +
"还是先去学些基础功夫吧！\n");
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "youling");
}


