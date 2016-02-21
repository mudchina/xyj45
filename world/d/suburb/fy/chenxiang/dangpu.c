// 
// 

inherit ROOM;
void create()
{
        set("short", "胡家当铺");
        set("long", @LONG
此间当铺很小，但却有一间很大的储藏室。当铺的四周堆满了东西，就连
墙上也挂满了只要是能挂起来的东西，每件东西上都有一张当票。所有堆积的
东西都布满了灰尘，显然是很多人将东西典当于此，却再也没有回来取。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"cxe3",
]));
        set("objects", ([
        __DIR__"npc/pawnowner": 1,
                        ]) );
        setup();
        replace_program(ROOM);
}
