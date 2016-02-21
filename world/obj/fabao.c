// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// fabao.c

#include <weapon.h>
#include <armor.h>

inherit EQUIP;
inherit F_SAVE;
inherit F_BACKUP;

void create()
{
   seteuid(0);   
   set_name("自制法宝物件", ({ "fabao object", "fabao", "object" }) );
   setup();
}

void reset()
{
    if( !environment() ||  //mon 2/4/98
        query("owner_id") != getuid(environment()) )  {
        destruct(this_object());
        return;
    }
}

// This is used by F_SAVE to determine the filename to save our data.
string query_save_file()
{
   string id, series;

   id = query("owner_id");
   series = query("series_no");
   if( !id || !series) return 0;

   return sprintf(DATA_DIR "fabao/%c/%s-%s", id[0], id, series);
}

int save()
{
   if( query("equipped") )   {
     write("必须放下法宝才能储存。\n");
     return 0;
   }
   return ::save();
}

void setup()
{
   ::setup();
}

int query_unique()  { return 1; }
