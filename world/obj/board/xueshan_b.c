// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// xueshan_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("     雪山留言板", ({ "wall" }) );
        set("location", "/d/xueshan/restroom.c");
        set("board_id", "xueshan_b");
        set("long",     "雪山留言板。\n" );
        setup();
        set("capacity", 80);
        replace_program(BULLETIN_BOARD);
}

