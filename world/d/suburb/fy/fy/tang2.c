inherit ROOM;
void create()
{
        set("short", "赏罚堂");
        set("long", @LONG
金钱帮帮规严明，凡有贪污受贿，无事生非，调戏民女之帮徒，都会在这里受到应
有的制裁。凡有巨功于金钱帮的，都会在这里受到帮主的赏赐和提拔。厅中悬条幅书
道：            赏罚分明
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"jhuang",
]));
        set("objects", ([
        __DIR__"npc/tiemian" : 1,
                        ]) );

        setup();
}
void init()
{
        add_action("do_open", "open");
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
        if( arg == "picture" || arg == "条幅" || arg == "tiao")
        {
        me = this_player();
        message_vision("$N拉起墙上的条幅，发现了一个暗门。\n", me);
        if( !query("exits/westdown") ) {
        set("exits/westdown", __DIR__"jsecret");
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
        if( !query("exits/westdown") ) return;
        message("vision",
"条幅荡了回来，又遮住了暗门。\n",
                this_object() );
                delete("exits/westdown");
}


