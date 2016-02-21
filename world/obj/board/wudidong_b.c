// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// wudidong_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("帐本", ({ "board" }) );
        set("location", "/d/qujing/wudidong/kitchen.c");
        set("board_id", "wudidong_b");
        set("long", "这是无底洞的帐本，是厨子用来记下谁孝敬了新鲜人肉用的。\n");
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}
