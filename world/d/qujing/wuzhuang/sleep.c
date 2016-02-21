// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit ROOM;

void create ()
{
   set ("short", "睡房");
   set ("long", @LONG

睡房中整齐的摆着二三十个软榻，上面铺着玄色的被子。室中
非常的安静，偶尔从外面的竹林中传来一两声鸟叫。
LONG);

   set("exits", 
   ([ //sizeof() == 4
     "west" : __DIR__"westway5",
   ]));
        set("sleep_room",1);
        set("if_bed",1);
   
   set("objects", 
   ([ //sizeof() == 1
     //__DIR__"npc/qingfeng" : 1,
     //__DIR__"npc/mingyue" : 1,
   ]));


//   set("outdoors", "wuzhuang");

   setup();
}
