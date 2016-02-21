// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit ITEM;

void create()
{
  set_name("【大雪山地图】", ({ "xueshan map","map" }) );
  set_weight(10);
  setup();
  set("unit", "张");
  set("long", @LONG
          【大雪山图】

   
          _/\_
           北

   ※※※※※
   ※大雪山※
   ※※※※※


   ※昆仑※
          
               ※※※※
               ※长安※
               ※※※※

LONG
  );

  setup();
}

void init()
{
}

