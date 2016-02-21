// yzuo.c 雾雨
 
#include <ansi.h>
 
inherit NPC;
 
void create()
{
        set_name("雾雨", ({"yzuo"}));
        set("nickname",HIM"星宿祖师"NOR);
        set("gender", "男性");
        set("age", 20);
        set("long",
                "他就是负担起振兴星宿派大业的大巫师雾雨！\n");
        set("attitude", "peaceful");
 
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
 
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

