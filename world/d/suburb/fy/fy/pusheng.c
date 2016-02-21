inherit ROOM;
void create()
{
	set("short", "ÆÕÉúÌÃ");
	set("long", @LONG
ÆÕÉúÌÃ±¾ÊÇÒ»ÔÆÓÎ¸ßÉ®Â·¾­·çÔÆ³Ç¶ºÁôÊ±ËùÉè£¬¸ßÉ®Í¯ĞÄÎ´ãı£¬ÓĞ¸Ğ´ËµØ·çÍÁÈË
Çé£¬Ò»Áô¾ÍÊÇÈıÄê¡£Ç×ÊÚÒ»µÜ×Ó¡£¸ßÉ®»ÛÑÛÊ¶Öé£¬´ËµÜ×ÓÄËÈËÖĞÖ®Áú£¬²»µ½ÈıÄêÒÑ½«
É®ÈËÒ½Êõ¾¡Ñ§¡£ÌÃÖĞĞüØÒÒ»¿é£º [32m
        		    ÃîÊÖ»Ø´º
[37m
LONG
	);
	
	set("exits", ([
		"east"    	: __DIR__"swind5",
		"north"		: __DIR__"yangsheng",
	]) );
	set("objects", ([
		__DIR__"npc/hosowner" : 1,

			]) );
	setup();
        replace_program(ROOM);

}
