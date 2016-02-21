// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit ITEM;
inherit F_SAVE;

void create()
{
        set_name("文档", ({ "doc" }));
        if (clonep())
                set_default_object(__FILE__);
        setup();
}

string query_save_file()
{return this_object()->query("file_name");}


