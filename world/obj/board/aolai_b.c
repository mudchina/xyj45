// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// nancheng_b.c

inherit BULLETIN_BOARD;

void create()
{
   set_name("翠香客栈留言板", ({ "board" }) );
   set("location", "/d/4world/cuixiang");
   set("board_id", "aolai_b");
   set("long",   "这是一个供人留言记事的留言板。\n" );
   setup();
   set("capacity", 100);
   replace_program(BULLETIN_BOARD);
}
