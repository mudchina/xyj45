// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit BULLETIN_BOARD;

void create()
{
  set_name("铁塔留言壁", ({"board"}) );
  set("location", "/d/kaifeng/tieta");
  set("board_id", "kaifeng_b");
  set("capacity", 100);
  set("long", "铁塔下一块留言壁，上面写满了留言。\n");
  setup();
  replace_program(BULLETIN_BOARD);
}

