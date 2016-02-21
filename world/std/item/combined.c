// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// combined_item.c
// 4/25/98 mon changed move() so that money will be combined
// even at a non-living thing, eg, room.

#include <dbase.h>
#include <name.h>

inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_MOVE;
inherit F_NAME;

static int amount;

void setup()
{
}

int query_amount() { return amount; }

private void destruct_me() { destruct(this_object()); }

void set_amount(int v)
{
   if( v < 0 ){
      amount=0; // mon 4/16/98
      error("combine:set_amount less than 1.\n");
   }
   if( v==0 ) {
       amount = 0; // mon 4/16/98
       call_out("destruct_me", 1);
   }
   else {
     amount = v;
     this_object()->set_weight(v * (int)query("base_weight"));
   }
}

void add_amount(int v) { set_amount(amount+v); }

string short()
{
   return chinese_number(query_amount()) + query("base_unit")
     + ::short();
}

varargs int move(mixed dest, int silent)
{
   object env, *inv;
   int i, total, result;
   string file;

   result= ::move(dest, silent);
   if(env = environment()) {
     file = base_name(this_object());
     inv = all_inventory(env);
     total = (int)query_amount();
     for(i=0; i<sizeof(inv); i++) {
        if( inv[i]==this_object() ) continue;
        if( base_name(inv[i])==file ) {
          total += (int)inv[i]->query_amount();
          destruct(inv[i]);
        }
     }
     set_amount(total);
   }
   return result;
}
