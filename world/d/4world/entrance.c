// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: /4world/entrance
inherit ROOM;

// int do_push(string);

void create ()
{
  set ("short", "仙石");
  set ("long", @LONG

这里是花果山腰的一块平地。一道瀑布从山顶飞流直下，
泻入一眼深潭，当真是：“一派白虹起，千寻雪浪飞”。
瀑布边上有一块大石头，相传为天地灵气所化。不知是谁在
上面刻了一首诗：

　　　　混沌未分天地乱，茫茫渺渺无人见。
　　　　自从盘古破鸿蒙，开辟从兹清浊辨。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/d/ourhome/npc/longear" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"houshan1",
  "southdown" : __DIR__"up2",
]));

  setup();
}

void init()
{
   add_action("do_push", "push");
}

int valid_leave(object me, string dir)
{
   object mbox;

   if( mbox = me->query_temp("mbox_ob") ) {
     tell_object(me, "你将信箱交回给邮差。\n");
     destruct(mbox);
   }
   return 1;
}

void check_trigger()
{
   object room;

   if( (int)query("left_trigger")==3
   &&   (int)query("right_trigger")==5
   &&   !query("exits/down") ) {
     message("vision", "仙石忽然发出轧轧的声音，露出一个向下的阶梯。\n",
        this_object() );
if( !(room = find_object(__DIR__"inner_shuiliandong")) )
room = load_object(__DIR__"inner_shuiliandong");

     if( room = find_object(__DIR__"inner_shuiliandong") ) {
set("exits/down", __DIR__"inner_shuiliandong");
        room->set("exits/up", __FILE__);
        message("vision", "仙石忽然发出轧轧的声音，露出一个向上的阶梯。\n",
          room );
     }
     delete("left_trigger");
     delete("right_trigger");
     call_out("close_passage", 10);
   }
}

void close_passage()
{
   object room;

   if( !query("exits/down") ) return;
   message("vision", "仙石忽然发出轧轧的声音，将向下的通道盖住了。\n",
     this_object() );
   if( room = find_object(__DIR__"inner_shuiliandong") ) {
     room->delete("exits/up");
     message("vision", "仙石忽然发出轧轧的声音，向上的通道又缓缓地被盖住了。\n",
        room );
   }
   delete("exits/down");
delete("left_trigger");
delete("right_trigger");
}


int do_push(string arg)
{
   string dir;
   object me=this_player();

   if( !arg || arg=="" ) return 0;

   if( arg=="stone" ) {
     write("你试着推动仙石，似乎可以左右滑动....\n");
delete("left_trigger");
delete("right_trigger");
     return 1;
   }
   if( sscanf(arg, "stone %s", dir)==1 ) {
     if( dir=="right" ) {
if(query("exits/down")) return notify_fail("仙石已经被推开了。\n");
        message_vision("$N将仙石往右推...，忽然「喀」一声仙石又移回原位。\n", me);
        add("right_trigger", 1);
        check_trigger();
        return 1;
     } else if( dir=="left" ) {
if(query("exits/down")) return notify_fail("仙石已经被推开了。\n");
        message_vision("$N将仙石往左推...，忽然「喀」一声仙石又移回原位。\n", me);
        add("left_trigger", 1);
        check_trigger();
        return 1;
     } else {
        write("你要将仙石往哪边推？\n");
        return 1;
     }
   }
}


void reset()
{
   ::reset();
   delete("left_trigger");
   delete("right_trigger");
}

