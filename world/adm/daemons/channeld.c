// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// channeld.c
// modified by tool on 96/10/05
// modified by mon@xyj on 10/97 to add support for
//          intermud emote.

#include <ansi.h>
#include <net/dns.h>
#include <net/macros.h>
inherit F_DBASE;

mapping channels = ([
   "sys":   ([   "msg_speak": HIG "【系统】%s：%s\n" NOR, "wiz_only": 1 ]),
   "wiz":   ([   "msg_speak": HIY "【巫师】%s：%s\n" NOR,
          "msg_emote": HIY "【巫师】%s\n" NOR,
          "wiz_only": 1
        ]),
   "gwiz":   ([   "msg_speak": BGRN "【网际巫师】%s：%s\n" NOR,
          "msg_emote": BGRN "【网际巫师】%s\n" NOR,
          "wiz_only": 1, "intermud": GWIZ, "channel": "CREATOR",
          "filter": 1,
          "intermud_emote": 1 ]),
   "xyj":   ([   "msg_speak": HIR "【西游记】%s：%s\n" NOR,
          "msg_emote": HIR "【西游记】%s\n" NOR,
          "intermud": GCHANNEL, "channel": "xyj",
          "filter": (:$1["MUDLIB"]=="A Journey to the West" :) ]),
   "es":   ([   "msg_speak": HIR "【网际闲聊】%s：%s\n" NOR,
          "msg_emote": HIR "【网际闲聊】%s\n" NOR,
          "intermud": GCHANNEL, "channel": "es",
          "filter": 1 ]), //keep the channel name
          //as "es" to be compatible with other
          //ES2 type muds.
        "sldh": ([      "msg_speak": HIC "【水陆大会】%s：%s\n" NOR,
                                "msg_emote": HIC "【水陆大会】%s\n" NOR,
                         ]),

/*   "es":   ([   "msg_speak": HIR "【东方故事】%s：%s\n" NOR,
          "msg_emote": HIR "【东方故事】%s" NOR,
          "intermud": GCHANNEL, "channel": "es",
          "filter": (: $1["MUDLIB"]=="Eastern Stories" :) ]),
   "twiz":   ([   "msg_speak": HIW "【台湾巫师】%s：%s\n" NOR,
          "msg_emote": HIW "【台湾巫师】%s" NOR,
          "wiz_only":1, "intermud": GCHANNEL, "channel": "twiz",
          "filter": (: $1["HOSTADDRESS"][0..2]=="140" :) ]),
*/
   "chat":   ([   "msg_speak": HIC "【闲聊】%s：%s\n" NOR,
          "msg_emote": HIC "【闲聊】%s\n" NOR,
         ]),
   "rumor":([   "msg_speak": HIM "【谣言】%s：%s\n" NOR,
          "msg_emote": HIM "【谣言】%s\n" NOR,
          "anonymous": "某人"
        ]),
/*   "music":([   "msg_speak": WHT "【心笙乐府】%s唱着：%s\n" NOR,
          "msg_speak": WHT "【心笙乐府】%s" NOR
         ]),
*/
]);

void create()
{
   seteuid(getuid());   // This is required to pass intermud access check.
        set("channel_id", "频道精灵");
}

