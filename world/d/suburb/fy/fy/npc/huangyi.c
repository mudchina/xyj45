
inherit NPC;

void create()
{
        set_name("»ÆÒÂÎÀ", ({ "guard", "yellow guard"}) );
        set("gender", "ÄÐÐÔ" );
        set("age", 32);
        set("long", "ÕâÊÇÒ»Î»½ðÇ®°ï×Ü¶æµÄ»ÆÒÂÎÀ¡£\n");
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set_skill("sword", 90+random(100));
	set_skill("dodge", 100);
        set("iron-cloth", 200);
        set("chat_chance", 1);
        set("chat_msg", ({
                "»ÆÒÂÎÀÏòÄãºÈµÀ£º¿ÚÁî£¿£¿\n",
                "»ÆÒÂÎÀÏòÄãºÈµÀ£ºÕ¾×¡£®ÁÁÄãµÄÑüÅÆ£¿\n",
        }) );
	
	setup();
	add_money("silver", 5);
        carry_object(__DIR__"obj/tangfu")->wear();
	carry_object("/obj/longsword")->wield();
}

