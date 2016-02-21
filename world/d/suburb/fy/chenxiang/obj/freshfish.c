// 
// 


inherit ITEM;
void create()
{
    set_name( "鲜鱼", ({ "freshfish","fish"  }) );
    set("unit", "条");
    set("value",8);
    set("long","
一条上好的鲜鱼
\n");
    set_weight(5);
}
