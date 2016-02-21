// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// common_b.c

inherit BULLETIN_BOARD;

void create()
{
   set_name("一般用途留言板", ({ "board" }) );
   set("location", "/d/ourhome/kedian");
   set("board_id", "common_a");
   set("long",   "这是一个供人留言记事的留言板。\n" );
   setup();
   set("capacity", 80);
   replace_program(BULLETIN_BOARD);
}
