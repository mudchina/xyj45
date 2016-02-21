// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 
     //accuse.c
//Feb/01/97 wuliao@xyj
#include <login.h>
#include <ansi.h>

int main(object me, string arg){

        object obj;
        int year, times;
        string pro;

   seteuid(getuid());

   if( me->query("combat_exp")<10000 )
       return notify_fail("ºÃºÃÁ·¹¦°É£¬±ğ¹âÏë×Å¼ì¾Ù±ğÈË£¡ \n");
        if( !arg )
       return notify_fail("ÄãÏë¼ì¾ÙË­£¿ \n");
        obj = find_player(arg);
        if ( !obj )
            return notify_fail("Õâ¸öÈË¶¼²»ÔÚÏßÉÏ£¡ \n");
        if( wizardp(obj) )
       return notify_fail("Äã²»ÄÜ¼ì¾ÙÎ×Ê¦¡£\n");
        times = me->query("robot_accusing");
   if( obj==me ){
       tell_object(me, "ÄãÒÑ¾­¼ì¾ÙÁË±ğÈË" + chinese_number(times) + "´Î¡£\n");
            return 1;
//       return notify_fail("ÄãÒª¼ì¾Ù×Ô¼º£¿ \n");
        }
        pro = gender_pronoun(obj->query("gender"));
   if( obj->is_ghost() )
            return notify_fail( obj->name(1) + "ÒÑ¾­ËÀÁË£¬·Å" + pro + "Ò»Âí°É¡£\n");
   if( environment(obj)->query("short")=="·¨Ôº" )
       return notify_fail( obj->name(1) + "ÒÑ¾­±»×¥½ø·¨ÔºÁË£¡ \n");
        if( !wizardp(me) ){
            year = me->query("combat_exp")/1000;
            if( 2*times>(year + 2 ))
                return notify_fail("ÄãÒÑ¾­ÔİÊ±µØÊ§È¥ÁË¼ì¾ÙÈ¨£¡ \n");
            me->add("robot_accusing",1);
       if( 2*(me->query("robot_accusing"))>( year + 2) ){
                me->move("/d/wiz/gongtang"); 
     return notify_fail("ÄãÀÄÓÃ¼ì¾ÙÈ¨Àû£¬ÏëÀ´µ·ÂÒ°É£¿£¡ \n");
             }
        else{
                  if( obj->query_temp("accuser/"+getuid(me)) ){
                       return notify_fail("ÄãÒÑ¾­ÔÚ¼ì¾Ù" + pro + "ÁË£¡¡ \n");
                  }
                  obj->set_temp("accuser/"+getuid(me), me->name() );
                  if( sizeof(obj->query_temp("accuser"))>4 ){
                  ROBOT_CHECK->test_me(obj);
                  tell_object(obj, HIW+"Äã±»ÈË¼ì¾ÙÁË£¬ÇëÄã½ÓÊÜÒ»¸öĞ¡Ğ¡µÄ²âÑé¡£\n" NOR);     
       tell_object(me, HIW+"ÄãÍ¶ÁË×îºóÒ»Æ±¡£" + obj->name() + "±»×¥½øÁË·¨Ôº£¡ \n" NOR);
                  obj->start_busy(20);
                  obj->delete_temp("accuser");
                  if( present("judge", environment(obj)))
                  me->command("chat* hehe " + obj->query("id"));
                  }
                  else{
                  tell_object(me, HIW+"Äã¼ì¾Ù" + obj->name() + "»úÆ÷ÈË£¬»¹²î" + chinese_number( 5 - sizeof(obj->query_temp("accuser")) ) + "Æ±¡£ \n" NOR);
                  }
              me->start_busy(1);
              }
        }
   else{
            ROBOT_CHECK->test_me(obj);
            tell_object(obj, HIW+"Äã±»ÈË¼ì¾ÙÁË£¬ÇëÄã½ÓÊÜÒ»¸öĞ¡Ğ¡µÄ²âÑé¡£\n" NOR);
            obj->start_busy(20);
            obj->delete_temp("accuser");
            present("judge",environment(obj))->command("chat* hehe "+obj->query("id")); 
   }
      return 1;
} 

int help(object me)
{
write(@HELP
Ö¸Áî¸ñÊ½ : accuse <Ä³ÈË>

Õâ¸öÖ¸ÁîÓÃÀ´¼ì¾Ù±ğÈË»úÆ÷ÈË£¬²»¹ıÒªÓĞÊ®ÄêµÄµÀĞĞ¡£Çë½÷É÷Ê¹ÓÃÕâÒ
Ò»Ö¸Áî¡£¼ì¾Ù×Ü´ÎÊı²»¿É³¬¹ıµÀĞĞÄêÊıµÄÒ»°ë¡£ÀÄÓÃÕß½«±»ÊÓÎª¹ÊÒâ
µ·ÂÒ£¬´òÈë¹«ÌÃ£¡£¡£¡

accuse ×Ô¼º£º    ¸ø³öÄã¼ì¾Ù±ğÈË×Ü´ÎÊı£¬
accuse ±ğÈË£º    ¼ì¾Ù±ğÈË¡£

HELP
);
   return 1;
} 
