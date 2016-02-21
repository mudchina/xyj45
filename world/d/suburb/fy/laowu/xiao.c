
inherit ROOM;
void cloth_path();
void create()
{
        set("short", "小屋");
        set("long", @LONG
屋子里温暖如春，桌上的瓶子里还插着几支腊梅，寒风在窗外呼啸，窗子却紧紧
的关着。地上铺着层木板，木板下就是冰冻三尺的松花江。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"yingou",
]));
        set("item_desc", ([
                "floor": "这层木板似乎可以拉开(pull)。\n",
                "木板": "这层木板似乎可以拉开(pull)。\n",
                "muban": "这层木板似乎可以拉开(pull)。\n",

        ]) );

        setup();
}
void init()
{
        add_action("do_open", "pull");
}
int do_open(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("你要打开什么？\n");
                return 1;
        }
        if( arg == "floor" || arg == "muban" || arg == "木板")
        {
        me = this_player();
        message_vision("$N拉起地上的木板，发现下面是空的。\n", me);
        if( !query("exits/down") ) {
        set("exits/down", __DIR__"secret");
        call_out("close_path", 1);
        }
        return 1;
        }
        else
        {
                write("你不可以打开"+arg+"\n");
                return 1;
        }
}
void close_path()
{
        if( !query("exits/down") ) return;
        message("vision",
"木板又弹了回来，遮住了夹间。\n",
                this_object() );
                delete("exits/down");
}

