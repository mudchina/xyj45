// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "国子监");
        set ("long", @LONG

这里是国子监的正堂，也就是秀才们平时上课的地方。高高低低的桌
子排了两溜。东边的一排窗子都开着，把屋中照的通亮。正面一桌一
椅，上有文房四宝。一位老先生正闭目养神。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "west" : __DIR__"guozijian",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/xiucai4" : 1,
                "/d/obj/misc/tables" : 1,
                "/d/obj/misc/chairs" : 2,
        ]));


//        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}


