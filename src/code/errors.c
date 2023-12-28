#include "code_begin.h"
Begin
// ============================================================================

const char * nameOfError_TinyUTF8( enum Error_TinyUTF8 error )
{
	switch (error) {
		case No_Error_TinyUTF8: return "None";
		case SrcTooSmall_Error_TinyUTF8: return "SrcTooSmall";
		case DestTooSmall_Error_TinyUTF8: return "DestTooSmall";
		case InvalidCP_Error_TinyUTF8: return "InvalidCP";
		case CPOutOfRange_Error_TinyUTF8: return "CPOutOfRange";
		case InvalidCoding_Error_TinyUTF8: return "InvalidCoding";
		case InvalidCodedCP_Error_TinyUTF8: return "InvalidCodedCP";
	}
	return "<Unknown>";
}

// ============================================================================
End
