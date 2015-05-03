#include <saveload.h>
#include <desc.h>
#include <item.h>
#include <object.h>

/** A clone-able object, useful for simple items that simply
 * need to exist (stuffed animals, for example)
 */

#ifdef DOXYGEN
struct Trinket : public Saveload, public Desc, public Item, public Object {
#endif

NAME( "trinket" )
LOOK( "It's a valueless trinket." )
DISTANT( "a trinket" )
SPECIFIC( "the trinket" )
PLURAL( "trinkets" )

#ifdef DOXYGEN
};
#endif
