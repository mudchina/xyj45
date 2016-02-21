// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 

// for encoding format conversion.
// mon 5/11/98

// GB:   0
// BIG5: 1
static int chinese_encoding=0;

int query_encoding() {return chinese_encoding;}

void set_encoding(int encoding) {chinese_encoding=encoding;}
