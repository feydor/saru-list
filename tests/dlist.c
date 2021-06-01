#include <unity.h>
#include <stdlib.h>
#include "saru-dlist.h"

void setUp(void)
{
    // set stuff up here
}

void tearDown(void)
{
    // clean stuff up here
}

void test_init(void)
{
    SDList list;
    sdlist_init(&list, NULL);
    TEST_ASSERT_EQUAL(0, list.size); 
    TEST_ASSERT_EQUAL(NULL, list.head); 
    TEST_ASSERT_EQUAL(NULL, list.tail); 
    TEST_ASSERT_EQUAL(NULL, list.destroy); 
}

void test_to_node(void)
{
    SDLIST_INIT(list, NULL);
    char str[] = "a string";
    SDNode *n1 = sdlist_to_node((void *)str);
    
    TEST_ASSERT_EQUAL(str, (char *)n1->data);
    TEST_ASSERT_EQUAL(NULL, n1->next);
    TEST_ASSERT_EQUAL(NULL, n1->prev);

    free(n1);
}

void test_pushback(void)
{
    SDLIST_INIT(list, NULL);
    int in[] = { 1, 2, 3 };
    int out[] = { 0, 0, 0};

    sdlist_pushfront(list, in[0]);
    sdlist_pushfront(list, in[1]);
    sdlist_pushfront(list, in[2]);

    SDNode *itr = sdlist_begin(list);
    for (int i = 0; itr != NULL; itr = itr->next, ++i)
        out[i] = *sdlist_at(int, itr); 
    
    printf("%d\n", out[0]);
    printf("%d\n", out[1]);
    printf("%d\n", out[2]);

    sdlist_destroy(&list);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_init);
    RUN_TEST(test_to_node);
    RUN_TEST(test_pushback);
}
