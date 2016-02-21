// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit BULLETIN_BOARD;

void create()
{
   set_name("生死簿", ({"board"}) );
set("location", "/d/death/zhengtang");
set("board_id", "shengsi_b");
set("capacity", 100);
set("long", "天下芸芸众生的生死都在这里记录。\n");
        setup();
        replace_program(BULLETIN_BOARD);
}

