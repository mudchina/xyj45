inherit ROOM;
// 
// 


void create()
{
        set("short", "山庄前院");
        set("long", @LONG
十丈方园的院子两侧种着几排翠绿的蔬菜。院角有一口小井。
井口有一木桶，桶上系着麻绳，显然是用来汲水的。院子另一边
堆着的几捆刚砍下来的木柴正在太阳下慢慢晒干。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"gate",
  "east" : __DIR__"meidang",
  "north" : __DIR__"woodroom",
  "south" : __DIR__"woodhouse",
  "northeast" : __DIR__"left",
  "southeast" : __DIR__"right",
]));
        set("outdoors", "wanmei");
        set("resource/water",1);
        set("item_desc", ([
                "蔬菜": "
                        好青好绿的蔬菜呀！你如果不怕人骂，拔（ｐｕｌｌ）一棵吧！\n",
                "木柴": "
                        快干了的木材，拿（ｐｉｃｋ）几根儿？\n",
                "小井": "
                        小井很滑，但你可以试着爬（ｃｌｉｍｂ）下去。\n"


        ]) );
        setup();
}
void init()
{
        add_action("do_fillwater", "fillwater");
        add_action("do_pull", "pull");
        add_action("do_pick", "pick");
        add_action("do_climb", "climb");
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
                        write("你从小井里装满了清水! \n");
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

void reset()
{
::reset();
delete("pulled");
delete("picked");
}
int do_climb()

{
write("你太胖了！！！\n");
return 1;
}	
int do_pull()
{
object vege;
if((int) query("pulled") <= 10)
{
write("你拔了一棵放在怀里。\n");
vege = new(__DIR__"obj/vege");
vege->move(this_player());
add("pulled",1);
return 1;
}
else
	write("都被人拔光了！！\n");
	return 1;
}
int do_pick()
{
object vege;
if((int) query("picked") <= 10)
{
write("你拿了一根放在怀里。\n");
vege = new(__DIR__"obj/wood");
vege->move(this_player());
add("picked",1);
return 1;
}
else
        write("都被人拿光了！！\n");
        return 1;
}

