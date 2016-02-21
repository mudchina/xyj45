// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// wizard_b.c

inherit BULLETIN_BOARD;

void create()
{
   set_name("系统公告板", ({ "board" }) );
   set("location", "/d/wiz/system");
   set("board_id", "system_b");
   set("long",
     "这是一个专门公告系统资讯的板子，只有巫师能 post。\n" );
   setup();
   set("capacity", 150);
   replace_program(BULLETIN_BOARD);
}
