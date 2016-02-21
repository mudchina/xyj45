
inherit ROOM;

void create()
{
        set("short", "神秘冰河");
        set("long", @LONG
阳光下的冰河，看起来辉煌壮观。冰结十丈，坚如钢铁。这里离河岸很近，冰的颜
色却好象比别处还要深暗些。一段枯树露在河面上，想必是开始封江的时候倒下来的。
枯枝也不知被谁削平了，树干却还有一小半露在河面外。
LONG
        );
        set("exits", ([ 
  "northeast" : __DIR__"street3",
]));
        set("outdoors", "laowu");

        setup();
}
void init()
{
	add_action("do_zha", "bomb");
}

int do_zha()
{
	object me, *inv;
	int i;
	object exp;
	object con,item;
	me = this_player();
	if( !(int)me->query("marks/李霞"))
	return 0;
	inv = all_inventory(me);
	               for(i=0; i<sizeof(inv); i++)
                {
				
			if( (int) inv[i]->query("explosive") )
				exp = inv[i];
		}
	if( !exp) 
	{
	tell_object(me,"你没有引爆的东西．\n");
	return 1;
	}

	message_vision("$N点燃了手中的"+exp->name()+"．．．
只听得一声滔天巨响＂轰＂，冰河被炸开个大洞．\n", me, exp);
	destruct(exp);
	con = new(__DIR__"obj/seal");
	item = new(__DIR__"obj/jadepai");
	if( con && item){
	item->move(con);
	con->move(this_object());
	me->set("marks/李霞",0);
			}
	return 1;

}
