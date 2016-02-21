// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// attribute.c

#include <dbase.h>
#include <skill.h>

int query_str()
{
   return (int)query("str") + (int)query("force_factor")
     + query_temp("apply/strength");
}

int query_cor()
{
   return (int)query("cor") + (int)query("bellicosity") / 50
     + query_temp("apply/courage");
}

int query_int()
{
   int final;
   final = (int)query("int") +query_temp("apply/intelligence");
   if((int)query_skill("literate",1)>20) final += ((int)query_skill("literate",1)-20)/10;
   if(final>40) final=40; 
   return final;   
}

int query_spi()
{
   int final;
   final = (int)query("spi") +query_temp("apply/spirituality");
   if((int)query_skill("spells",1)>20) final += ((int)query_skill("spells",1)-20)/10;
   if(final>40) final=40; 
   return final;
}

int query_cps()
{
   return (int)query("cps") + (int)query("force_factor") / 2
     + query_temp("apply/composure");
}

int query_per()
{
   return (int)query("per")
     + query_temp("apply/personality");
}

int query_con()
{
   int final;
   final = (int)query("con") +query_temp("apply/constitution");
   if((int)query_skill("force",1)>20) final += ((int)query_skill("force",1)-20)/10;
   if(final>40) final=40; 
   return final;
}

int query_kar()
{
   int final;
   final = (int)query("kar") + query_temp("apply/karma") + (int)query("donation")/1000000;
   if(final > 40) final=40;
   return final;
}

