// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Wuliao's Board


inherit BULLETIN_BOARD;

void create()
{
        set_name("闲聊板", ({ "board" }) );
  set("location", "/u/wuxin/workroom");
        set("board_id", "wuliao_board");
        set("long",     "这是一闲聊板，上面写满了杂乱无章的留言。\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}
