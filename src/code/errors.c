#include "code_begin.h"
Begin
// ============================================================================

const char * nameOfError_TinyUTF8( enum Error_TinyUTF8 error )
{
	switch (error) {
		case No_Error_TinyUTF8: return "None";
		case SrcTooSmall_Error_TinyUTF8: return "SourceTooSmall";
		case DestTooSmall_Error_TinyUTF8: return "DestinationTooSmall";
		case CPOutOfRange_Error_TinyUTF8: return "CodePointOutOfValidRange";
		case InvalidCoding_Error_TinyUTF8: return "InvalidCoding";
		case InvalidCodedCP_Error_TinyUTF8: return "InvalidCodedCP";
	}
	return "<Unknown>";
}

// ============================================================================
End
