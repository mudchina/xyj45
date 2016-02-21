
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("水玉璧", ({ "shuiyu" , "玉璧"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", "这是一角玉璧，上面刻了个＂水＂字，
还刻了些奇怪的花纹，但只从这一角玉璧，你已经感到一种神奇的力量．
玉璧不时发出暗红色的光茫．似乎要和另外几角合璧（ｃｏｍｂｉｎｅ）\n");
		set("value", 1);
	}
}


void init()
{
  if(this_player()==environment())
  add_action("do_combine","combine");
}

int do_combine()
{
int i,yue=0,liu=0,xue=0,nu=0,cao=0,hua=0,jiu=0;
object jade,me, *inv;
object yuebi,liubi,xuebi,nubi,caobi,huabi,jiubi;
me = this_player();
inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
			if(inv[i]->query("name") == "月玉璧") {yue = 1; yuebi = inv[i];}
                        if(inv[i]->query("name") == "柳玉璧") {liu = 1; liubi = inv[i];}
                        if(inv[i]->query("name") == "雪玉璧") {xue = 1; xuebi = inv[i];}
                        if(inv[i]->query("name") == "女玉璧") {nu = 1;  nubi = inv[i];}
                        if(inv[i]->query("name") == "草玉璧") {cao = 1; caobi = inv[i];}
                        if(inv[i]->query("name") == "花玉璧") {hua = 1; huabi = inv[i];}
                        if(inv[i]->query("name") == "酒玉璧") {jiu = 1; jiubi = inv[i];}

		}
if( yue && liu && xue && nu && cao && hua && jiu )
{
	destruct(yuebi);
        destruct(liubi);
        destruct(xuebi);
        destruct(nubi);
        destruct(caobi);
        destruct(huabi);
        destruct(jiubi);
	jade = new(__DIR__"guyupai");
	jade->move(me);
message_vision("$N把手里的几角玉璧摆弄了几下．＂咯嚓＂一声，八璧和一．\n",this_player());
	destruct(this_object());

}
else 
message_vision("$N把手里的几角玉璧摆弄了几下．\n",this_player());

return 1;
}
