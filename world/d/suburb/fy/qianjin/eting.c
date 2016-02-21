inherit ROOM;
void create()
{
        set("short", "东偏厅");
        set("long", @LONG
此厅无窗，尽以儿臂红烛照耀。厅中一张小木台，台上一壶酒，酒尚有余温。右角
一小方地毯，毯色鲜红。左边是支木架，架上有陈年老酒。还有一张小床，似乎有人长
年住在这里的样子。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"tading",
]));
        set("item_desc", ([
                "carpet": "这块小方地毯似乎可以拉开(pull)。\n",
                "ditan": "这块小方地毯似乎可以拉开(pull)。\n",
                "地毯": "这块小方地毯似乎可以拉开(pull)。\n",

        ]) );
	set("NONPC",1);
       set("objects", ([
        __DIR__"npc/guard" : 1,
                        ]) );

        setup();
}
void init()
{
	add_action("do_pull", "pull");
}
int do_pull(string arg)
{
object ob;
object sect;
if ( !arg && arg != "carpet" && arg != "ditan" && arg != "地毯")
                return 0;
        if( ob = present("guard", this_object()))
        {
        message_vision("$N对$n说：来，别瞎忙，喝！\n", ob, this_player());
        return 1;
        }
        if( !query("exits/down") ) {
        message_vision("$N把地毯拉开发现了一条密道．\n", this_player());
       set("exits/down", __DIR__"secret_room");
	sect = find_object(__DIR__"secret_room");
	if( ! sect)
        sect = load_object(__DIR__"secret_room");
	if( sect )
        sect->set("exits/up", __FILE__);
	call_out("close_path",15);
        }
        else
        {
       message_vision("$N把地毯拉过来掩盖住密道．\n", this_player());
        delete("exits/down");
        sect = find_object(__DIR__"secret_room");
        if( ! sect)
        sect = load_object(__DIR__"secret_room");
	if (sect)
        sect->delete("exits/up");
        }
        return 1;
}
void close_path()
{
	object sect;
        if( !query("exits/down") ) return;
                delete("exits/down");
        sect = find_object(__DIR__"secret_room");
        if( ! sect)
        sect = load_object(__DIR__"secret_room");
        if (sect)
        sect->delete("exits/up");

}

