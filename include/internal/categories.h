#pragma once

#include "../header.h"
BeginHeader
// ============================================================================

typedef enum {

	/// Out of valid code point range
	Invalid_CodePointCategory_TinyUTF8,

	/// Uppers case letter
	Lu_CodePointCategory_TinyUTF8,

	/// Lower case letter
	Ll_CodePointCategory_TinyUTF8,

	/// Title case letter
	Lt_CodePointCategory_TinyUTF8,


	/// Modifier letter
	Lm_CodePointCategory_TinyUTF8,

	/// Other letter
	Lo_CodePointCategory_TinyUTF8,


	/// Non-spacing mark
	Mn_CodePointCategory_TinyUTF8,

	/// Spacing mark
	Mc_CodePointCategory_TinyUTF8,

	/// Enclosing mark
	Me_CodePointCategory_TinyUTF8,


	/// Decimal number
	Nd_CodePointCategory_TinyUTF8,

	/// Letter number
	Nl_CodePointCategory_TinyUTF8,

	/// Other number
	No_CodePointCategory_TinyUTF8,


	/// Connector punctuation
	Pc_CodePointCategory_TinyUTF8,

	/// Dash punctuation
	Pd_CodePointCategory_TinyUTF8,

	/// Open punctuation
	Ps_CodePointCategory_TinyUTF8,

	/// Close punctuation
	Pe_CodePointCategory_TinyUTF8,

	/// Initial punctuation
	Pi_CodePointCategory_TinyUTF8,

	/// Final punctuation
	Pf_CodePointCategory_TinyUTF8,

	/// Other punctuation
	Po_CodePointCategory_TinyUTF8,


	/// Math symbol
	Sm_CodePointCategory_TinyUTF8,

	/// Currency symbol
	Sc_CodePointCategory_TinyUTF8,

	/// Modifier symbol
	Sk_CodePointCategory_TinyUTF8,

	/// Other symbol
	So_CodePointCategory_TinyUTF8,


	/// Space separator
	Zs_CodePointCategory_TinyUTF8,

	/// Line separator
	Zl_CodePointCategory_TinyUTF8,

	/// Paragraph separator
	Zp_CodePointCategory_TinyUTF8,


	/// Control
	Cc_CodePointCategory_TinyUTF8,

	/// Format
	Cf_CodePointCategory_TinyUTF8,

	/// Surrogate
	Cs_CodePointCategory_TinyUTF8,

	/// Private use
	Co_CodePointCategory_TinyUTF8,

	/// Unassigned
	Cn_CodePointCategory_TinyUTF8

} CodePointCategory_TinyUTF8;

// ============================================================================
EndHeader