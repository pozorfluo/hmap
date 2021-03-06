//------------------------------------------------------------------ SUMMARY ---
/**
 * Common configuration elements for various hmap implementations
 *
 */

#ifndef configuration_h
#define configuration_h

//------------------------------------------------------------ CONFIGURATION ---
#define WELCOME_MESSAGE                                                        \
	FG_BRIGHT_BLUE REVERSE                                                     \
	    " hmap version 0.26.2 " RESET FG_BRIGHT_BLUE                           \
	    " type exit to quit\n" RESET FG_BRIGHT_RED REVERSE                     \
	    "\t todo \n" RESET FG_BRIGHT_RED                                       \
	    "\t- [ ] Wrap up a version satisfying build-your-own-lisp use case\n"  \
	    "\t\t+ [ ] Implement <string => int>\n"                                \
	    "\t\t\t* [ ] Test\n"                                                   \
	    "\t\t\t* [ ] Bench different hash function\n"                          \
	    "\t\t+ [ ] Implement <string => pointer>\n"                            \
	    "\t\t\t* [ ] Test\n"                                                   \
	    "\t\t\t* [ ] Bench different hash function\n"                          \
	    "\t\t+ [ ] Implement <string => function pointer>\n"                   \
	    "\t\t\t* [ ] Test\n"                                                   \
	    "\t\t\t* [ ] Bench different hash function\n"                          \
	    "\t- [ ] Move on to next build your own lisp step\n"                   \
	    "\t\t+ [x] Implement remove for bucket aos\n" RESET FG_BRIGHT_YELLOW   \
	    "\t- [ ] Consider explicitely filling padding in map struct with a "   \
	    "union of interesting extras metadata depending on types/use of "      \
	    "hmap\n"                                                               \
	    "\t\t+ [ ] See PHPs-new-hashtable-implementation.html\n"                \
	    "\t- [ ] Bench other types of KVP\n"                                   \
	    "\t- [ ] Bench murmur, reduce fibo, tab_hash\n"                        \
	    "\t- [ ] Investigate how hmap_bucket_aos fails at load_factor=1\n"     \
	    "\t\t+ [ ] Compare with hmap_simd\n"                                   \
	    "\t- [ ] Consider that current SIMD implementation is flawed\n"        \
	    "\t\t+ [ ] Review it\n"                                                \
	    "\t\t+ [ ] Investigate how aos bucket w/o simd beat it so soundly\n"   \
	    "\t\t+ [ ] Consider that TLF and SIMD make each other irrelevant\n"    \
	    "\t- [ ] Compare to alternative implementation\n"                      \
	    "\t\t+ [x] Try separate meta array, aos bucket\n"                      \
	    "\t\t+ [x] Try SIMD probe without TLF slingshots\n"                    \
	    "\t- [ ] Consider adding a cursor for store iteration\n"               \
	    "\t- [x] Wrap hmap interface with an opaque pointer to an incomplete " \
	    "type \n"                                                              \
	    "\t\t+ [ ] see "                                                       \
	    "https://alastairs-place.net/blog/2013/06/03/encapsulation-in-c/\n"    \
	    "\t- [x] Update hmap->top when doing hmap->remove\n"                   \
	    "\t\t+ [ ] Look for simpler ways to update the store !!\n"             \
	    "\t- [x] Fill and read an array as a baseline\n"                       \
	    "\t- [x] Add a test that does a constant number of find, get, put,\n"  \
	    "\t\tremove and compare output at different hmap sizes, load "         \
	    "factor\n" RESET FG_BRIGHT_GREEN                                       \
	    "\t- [ ] Use macros to define key, value data types and compare "      \
	    "func\n"                                                               \
	    "\t- [ ] Consider a Fat Pointer style struct wrapper to allow\n"       \
	    "\t\tgeneric key, value type handling\n"                               \
	    "\t- [ ] Consider storing a deep space hash and reducing with hash\n"  \
	    "\t\tshift as needed instead of rehashing on resize\n"                 \
	    "\t- [ ] Split hash functions to hash.c\n"                             \
	    "\t- [ ] Implement hset\n"                                             \
	    "\t- [ ] Consider an optional hset of all values in hmap\n" RESET      \
	    "\t- [x] Refactor Slingshot sequences by array\n"                      \
	    "\t\t+ [x] Slingshot ALL buckets.metas then\n"                         \
	    "\t\t+ [x] Slingshot ALL buckets.distances then\n"                     \
	    "\t\t+ [x] Slingshot ALL buckets.entries\n"                            \
	    "\t- [x] Implement backward shift deletion\n"                          \
	    "\t- [x] Profile core table operations\n"                              \
	    "\t\t+ [x] Isolate them by using fixed size keys, a innocuous hash "   \
	    "func\n"                                                               \
	    "\t- [x] Check boundaries when doing slingshots\n"                     \
	    "\t- [x] Consider tossing actual_capacity \n"                          \
	    "\t\t+ [ ] Hunt potential off-by-1 errors checking entry vs "          \
	    "capacity\n"                                                           \
	    "\t- [x] Implement baseline non-SIMD linear probing\n"                 \
	    "\t\t+ [x] Benchmark against SIMD wip versions\n"                      \
	    "\t- [x] Implement the most basic put operation to mock tables\n"      \
	    "\t- [x] Try mapping and storing primitive type/values\n"              \
	    "\t\t+ [ ] Benchmark the difference with store of pointers\n"

#define SIMD_PROBE
#define BENCHMARK
#define TEST_COUNT 1000000
#include "benchmark.h"

#endif /* configuration_h */