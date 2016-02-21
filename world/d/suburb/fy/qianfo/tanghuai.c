// 
// 

#include <room.h>
inherit ROOM;
void create()
{
  set("short","唐槐亭");
  set("long",@LONG
山行从此向东开始陡峭，一座凉亭前有一棵大槐树，据称唐将
秦琼曾在此栓马，此树得风气之先长的郁郁葱葱，遮天蔽日。许多
登山者都在此歇脚。
LONG
  );
  set("exits",([
         "west"  :__DIR__"shanjiao.c",
         "eastup":__DIR__"qiyan.c"
               ]));
        set("objects", ([
                __DIR__"npc/horse" : 1,
		__DIR__"npc/climber" : 2,
       ]) );
        set("outdoors", "qianfo");
  setup();
}
void init()
{
        add_action("do_climb", "climb");
        if( this_player() ) {
                tell_room(__DIR__"tree1", this_player()->name() + "往树下走了过来。\n");
        }
}

int do_climb(string arg)
{
        if( arg!="tree" ) return 0;

        message_vision("$N手脚并用，敏捷地爬上了凉亭前的大槐树。\n",
                this_player());

        tell_room(__DIR__"tree1", this_player()->name() + "从树下爬了上来。\n");
        this_player()->move(__DIR__"tree1");

        return 1;
}

int valid_leave(object me, string dir)
{
        tell_room(__DIR__"tree1",
                "树下的" + me->name() + "往" + to_chinese(dir) + "离开了。\n");
        return 1;
}

