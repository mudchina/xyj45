inherit ROOM;
int check_container(object ob);
void create()
{
        set("short", "Ç§½ğÂ¥Íâ");
        set("long", @LONG
´ËÂ¥Ëä²»ÔÚ¾©¶¼£¬µ«È´ÊÇÖĞÔ­×îÓĞÃûµÄÇàÂ¥¡£ÕâÀïÓĞ×î¹óµÄ¾Æ£¬Ò²ÊÇ×îºÃµÄ¾Æ£»
ÕâÀïÓĞ×î¹óµÄÅ®ÈË£¬Ò²ÊÇ×îÓĞÎ¶¶ùµÄÅ®ÈË£»ÕâÀïÓĞ×î¹óµÄ·şÎñ£¬Ò²ÊÇ×îºÃµÄ·şÎñ¡£
Öìºì´óÃÅÉÏÅÆ£¨£ó£é£ç£î£©Ò»¿é£¬ÓÖ¸ßĞüÒ»¿éÓù´Í½ğØÒ£º
[1;35m
			´ºÉ«ÎŞ±ß
[2;37;0m
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : "/d/suburb/fy/fy/swind4",
  "west" : __DIR__"pingfeng",
]));
        set("item_desc", ([
                "sign": @TEXT
Ç§½ğÂ¥Â¥¹æ£º
£±£®²»¿É¼Ğ´øÈÎºÎ±øÆ÷ÈëÂ¥¡£
£²£®ÒÔ·ÀÄú±»Ç§½ğÂ¥Ğ¡½ãÎóÈÏÎªÃ»ÓĞÏû·ÑÄÜÁ¦£¬
¡¡¡¡²»¿É¼Ğ´øÈÎºÎÊ³Îï£¬¾ÆË®ÈëÂ¥¡£
£³£®´ó¼Ò³öÃÅÔÚÍâÊÇÅóÓÑ£¬Ïà»¥¸øµãÃæ×Ó£¬
¡¡¡¡´ò¼Ü£¬ÄÖÊÂÕßÂ¥¹æ´¦ÖÃ¡£
£´£®£¢ÉÍÍ·£¢¸øµÃÔ½¶à£¬ÄúÊÜµÄËÅºîÔ½ºÃ¡£
TEXT
        ]) );

	set("outdoors","fengyun");
	set("no_fight",1);
	set("no_magic",1);
	set("NONPC",1);
        set("objects", ([
        __DIR__"npc/guinu" : 2,
                        ]) );
        setup();
}
int valid_leave(object me, string dir)
{
        object ob;
	object *inv;
	int i;
        if( dir == "west" && !(int)this_object()->query("enter_permission") && ob = present("guinu",this_object()))
        {
		message_vision("$NÍûÍûÌì£¬¶Ô$nĞ¦×ÅËµ£ºÊ±³½ÉĞÔç£¬¹ÃÄïÃÇ»¹ÔÚË¯£¬Äú£®£®£®\n", ob, me);
		return		notify_fail("ÈÌÄÍÒ»ÏÂ°É£¡\n");
        }
        if( dir == "west" &&  ob = present("guinu",this_object()))
        {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
                        if((int)inv[i]->query("weapon_prop"))
			return notify_fail(ob->name()+"ÏòÄãĞ¦µÀ£ºÇ§½ğÂ¥ÓĞÇ§½ğÂ¥µÄÂ¥¹æ£¬ÄúÇë¿´ÅÆ£®\n");
			if((int)inv[i]->query("food_remaining") != 0)
			return notify_fail(ob->name()+"ÏòÄãĞ¦µÀ£ºÇ§½ğÂ¥ÓĞÇ§½ğÂ¥µÄÂ¥¹æ£¬ÄúÇë¿´ÅÆ£®\n");
			if((int)inv[i]->query("liquid/remaining") !=0)
			return notify_fail(ob->name()+"ÏòÄãĞ¦µÀ£ºÇ§½ğÂ¥ÓĞÇ§½ğÂ¥µÄÂ¥¹æ£¬ÄúÇë¿´ÅÆ£®\n");
			if((int)inv[i]->is_container()) 
//			if(check_container(inv[i]))
			return notify_fail(ob->name()+"ÏòÄãĞ¦µÀ£ºÇ§½ğÂ¥ÓĞÇ§½ğÂ¥µÄÂ¥¹æ£¬ÄúÇë¿´ÅÆ£®\n");
		}
        me->set("food",0);
        me->set("water",0);
        }
	return 1;
}

int check_container(object ob)
{
object *inv;
int i;
inv = all_inventory(ob);
 for(i=0; i<sizeof(inv); i++)
 {
                        if(inv[i]->query("weapon_prop"))
                        return 1;
                        if(inv[i]->query("food_remaining") != 0)
                        return 1;
                        if(inv[i]->query("liquid/remaining") !=0)
                        return 1;
                        if(inv[i]->is_container()) 
                        if(check_container(inv[i]))
                        return 1;
 }
return 0;
}
