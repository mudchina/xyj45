// teacher.c

inherit NPC;
#include <ansi.h>
void create()
{
	set_name("查猛", ({ "meng", "cha meng" }) );
	set("title", HIY "金狮掌" NOR);
	set("gender", "男性" );
	set("age", 42);
	set("skill_public",1);
	set("int", 30);
        create_family("少林俗家", 21, "弟子");
	set("long",
		"金狮掌查猛是少林俗家弟子，人不但性情豪爽，且广交朋友．
		 凡是想向他求教的，只要为镖局出点力，他就肯教．\n"
		);
       set("chat_chance", 1);
        set("chat_msg", ({
                "查猛说道：这个月镖局生意不错！\n",
        }) );
	set("attitude", "peaceful");
	set_skill("unarmed", 30);
	set_skill("changquan", 30);
	set_skill("literate", 30);
	set_skill("force", 30);
	set_skill("dodge",30);
	set_skill("parry",30);
	map_skill("unarmed", "changquan");
	set("combat_exp", 90000);
	setup();
	carry_object(__DIR__"obj/jinzhuang")->wear();
}
int recognize_apprentice(object ob)
{
        if((time() - ob->query("marks/金狮") ) > 1800  ){
                say("查猛说道：你．．你好象很久没为镖局出过力了....\n");
                return 0;
        }

        return 1;
}
