// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
 
inherit NPC;
 
void create()
{
   set_name("典簿", ({"dian bu"})); 
        set("gender", "男性" );
   set("long", "御马监典簿。\n");
        set("age",40);
   set("title", "御马监");
        set("str", 30);
        set("int", 20);
   set("con", 30);
   set("spi", 20);
        set("per", 15);
   set("class", "xian");
   set("attitude", "friendly");
        set("combat_exp", 8500);
   set("max_kee", 1000);
   set("max_sen", 1000);
        setup();
        carry_object("/d/obj/cloth/xianpao")->wear();
}
 

