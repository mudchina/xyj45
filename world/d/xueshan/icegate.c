// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//standroom.c used by weiqi...others may hate this format:D
//icegate.c

inherit ROOM;

void create ()
{
   set ("short", "冰宫大门");
   set ("long", @LONG

放眼望去，这座冰宫通体雪明，当真是巍峨壮观。但是此刻宫门
紧闭，一位身披银甲的壮汉和一位面目阴森的老者正神情紧张地
守在门前。
LONG);

   //set("item_desc", ([" *** " : " *** \n", ]));
   //for look something.

   set("exits", 
   ([ //sizeof() == 4
     "south" : __DIR__"wuchang-n",
     //"north" : __DIR__"icegate",
     //"west" : __DIR__"wuchang-nw",
     //"east" : __DIR__"wuchang-ne",
     //"up" : __DIR__"***",
     //"down" : __DIR__"***",
   ]));
   
   set("objects", 
   ([ //sizeof() == 1
     __DIR__"npc/tuying-zunzhe" : 1,
     __DIR__"npc/baixiang-zunzhe" : 1,
   ]));


   set("outdoors", "xueshan");

   setup();
}

//void init()
//{
   //add_action("do_jump", "jump");
//}

//int do_jump(string arg)
//{
       
//}

