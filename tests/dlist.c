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
    SDNode *n1 = sdlist_to_node(str);
    
    TEST_ASSERT_EQUAL(str, (char *)n1->data);
    TEST_ASSERT_EQUAL(NULL, n1->next);
    TEST_ASSERT_EQUAL(NULL, n1->prev);

    free(n1);
}

void test_pushback(void)
{
    SDLIST_INIT(list, NULL);
    int in[] = { 1, 2, 3 , 4};
    int out[] = { 0, 0, 0, 0};

    sdlist_pushback(list, in[0]);
    sdlist_pushback(list, in[1]);
    sdlist_pushback(list, in[2]);
    sdlist_pushback(list, in[3]);

    SDNode *itr = sdlist_begin(list);
    for (int i = 0; itr != NULL; itr = sdlist_next(itr), ++i)
        out[i] = *sdlist_at(int, itr); 
    
    TEST_ASSERT_EQUAL(1, out[0]);
    TEST_ASSERT_EQUAL(2, out[1]);
    TEST_ASSERT_EQUAL(3, out[2]);
    TEST_ASSERT_EQUAL(4, out[3]);

    sdlist_destroy(&list);
}

void test_pushfront(void)
{
    SDLIST_INIT(list, NULL);
    int in[] = { 1, 2, 3};
    int out[] = { 0, 0, 0};

    sdlist_pushback(list, in[0]);
    sdlist_pushback(list, in[1]);
    sdlist_pushback(list, in[2]);

    SDNode *itr = sdlist_begin(list);
    for (int i = 0; itr != NULL; itr = sdlist_next(itr), ++i)
        out[i] = *sdlist_at(int, itr);

    TEST_ASSERT_EQUAL(3, out[0]);
    TEST_ASSERT_EQUAL(2, out[1]);
    TEST_ASSERT_EQUAL(1, out[2]);

    sdlist_destroy(&list);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_init);
    RUN_TEST(test_to_node);
    RUN_TEST(test_pushback);
}
