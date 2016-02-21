// 
// 

#include <room.h>
inherit ROOM;
int close_path();
void create()
{
  set("short","香积厨");
  set("long",@LONG
香积厨为禅寺的厨房，供奉的是万紧那罗王，相传曾显化为一火
头僧，运三尺棍趋散红巾首领的犯寺。
LONG
  );
  set("exits",([
//            "north":__DIR__"changlang4.c",
            "west" :__DIR__"guanyin.c",
               ]));
          set("objects", ([
                __DIR__"npc/monk" : 1,
       ]) );
  setup();
}

void init()
{
add_action("do_push","push");
}
int do_push(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("你要推开什么？\n");
                return 1;
        }
        if( arg == "luowang" || arg == "万紧那罗王" || arg == "罗王")
        {
        me = this_player();
        message_vision("$N推开万紧那罗王，发现了一条密道。\n", me);
        if( !query("exits/north") ) {
        set("exits/north", __DIR__"changlang4");
        call_out("close_path", 5);
        }
        return 1;
        }
        else
        {
                write("你推了推"+arg+"。\n");
                return 1;
        }
}
int close_path()
{
        if( !query("exits/north") ) return;
        message("vision",
"万紧那罗王又转了回来，堵住了向北的路。\n",
                this_object() );
                delete("exits/north");
}