varargs int do_channel(object me, string verb, string arg, int emote)
{
   object *ob;
   string *tuned_ch, who, arg1;
   int time,count,last_chat,len;

   // Check if this is a channel emote.
        if(sizeof(verb)>0)
           if( verb[sizeof(verb)-1] == '*' ) {
     emote = 1;
     verb = verb[0..<2];
   }


   if( !mapp(channels) || undefinedp(channels[verb]) )
     return 0;

   if( userp(me) ) {
     if(channels[verb]["wiz_only"] && !wizardp(me) )
        return 0;

                //temporary block chat flooding.
     time=time();
     if(me->query("channel/chat_block") &&
       (time-me->query("channel/chat_block"))<0 )
        return notify_fail("你的交谈频道被暂时关闭了。\n");
              
           count=me->query("channel/chat_count");
                count++;
     last_chat=me->query("channel/last_chat");
     if (count>2) {
       count=0;
       me->set("channel/last_chat",time);
       if (time==last_chat) {
         me->set("channel/chat_block",time+180);
         return notify_fail("因为一次讲话太多，你的交谈频道被暂时关闭了。\n");
       }
           }
     me->set("channel/chat_count",count);

     if( arg==(string)me->query_temp("last_channel_msg") )
        return notify_fail("用交谈频道说话请不要重复相同的讯息。\n");

     // If we speaks something in this channel, then must tune it in.
     tuned_ch = me->query("channels");
     if( !pointerp(tuned_ch) )
        me->set("channels", ({ verb }) );
     else if( member_array(verb, tuned_ch)==-1 )
        me->set("channels", tuned_ch + ({ verb }) );

     // Support of channel emote
     if( emote && !channels[verb]["intermud_emote"]) {
        string vb, emote_arg;

        if( nullp(arg) ) return 0;
        if( sscanf(arg, "%s %s", vb, emote_arg)!= 2 ) {
          vb = arg;
          emote_arg = "";
        }
     if( channels[verb]["anonymous"] )
           arg = EMOTE_D->do_emote(me, vb, emote_arg, 1, 1);
                else {
        arg = EMOTE_D->do_emote(me, vb, emote_arg, 1, 0,
                       !undefinedp(channels[verb]["intermud"]));
                   if(!arg) {
                      string id, site;
                      if(sscanf(emote_arg, "%s@%s", id, site)==2) {
        "/adm/daemons/network/services/gemote_q"->
        send_msg(channels[verb]["channel"], me,
        vb, id, site, channels[verb]["filter"]);
                        return 1;
           }
                   }
                }

     if( !arg ) return 0;
     }
   }

   // Make the identity of speaker.

   if( channels[verb]["anonymous"] ) {
     who = channels[verb]["anonymous"];
     if (userp(me))
                do_channel( this_object(), "sys", 
       sprintf("谣言：%s(%s)。", me->name(),me->query("id")));
   }
   else if( userp(me) || !stringp(who = me->query("channel_id")) ) {
     who = me->query("name");
     if(me->query("id")) 
       who=who+"(" + capitalize(me->query("id")) + ")";
             }

   // Ok, now send the message to those people listening us.

   ob = filter_array( users(), "filter_listener", this_object(), channels[verb] );
   if( !arg ) arg = "．．．";

   len=strlen(arg);
   while(len>1 && arg[len-1]=='\n')
       arg=arg[0..((len--)-2)];
   //remove excessive return at the end. by mon 9/20/97

        if(userp(me)) arg1=replace_string(arg, "$N", me->name());
        else arg1=arg;

   if( emote ) {
     // Support of old behavier of intermud emote.
     if( channels[verb]["intermud_emote"] ) arg1 = who + " " + arg;

     message( "channel:" + verb,
        sprintf( channels[verb]["msg_emote"], arg1 ), ob );
   } else
     message( "channel:" + verb,
        sprintf( channels[verb]["msg_speak"], who, arg1 ), ob );

   if( arrayp(channels[verb]["extra_listener"]) ) {
     channels[verb]["extra_listener"] -= ({ 0 });
     if( sizeof(channels[verb]["extra_listener"]) )
        channels[verb]["extra_listener"]->relay_channel(me, verb, arg);
   }
   
   if( !undefinedp(channels[verb]["intermud"])
   &&   base_name(me) != channels[verb]["intermud"] ) {
          if(userp(me)) {
            arg=replace_string(arg, "$N", me->name()+"("+
                capitalize(me->query("id"))+"@"+Mud_name()+")",1);
            arg=replace_string(arg, "$N", me->name());
          }
     channels[verb]["intermud"]->send_msg(
     channels[verb]["channel"], me->query("id"), 
                   me->name(1), arg, emote, channels[verb]["filter"] );
        }

   if( userp(me) ) 
     me->set_temp("last_channel_msg", arg);

   return 1;
}

int filter_listener(object ppl, mapping ch)
{
   // Don't bother those in the login limbo.
   if( !environment(ppl) ) return 0;

   if( ch["wiz_only"] ) return wizardp(ppl);
   return 1;
}

void register_relay_channel(string channel)
{
   object ob;

   ob = previous_object();
   if( undefinedp(channels[channel]) || !ob) return;
   if( arrayp(channels[channel]["extra_listener"]) ) {
     if( member_array(ob, channels[channel]["extra_listener"]) >=0 ) return;
     channels[channel]["extra_listener"] += ({ ob });
   } else
     channels[channel]["extra_listener"] = ({ ob });
}
