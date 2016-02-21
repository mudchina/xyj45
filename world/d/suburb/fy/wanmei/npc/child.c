inherit NPC;
void create()
{
        set_name("小西门", ({ "xiao ximen", "ximen"}) );
        set("title", "西门吹雪之子");
        set("gender", "男性");
        set("age", 3);
        set("long",
"西门吹雪乃是当代绝顶高手之一．剑法已经到达了＂无剑＂的境界．．
当然，他儿子很小，还没有很高的武功。\n"
               ); 

        set("attitude", "peaceful");
        set("combat_exp", 10);
        set("chat_chance", 10);
        set("chat_msg", ({
                "小西门指着北边说道：陆叔叔和我娘从那边走了．．．\n",
        }) );
        setup();
	carry_object(__DIR__"obj/cloth2")->wear();
}
