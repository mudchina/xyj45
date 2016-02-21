// inn.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
	set("short", "·çÔÆ¸ó");
	set("long", @LONG
·çÔÆ¸óµÄÖ÷ÈË¾ÍÊÇµ±½ñÌìÏÂÏÀÃû¶¦¶¦µÄĞ¡Àî·Éµ¶¡£ÀîÌ½»¨³¤ÄêĞĞÏÀÔÚÍâ£¬µ«»¹ÊÇ
ÓĞºÜ¶à¿ÍÈËÄ½ÃûÀ´µ½´Ë¸ó£¬ÒÔÇóÒ»ÃæÖ®Ôµ¡£¸óÖĞ´óºì²¨Ë¹µØÌºÆÌµØ£¬¸»ÀöÌÃ»Í¡£Öìºì
µÄ´óÃÅÁ½²à¸÷¹ÒÒ»·ùÊ¯¿ÌµÄ¶ÔÁª¶ù£º
[33m
                	Ò»ÃÅÆß½øÊ¿£¬
                	¸¸×ÓÈıÌ½»¨¡£
[37m
LONG
	);
	set("valid_startroom", 1);
	set("item_desc", ([
		"sign": (: look_sign :),
	]) );
	
	set("exits", ([
		"west"    	: __DIR__"nwind1",
		"up"		: __DIR__"fyyage",
	]) );

	set("objects", ([
		__DIR__"npc/fywaiter" : 1,

			]) );


	setup();

	// To "load" the board, don't ever "clone" a bulletin board.
	call_other( "/obj/board/common_fy", "???" );
}

string look_sign(object me)
{
	if( wizardp(me) )
		return "ÕĞÅÆĞ´Öø£º·çÔÆ¸ó¡£ÅÔ±ßÒ»ÅÅĞ¡×Ö£º°¢ÌúÌâ¡£\n";
	else
		return "ÕĞÅÆĞ´Öø£º·çÔÆ¸ó¡£\n";
}
