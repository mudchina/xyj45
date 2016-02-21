inherit ROOM;
void create()
{
        set("short", "风云东城门");
        set("long", @LONG
风云东门高三丈，宽约二丈有余，尺许厚的城门上镶满了拳头般大小的柳钉。
门洞长约四丈，大约每隔两个时辰就换官兵把守。洞侧帖满了悬赏捉拿之类的官
府通谍。门洞西侧则是一条上城墙的窄梯。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
"east" : "/u/palace/palace_path1",
  "west" : __DIR__"ecloud5",
  "up" : "/d/suburb/fy/fywall/eupgate",
]));
        set("objects", ([
        __DIR__"npc/wind_solider" : 2,
        __DIR__"npc/cloud_solider": 2, 
			]) );
        set("outdoors", "fengyun");
        setup();
}
int valid_leave(object me, string dir)
{
	object *inv;
	object ob;
	int i;
	if( userp(me))
	{
	if( dir == "west" && ob=present("garrison", this_object()))
	{
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
		{
			if((int)(inv[i]->query("weapon_prop")) && (int)(inv[i]->query("equipped")))
			return notify_fail(ob->name()+"向你喝道：不可手持兵器入风云城！\n");	
			
		}
	}
        if( dir == "up" && ob=present("garrison", this_object()))
        {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
                        if((string)inv[i]->name() == "风云战甲" && (int)inv[i]->query("equipped"))
                        {
			return 1;
                        }

                }
		return notify_fail(ob->name()+"向你喝道：闲杂人等不可上登护城墙！\n");
        }

        return 1;
	}
	else return 1;
}

