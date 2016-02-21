// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// /d/changan/playerhomes/stdbed.c
// this  is a standard bed for married couples.
// wiz should modify /d/changan/playerhomes/h_playername  to 
// connect here.
// IMPORTANT: should copy this to bed_playername, otherwise...  

inherit ROOM;

void create()
{
        set("short", "床上");
        set("long", @LONG

LONG
        );
        
   set("exits", ([
                "out": "/d/changan/playerhomes/h_nonn",
            ]));
   set("sleep_room",1);
   set("if_bed",1);
                                              
        setup();
}



