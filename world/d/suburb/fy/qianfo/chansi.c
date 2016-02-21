//mac's chansi.c
#include <room.h>

inherit ROOM;

void create()
{
  set("short","ĞË¹úìøËÂ");
  set("long",@LONG
ÇàÊ¯ÆöÆğµÄÉ½ÃÅÉÏ¿Ì×Å£ºĞË¹úìøËÂ¡£ËÂÄÚÆ®À´µÄÕóÕó·ğÏã¸øÈËÒ»
ÖÖËàÄÂµÄ¸Ğ¾õ¡£É½ÃÅÁ½ÅÔµÄ¶ÔÁª¸ñÍâÒıÈË×¢Ä¿£º
[35m
		Äº	¾­
		¹Ä	Éù
		³¿	·ğ
		ÖÓ	ºÅ
		¾ª	»½
		ĞÑ	»Ø
		ÊÀ	¿à
		¼ä	º£
		Ãû	ÃÎ
		Àû	ÃÔ
		¿Í£¬	ÈË¡£	
[37m
LONG
  );
        set("objects", ([
                __DIR__"npc/bonze2" : 2,
       ]) );
  set("exits",([
         "southdown":__DIR__"fudi.c",
         "north"    :__DIR__"jinggang.c"
               ]));
   
          set("outdoors", "qianfo");
	setup();
  replace_program(ROOM);
}
