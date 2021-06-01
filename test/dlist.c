#include <unity.h>
#include "saru-dlist.h"

void setUp(void);
void tearDown(void);

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_sb_create);
    RUN_TEST(test_sb_put_get);
    RUN_TEST(test_sb_memcpy);
    RUN_TEST(test_sb_strcpy);
}

void setUp(void)
{
    // set stuff up here
}

void tearDown(void)
{
    // clean stuff up here
}
