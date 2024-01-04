
#include "internal/stdc.h"

/// Table up to code point 127
static
const uint16_t categoryLookupTable[ ] = {
	0x5E52, 0x4A92, 0x4A4E, 0x3E53, 0x49B2, 0x4929, 0x2529, 0x2529,
	0x2532, 0x4A73, 0x4E52, 0x421, 0x421, 0x421, 0x421, 0x421,
	0x421, 0x421, 0x421, 0x42E, 0x49F5, 0x32A2, 0x842, 0x842,
	0x842, 0x842, 0x842, 0x842, 0x842, 0x842, 0x9D3, 0x3E7A
};

const size_t categoryLookupTableCount = 127;


/// Starts at code point 128
static
const uint32_t categorySearchTable[ ] = {
	0x403FA, 0x50017, 0x50812, 0x51074,
	0x53016, 0x53812, 0x54015, 0x54816,
	0x55005, 0x55810, 0x56013, 0x5681B,
	0x57016, 0x57815, 0x58016, 0x58813,
	0x5902B, 0x5A015, 0x5A802, 0x5B032,
	0x5C015, 0x5C80B, 0x5D005, 0x5D811,
	0x5E04B, 0x5F812, 0x602C1, 0x6B813,
	0x6C0C1, 0x6FAE2, 0x7B813, 0x7C0E2,
	0x80001, 0x80802, 0x81001, 0x81802,
	0x82001, 0x82802, 0x83001, 0x83802,
	0x84001, 0x84802, 0x85001, 0x85802,
	0x86001, 0x86802, 0x87001, 0x87802,
	0x88001, 0x88802, 0x89001, 0x89802,
	0x8A001, 0x8A802, 0x8B001, 0x8B802,
	0x8C001, 0x8C802, 0x8D001, 0x8D802,
	0x8E001, 0x8E802, 0x8F001, 0x8F802,
	0x90001, 0x90802, 0x91001, 0x91802,
	0x92001, 0x92802, 0x93001, 0x93802,
	0x94001, 0x94802, 0x95001, 0x95802,
	0x96001, 0x96802, 0x97001, 0x97802,
	0x98001, 0x98802, 0x99001, 0x99802,
	0x9A001, 0x9A802, 0x9B001, 0x9B822,
	0x9C801, 0x9D002, 0x9D801, 0x9E002,
	0x9E801, 0x9F002, 0x9F801, 0xA0002,
	0xA0801, 0xA1002, 0xA1801, 0xA2002,
	0xA2801, 0xA3002, 0xA3801, 0xA4022,
	0xA5001, 0xA5802, 0xA6001, 0xA6802,
	0xA7001, 0xA7802, 0xA8001, 0xA8802,
	0xA9001, 0xA9802, 0xAA001, 0xAA802,
	0xAB001, 0xAB802, 0xAC001, 0xAC802,
	0xAD001, 0xAD802, 0xAE001, 0xAE802,
	0xAF001, 0xAF802, 0xB0001, 0xB0802,
	0xB1001, 0xB1802, 0xB2001, 0xB2802,
	0xB3001, 0xB3802, 0xB4001, 0xB4802,
	0xB5001, 0xB5802, 0xB6001, 0xB6802,
	0xB7001, 0xB7802, 0xB8001, 0xB8802,
	0xB9001, 0xB9802, 0xBA001, 0xBA802,
	0xBB001, 0xBB802, 0xBC021, 0xBD002,
	0xBD801, 0xBE002, 0xBE801, 0xBF042,
	0xC0821, 0xC1802, 0xC2001, 0xC2802,
	0xC3021, 0xC4002, 0xC4841, 0xC6022,
	0xC7061, 0xC9002, 0xC9821, 0xCA802,
	0xCB041, 0xCC842, 0xCE021, 0xCF002,
	0xCF821, 0xD0802, 0xD1001, 0xD1802,
	0xD2001, 0xD2802, 0xD3021, 0xD4002,
	0xD4801, 0xD5022, 0xD6001, 0xD6802,
	0xD7021, 0xD8002, 0xD8841, 0xDA002,
	0xDA801, 0xDB002, 0xDB821, 0xDC822,
	0xDD805, 0xDE001, 0xDE842, 0xE0065,
	0xE2001, 0xE2803, 0xE3002, 0xE3801,
	0xE4003, 0xE4802, 0xE5001, 0xE5803,
	0xE6002, 0xE6801, 0xE7002, 0xE7801,
	0xE8002, 0xE8801, 0xE9002, 0xE9801,
	0xEA002, 0xEA801, 0xEB002, 0xEB801,
	0xEC002, 0xEC801, 0xED002, 0xED801,
	0xEE022, 0xEF001, 0xEF802, 0xF0001,
	0xF0802, 0xF1001, 0xF1802, 0xF2001,
	0xF2802, 0xF3001, 0xF3802, 0xF4001,
	0xF4802, 0xF5001, 0xF5802, 0xF6001,
	0xF6802, 0xF7001, 0xF7822, 0xF8801,
	0xF9003, 0xF9802, 0xFA001, 0xFA802,
	0xFB041, 0xFC802, 0xFD001, 0xFD802,
	0xFE001, 0xFE802, 0xFF001, 0xFF802,
	0x100001, 0x100802, 0x101001, 0x101802,
	0x102001, 0x102802, 0x103001, 0x103802,
	0x104001, 0x104802, 0x105001, 0x105802,
	0x106001, 0x106802, 0x107001, 0x107802,
	0x108001, 0x108802, 0x109001, 0x109802,
	0x10A001, 0x10A802, 0x10B001, 0x10B802,
	0x10C001, 0x10C802, 0x10D001, 0x10D802,
	0x10E001, 0x10E802, 0x10F001, 0x10F802,
	0x110001, 0x110802, 0x111001, 0x111802,
	0x112001, 0x112802, 0x113001, 0x113802,
	0x114001, 0x114802, 0x115001, 0x115802,
	0x116001, 0x116802, 0x117001, 0x117802,
	0x118001, 0x118802, 0x119001, 0x1198C2,
	0x11D021, 0x11E002, 0x11E821, 0x11F822,
	0x120801, 0x121002, 0x121861, 0x123802,
	0x124001, 0x124802, 0x125001, 0x125802,
	0x126001, 0x126802, 0x127001, 0x128082,
	0x14A005, 0x14AB42, 0x158224, 0x161075,
	0x163164, 0x1691B5, 0x170084, 0x1728D5,
	0x176004, 0x176815, 0x177004, 0x177A15,
	0x180DE6, 0x1B8001, 0x1B8802, 0x1B9001,
	0x1B9802, 0x1BA004, 0x1BA815, 0x1BB001,
	0x1BB802, 0x1BD004, 0x1BD842, 0x1BF012,
	0x1BF801, 0x1C2035, 0x1C3001, 0x1C3812,
	0x1C4041, 0x1C6001, 0x1C7021, 0x1C8002,
	0x1C8A01, 0x1D1901, 0x1D6442, 0x1E7801,
	0x1E8022, 0x1E9041, 0x1EA842, 0x1EC001,
	0x1EC802, 0x1ED001, 0x1ED802, 0x1EE001,
	0x1EE802, 0x1EF001, 0x1EF802, 0x1F0001,
	0x1F0802, 0x1F1001, 0x1F1802, 0x1F2001,
	0x1F2802, 0x1F3001, 0x1F3802, 0x1F4001,
	0x1F4802, 0x1F5001, 0x1F5802, 0x1F6001,
	0x1F6802, 0x1F7001, 0x1F7882, 0x1FA001,
	0x1FA802, 0x1FB013, 0x1FB801, 0x1FC002,
	0x1FC821, 0x1FD822, 0x1FEE41, 0x2185E2,
	0x230001, 0x230802, 0x231001, 0x231802,
	0x232001, 0x232802, 0x233001, 0x233802,
	0x234001, 0x234802, 0x235001, 0x235802,
	0x236001, 0x236802, 0x237001, 0x237802,
	0x238001, 0x238802, 0x239001, 0x239802,
	0x23A001, 0x23A802, 0x23B001, 0x23B802,
	0x23C001, 0x23C802, 0x23D001, 0x23D802,
	0x23E001, 0x23E802, 0x23F001, 0x23F802,
	0x240001, 0x240802, 0x241016, 0x241886,
	0x244028, 0x245001, 0x245802, 0x246001,
	0x246802, 0x247001, 0x247802, 0x248001,
	0x248802, 0x249001, 0x249802, 0x24A001,
	0x24A802, 0x24B001, 0x24B802, 0x24C001,
	0x24C802, 0x24D001, 0x24D802, 0x24E001,
	0x24E802, 0x24F001, 0x24F802, 0x250001,
	0x250802, 0x251001, 0x251802, 0x252001,
	0x252802, 0x253001, 0x253802, 0x254001,
	0x254802, 0x255001, 0x255802, 0x256001,
	0x256802, 0x257001, 0x257802, 0x258001,
	0x258802, 0x259001, 0x259802, 0x25A001,
	0x25A802, 0x25B001, 0x25B802, 0x25C001,
	0x25C802, 0x25D001, 0x25D802, 0x25E001,
	0x25E802, 0x25F001, 0x25F802, 0x260021,
	0x261002, 0x261801, 0x262002, 0x262801,
	0x263002, 0x263801, 0x264002, 0x264801,
	0x265002, 0x265801, 0x266002, 0x266801,
	0x267022, 0x268001, 0x268802, 0x269001,
	0x269802, 0x26A001, 0x26A802, 0x26B001,
	0x26B802, 0x26C001, 0x26C802, 0x26D001,
	0x26D802, 0x26E001, 0x26E802, 0x26F001,
	0x26F802, 0x270001, 0x270802, 0x271001,
	0x271802, 0x272001, 0x272802, 0x273001,
	0x273802, 0x274001, 0x274802, 0x275001,
	0x275802, 0x276001, 0x276802, 0x277001,
	0x277802, 0x278001, 0x278802, 0x279001,
	0x279802, 0x27A001, 0x27A802, 0x27B001,
	0x27B802, 0x27C001, 0x27C802, 0x27D001,
	0x27D802, 0x27E001, 0x27E802, 0x27F001,
	0x27F802, 0x280001, 0x280802, 0x281001,
	0x281802, 0x282001, 0x282802, 0x283001,
	0x283802, 0x284001, 0x284802, 0x285001,
	0x285802, 0x286001, 0x286802, 0x287001,
	0x287802, 0x288001, 0x288802, 0x289001,
	0x289802, 0x28A001, 0x28A802, 0x28B001,
	0x28B802, 0x28C001, 0x28C802, 0x28D001,
	0x28D802, 0x28E001, 0x28E802, 0x28F001,
	0x28F802, 0x290001, 0x290802, 0x291001,
	0x291802, 0x292001, 0x292802, 0x293001,
	0x293802, 0x294001, 0x294802, 0x295001,
	0x295802, 0x296001, 0x296802, 0x297001,
	0x297802, 0x298CA1, 0x2AC804, 0x2AD0B2,
	0x2B0502, 0x2C4812, 0x2C500D, 0x2C6836,
	0x2C7814, 0x2C8D86, 0x2DF00D, 0x2DF806,
	0x2E0012, 0x2E0826, 0x2E1812, 0x2E2026,
	0x2E3012, 0x2E3806, 0x2E8345, 0x2F7865,
	0x2F9832, 0x3000BB, 0x303053, 0x304832,
	0x305814, 0x306032, 0x307036, 0x308146,
	0x30D812, 0x30E01B, 0x30E852, 0x3103E5,
	0x320004, 0x320925, 0x325A86, 0x330129,
	0x335072, 0x337025, 0x338006, 0x339445,
	0x36A012, 0x36A805, 0x36B0C6, 0x36E81B,
	0x36F016, 0x36F8A6, 0x372824, 0x373826,
	0x374816, 0x375066, 0x377025, 0x378129,
	0x37D045, 0x37E836, 0x37F805, 0x3801B2,
	0x38781B, 0x388005, 0x388806, 0x3893A5,
	0x398346, 0x3A7305, 0x3D3146, 0x3D8805,
	0x3E0129, 0x3E5405, 0x3F5906, 0x3FA024,
	0x3FB016, 0x3FB852, 0x3FD004, 0x3FE806,
	0x3FF034, 0x4002A5, 0x40B066, 0x40D004,
	0x40D906, 0x412004, 0x412846, 0x414004,
	0x414886, 0x4181D2, 0x420305, 0x42C846,
	0x42F012, 0x430145, 0x4382E5, 0x444015,
	0x4448A5, 0x44803B, 0x44C0E6, 0x450505,
	0x464804, 0x4652E6, 0x47101B, 0x471BE6,
	0x481807, 0x4826A5, 0x49D006, 0x49D807,
	0x49E006, 0x49E805, 0x49F047, 0x4A08E6,
	0x4A4867, 0x4A6806, 0x4A7027, 0x4A8005,
	0x4A88C6, 0x4AC125, 0x4B1026, 0x4B2032,
	0x4B3129, 0x4B8012, 0x4B8804, 0x4B91C5,
	0x4C0806, 0x4C1027, 0x4C28E5, 0x4C7825,
	0x4C9AA5, 0x4D50C5, 0x4D9005, 0x4DB065,
	0x4DE006, 0x4DE805, 0x4DF047, 0x4E0866,
	0x4E3827, 0x4E5827, 0x4E6806, 0x4E7005,
	0x4EB807, 0x4EE025, 0x4EF845, 0x4F1026,
	0x4F3129, 0x4F8025, 0x4F9034, 0x4FA0AB,
	0x4FD016, 0x4FD814, 0x4FE005, 0x4FE812,
	0x4FF006, 0x500826, 0x501807, 0x5028A5,
	0x507825, 0x509AA5, 0x5150C5, 0x519025,
	0x51A825, 0x51C025, 0x51E006, 0x51F047,
	0x520826, 0x523826, 0x525846, 0x528806,
	0x52C865, 0x52F005, 0x533129, 0x538026,
	0x539045, 0x53A806, 0x53B012, 0x540826,
	0x541807, 0x542905, 0x547845, 0x549AA5,
	0x5550C5, 0x559025, 0x55A885, 0x55E006,
	0x55E805, 0x55F047, 0x560886, 0x563826,
	0x564807, 0x565827, 0x566806, 0x568005,
	0x570025, 0x571026, 0x573129, 0x578012,
	0x578814, 0x57C805, 0x57D0A6, 0x580806,
	0x581027, 0x5828E5, 0x587825, 0x589AA5,
	0x5950C5, 0x599025, 0x59A885, 0x59E006,
	0x59E805, 0x59F007, 0x59F806, 0x5A0007,
	0x5A0866, 0x5A3827, 0x5A5827, 0x5A6806,
	0x5AA826, 0x5AB807, 0x5AE025, 0x5AF845,
	0x5B1026, 0x5B3129, 0x5B8016, 0x5B8805,
	0x5B90AB, 0x5C1006, 0x5C1805, 0x5C28A5,
	0x5C7045, 0x5C9065, 0x5CC825, 0x5CE005,
	0x5CF025, 0x5D1825, 0x5D4045, 0x5D7165,
	0x5DF027, 0x5E0006, 0x5E0827, 0x5E3047,
	0x5E5047, 0x5E6806, 0x5E8005, 0x5EB807,
	0x5F3129, 0x5F804B, 0x5F98B6, 0x5FC814,
	0x5FD016, 0x600006, 0x600847, 0x602006,
	0x6028E5, 0x607045, 0x6092C5, 0x6151E5,
	0x61E006, 0x61E805, 0x61F046, 0x620867,
	0x623046, 0x625066, 0x62A826, 0x62C045,
	0x62E805, 0x630025, 0x631026, 0x633129,
	0x63B812, 0x63C0CB, 0x63F816, 0x640005,
	0x640806, 0x641027, 0x642012, 0x6428E5,
	0x647045, 0x6492C5, 0x655125, 0x65A885,
	0x65E006, 0x65E805, 0x65F007, 0x65F806,
	0x660087, 0x663006, 0x663827, 0x665027,
	0x666026, 0x66A827, 0x66E825, 0x670025,
	0x671026, 0x673129, 0x678825, 0x679807,
	0x680026, 0x681027, 0x682105, 0x687045,
	0x689505, 0x69D826, 0x69E805, 0x69F047,
	0x6A0866, 0x6A3047, 0x6A5047, 0x6A6806,
	0x6A7005, 0x6A7816, 0x6AA045, 0x6AB807,
	0x6AC0CB, 0x6AF845, 0x6B1026, 0x6B3129,
	0x6B810B, 0x6BC816, 0x6BD0A5, 0x6C0806,
	0x6C1027, 0x6C2A25, 0x6CD2E5, 0x6D9905,
	0x6DE805, 0x6E00C5, 0x6E5006, 0x6E7847,
	0x6E9046, 0x6EB006, 0x6EC0E7, 0x6F3129,
	0x6F9027, 0x6FA012, 0x700DE5, 0x718806,
	0x719025, 0x71A0C6, 0x71F814, 0x7200A5,
	0x723004, 0x7238E6, 0x727812, 0x728129,
	0x72D032, 0x740825, 0x742005, 0x743085,
	0x7462E5, 0x752805, 0x753925, 0x758806,
	0x759025, 0x75A106, 0x75E805, 0x760085,
	0x763004, 0x7640C6, 0x768129, 0x76E065,
	0x780005, 0x780856, 0x7821D2, 0x789816,
	0x78A012, 0x78A856, 0x78C026, 0x78D0B6,
	0x790129, 0x79512B, 0x79A016, 0x79A806,
	0x79B016, 0x79B806, 0x79C016, 0x79C806,
	0x79D00E, 0x79D80F, 0x79E00E, 0x79E80F,
	0x79F027, 0x7A00E5, 0x7A4C65, 0x7B89A6,
	0x7BF807, 0x7C0086, 0x7C2812, 0x7C3026,
	0x7C4085, 0x7C6946, 0x7CCC66, 0x7DF0F6,
	0x7E3006, 0x7E38B6, 0x7E7036, 0x7E8092,
	0x7EA876, 0x7EC832, 0x800545, 0x815827,
	0x816866, 0x818807, 0x8190A6, 0x81C007,
	0x81C826, 0x81D827, 0x81E826, 0x81F805,
	0x820129, 0x8250B2, 0x8280A5, 0x82B027,
	0x82C026, 0x82D065, 0x82F046, 0x830805,
	0x831047, 0x832825, 0x8338C7, 0x837045,
	0x838866, 0x83A985, 0x841006, 0x841827,
	0x842826, 0x8438A7, 0x846806, 0x847005,
	0x847807, 0x848129, 0x84D047, 0x84E806,
	0x84F036, 0x8504A1, 0x863801, 0x866801,
	0x868542, 0x87D812, 0x87E004, 0x87E842,
	0x880FE5, 0x8C0FE5, 0x900905, 0x925065,
	0x9280C5, 0x92C005, 0x92D065, 0x930505,
	0x945065, 0x948405, 0x959065, 0x95C0C5,
	0x960005, 0x961065, 0x9641C5, 0x96C705,
	0x989065, 0x98C845, 0x9AE846, 0x9B0112,
	0x9B4A6B, 0x9C01E5, 0x9C8136, 0x9D0AA1,
	0x9FC0A2, 0xA0000D, 0xA017E5, 0xA417E5,
	0xA817E5, 0xAC17E5, 0xB01565, 0xB36816,
	0xB37012, 0xB37A05, 0xB40017, 0xB40B25,
	0xB4D80E, 0xB4E00F, 0xB50945, 0xB75852,
	0xB7704A, 0xB788E5, 0xB80225, 0xB89046,
	0xB8A807, 0xB8FA45, 0xB99026, 0xB9A007,
	0xB9A832, 0xBA0225, 0xBA9026, 0xBB0185,
	0xBB7045, 0xBB9026, 0xBC0665, 0xBDA026,
	0xBDB007, 0xBDB8C6, 0xBDF0E7, 0xBE3006,
	0xBE3827, 0xBE4946, 0xBEA052, 0xBEB804,
	0xBEC052, 0xBED814, 0xBEE005, 0xBEE806,
	0xBF0129, 0xBF812B, 0xC000B2, 0xC0300D,
	0xC03872, 0xC05846, 0xC0701B, 0xC07806,
	0xC08129, 0xC10445, 0xC21804, 0xC22685,
	0xC40085, 0xC42826, 0xC43C25, 0xC54806,
	0xC55005, 0xC588A5, 0xC803C5, 0xC90046,
	0xC91867, 0xC93826, 0xC94847, 0xC98027,
	0xC99006, 0xC998A7, 0xC9C846, 0xCA0016,
	0xCA2032, 0xCA3129, 0xCA83A5, 0xCB8085,
	0xCC0565, 0xCD8325, 0xCE8129, 0xCED00B,
	0xCEF436, 0xD002C5, 0xD0B826, 0xD0C827,
	0xD0D806, 0xD0F032, 0xD10685, 0xD2A807,
	0xD2B006, 0xD2B807, 0xD2C0C6, 0xD30006,
	0xD30807, 0xD31006, 0xD31827, 0xD328E6,
	0xD368A7, 0xD39926, 0xD3F806, 0xD40129,
	0xD48129, 0xD500D2, 0xD53804, 0xD540B2,
	0xD581A6, 0xD5F008, 0xD5F9E6, 0xD80066,
	0xD82007, 0xD82DC5, 0xD9A006, 0xD9A807,
	0xD9B086, 0xD9D807, 0xD9E006, 0xD9E887,
	0xDA1006, 0xDA1827, 0xDA28E5, 0xDA8129,
	0xDAD0D2, 0xDB0936, 0xDB5906, 0xDBA116,
	0xDBE832, 0xDC0026, 0xDC1007, 0xDC1BA5,
	0xDD0807, 0xDD1066, 0xDD3027, 0xDD4026,
	0xDD5007, 0xDD5846, 0xDD7025, 0xDD8129,
	0xDDD565, 0xDF3006, 0xDF3807, 0xDF4026,
	0xDF5047, 0xDF6806, 0xDF7007, 0xDF7846,
	0xDF9027, 0xDFE072, 0xE00465, 0xE120E7,
	0xE160E6, 0xE1A027, 0xE1B026, 0xE1D892,
	0xE20129, 0xE26845, 0xE28129, 0xE2D3A5,
	0xE3C0A4, 0xE3F032, 0xE40102, 0xE48541,
	0xE5E841, 0xE600F2, 0xE68046, 0xE69812,
	0xE6A186, 0xE70807, 0xE710C6, 0xE74865,
	0xE76806, 0xE770A5, 0xE7A006, 0xE7A825,
	0xE7B807, 0xE7C026, 0xE7D005, 0xE80562,
	0xE967C4, 0xEB5982, 0xEBC004, 0xEBCC22,
	0xECDC84, 0xEE07E6, 0xF00001, 0xF00802,
	0xF01001, 0xF01802, 0xF02001, 0xF02802,
	0xF03001, 0xF03802, 0xF04001, 0xF04802,
	0xF05001, 0xF05802, 0xF06001, 0xF06802,
	0xF07001, 0xF07802, 0xF08001, 0xF08802,
	0xF09001, 0xF09802, 0xF0A001, 0xF0A802,
	0xF0B001, 0xF0B802, 0xF0C001, 0xF0C802,
	0xF0D001, 0xF0D802, 0xF0E001, 0xF0E802,
	0xF0F001, 0xF0F802, 0xF10001, 0xF10802,
	0xF11001, 0xF11802, 0xF12001, 0xF12802,
	0xF13001, 0xF13802, 0xF14001, 0xF14802,
	0xF15001, 0xF15802, 0xF16001, 0xF16802,
	0xF17001, 0xF17802, 0xF18001, 0xF18802,
	0xF19001, 0xF19802, 0xF1A001, 0xF1A802,
	0xF1B001, 0xF1B802, 0xF1C001, 0xF1C802,
	0xF1D001, 0xF1D802, 0xF1E001, 0xF1E802,
	0xF1F001, 0xF1F802, 0xF20001, 0xF20802,
	0xF21001, 0xF21802, 0xF22001, 0xF22802,
	0xF23001, 0xF23802, 0xF24001, 0xF24802,
	0xF25001, 0xF25802, 0xF26001, 0xF26802,
	0xF27001, 0xF27802, 0xF28001, 0xF28802,
	0xF29001, 0xF29802, 0xF2A001, 0xF2A802,
	0xF2B001, 0xF2B802, 0xF2C001, 0xF2C802,
	0xF2D001, 0xF2D802, 0xF2E001, 0xF2E802,
	0xF2F001, 0xF2F802, 0xF30001, 0xF30802,
	0xF31001, 0xF31802, 0xF32001, 0xF32802,
	0xF33001, 0xF33802, 0xF34001, 0xF34802,
	0xF35001, 0xF35802, 0xF36001, 0xF36802,
	0xF37001, 0xF37802, 0xF38001, 0xF38802,
	0xF39001, 0xF39802, 0xF3A001, 0xF3A802,
	0xF3B001, 0xF3B802, 0xF3C001, 0xF3C802,
	0xF3D001, 0xF3D802, 0xF3E001, 0xF3E802,
	0xF3F001, 0xF3F802, 0xF40001, 0xF40802,
	0xF41001, 0xF41802, 0xF42001, 0xF42802,
	0xF43001, 0xF43802, 0xF44001, 0xF44802,
	0xF45001, 0xF45802, 0xF46001, 0xF46802,
	0xF47001, 0xF47802, 0xF48001, 0xF48802,
	0xF49001, 0xF49802, 0xF4A001, 0xF4A902,
	0xF4F001, 0xF4F802, 0xF50001, 0xF50802,
	0xF51001, 0xF51802, 0xF52001, 0xF52802,
	0xF53001, 0xF53802, 0xF54001, 0xF54802,
	0xF55001, 0xF55802, 0xF56001, 0xF56802,
	0xF57001, 0xF57802, 0xF58001, 0xF58802,
	0xF59001, 0xF59802, 0xF5A001, 0xF5A802,
	0xF5B001, 0xF5B802, 0xF5C001, 0xF5C802,
	0xF5D001, 0xF5D802, 0xF5E001, 0xF5E802,
	0xF5F001, 0xF5F802, 0xF60001, 0xF60802,
	0xF61001, 0xF61802, 0xF62001, 0xF62802,
	0xF63001, 0xF63802, 0xF64001, 0xF64802,
	0xF65001, 0xF65802, 0xF66001, 0xF66802,
	0xF67001, 0xF67802, 0xF68001, 0xF68802,
	0xF69001, 0xF69802, 0xF6A001, 0xF6A802,
	0xF6B001, 0xF6B802, 0xF6C001, 0xF6C802,
	0xF6D001, 0xF6D802, 0xF6E001, 0xF6E802,
	0xF6F001, 0xF6F802, 0xF70001, 0xF70802,
	0xF71001, 0xF71802, 0xF72001, 0xF72802,
	0xF73001, 0xF73802, 0xF74001, 0xF74802,
	0xF75001, 0xF75802, 0xF76001, 0xF76802,
	0xF77001, 0xF77802, 0xF78001, 0xF78802,
	0xF79001, 0xF79802, 0xF7A001, 0xF7A802,
	0xF7B001, 0xF7B802, 0xF7C001, 0xF7C802,
	0xF7D001, 0xF7D802, 0xF7E001, 0xF7E802,
	0xF7F001, 0xF7F902, 0xF840E1, 0xF880A2,
	0xF8C0A1, 0xF900E2, 0xF940E1, 0xF980E2,
	0xF9C0E1, 0xFA00A2, 0xFA40A1, 0xFA80E2,
	0xFAC801, 0xFAD801, 0xFAE801, 0xFAF801,
	0xFB00E2, 0xFB40E1, 0xFB81A2, 0xFC00E2,
	0xFC40E3, 0xFC80E2, 0xFCC0E3, 0xFD00E2,
	0xFD40E3, 0xFD8082, 0xFDB022, 0xFDC061,
	0xFDE003, 0xFDE815, 0xFDF002, 0xFDF855,
	0xFE1042, 0xFE3022, 0xFE4061, 0xFE6003,
	0xFE6855, 0xFE8062, 0xFEB022, 0xFEC061,
	0xFEE855, 0xFF00E2, 0xFF4081, 0xFF6855,
	0xFF9042, 0xFFB022, 0xFFC061, 0xFFE003,
	0xFFE835, 0x1000157, 0x100589B, 0x10080AD,
	0x100B032, 0x100C010, 0x100C811, 0x100D00E,
	0x100D830, 0x100E811, 0x100F00E, 0x100F810,
	0x10100F2, 0x1014018, 0x1014819, 0x101509B,
	0x1017817, 0x1018112, 0x101C810, 0x101D011,
	0x101D872, 0x101F82C, 0x1020852, 0x1022013,
	0x102280E, 0x102300F, 0x1023952, 0x1029013,
	0x1029812, 0x102A00C, 0x102A932, 0x102F817,
	0x103009B, 0x103313B, 0x103800B, 0x1038804,
	0x103A0AB, 0x103D053, 0x103E80E, 0x103F00F,
	0x103F804, 0x104012B, 0x1045053, 0x104680E,
	0x104700F, 0x1048184, 0x1050414, 0x1068186,
	0x106E868, 0x1070806, 0x1071048, 0x1072966,
	0x1080036, 0x1081001, 0x1081876, 0x1083801,
	0x1084036, 0x1085002, 0x1085841, 0x1087022,
	0x1088041, 0x1089802, 0x108A016, 0x108A801,
	0x108B036, 0x108C013, 0x108C881, 0x108F0B6,
	0x1092001, 0x1092816, 0x1093001, 0x1093816,
	0x1094001, 0x1094816, 0x1095061, 0x1097016,
	0x1097802, 0x1098061, 0x109A002, 0x109A865,
	0x109C802, 0x109D036, 0x109E022, 0x109F021,
	0x10A0093, 0x10A2801, 0x10A3062, 0x10A5016,
	0x10A5813, 0x10A6036, 0x10A7002, 0x10A7816,
	0x10A81EB, 0x10B044A, 0x10C1801, 0x10C2002,
	0x10C286A, 0x10C480B, 0x10C5036, 0x10C8093,
	0x10CA896, 0x10CD033, 0x10CE076, 0x10D0013,
	0x10D0836, 0x10D1813, 0x10D2036, 0x10D3013,
	0x10D38D6, 0x10D7013, 0x10D7BD6, 0x10E7033,
	0x10E8036, 0x10E9013, 0x10E9816, 0x10EA013,
	0x10EABD6, 0x10FAFF3, 0x113AFF3, 0x117A173,
	0x11800F6, 0x118400E, 0x118480F, 0x118500E,
	0x118580F, 0x1186276, 0x1190033, 0x11910D6,
	0x119480E, 0x119500F, 0x1196216, 0x11BE013,
	0x11BEBB6, 0x11CDB13, 0x11DA4F6, 0x11EE0B3,
	0x11F1896, 0x1220156, 0x123076B, 0x124E9B6,
	0x12752AB, 0x1280FF6, 0x12C06D6, 0x12DB813,
	0x12DC116, 0x12E0813, 0x12E16B6, 0x12FC0F3,
	0x1300DD6, 0x1337813, 0x1338FF6, 0x1378EF6,
	0x13B400E, 0x13B480F, 0x13B500E, 0x13B580F,
	0x13B600E, 0x13B680F, 0x13B700E, 0x13B780F,
	0x13B800E, 0x13B880F, 0x13B900E, 0x13B980F,
	0x13BA00E, 0x13BA80F, 0x13BB3AB, 0x13CA576,
	0x13E0093, 0x13E280E, 0x13E300F, 0x13E3BD3,
	0x13F300E, 0x13F380F, 0x13F400E, 0x13F480F,
	0x13F500E, 0x13F580F, 0x13F600E, 0x13F680F,
	0x13F700E, 0x13F780F, 0x13F81F3, 0x1400FF6,
	0x1440FF6, 0x1480FF3, 0x14C0053, 0x14C180E,
	0x14C200F, 0x14C280E, 0x14C300F, 0x14C380E,
	0x14C400F, 0x14C480E, 0x14C500F, 0x14C580E,
	0x14C600F, 0x14C680E, 0x14C700F, 0x14C780E,
	0x14C800F, 0x14C880E, 0x14C900F, 0x14C980E,
	0x14CA00F, 0x14CA80E, 0x14CB00F, 0x14CB80E,
	0x14CC00F, 0x14CCFD3, 0x14EC00E, 0x14EC80F,
	0x14ED00E, 0x14ED80F, 0x14EE3F3, 0x14FE00E,
	0x14FE80F, 0x14FFFF3, 0x153FFF3, 0x157F033,
	0x15805F6, 0x1598293, 0x15A2836, 0x15A38B3,
	0x15A6CD6, 0x15BB3F6, 0x15CC516, 0x16005E1,
	0x16185E2, 0x1630001, 0x1630802, 0x1631041,
	0x1632822, 0x1633801, 0x1634002, 0x1634801,
	0x1635002, 0x1635801, 0x1636002, 0x1636861,
	0x1638802, 0x1639001, 0x1639822, 0x163A801,
	0x163B0A2, 0x163E024, 0x163F041, 0x1640802,
	0x1641001, 0x1641802, 0x1642001, 0x1642802,
	0x1643001, 0x1643802, 0x1644001, 0x1644802,
	0x1645001, 0x1645802, 0x1646001, 0x1646802,
	0x1647001, 0x1647802, 0x1648001, 0x1648802,
	0x1649001, 0x1649802, 0x164A001, 0x164A802,
	0x164B001, 0x164B802, 0x164C001, 0x164C802,
	0x164D001, 0x164D802, 0x164E001, 0x164E802,
	0x164F001, 0x164F802, 0x1650001, 0x1650802,
	0x1651001, 0x1651802, 0x1652001, 0x1652802,
	0x1653001, 0x1653802, 0x1654001, 0x1654802,
	0x1655001, 0x1655802, 0x1656001, 0x1656802,
	0x1657001, 0x1657802, 0x1658001, 0x1658802,
	0x1659001, 0x1659802, 0x165A001, 0x165A802,
	0x165B001, 0x165B802, 0x165C001, 0x165C802,
	0x165D001, 0x165D802, 0x165E001, 0x165E802,
	0x165F001, 0x165F802, 0x1660001, 0x1660802,
	0x1661001, 0x1661802, 0x1662001, 0x1662802,
	0x1663001, 0x1663802, 0x1664001, 0x1664802,
	0x1665001, 0x1665802, 0x1666001, 0x1666802,
	0x1667001, 0x1667802, 0x1668001, 0x1668802,
	0x1669001, 0x1669802, 0x166A001, 0x166A802,
	0x166B001, 0x166B802, 0x166C001, 0x166C802,
	0x166D001, 0x166D802, 0x166E001, 0x166E802,
	0x166F001, 0x166F802, 0x1670001, 0x1670802,
	0x1671001, 0x1671822, 0x16728B6, 0x1675801,
	0x1676002, 0x1676801, 0x1677002, 0x1677846,
	0x1679001, 0x1679802, 0x167C872, 0x167E80B,
	0x167F032, 0x16804A2, 0x1693802, 0x1696802,
	0x16986E5, 0x16B7804, 0x16B8012, 0x16BF806,
	0x16C02C5, 0x16D00C5, 0x16D40C5, 0x16D80C5,
	0x16DC0C5, 0x16E00C5, 0x16E40C5, 0x16E80C5,
	0x16EC0C5, 0x16F03E6, 0x1700032, 0x1701010,
	0x1701811, 0x1702010, 0x1702811, 0x1703052,
	0x1704810, 0x1705011, 0x1705812, 0x1706010,
	0x1706811, 0x1707112, 0x170B80D, 0x170C032,
	0x170D00D, 0x170D812, 0x170E010, 0x170E811,
	0x170F032, 0x1710010, 0x1710811, 0x171100E,
	0x171180F, 0x171200E, 0x171280F, 0x171300E,
	0x171380F, 0x171400E, 0x171480F, 0x1715092,
	0x1717804, 0x1718132, 0x171D02D, 0x171E072,
	0x172000D, 0x1720812, 0x172100E, 0x1721992,
	0x1728036, 0x1729052, 0x172A80E, 0x172B00F,
	0x172B80E, 0x172C00F, 0x172C80E, 0x172D00F,
	0x172D80E, 0x172E00F, 0x172E80D, 0x1740336,
	0x174E316, 0x1780FF6, 0x17C0AB6, 0x17F8176,
	0x1800017, 0x1800852, 0x1802016, 0x1802804,
	0x1803005, 0x180380A, 0x180400E, 0x180480F,
	0x180500E, 0x180580F, 0x180600E, 0x180680F,
	0x180700E, 0x180780F, 0x180800E, 0x180880F,
	0x1809036, 0x180A00E, 0x180A80F, 0x180B00E,
	0x180B80F, 0x180C00E, 0x180C80F, 0x180D00E,
	0x180D80F, 0x180E00D, 0x180E80E, 0x180F02F,
	0x1810016, 0x181090A, 0x1815066, 0x1817027,
	0x181800D, 0x1818884, 0x181B036, 0x181C04A,
	0x181D804, 0x181E005, 0x181E812, 0x181F036,
	0x18212A5, 0x184C826, 0x184D835, 0x184E824,
	0x184F805, 0x185000D, 0x1851325, 0x187D812,
	0x187E044, 0x187F805, 0x1882D45, 0x18993A5,
	0x18C8036, 0x18C906B, 0x18CB136, 0x18D03E5,
	0x18E0476, 0x18F81E5, 0x19003D6, 0x191012B,
	0x19153B6, 0x19240EB, 0x1928016, 0x19289CB,
	0x19303F6, 0x194012B, 0x19454D6, 0x19589CB,
	0x1960FF6, 0x19A0FF6, 0x19E07F6, 0x1A00005,
	0x26DF805, 0x26E07F6, 0x2700005, 0x4FFFAA5,
	0x500A804, 0x500BFE5, 0x504BFE5, 0x508BFE5,
	0x50CBFE5, 0x510BFE5, 0x514BFE5, 0x518BFE5,
	0x51CBFE5, 0x520BEC5, 0x52486D6, 0x52684E5,
	0x527C0A4, 0x527F032, 0x5280FE5, 0x52C0FE5,
	0x5300165, 0x5306004, 0x5306852, 0x53081E5,
	0x5310129, 0x5315025, 0x5320001, 0x5320802,
	0x5321001, 0x5321802, 0x5322001, 0x5322802,
	0x5323001, 0x5323802, 0x5324001, 0x5324802,
	0x5325001, 0x5325802, 0x5326001, 0x5326802,
	0x5327001, 0x5327802, 0x5328001, 0x5328802,
	0x5329001, 0x5329802, 0x532A001, 0x532A802,
	0x532B001, 0x532B802, 0x532C001, 0x532C802,
	0x532D001, 0x532D802, 0x532E001, 0x532E802,
	0x532F001, 0x532F802, 0x5330001, 0x5330802,
	0x5331001, 0x5331802, 0x5332001, 0x5332802,
	0x5333001, 0x5333802, 0x5334001, 0x5334802,
	0x5335001, 0x5335802, 0x5336001, 0x5336802,
	0x5337005, 0x5337806, 0x5338048, 0x5339812,
	0x533A126, 0x533F012, 0x533F804, 0x5340001,
	0x5340802, 0x5341001, 0x5341802, 0x5342001,
	0x5342802, 0x5343001, 0x5343802, 0x5344001,
	0x5344802, 0x5345001, 0x5345802, 0x5346001,
	0x5346802, 0x5347001, 0x5347802, 0x5348001,
	0x5348802, 0x5349001, 0x5349802, 0x534A001,
	0x534A802, 0x534B001, 0x534B802, 0x534C001,
	0x534C802, 0x534D001, 0x534D802, 0x534E024,
	0x534F026, 0x53508A5, 0x537312A, 0x5378026,
	0x53790B2, 0x53802D5, 0x538B904, 0x5390035,
	0x5391001, 0x5391802, 0x5392001, 0x5392802,
	0x5393001, 0x5393802, 0x5394001, 0x5394802,
	0x5395001, 0x5395802, 0x5396001, 0x5396802,
	0x5397001, 0x5397842, 0x5399001, 0x5399802,
	0x539A001, 0x539A802, 0x539B001, 0x539B802,
	0x539C001, 0x539C802, 0x539D001, 0x539D802,
	0x539E001, 0x539E802, 0x539F001, 0x539F802,
	0x53A0001, 0x53A0802, 0x53A1001, 0x53A1802,
	0x53A2001, 0x53A2802, 0x53A3001, 0x53A3802,
	0x53A4001, 0x53A4802, 0x53A5001, 0x53A5802,
	0x53A6001, 0x53A6802, 0x53A7001, 0x53A7802,
	0x53A8001, 0x53A8802, 0x53A9001, 0x53A9802,
	0x53AA001, 0x53AA802, 0x53AB001, 0x53AB802,
	0x53AC001, 0x53AC802, 0x53AD001, 0x53AD802,
	0x53AE001, 0x53AE802, 0x53AF001, 0x53AF802,
	0x53B0001, 0x53B0802, 0x53B1001, 0x53B1802,
	0x53B2001, 0x53B2802, 0x53B3001, 0x53B3802,
	0x53B4001, 0x53B4802, 0x53B5001, 0x53B5802,
	0x53B6001, 0x53B6802, 0x53B7001, 0x53B7802,
	0x53B8004, 0x53B88E2, 0x53BC801, 0x53BD002,
	0x53BD801, 0x53BE002, 0x53BE821, 0x53BF802,
	0x53C0001, 0x53C0802, 0x53C1001, 0x53C1802,
	0x53C2001, 0x53C2802, 0x53C3001, 0x53C3802,
	0x53C4004, 0x53C4835, 0x53C5801, 0x53C6002,
	0x53C6801, 0x53C7002, 0x53C7805, 0x53C8001,
	0x53C8802, 0x53C9001, 0x53C9842, 0x53CB001,
	0x53CB802, 0x53CC001, 0x53CC802, 0x53CD001,
	0x53CD802, 0x53CE001, 0x53CE802, 0x53CF001,
	0x53CF802, 0x53D0001, 0x53D0802, 0x53D1001,
	0x53D1802, 0x53D2001, 0x53D2802, 0x53D3001,
	0x53D3802, 0x53D4001, 0x53D4802, 0x53D5081,
	0x53D7802, 0x53D8081, 0x53DA802, 0x53DB001,
	0x53DB802, 0x53DC001, 0x53DC802, 0x53DD001,
	0x53DD802, 0x53DE001, 0x53DE802, 0x53DF001,
	0x53DF802, 0x53E0001, 0x53E0802, 0x53E1001,
	0x53E1802, 0x53E2061, 0x53E4002, 0x53E4801,
	0x53E5002, 0x53E8001, 0x53E8802, 0x53E9802,
	0x53EA802, 0x53EB001, 0x53EB802, 0x53EC001,
	0x53EC802, 0x53F9044, 0x53FA801, 0x53FB002,
	0x53FB805, 0x53FC024, 0x53FD002, 0x53FD8C5,
	0x5401006, 0x5401845, 0x5403006, 0x5403865,
	0x5405806, 0x54062C5, 0x5411827, 0x5412826,
	0x5413807, 0x5414076, 0x5416006, 0x54180AB,
	0x541B036, 0x541C014, 0x541C816, 0x5420665,
	0x543A072, 0x5440027, 0x5441625, 0x545A1E7,
	0x5462026, 0x5467032, 0x5468129, 0x5470226,
	0x54790A5, 0x547C052, 0x547D805, 0x547E012,
	0x547E825, 0x547F806, 0x5480129, 0x5485365,
	0x54930E6, 0x5497032, 0x54982C5, 0x54A3946,
	0x54A9027, 0x54AF812, 0x54B0385, 0x54C0046,
	0x54C1807, 0x54C25C5, 0x54D9806, 0x54DA027,
	0x54DB066, 0x54DD027, 0x54DE026, 0x54DF047,
	0x54E0992, 0x54E7804, 0x54E8129, 0x54EF032,
	0x54F0085, 0x54F2806, 0x54F3004, 0x54F3905,
	0x54F8129, 0x54FD085, 0x5500505, 0x55148A6,
	0x5517827, 0x5518826, 0x5519827, 0x551A826,
	0x5520045, 0x5521806, 0x55220E5, 0x5526006,
	0x5526807, 0x5528129, 0x552E072, 0x55301E5,
	0x5538004, 0x55388A5, 0x553B856, 0x553D005,
	0x553D807, 0x553E006, 0x553E807, 0x553F625,
	0x5558006, 0x5558805, 0x5559046, 0x555A825,
	0x555B826, 0x555C885, 0x555F026, 0x5560005,
	0x5560806, 0x5561005, 0x556D825, 0x556E804,
	0x556F032, 0x5570145, 0x5575807, 0x5576026,
	0x5577027, 0x5578032, 0x5579005, 0x5579824,
	0x557A807, 0x557B006, 0x55808A5, 0x55848A5,
	0x55888A5, 0x55900C5, 0x55940C5, 0x5598542,
	0x55AD815, 0x55AE064, 0x55B0102, 0x55B4804,
	0x55B5035, 0x55B89E2, 0x55E0445, 0x55F1827,
	0x55F2806, 0x55F3027, 0x55F4006, 0x55F4827,
	0x55F5812, 0x55F6007, 0x55F6806, 0x55F8129,
	0x5600005, 0x6BD1805, 0x6BD82C5, 0x6BE5E05,
	0x6C0001C, 0x6DBF83C, 0x6DFF83C, 0x6FFF81C,
	0x700001D, 0x7C7F81D, 0x7C80FE5, 0x7CC0FE5,
	0x7D00DA5, 0x7D38D25, 0x7D800C2, 0x7D89882,
	0x7D8E805, 0x7D8F006, 0x7D8F925, 0x7D94813,
	0x7D95185, 0x7D9C085, 0x7D9F005, 0x7DA0025,
	0x7DA1825, 0x7DA3D65, 0x7DD9215, 0x7DEA7E5,
	0x7E2A7E5, 0x7E6A545, 0x7E9F00F, 0x7E9F80E,
	0x7EA01F6, 0x7EA87E5, 0x7EC96A5, 0x7EE7816,
	0x7EF8165, 0x7EFE014, 0x7EFE856, 0x7F001E6,
	0x7F080D2, 0x7F0B80E, 0x7F0C00F, 0x7F0C812,
	0x7F101E6, 0x7F18012, 0x7F1882D, 0x7F1982C,
	0x7F1A80E, 0x7F1B00F, 0x7F1B80E, 0x7F1C00F,
	0x7F1C80E, 0x7F1D00F, 0x7F1D80E, 0x7F1E00F,
	0x7F1E80E, 0x7F1F00F, 0x7F1F80E, 0x7F2000F,
	0x7F2080E, 0x7F2100F, 0x7F2180E, 0x7F2200F,
	0x7F22832, 0x7F2380E, 0x7F2400F, 0x7F24872,
	0x7F2684C, 0x7F28052, 0x7F2A072, 0x7F2C00D,
	0x7F2C80E, 0x7F2D00F, 0x7F2D80E, 0x7F2E00F,
	0x7F2E80E, 0x7F2F00F, 0x7F2F852, 0x7F31013,
	0x7F3180D, 0x7F32053, 0x7F34012, 0x7F34814,
	0x7F35032, 0x7F38085, 0x7F3BFE5, 0x7F7B0C5,
	0x7F7F81B, 0x7F80852, 0x7F82014, 0x7F82852,
	0x7F8400E, 0x7F8480F, 0x7F85012, 0x7F85813,
	0x7F86012, 0x7F8680D, 0x7F87032, 0x7F88129,
	0x7F8D032, 0x7F8E053, 0x7F8F832, 0x7F90B21,
	0x7F9D80E, 0x7F9E012, 0x7F9E80F, 0x7F9F015,
	0x7F9F80C, 0x7FA0015, 0x7FA0B22, 0x7FAD80E,
	0x7FAE013, 0x7FAE80F, 0x7FAF013, 0x7FAF80E,
	0x7FB000F, 0x7FB0812, 0x7FB100E, 0x7FB180F,
	0x7FB2032, 0x7FB3125, 0x7FB8004, 0x7FB8D85,
	0x7FCF024, 0x7FD03C5, 0x7FE10A5, 0x7FE50A5,
	0x7FE90A5, 0x7FED045, 0x7FF0034, 0x7FF1013,
	0x7FF1815, 0x7FF2016, 0x7FF2834, 0x7FF4016,
	0x7FF4873, 0x7FF6836, 0x7FFC85B, 0x7FFE036,
	0x8000165, 0x8006B25, 0x8014245, 0x801E025,
	0x801F9C5, 0x80281A5, 0x8040F45, 0x8080052,
	0x8083D8B, 0x809B916, 0x80A068A, 0x80BA86B,
	0x80BCA16, 0x80C502B, 0x80C6056, 0x80C8196,
	0x80D0016, 0x80E8596, 0x80FE806, 0x8140385,
	0x8150605, 0x8170006, 0x8170B4B, 0x81803E5,
	0x819006B, 0x8196A65, 0x81A080A, 0x81A10E5,
	0x81A500A, 0x81A84A5, 0x81BB086, 0x81C03A5,
	0x81CF812, 0x81D0465, 0x81E40E5, 0x81E8012,
	0x81E888A, 0x82004E1, 0x82144E2, 0x82289A5,
	0x8250129, 0x8258461, 0x826C462, 0x82804E5,
	0x8298665, 0x82B7812, 0x82B8141, 0x82BE1C1,
	0x82C60C1, 0x82CA021, 0x82CB942, 0x82D19C2,
	0x82D98C2, 0x82DD822, 0x8300FE5, 0x8340FE5,
	0x83806C5, 0x83A02A5, 0x83B00E5, 0x83C00A4,
	0x83C3D24, 0x83D9104, 0x84000A5, 0x8404005,
	0x8405565, 0x841B825, 0x841E005, 0x841FAC5,
	0x842B812, 0x842C0EB, 0x84302C5, 0x843B836,
	0x843C8CB, 0x84403C5, 0x845390B, 0x8470245,
	0x847A025, 0x847D88B, 0x84802A5, 0x848B0AB,
	0x848F812, 0x8490325, 0x849F812, 0x84C06E5,
	0x84DE02B, 0x84DF025, 0x84E01EB, 0x84E95AB,
	0x8500005, 0x8500846, 0x8502826, 0x8506066,
	0x8508065, 0x850A845, 0x850CB85, 0x851C046,
	0x851F806, 0x852010B, 0x8528112, 0x8530385,
	0x853E82B, 0x853F812, 0x8540385, 0x854E84B,
	0x85600E5, 0x8564016, 0x8564B65, 0x8572826,
	0x857588B, 0x85780D2, 0x85806A5, 0x859C8D2,
	0x85A02A5, 0x85AC0EB, 0x85B0245, 0x85BC0EB,
	0x85C0225, 0x85CC872, 0x85D48CB, 0x8600905,
	0x8640641, 0x8660642, 0x867D0AB, 0x8680465,
	0x8692066, 0x8698129, 0x87303CB, 0x8740525,
	0x8755826, 0x875680D, 0x8758025, 0x877E846,
	0x8780385, 0x878E92B, 0x8793805, 0x87982A5,
	0x87A3146, 0x87A886B, 0x87AA892, 0x87B8225,
	0x87C1066, 0x87C3072, 0x87D8285, 0x87E28CB,
	0x87F02C5, 0x8800007, 0x8800806, 0x8801007,
	0x8801E85, 0x881C1C6, 0x88238D2, 0x882926B,
	0x8833129, 0x8838006, 0x8838825, 0x8839826,
	0x883A805, 0x883F846, 0x8841007, 0x8841D85,
	0x8858047, 0x8859866, 0x885B827, 0x885C826,
	0x885D832, 0x885E81B, 0x885F072, 0x8861006,
	0x886681B, 0x8868305, 0x8878129, 0x8880046,
	0x8881C65, 0x8893886, 0x8896007, 0x88968E6,
	0x889B129, 0x88A0072, 0x88A2005, 0x88A2827,
	0x88A3805, 0x88A8445, 0x88B9806, 0x88BA032,
	0x88BB005, 0x88C0026, 0x88C1007, 0x88C1DE5,
	0x88D9847, 0x88DB106, 0x88DF827, 0x88E0865,
	0x88E2872, 0x88E4866, 0x88E6812, 0x88E7007,
	0x88E7806, 0x88E8129, 0x88ED005, 0x88ED812,
	0x88EE005, 0x88EE852, 0x88F0A6B, 0x8900225,
	0x8909B05, 0x8916047, 0x8917846, 0x8919027,
	0x891A006, 0x891A807, 0x891B026, 0x891C0B2,
	0x891F006, 0x891F825, 0x8920806, 0x89400C5,
	0x8944005, 0x8945065, 0x89479C5, 0x894F925,
	0x8954812, 0x89585C5, 0x896F806, 0x8970047,
	0x89718E6, 0x8978129, 0x8980026, 0x8981027,
	0x89828E5, 0x8987825, 0x8989AA5, 0x89950C5,
	0x8999025, 0x899A885, 0x899D826, 0x899E805,
	0x899F027, 0x89A0006, 0x89A0867, 0x89A3827,
	0x89A5847, 0x89A8005, 0x89AB807, 0x89AE885,
	0x89B1027, 0x89B30C6, 0x89B8086, 0x8A00685,
	0x8A1A847, 0x8A1C0E6, 0x8A20027, 0x8A21046,
	0x8A22807, 0x8A23006, 0x8A23865, 0x8A25892,
	0x8A28129, 0x8A2D032, 0x8A2E812, 0x8A2F006,
	0x8A2F845, 0x8A405E5, 0x8A58047, 0x8A598A6,
	0x8A5C807, 0x8A5D006, 0x8A5D867, 0x8A5F826,
	0x8A60807, 0x8A61026, 0x8A62025, 0x8A63012,
	0x8A63805, 0x8A68129, 0x8AC05C5, 0x8AD7847,
	0x8AD9066, 0x8ADC067, 0x8ADE026, 0x8ADF007,
	0x8ADF826, 0x8AE0AD2, 0x8AEC065, 0x8AEE026,
	0x8B005E5, 0x8B18047, 0x8B198E6, 0x8B1D827,
	0x8B1E806, 0x8B1F007, 0x8B1F826, 0x8B20852,
	0x8B22005, 0x8B28129, 0x8B30192, 0x8B40545,
	0x8B55806, 0x8B56007, 0x8B56806, 0x8B57027,
	0x8B580A6, 0x8B5B007, 0x8B5B806, 0x8B5C005,
	0x8B5C812, 0x8B60129, 0x8B80345, 0x8B8E846,
	0x8B90027, 0x8B91066, 0x8B93007, 0x8B93886,
	0x8B98129, 0x8B9D02B, 0x8B9E052, 0x8B9F816,
	0x8BA00C5, 0x8C00565, 0x8C16047, 0x8C17906,
	0x8C1C007, 0x8C1C826, 0x8C1D812, 0x8C503E1,
	0x8C603E2, 0x8C70129, 0x8C7510B, 0x8C7F8E5,
	0x8C84805, 0x8C860E5, 0x8C8A825, 0x8C8C2E5,
	0x8C980A7, 0x8C9B827, 0x8C9D826, 0x8C9E807,
	0x8C9F006, 0x8C9F805, 0x8CA0007, 0x8CA0805,
	0x8CA1007, 0x8CA1806, 0x8CA2052, 0x8CA8129,
	0x8CD00E5, 0x8CD54C5, 0x8CE8847, 0x8CEA066,
	0x8CED026, 0x8CEE067, 0x8CF0006, 0x8CF0805,
	0x8CF1012, 0x8CF1805, 0x8CF2007, 0x8D00005,
	0x8D00926, 0x8D05CE5, 0x8D198A6, 0x8D1C807,
	0x8D1D005, 0x8D1D866, 0x8D1F8F2, 0x8D23806,
	0x8D28005, 0x8D288A6, 0x8D2B827, 0x8D2C846,
	0x8D2E5A5, 0x8D45186, 0x8D4B807, 0x8D4C026,
	0x8D4D052, 0x8D4E805, 0x8D4F092, 0x8D58905,
	0x8D80132, 0x8E00105, 0x8E05485, 0x8E17807,
	0x8E180C6, 0x8E1C0A6, 0x8E1F007, 0x8E1F806,
	0x8E20005, 0x8E20892, 0x8E28129, 0x8E2D24B,
	0x8E38032, 0x8E393A5, 0x8E492A6, 0x8E54807,
	0x8E550C6, 0x8E58807, 0x8E59026, 0x8E5A007,
	0x8E5A826, 0x8E800C5, 0x8E84025, 0x8E85CA5,
	0x8E988A6, 0x8E9D006, 0x8E9E026, 0x8E9F8C6,
	0x8EA3005, 0x8EA3806, 0x8EA8129, 0x8EB00A5,
	0x8EB3825, 0x8EB53E5, 0x8EC5087, 0x8EC8026,
	0x8EC9827, 0x8ECA806, 0x8ECB007, 0x8ECB806,
	0x8ECC005, 0x8ED0129, 0x8F70245, 0x8F79826,
	0x8F7A827, 0x8F7B832, 0x8F80026, 0x8F81005,
	0x8F81807, 0x8F82185, 0x8F89425, 0x8F9A027,
	0x8F9B086, 0x8F9F027, 0x8FA0006, 0x8FA0807,
	0x8FA1006, 0x8FA1992, 0x8FA8129, 0x8FD8005,
	0x8FE028B, 0x8FEA8F6, 0x8FEE874, 0x8FF0A16,
	0x8FFF812, 0x9000FE5, 0x9040FE5, 0x9080FE5,
	0x90C0FE5, 0x9100FE5, 0x9140FE5, 0x9180FE5,
	0x91C0325, 0x9200DCA, 0x9238092, 0x9240FE5,
	0x9280865, 0x97C8C05, 0x97F8832, 0x9800FE5,
	0x9840FE5, 0x9880FE5, 0x98C0FE5, 0x9900FE5,
	0x9940FE5, 0x9980FE5, 0x99C0FE5, 0x9A005E5,
	0x9A181FB, 0x9A20006, 0x9A208A5, 0x9A239C6,
	0xA200FE5, 0xA240FE5, 0xA280FE5, 0xA2C0FE5,
	0xA3008C5, 0xB400FE5, 0xB440FE5, 0xB480FE5,
	0xB4C0FE5, 0xB500705, 0xB5203C5, 0xB530129,
	0xB537032, 0xB5389C5, 0xB560129, 0xB5683A5,
	0xB578086, 0xB57A812, 0xB5805E5, 0xB5980C6,
	0xB59B892, 0xB59E076, 0xB5A0064, 0xB5A2012,
	0xB5A2816, 0xB5A8129, 0xB5AD8CB, 0xB5B1A85,
	0xB5BEA45, 0xB7203E1, 0xB7303E2, 0xB7402CB,
	0xB74B872, 0xB780945, 0xB7A7806, 0xB7A8005,
	0xB7A8EC7, 0xB7C7866, 0xB7C9984, 0xB7F0024,
	0xB7F1012, 0xB7F1804, 0xB7F2006, 0xB7F8027,
	0xB800005, 0xC3FB805, 0xC400FE5, 0xC440FE5,
	0xC480FE5, 0xC4C0FE5, 0xC500FE5, 0xC540FE5,
	0xC580FE5, 0xC5C0FE5, 0xC600FE5, 0xC640AA5,
	0xC680005, 0xC684005, 0xD7F8064, 0xD7FA8C4,
	0xD7FE824, 0xD800FE5, 0xD840FE5, 0xD880445,
	0xD899005, 0xD8A8045, 0xD8AA805, 0xD8B2065,
	0xD8B8FE5, 0xD8F8FE5, 0xD938FE5, 0xD978165,
	0xDE00D45, 0xDE38185, 0xDE40105, 0xDE48125,
	0xDE4E016, 0xDE4E826, 0xDE4F812, 0xDE5007B,
	0xE7805A6, 0xE7982C6, 0xE7A8E76, 0xE800FF6,
	0xE840EB6, 0xE8804D6, 0xE894F76, 0xE8B2827,
	0xE8B3846, 0xE8B5056, 0xE8B68A7, 0xE8B98FB,
	0xE8BD8E6, 0xE8C1836, 0xE8C28C6, 0xE8C63B6,
	0xE8D5066, 0xE8D7796, 0xE900836, 0xE921046,
	0xE922816, 0xE96026B, 0xE97026B, 0xE980AD6,
	0xE9B030B, 0xEA00321, 0xEA0D322, 0xEA1A321,
	0xEA270C2, 0xEA2B222, 0xEA34321, 0xEA41322,
	0xEA4E001, 0xEA4F021, 0xEA51001, 0xEA52821,
	0xEA54861, 0xEA570E1, 0xEA5B062, 0xEA5D802,
	0xEA5E8C2, 0xEA62942, 0xEA68321, 0xEA75322,
	0xEA82021, 0xEA83861, 0xEA868E1, 0xEA8B0C1,
	0xEA8F322, 0xEA9C021, 0xEA9D861, 0xEAA0081,
	0xEAA3001, 0xEAA50C1, 0xEAA9322, 0xEAB6321,
	0xEAC3322, 0xEAD0321, 0xEADD322, 0xEAEA321,
	0xEAF7322, 0xEB04321, 0xEB11322, 0xEB1E321,
	0xEB2B322, 0xEB38321, 0xEB45362, 0xEB54301,
	0xEB60813, 0xEB61302, 0xEB6D813, 0xEB6E0A2,
	0xEB71301, 0xEB7D813, 0xEB7E302, 0xEB8A813,
	0xEB8B0A2, 0xEB8E301, 0xEB9A813, 0xEB9B302,
	0xEBA7813, 0xEBA80A2, 0xEBAB301, 0xEBB7813,
	0xEBB8302, 0xEBC4813, 0xEBC50A2, 0xEBC8301,
	0xEBD4813, 0xEBD5302, 0xEBE1813, 0xEBE20A2,
	0xEBE5001, 0xEBE5802, 0xEBE7629, 0xEC00FF6,
	0xEC40FF6, 0xEC80FF6, 0xECC0FF6, 0xED006C6,
	0xED1B876, 0xED1DE26, 0xED368F6, 0xED3A806,
	0xED3B1B6, 0xED42006, 0xED42836, 0xED43892,
	0xED4D886, 0xED509C6, 0xEF80122, 0xEF85005,
	0xEF85A62, 0xEF928A2, 0xF0000C6, 0xF004206,
	0xF00D8C6, 0xF011826, 0xF013086, 0xF0187A4,
	0xF047806, 0xF080585, 0xF0980C6, 0xF09B8C4,
	0xF0A0129, 0xF0A7005, 0xF0A7816, 0xF1483A5,
	0xF157006, 0xF160565, 0xF176066, 0xF178129,
	0xF17F814, 0xF268345, 0xF275804, 0xF276066,
	0xF278129, 0xF3F00C5, 0xF3F4065, 0xF3F6825,
	0xF3F81C5, 0xF400FE5, 0xF440885, 0xF46390B,
	0xF4680C6, 0xF480421, 0xF491422, 0xF4A20C6,
	0xF4A5804, 0xF4A8129, 0xF4AF032, 0xF638F4B,
	0xF656016, 0xF65684B, 0xF658014, 0xF65886B,
	0xF680D8B, 0xF697016, 0xF6979CB, 0xF700065,
	0xF702B45, 0xF710825, 0xF712005, 0xF713805,
	0xF714925, 0xF71A065, 0xF71C805, 0xF71D805,
	0xF721005, 0xF723805, 0xF724805, 0xF725805,
	0xF726845, 0xF728825, 0xF72A005, 0xF72B805,
	0xF72C805, 0xF72D805, 0xF72E805, 0xF72F805,
	0xF730825, 0xF732005, 0xF733865, 0xF7360C5,
	0xF73A065, 0xF73C865, 0xF73F005, 0xF740125,
	0xF745A05, 0xF750845, 0xF752885, 0xF755A05,
	0xF778033, 0xF800576, 0xF818C76, 0xF8501D6,
	0xF8589D6, 0xF8609D6, 0xF868C96, 0xF88018B,
	0xF8877F6, 0xF8C6C16, 0xF8F3396, 0xF908576,
	0xF920116, 0xF928036, 0xF9300B6, 0xF980FF6,
	0xF9C0F56, 0xF9FD895, 0xFA00FF6, 0xFA40FF6,
	0xFA80FF6, 0xFAC0FF6, 0xFB00FF6, 0xFB40AF6,
	0xFB6E216, 0xFB78196, 0xFB80ED6, 0xFBBE3D6,
	0xFBF0176, 0xFBF8016, 0xFC00176, 0xFC086F6,
	0xFC28136, 0xFC304F6, 0xFC483B6, 0xFC58036,
	0xFC80FF6, 0xFCC0FF6, 0xFD00A76, 0xFD301B6,
	0xFD38196, 0xFD40116, 0xFD485B6, 0xFD5F8D6,
	0xFD671B6, 0xFD70116, 0xFD78116, 0xFD80FF6,
	0xFDC0256, 0xFDCA6D6, 0xFDF8129, 0x10000005,
	0x1536F805, 0x15380005, 0x15B9C805, 0x15BA0005,
	0x15C0E805, 0x15C10005, 0x16750805, 0x16758005,
	0x175F0005, 0x17C00FE5, 0x17C40FE5, 0x17C80FE5,
	0x17CC0FE5, 0x17D003A5, 0x18000005, 0x189A5005,
	0x189A8005, 0x191D7805, 0x7000081B, 0x70010BFB,
	0x70080FE6, 0x700C0DE6, 0x7800001D, 0x7FFFE81D,
	0x8000001D, 0x87FFE81D
};

/// == 3382
const size_t categorySearchTableCount =
	sizeof(categorySearchTable) / sizeof(*categorySearchTable);
