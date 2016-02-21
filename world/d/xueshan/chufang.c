// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//standroom.c used by weiqi...others may hate this format:D
//chufang.c

inherit ROOM;

void create ()
{
   set ("short", "厨房");
   set ("long", @LONG

这里是厨房。雪山弟子众多厨房却不大，吃东西得拿到外面去。
当然，明王及护法尊者们另有就餐的地方。有个怪头怪脑的小妖
正在里面忙来忙去。他腰上挂着一块牌子，上面歪歪拐拐地写着：
“小钻风”。
LONG);

   //set("item_desc", ([" *** " : " *** \n", ]));
   //for look something.

   set("exits", 
   ([ //sizeof() == 4
     "south" : __DIR__"eroad3",
     //"north" : __DIR__"wuchang-ne",
     "west" : __DIR__"wuchang-e",
     //"east" : __DIR__"chufang",
     //"up" : __DIR__"***",
     //"down" : __DIR__"***",
   ]));
   
   set("objects", 
   ([ //sizeof() == 1
     //__DIR__"npc/xunshi" : 2,
     __DIR__"npc/xiaozuanfeng" : 1,
   ]));


   //set("outdoors", "xueshan");

   setup();
}

//void init()
//{
   //add_action("do_jump", "jump");
//}

//int do_jump(string arg)
//{
       
//}

