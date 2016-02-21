inherit ROOM;
void create()
{
        set("short", "Ì½»¨Ê«Ì¨");
        set("long", @LONG
·çÔÆÖĞµÄÀÏÀÏÉÙÉÙ´ó¶¼ÓĞÒ÷Ê«¶Ô´ÊµÄÑÅºÃ¡£Ö»ÒªÉÔÓĞÁé¸Ğ£¬¾Í»á´ø×Å±ÊÄ«µ½ÕâÀïÀ´
ÔÍÄğ£¬µÈµ½Áé¹âÕ§ÏÖÄÇö®ÄÇ£¬·Ü±Ê¼±Êé£¬ÒÔÇóÇ§¹ÅÃû¾ä¡£Ê«Ì¨ÕıÖĞÖì±ÊÈëÄ¾¿ñ²İ£º
[33m
                       ½ñÈÕÓĞ¾Æ½ñ³¯×í£¬
                       ÄÄ¹ÜËüÈÕ½£¸îÍ·£¡
                                       °¢Ìú¿ñÎèÓÚ¾ÆºóÊ§ÒâÊ±¡£

[37m
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"wcloud1",
]));
        set("objects", ([
        __DIR__"npc/yaren" : 1,
                        ]) );
	set("no_death_penalty",1);
        setup();
        call_other( "/obj/board/poem_b", "???" );
}
