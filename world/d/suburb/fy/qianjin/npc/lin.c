#include <ansi.h>
inherit NPC;

void create()
{
	set_name("林仙儿", ({ "linxian" }) );
	set("title", HIR "武林第一美人" NOR);
	set("gender", "女性" );
	set("age", 22);
	set("str", 10);
	set("per", 30);
	set("long", @LONG
两弯似戚非戚笼烟眉，一双似喜非喜含情目．
行动如弱柳扶风，闲静似娇花照水．
LONG
);
	set("combat_exp", 100000);
	set("attitude", "friendly");
        set("chat_chance", 1);
        set("chat_msg", ({
"林仙儿又意无意地撩起长裙，向你露出她那双白如羊脂的细足．\n",
"林仙儿似乎怕热，拎起领口扇了扇，半边雪白的坚挺的胸膛尽收眼底．\n",
"林仙儿向你笑了笑，又满眼愤毒的瞥了阿飞一眼．\n",
        }) );

	setup();
	carry_object(__DIR__"obj/sskirt")->wear();
}

int accept_fight(object me)
{
	command("say 小女子哪里是您的对手？");
	return 0;
}
