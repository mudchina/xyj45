// worker.c

inherit NPC;

void create()
{
        set_name("丫环", ({ "yahuan", "ya" }) );
        set("gender", "女性" );
        set("age", 11);
        set("long", "天真可爱的丫环正在相互低头切切私语。 \n");
        set("combat_exp", 700);
        set("attitude", "friendly");
        set_skill("unarmed", 10);
        set("chat_chance", 10);
        set("chat_msg", ({
"一个丫环叽叽喳喳的告诉另一个丫环：昨天来了个异人，给湖上八个姐姐一人一块玉璧．\n",
"一个丫环叽叽喳喳的告诉另一个丫环：还说什么八璧合一，天下无敌！\n",
        }) );

	setup();
        carry_object(__DIR__"obj/wch_skirt")->wear();
        carry_object(__DIR__"obj/clothtwo");
}

