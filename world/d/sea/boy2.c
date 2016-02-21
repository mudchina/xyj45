// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// boy2.c

inherit ROOM;

void create()
{
  set ("short", "过道");
  set ("long", @LONG

一条长长的走廊，联结着前后厅。东边是太子的寝室，传出杯酬
交错的声音，几名宫女端着盒子走来走去。北边一间大厅，是太
子练武的地方。
LONG);
set("exits", ([ /* sizeof() == 4 */
"southwest" : __DIR__"boy1",
"east" : __DIR__"boy3",
"north" : __DIR__"boy4",
]));
set("objects", ([
                __DIR__"npc/gongnu": 2]) );

        set("no_clean_up", 0);
        setup();
}

