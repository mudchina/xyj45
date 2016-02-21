// common_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("风云雅兴集", ({ "board" }) );
	set("location", "/d/suburb/fy/fy/poemp");
	set("board_id", "poem_b");
	set("long",	"这是一个供风云人物雅兴大发时所用。\n" );
	setup();
	set("capacity", 60);
	replace_program(BULLETIN_BOARD);
}
