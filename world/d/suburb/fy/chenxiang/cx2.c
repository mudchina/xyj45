// 
// 

inherit ROOM;
void create()
{
        set("short", "沉香镇石桥");
        set("long", @LONG
这里充分地显示着江南小镇那种独特仅有的风格，园拱形的小桥横跨
一条弯弯的小河流。桥下的流水被浮萍染成爱人的翠绿。偶尔一两只轻舟
划过，带动着河边的莲藕。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"cx1",
  "southwest" : __DIR__"cx3",
]));
        set("objects", ([
        __DIR__"npc/boy": 2,
                        ]) );
        set("outdoors", "chenxiang");
        set("resource/water",1);
        setup();
}
void init()
{
        add_action("do_fillwater", "fillwater");
}

int do_fillwater(string arg)
{
        object *list, ob;
        int i, can_fillwater;
        string dir;

        if( !arg || arg=="" ) return 0;

        if( arg=="skin" || arg=="wineskin" ) {
                list = all_inventory(this_player());
                i = sizeof(list);
                can_fillwater = 0;
                while (i--) {
                  if (((string)list[i]->query("liquid/type") == "alcohol")
 || ((string)list[i]->query("liquid/type") == "water")         ) {
                        ob = list[i];
                        can_fillwater = 1;
                        ob->set("liquid", ([
                                "type": "water",
                                "name": "清水",
                                "remaining": 15,
                                "drunk_apply": 6,
                        ]) );
                        write("你从弯弯的小河流里装满了清水! \n");
                        return 1;
                   }
                }
                if (can_fillwater ==0) {
                        write("你没有装水的东西啊....\n");
                        return 1;
                }
        }
        else {
                write("你要往什么东西里灌水？");
        }
        return 1;
}

