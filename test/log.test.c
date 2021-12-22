#define FLAT_INCLUDES
#include "../log.h"

int main()
{
    log_normal ("This is normal output");
    log_error ("This is an error");

    return 0;
}
