// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: /d/4world/tudi.c
inherit ROOM;

void create ()
{
  set ("short", "土地庙");
  set ("long", @LONG

一座小小的土地庙，庙里供着土地公公和土地婆婆(status)。供
台上摆着些供品香烛，还有些求告平安的文书。庙里很静，听不
到什么响动，供台上两支长烛发出淡淡的光线。
LONG);
  set("item_desc", ([ /* sizeof() == 1 */
  "status" : "泥像好象能够推动(push)。\n",
]));


  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"west2",
]));

  setup();
}
void init()
{
        add_action("do_push", "push");
}

int do_push(string arg)
{       
        object me,m;
        me=this_player();
   m=new("/d/4world/npc/niwawa");
        if ( !arg &&(arg != "土地公公")&&(arg !=
"土地婆婆")&&(arg!="status") )
                return notify_fail("你要推什么？\n");
   if (objectp(present("mud baby", environment(me))))
     return notify_fail("泥娃娃向你笑嘻嘻地说：我在这呢，推什么推？\n");

     message_vision("$N使劲地推了推土地公公和土地婆婆的泥像。\n",me);
     m->move(environment(me));
     write("「漱嗦」几声嫌诏，泥像后蹦出个泥娃娃来！\n");
                return 1;
}

