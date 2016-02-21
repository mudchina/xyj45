// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// gargoyle.c

#include <ansi.h>
#include <login.h>

inherit NPC;
inherit F_MASTER;
inherit F_CLEAN_UP;

string *death_msg = ({
        HIW "白无常说道：喂！新来的，你叫什么名字？\n\n" NOR,
        HIW "白无常用奇异的眼光盯着你，好像要看穿你的一切似的。\n\n" NOR,
        HIW "白无常「哼」的一声，从袖中掏出一本像帐册的东西翻看着。\n\n" NOR,
        HIW "白无常合上册子，说道：咦？阳寿未尽？怎么可能？\n\n" NOR,
        HIW "白无常搔了搔头，叹道：罢了罢了，你走吧。\n\n"
                "一股阴冷的浓雾突然出现，很快地包围了你。\n\n" NOR,
});

void create()
{
        set_name("白无常", ({ "white gargoyle", "gargoyle" }));
        set("long",
"白无常伸着长长的舌头瞪着你，死白的脸上看不出任何喜怒哀乐。\n");
        set("attitude", "peaceful");
set("chat_chance", 15);
set("chat_msg", ({
"白无常发出一阵像呻吟的声音，当他发现你正注视着他的时候，瞪了你一眼。\n",

"白无常把长长的舌头伸出来，缓缓地舔了舔自己又白又长的手指。\n"
        }) );
   set("per", 100);
   set("str", 20);
   set("int", 20);
        set("age", 217);
   set("title", "迎魂使者");
        set("combat_exp", 100000);
        set("max_gin", 600);
        set("max_kee", 700);
        set("max_sen", 600);
   set("class", "youling");
   set("force", 400);
   set("max_force", 400);
   set("force_factor", 20);
   set("max_mana", 300);
   set("mana", 300);
   set("mana_factor", 15);
   set_skill("ghost-steps", 50);
        set_skill("dodge", 50);
        set_skill("unarmed", 50);
   set_skill("parry", 50);
   set_skill("spells", 50);
   set_skill("gouhunshu", 50);
   set_skill("jinghun-zhang", 50);
   set_skill("force", 50);
   set_skill("tonsillit", 50);
   map_skill("spells", "gouhunshu");
   map_skill("dodge", "ghost-steps");
   map_skill("force", "tonsillit");
   map_skill("unarmed", "jinghun-zhang");
create_family("阎罗地府", 3, "你好");

        setup();
   carry_object("/d/obj/cloth/bai")->wear();
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
                        command("say 喂！阳人来阴间做什么？");
        command("kick " + ob->query("id"));
                        return;
                }
                return;
        }

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
{   object me;
   me = this_player();
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
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "youling");
}

