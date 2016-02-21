// npc: /d/city/npc/wei.c
// Jay 5/15/96

inherit NPC;

void create()
{
        set_name("Î¤´º·¼", ({ "wei chunfang", "chunfang", "wei" }) );
        set("gender", "Å®ĞÔ" );
	set("title", "Àö´ºÔºÀÏ°åÄï");
//	set("nickname", "Â¹¶¦¹«");
        set("age", 42);
        set("long", 
            "Î¤´º·¼ÊÇµ±³¯Â¹¶¦¹«¼æºì»¨»á×Ü¶æÖ÷Î¤Ğ¡±¦ËûÄï£¬ËäÊÇĞì"
	    "Äï°ëÀÏ£¬µ«·çÔÏÓÈ´æ¡£\n");
        set("str", 25);
        set("dex", 25);
        set("con", 25);
        set("int", 25);
        set("shen_type", 1);

        set_skill("unarmed", 20);
	set_skill("force", 20);
        set_skill("dodge", 35);

        set("combat_exp", 25000);

        set("max_kee", 300);
        set("max_gin", 100);
        set("force", 500);
        set("max_force", 500);

        set("attitude", "friendly");
        set("inquiry", ([
            "name" : "ÀÏÄïÎÒ¾ÍÊÇÎ¤´º·¼¡£",
            "Î¤Ğ¡±¦" : "ÄÇÊÇÎÒµÄ¹Ô¶ù×Ó£¬³¤µÃ¾ÍÏñÄã¡£",
            "Àö´ºÔº" : "ÎÒÃÇÀö´ºÔº¿ÉÊÇÑïÖİ³ÇÀïÍ·Ò»·İµÄÕÒÀÖ×ÓÈ¥´¦¡£",
            "here" : "ÎÒÃÇÀö´ºÔº¿ÉÊÇÑïÖİ³ÇÀïÍ·Ò»·İµÄÕÒÀÖ×ÓÈ¥´¦¡£",
       ]) );

        setup();
        setup();
        set("chat_chance", 15);
        set("chat_msg", ({
                "Î¤´º·¼µÃÒâµØËµµÀ£ºµ±ÄêÀÏÄïÎÒ±êÖÂµÃºÜ£¬Ã¿ÌìÓĞºÃ¼¸¸ö¿ÍÈË¡£\n",
                "Î¤´º·¼Å­ÂîµÀ£ºÀ±¿éÂèÂè£¬ÒªÊÇÂŞÉ²¹í¡¢ºìÃ«¹í×Óµ½Àö´ºÔºÀ´£¬ÀÏÄïÓÃ´óÉ¨ÖãÅÄÁË³öÈ¥¡¡£\n",
                "Î¤´º·¼¶ÔÄãËµµÀ£ºÄãÒ»Ë«ÑÛ¾¦Ôôß¯ÎûÎûµÄ£¬ÕæÏñÄÇ¸öÀ®Âï£¡\n",
        }) );
        carry_object("/d/suburb/xkx/city/obj/flower_shoe")->wear();

        carry_object("/d/suburb/xkx/city/obj/pink_cloth")->wear();
}
void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object me)
{
    command("look " + me->query("id"));

    if (me->query("gender")=="ÎŞĞÔ") {
       command("say Äãµ±ÀÏÄïÊÇÀÃæ»×ÓÂğ£¿À±¿éÂèÂè£¬ÀÏÄïÂúººÃÉ²Ø»Ø¶¼½Ó£¬¾ÍÊÇ²»ËÅºòÌ«¼à£¡");
       command("kick " + me->query("id"));
       message("vision", me->name() +"±»Î¤´º·¼Ò»½ÅÌß³öÃÅÍâ¡£\n",
                environment(me), ({me}));
       me->move("/d/suburb/xkx/city/nandajie2");
       message("vision", me->name() +"±»ÈË´ÓÀö´ºÔºÀïÌßÁË³öÀ´£¬ÔÔµ¹ÔÚµØÉÏ£¬¿ÄµôÁ½¿ÅÃÅÑÀ¡£\n", 
                environment(me), ({me}));

    }
    else {
    if (me->query("class") =="bonze") {
       command("say ßÏ£¬" + RANK_D->query_respect(me) 
                +"Ò²À´¹â¹ËÎÒÃÇÀö´ºÔº°¡¡£");
       command("say Ïëµ±ÄêÎÒ½Ó¹ıÒ»¸öÎ÷²ØÀ®Âï£¬ËûÉÏ´²Ç°Ò»¶¨ÒªÄî¾­£¬Ò»ÃæÄî¾­£¬ÑÛÖé×Ó¾Í¹ÇÁïÁïµÄÇÆ×ÅÎÒ¡£");
    }
    if (me->query("gender")=="Å®ĞÔ") {
       command("say °¥Ñ½£¬ÕâÄêÔÂ´ó¹ÃÄïÒ²¹äÒ¤×Ó£¬³ÉºÎÌåÍ¬¡£");
       command("sigh");
       command("say ¿ÉÏ§ÎÒ¶ù×Ó²»ÔÚ£¬²»È»ÈÃËûËÅºòÄã¡£");
    }
    command("say Â¥ÉÏÂ¥ÏÂµÄ¹ÃÄïÃÇ£¬¿ÍÈËÀ´ÁË£¡");
    }
    return ;
}

