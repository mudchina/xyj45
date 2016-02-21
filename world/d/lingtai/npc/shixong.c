// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// worker.c

inherit NPC;
string try_me(object me);

void create()
{
        set_name("皤不分", ({"bo bufen", "bo"}));
        set("gender", "男性" );
        set("age", 33);
        set("long", "一个胖乎乎的道士，正傻呵呵的不知笑什么．\n");
   set("class", "taoist");
        set("combat_exp", 5000);
        set("attitude", "friendly");

        set("chat_chance_combat", 50 );
        set("inquiry", ([
"笑什么": "师父刚教我一招移行换位，嘻嘻．．．\n",
"移行换位": "听师父说可以把人传到远处，你想试试看？\n",
"试试": (: try_me :),
]) );
        setup();

}
string try_me(object me)
{   me = this_player();
        command ("say 试试也好．．．");

message_vision("皤不分双手往$N头上一按，念了句咒语．$N迷糊之中好象飞了出去．．．\n",
me);
   me->move("/d/lingtai/hill");
   return "怪了，人怎么不见了？";
}

void init()
{
        object ob;

        ::init();
        set("chat_chance", 10);
        set("chat_msg", ({
            (: random_move :)
        }) );
}

