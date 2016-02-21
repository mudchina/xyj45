// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// vendor.c

#include <dbase.h>

int is_vendor()
{
  return 1;
}

int is_good (mixed arg)
{
   if (! arg)
      return 0;
   if (! stringp(arg))
      return 0;
   if (find_object(arg))
      return 1;
   if (load_object(arg))
      return 1;
   return 0;
}

int buy_object(object me, string what)
{
  string ob;
  mapping goods;
  string list, *name;
  int i;

  if( stringp(ob = query("vendor_goods/" + what)) )
   return ob->query("value");
  else {
        if( !mapp(goods = query("vendor_goods")) ) return 0;
        name = keys(goods);
        for(i=0; i<sizeof(name); i++){
          if(is_good(name[i]) && (what == name[i]->name() || what == (name[i]->query("id"))))
             return    (int)  (name[i]->query("value")) ;
        }
        for(i=0; i<sizeof(name); i++){
          if(is_good(goods[name[i]]) && (what == goods[name[i]]->name() || what == (goods[name[i]]->query("id"))))
             return    (int)  (goods[name[i]]->query("value")) ;
        }
   return 0;
  }
}

int complete_trade(object me, string what)
{
  string ob_file;
  object ob;
  mapping goods;
  string list, *name, last = "";
  int i;

  if( stringp(ob_file = query("vendor_goods/" + what)) ) {
   ob = new(ob_file);
   if(ob->move(me)) {
      message_vision("$N向$n买下一" + 
      ob->query("unit") + ob->query("name") + "。\n", me, this_object() );
      return 1;
   }
  }
  if( !mapp(goods = query("vendor_goods")) ) return 0;
  name = keys(goods);
  for(i=0; i<sizeof(name); i++){
     if(is_good (name[i]) && (what == name[i]->name() || what == (name[i]->query("id"))))
     {
       if( stringp(ob_file = name[i]) ) {
          ob = new(ob_file);
          goods[name[i]]--;
          if(goods[name[i]] <= 0){
          map_delete(goods,name[i]);
          last = "最后";
          }
          if(ob->move(me)){
            printf("你向%s买下%s一%s%s.\n",this_object()->query("name"),
                   last,
                   ob->query("unit"), ob->name());
          }
          else
             destruct(ob);
          return 1;
        }
     }
  }
  for(i=0; i<sizeof(name); i++){
     if(is_good (goods[name[i]]) && (what == goods[name[i]]->name() || what == (goods[name[i]]->query("id"))))
     {
       ob = new(goods[name[i]]);
       if(ob->move(me)) {
          message_vision("$N向$n买下一" + 
          ob->query("unit") + ob->query("name") + "。\n", me, this_object() );
          return 1;
       }
     }
   }

  return notify_fail("没有这样东西卖。\n");
}

string price_string(int v)
{
  if( v%10000 == 0 )
   return (v/10000) + "两黄金";
  if( v%100 == 0 )
   return (v/100) + "两银子";
  return v + "文钱";
}

int do_vendor_list(string arg)
{
  mapping goods;
  string list, *name;
  int i;
  string tlist;

  if( !mapp(goods = query("vendor_goods")) ) return 0;
  if( arg && !this_object()->id(arg) ) return 0;
  name = keys(goods);
  if(!sizeof(name))
    return notify_fail("这儿的东西全卖光了。\n");
  list = "你可以购买下列这些东西：\n";
  for(i=0; i<sizeof(name); i++) {
   if (is_good(goods[name[i]])) {
     if (! is_chinese(name[i]))
        tlist = sprintf("%s(%s)", goods[name[i]]->query("name"), name[i]);
     else
        tlist = sprintf("%s(%s)", name[i], goods[name[i]]->query("id"));
     list += sprintf("%-30s：%s\n", tlist,
      price_string(goods[name[i]]->query("value")) );
   } else if (is_good(name[i])) {
     tlist = sprintf("%s(%s)", name[i]->name(),name[i]->query("id"));
     list += sprintf("%-30s：%s\n", tlist,
      price_string(name[i]->query("value")) );

   }
    }
  write(list);
  return 1;  
}
