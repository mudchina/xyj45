#include <room.h>
inherit ROOM;
void close_path();
void create()
{
  set("short","长廊");
  set("long",@LONG
松木的廊栏已被香客和游人摸的发亮，廊脊上塑有九鲤化龙，双
凤朝牡丹的图像，颇据闽南建筑艺术风格。令人怀疑此寺与佛教南宗
一脉相承。
LONG
  );
  set("exits",([
         "north":__DIR__"chanfang.c",
//         "south":__DIR__"zhaitang.c",
         "east" :__DIR__"houyuan.c"
               ]));
        set("item_desc", ([
                "廊栏": "
                        廊栏上似乎有一木键（ｂｕｔｔｏｎ）\n",
                "langlan": "
                        廊栏上似乎有一木键（ｂｕｔｔｏｎ）\n"

        ]) );
          set("objects", ([
                __DIR__"npc/bigmonk" : 1,
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
                write("你要按什么？\n");
                return 1;
        }
        if( arg == "button" )
        {
        me = this_player();
        message_vision("$N按了下木键，长廊前方的暗门无声无息地滑开了。\n", me);
        if( !query("exits/south") ) {
        set("exits/south", __DIR__"zhaitang");
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
void close_path()
{
        if( !query("exits/south") ) return;
        message("vision",
"长廊前方的暗门无声无息地转了回来，堵住了向南的路。\n",
                this_object() );
                delete("exits/south");
}

