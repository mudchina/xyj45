// 
// 

#include <room.h>
inherit ROOM;
void create()
{
  set("short","放生池");
  set("long",@LONG
放生池有山泉汇集而成。泉水清澈见底，池中鱼可百许头，皆若
空游无所依。看着鱼儿在水中自由自在的游，令人顿生倦意，“人在
江湖，身不由己”，此话确有几分道理。
LONG
  );
  set("exits",([
         "east" :__DIR__"jinggang.c",
         "north":__DIR__"changlang.c",
               ]));
        set("outdoors", "qianfo");
        set("resource/water",1);
	set("liquid/name","山泉水");
	set("liquid/type", "water");
	set("liquid/drunk_apply",0);
        set("objects", ([
                __DIR__"npc/lady" : 1,
		__DIR__"npc/badguy":1,
       ]) );

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
                                "name": "山泉水",
                                "remaining": 15,
                                "drunk_apply": 0,
                        ]) );
                        write("你从放生池里装满了山泉水！ \n");
                        return 1;
                   }
                }
                if (can_fillwater ==0) {
                        write("你没有装水的东西啊....\n");
                        return 1;
                }
        }
        else {
                write("你要往什么东西里灌水？\n");
        }
        return 1;
}

