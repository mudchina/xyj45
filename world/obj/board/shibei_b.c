// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit BULLETIN_BOARD;

void create()
{
        set_name("  石碑  ", ({ "shibei" }) );
        set("location", "/d/lingtai/gate");
        set("board_id", "shibei_b");
   set("long", "一块大石碑，上写“灵台方寸山，斜月三星洞”
－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－\n");
        setup();
        set("capacity", 80);
        replace_program(BULLETIN_BOARD);
}

