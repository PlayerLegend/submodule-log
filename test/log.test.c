#define FLAT_INCLUDES
#include "../log.h"
#include "../../debug/debug.h"

int main()
{
    log_normal ("This is normal output");
    log_error ("This is an error");

    return 0;
}
