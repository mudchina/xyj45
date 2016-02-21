inherit ROOM;
void create()
{
        set("short", "洗礼池");
        set("long", @LONG
这里是风云兵马征战回来接受洗礼（ｓａｌｕｔｅ）的地方，
以求洗去杀孽之气。布置得很简单，中间一个水池，池中冒出袅
袅水湮。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
"north" : __DIR__"ecloud4",
]));
        set("outdoors", "fengyun");
        setup();
}
void init()
{
       add_action("do_ponder","salute");
}
int do_ponder(string arg)
{
       object who;

       who = this_player();
        if((int) who->query("sen") <=50)
        return notify_fail("你的神不够。\n");
       message_vision("$N将双手浸入水池中。\n" ,who);
       who->receive_damage("sen",50);
       if( (int)who->query("bellicosity") > 0)
           who->add("bellicosity", - (random((int)who->query("kar")) + 7 ) );
       message_vision("$N身上的杀孽之气似乎轻了。 \n" , who);
    return 1;
}

