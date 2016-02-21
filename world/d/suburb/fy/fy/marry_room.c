// marry_room.c
// tie@fengyun
#include <room.h>
inherit ROOM;
string look_sign(object me);
void create()
{
        set("short", "鸳鸯亭");
        set("long", @LONG
你现在正站在鸳鸯亭里，这里是专门替人缔结婚约和解除婚约的地方，
城里所有的夫妇都是在这里喜结良缘的，就连附近镇子也有许多慕名而来的
年青人．靠近门口的地方有一块乌木雕成的招牌（ｓｉｇｎ）。
LONG
        );
        set("exits", ([
                "north"          : __DIR__"ecloud1", 
         ]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

        set("objects", ([
                __DIR__"npc/mei_po" : 1,
        ]) );
 
        setup();

}

string look_sign(object me)
{
        return "缔结（ｍａｒｒｙ）或解除（ｕｎｍａｒｒｙ）婚约。\n";
}

