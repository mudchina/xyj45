inherit ROOM;
// 
// 


void create()
{
        set("short", "后厨房");
        set("long", @LONG
一盏昏暗的油灯在陈旧的灶台上发出幽弱的光。灶下还有几根半焦的
干柴，缓缓地燃烧着。灶上锅内的山参野鸡汤发出诱人的香味，丝丝白气
从锅内的缝中飘出，令人垂涎欲滴。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"backyard",
]));
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
                                "name": "山参野鸡汤",
                                "remaining": 15,
                                "drunk_apply": 6,
                        ]) );
                        write("你从灶上锅内里装满了山参野鸡汤！ \n");
                        return 1;
                   }
                }
                if (can_fillwater ==0) {
                        write("你没有装汤的东西啊....\n");
                        return 1;
                }
        }
        else {
                write("你要往什么东西里灌汤？");
        }
        return 1;
}
