
// 
// 


#include <ansi.h>
#include <dbase.h>

mapping pawn;
mapping vpawn;
mapping fpawn;

mapping query_pawn() { return pawn; }
mapping query_vpawn() { return vpawn; }
mapping query_fpawn() { return fpawn; }

void set_pawn(string num, string name)
{
	if( !mapp(pawn) ) pawn= ([ num: name ]);
	else pawn[num] = name;
}
void set_vpawn(string num, int val)
{
        if( !mapp(vpawn) ) vpawn= ([ num: val]);
        else vpawn[num] = val;
}
void set_fpawn(string num, string name)
{
        if( !mapp(fpawn) ) fpawn= ([ num: name ]);
        else fpawn[num] = name;
}

int delete_pawn(string num)
{
	if( mapp(pawn) ) {
		map_delete(pawn, num);
		return undefinedp(pawn[num]);
	}
	return 0;

}
int delete_vpawn(string num)
{
        if( mapp(vpawn) ) {
                map_delete(vpawn, num);
                return undefinedp(vpawn[num]);
        }
        return 0;

}
int delete_fpawn(string num)
{
        if( mapp(fpawn) ) {
                map_delete(fpawn, num);
                return undefinedp(fpawn[num]);
        }
        return 0;

}
