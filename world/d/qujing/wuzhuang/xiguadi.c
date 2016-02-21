// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//huludi.c

inherit ROOM;

void create ()
{
   set ("short", "西瓜地");
   set ("long", @LONG

五庄观做事的多，吃饭的也不少，所以观内雇了附近的一些农家
来种蔬菜瓜果。这里是西瓜地。往北是有一道荆棘结成的篱笆，
篱笆上开了一道简陋的杏木门，门上挂着一把黄铜锁。
LONG);

   set("exits", 
   ([ //sizeof() == 4
     "southeast" : __DIR__"baicaidi",
     "southwest" : __DIR__"huludi",
   ]));
   
   set("objects", 
   ([ //sizeof() == 1
     "/d/obj/food/watermellon" : 3,
   ]));

   //create_door("north", "杏木门", "south", DOOR_CLOSED);
   set("outdoors", "wuzhuang");

   setup();
}

void init()
{
   add_action("do_open", "open");
}

int do_open(string arg)
{
   object me, key, nroom;

   me = this_player();

   if( !arg || arg != "door" ) 
     return notify_fail("你要打开什么？\n");

   if( !(key = present("huangtong key", me)) ) 
     return notify_fail("你没有开这道门的钥匙。\n");

   //now we are ready to open...
   if( !(nroom = find_object(__DIR__"renshenguo-yuan")) )
     nroom = load_object(__DIR__"renshenguo-yuan");

   set("exits/north", __DIR__"renshenguo-yuan");
   nroom->set("exits/south", __FILE__);
   message("vision", "只听喀嚓！一声，钥匙断了。好在门已经开了。\n", this_object() );

   me->set_temp("used_huangtong_key", 1);
   destruct(key);
   return 1;
}


