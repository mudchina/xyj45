// work.c
//#include "/feature/damage.c"

inherit ROOM;

void create()
{
        set("short", "谷物加工厂");
        set("long", @LONG
这是一间谷物加工厂，这里是谷子脱壳成米的地方。米厂老板是一个一
看就知道是十分精明的干瘦的中年人，老是带着一脸奸笑。你可以看到
许多人正在忙忙碌碌的工作着，门口挂著一块牌子(sign)，往西是通往
雪亭镇大街的大门。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "west" : "/d/suburb/es/snow/mstreet2",
]));

        set("item_desc", ([
                "sign": @TEXT
现在正紧缺人手，急需雇佣一批短工来干活。

work     开始工作。

TEXT
        ]) );
    set("no_fight", 1);
    set("no_magic", 1);
        setup();
}

void init()
{
        add_action("do_work", "work");
}

int do_work(string arg)
{
        object ob;
        object me;

        me = this_player();

message_vision("$N辛苦的工作终于结束了，可人也累的要死\n", 
me);
me->add("gin",-30);
me->add("sen",-30);
//receive_damage("gin",30,me);
//receive_damage("sen",30, me);
ob = new("/obj/money/silver");
ob->move(me);
message_vision("老板对$N说：这是你的工钱。\n", me);
return 1;
}
