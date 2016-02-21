// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit BULLETIN_BOARD;

void create()
{
        set_name("龙腾四海留言版", ({ "board" }) );
        set("location", "/d/sea/yujie2");
        set("board_id", "dragon_b");
   set("long", "
－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－\n");
        setup();
        set("capacity", 80);
        replace_program(BULLETIN_BOARD);
}

