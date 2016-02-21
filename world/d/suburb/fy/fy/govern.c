inherit ROOM;
void create()
{
        set("short", "·çÔÆÑÃÃÅ");
        set("long", @LONG
ÕâÀïÊÇ³¯Í¢ËùÉè£¬·çÔÆ³ÇÀïµÄ¾À·×¶¼¿ÉÒÔÔÚÕâÀïÉÏ×´ÇëÇó´¦Àí¡£´óÌüÄÏÊ×Ò»ÕÅ¾í
éÜÄ¾°¸£¬°¸ÉÏÓĞ¸öĞ¡ÖñÍ°£¬ÀïÃæ²å×Å¼¸¸ùÓĞÖª¸®¹ÙÓ¡µÄÖñÇ©¡£Ä¾°¸ºóµÄÌ«Ê¦ÒÎÉÏÆÌ×Å
Ñ©ÈŞÆ¤£¬ÒÎºóÆÁ·çÉÏºìÈÕÇàÔÆÍ¼¡£ÉÏĞü½ğ±ßØÒ£º
[31m
				Ã÷²ìÇïºÁ
[37m
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"wcloud2",
  "east" : __DIR__"shufang",
]));
        set("objects", ([
        __DIR__"npc/yayi1" : 3,
        __DIR__"npc/yayi" : 3,
        __DIR__"npc/yayi2" : 3,

                        ]) );
	set("NONPC",1);
        setup();
        replace_program(ROOM);
}
