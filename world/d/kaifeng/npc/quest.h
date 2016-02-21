// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat

#ifndef __KAIFENG_QUEST__
#define __KAIFENG_QUEST__

//#define MAXDELAY   200
// mon reduced time limit. 4/7/98
#define MAXDELAY   60
#define DELAY_CONST 50
#define MAXREWARD  200

#define INDEXTIMES 40
#define CACHESIZE  30
#define INDEXDELTA 20

#define IDX_TYPE 0
#define IDX_NAME 1
#define IDX_ID   2
#define IDX_OBJ  3
#define IDX_AMT  4

// the quest format is the following mapping:
// daoxing :     type     name     id            object         amount
//---------------------------------------------------------------
//  1000   : ({ "find",  "秘笈",   "mi ji" ,     "",             "1" }), 
//  5000   : ({ "give",  "灾民",   "zai min" ,   "白银(silver)", "5" }), 
// 12000   : ({ "kill",  "白骨精", "baigu jing", "",             "3" });
 
//找一本秘笈，救济灾民五两银子，三打白骨精．．．．．．

int *order_list (int *list)
{
  int i, j;
  int size = sizeof(list);
        
  for (i = size-2; i >= 0; i--)
  {
    for (j = 0; j <= i; j++)
    {
      reset_eval_cost();
      if (list[j] > list[j+1])
      {
        int k = list[j];
        list[j] = list[j+1];
        list[j+1] = k;
      }
    }
  }
  return list;
}

// must execute only once !
int *sort_quests (mapping quests)
{
  int *quest_keys = keys (quests);

  return order_list (quest_keys);
}

int quest_accurate_index (int *quest_keys, int daoxing)
{
  int i = 0;
  int j = 0;
  int k = sizeof(quest_keys)-1;

  while (i < k)
  {
    // reset_eval_cost();
    j = (k-i)/2+i;
    if (quest_keys[j] == daoxing)
    {
      return j;
    }  
    else if (quest_keys[j] > daoxing)
    {
      k = j - 1;
    }  
    else
    {
      i = j + 1;
    }  
  }
  return j;
}

void reduce_cache (object who, string cache_name)
{
  mapping cache = who->query(cache_name);
  string key;
  int value = 0;
  int k = 0;
  string *my_keys;
  int *my_values;
  
  if (! cache)
    return;
    
  my_keys = keys(cache);
  my_values = values(cache);
  
  k = sizeof (cache);  
  if (k < CACHESIZE)
    return;
    
  while (k--)
  {
    if (my_values[k] < value ||
        0 == value)
    {
      key = my_keys[k];
      value = my_values[k];
    }
  } 
  who->delete (cache_name+"/"+key);
}

int quest_random_index (int *quest_keys, int i, object who, string cache_name)
{
  int j = INDEXTIMES;
  int k;
  int lower;
  int upper;
  int size = sizeof (quest_keys);

  lower = i - INDEXDELTA;
  upper = i + INDEXDELTA;

  if (lower < 0)
  {
    lower = 0;
    upper = INDEXDELTA + INDEXDELTA;
  }

  if (upper >= size)
  {
    upper = size - 1;
  }

  // adjust here, allow access to lower quests:
  lower = upper/4;
  if (upper - lower < INDEXDELTA)
    lower = 0;
  
  reduce_cache (who, cache_name);
  while (j--)
  {
    string str;
    
    reset_eval_cost();
    k = lower + random (upper-lower);  
    str = cache_name+"/"+to_chinese(k);
    if (! who->query(str))
    {
      who->set(str,who->query("quest/number"));
      return k;
    }
  }
  return -1;
}

int log10 (int i)
{
  int j = 0;
  while (i = i/10)
    j++;
  return j;
}

int quest_reward (object who, mapping quests, string quest)
{
  int reward;
  int exp = who->query("combat_exp");
  int dx = who->query("quest/pending/"+quest+"/daoxing");
  int index = who->query("quest/pending/"+quest+"/index");

  reward = random(who->query("cps")); // initial value
  reward += MAXREWARD*(1+index)/sizeof(quests); // normal value
  reward = reward*(1+log10(exp/10000))*exp/(exp+dx)*dx/(exp+dx); // high value
  reward += random(who->query_int())+random(who->query_kar()); // base value
  if (reward >= MAXREWARD)
    reward = MAXREWARD + random(who->query("kar"));
  return reward;
}

void quest_done (object who)
{
  string *strs = ({
    "慢慢地一小团祥云在$N的身边升起。\n",
    "$N的身上慢慢升起一股祥云。\n",
    "一小股祥云在$N的身上缓缓升起。\n",
    "只见$N的身上徐徐飘浮起一小团祥云。\n",
    "一团小祥云在$N的身上慢慢升起。\n",
  });

  who->add("quest/number",1);
  message_vision (strs[random(sizeof(strs))],who);
  tell_object (who, "你的品德增加了。\n");
}

#endif

