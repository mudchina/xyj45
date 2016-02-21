//mac's dongyu.c
#include <room.h>
inherit ROOM;
void create()
{
  set("short","东御座");
  set("long",@LONG
此处又称迎宾堂，为皇帝登祀泰山时起居的处所，也是存放祭器
的地方，其中以温凉玉雕床尤以引人注目，此床长八尺，宽三尺，面
刻三星波纹，上中部都是凉的，而下部却是温的，为泰山三宝之一。
LONG
  );
  set("exits",([
         "west":__DIR__"renan.c",
               ]));
        set("objects", ([
                __DIR__"npc/daoshi" : 1,
       ]) );
  setup();
  replace_program(ROOM);
}
