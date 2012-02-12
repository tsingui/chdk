#include "../generic/wrappers.c"

long lens_get_focus_pos()
{
	//return _GetFocusLensSubjectDistance();    // returns plaintext, calls GetCurrentTargetDistance to get value
	return _GetCurrentTargetDistance(); 
}

long lens_get_focus_pos_from_lens()
{
	return _GetCurrentTargetDistance(); 
	//return _GetFocusLensSubjectDistanceFromLens(); 
}

long lens_get_target_distance()
{
	return _GetCurrentTargetDistance();
}

//VERIFY_SD780 Only one arg?
long OpLog_Get(long i)
{
    extern int _OpLog_Get(int);
	return _OpLog_Get(i);
}
