inherit ROOM;
void create()
{
	object con, item;
        set("short", "草堂");
        set("long", @LONG
房虽草覆，却高爽宽敞，窗台明亮。堂中挂一幅无名小画，设一张白木卧榻。桌凳
之类，色色洁净。打扫得地下无纤毫尘垢。堂中花卉无所不有，十分繁茂。真个四时不
谢，八节长春。再往两侧行，则是湖上八娇的住处。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"yue",
  "south" : __DIR__"shui",
  "east" : __DIR__"bridge1",
  "west" : __DIR__"bridge2",
]));
        set("objects", ([
        __DIR__"obj/flower" : 1,
	__DIR__"obj/pin" :1,
	__DIR__"npc/qianjinwaiter" :1,
                        ]) );
        setup();
	con = present("flower", this_object());
	item= present("pin", this_object());
	item->move(con);
}

void init()
{
 
if(!random(1000)) call_out("lucky", 1, this_player());

}

int lucky(object me)
{

message_vision("$N好象看到堂中花卉里有东西闪了闪．\n", me);
return 1;
}
