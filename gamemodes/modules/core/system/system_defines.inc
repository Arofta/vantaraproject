//#define function:%0(%1) forward %0(%1); public %0(%1)
#define    function:%0(%1)	forward %0(%1); public %0(%1)

#if defined BCRYPT_COST
    #undef BCRYPT_COST
    #define BCRYPT_COST     12
#else
    #define BCRYPT_COST     12
#endif

#if defined MAX_PLAYERS
    #undef MAX_PLAYERS
    #define MAX_PLAYERS     20
#else
    #define MAX_PLAYERS     20
#endif
#define MAX_CHARACTERS      3

#define INVALID_VALUE       0xFFFF

// HOLDING(keys)
#define HOLDING(%0) \
	((newkeys & (%0)) == (%0))

// PRESSED(keys)
#define PRESSED(%0) \
	(((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))

// PRESSING(keyVariable, keys)
#define PRESSING(%0,%1) \
	(%0 & (%1))

// RELEASED(keys)
#define RELEASED(%0) \
	(((newkeys & (%0)) != (%0)) && ((oldkeys & (%0)) == (%0)))

// inventory system
#define MAX_INVENTORY_SLOTS     40
#define MAX_SLOTS_PER_PAGE      20

// drop system
#define MAX_DROPPED_ITEMS    1000

// enum e_XYZ
// {
//     Float:x,
//     Float:y,
//     Float:z
// };
// 
// enum e_XYZA
// {
//     Float:x,
//     Float:y,
//     Float:z,
//     Float:a
// };
// 
// enum e_XYZR
// {
//     Float:x,
//     Float:y,
//     Float:z,
//     Float:rx,
//     Float:ry,
//     Float:rz
// };

//#define isnull(%0) ((!(%0[0])) ? (true) : (false))