
inherit ITEM;

void create()
{
	set_name("½¹»ÆÃ©²Ý", ({ "grass" , "Ã©²Ý", "½¹»ÆÃ©²Ý"}) );
	set_weight(500);
	set_max_encumbrance(8000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "´Ô");
		set("long", "°ëÈË¸ßµÄ½¹»ÆÃ©²Ý¡£\n");
		set("value", 1);
	}
}

int is_container() { return 1; }

