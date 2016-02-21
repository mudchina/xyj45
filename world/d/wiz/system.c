// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: /d/wiz/system.c

inherit ROOM;

void create()
{
   set("short", "系统公告室");
   set("long", @LONG
这是一间很普通的房间，房内贴着一些有关这个世界的资讯，
往南可以回到国宾馆大厅，往东是巫师会议厅。   
LONG
   );
set("item_desc" , ([ /* sizeof() == 1 */
"east": "房子里云雾缭绕，什么也看不清楚。\n",
]));
   set("exits", ([ /* sizeof() == 2 */
  "east" : "/d/wiz/wizroom",
  "south" : "/d/wiz/entrance",
]));
   set("no_clean_up", 0);
   set("no_fight", 1);
   set("no_magic", 1);
   set("post_limit", 1);

   setup();
   call_other("/obj/board/system_b", "???");
}


int valid_leave(object me, string dir)
{
//     if(me->query("id")=="beavis") return ::valid_leave(me, dir);
       //temp access for future wiz.

     if( dir=="east" && !wizardp(me) )
        return notify_fail("那里只有巫师才能进去。\n");
     return ::valid_leave(me, dir);
}


