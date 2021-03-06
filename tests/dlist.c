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

    for (size_t i = 0; i < (sizeof(in) / sizeof(in[0])); ++i)
        sdlist_pushback(list, in[i]);

    SDNode *itr = sdlist_begin(list);
    for (int i = 0; itr != NULL; itr = sdlist_next(itr), ++i)
        out[i] = *sdlist_at(int, itr); 
    
    TEST_ASSERT_EQUAL(1, out[0]);
    TEST_ASSERT_EQUAL(2, out[1]);
    TEST_ASSERT_EQUAL(3, out[2]);
    TEST_ASSERT_EQUAL(4, out[3]);

    sdlist_destroy(&list);
}

void test_pushback_types(void)
{
    SDLIST_INIT(list, NULL);
    int n = 1;
    char s = '2';
    float f = 3.0;
    struct data_t {
        int n1;
        int n2;
    };
    struct data_t data;
    data.n1 = 4;
    data.n2 = 4;

    int out1 = 0;
    char out2 = '0';
    float out3 = 0.0;
    struct data_t out4;

    sdlist_pushback(list, n);
    sdlist_pushback(list, s);
    sdlist_pushback(list, f);
    sdlist_pushback(list, data);

    SDNode *itr = sdlist_begin(list);
    out1 = *sdlist_at(int, itr);
    itr = sdlist_next(itr);
    out2 = *sdlist_at(char, itr);
    itr = sdlist_next(itr);
    out3 = *sdlist_at(float, itr);
    itr = sdlist_next(itr);
    out4 = *sdlist_at(struct data_t, itr);

    TEST_ASSERT_EQUAL(n, out1);
    TEST_ASSERT_EQUAL(s, out2);
    TEST_ASSERT_EQUAL(f, out3);
    TEST_ASSERT_EQUAL(data.n1, out4.n1);
    TEST_ASSERT_EQUAL(data.n2, out4.n2);

    sdlist_destroy(&list);
}

void test_pushfront(void)
{
    SDLIST_INIT(list, NULL);
    int in[] = { 1, 2, 3};
    int out[] = { 0, 0, 0};

    for (size_t i = 0; i < (sizeof(in) / sizeof(in[0])); ++i)
        sdlist_pushfront(list, in[i]);

    SDNode *itr = sdlist_begin(list);
    for (int i = 0; itr != NULL; itr = sdlist_next(itr), ++i)
        out[i] = *sdlist_at(int, itr);

    TEST_ASSERT_EQUAL(3, out[0]);
    TEST_ASSERT_EQUAL(2, out[1]);
    TEST_ASSERT_EQUAL(1, out[2]);

    sdlist_destroy(&list);
}

void test_pop(void)
{
    SDLIST_INIT(list, NULL);
    int in[] = { 1, 2, 3 };
    int out[] = { 0, 0, 0 };

    for (size_t i = 0; i < (sizeof(in) / sizeof(in[0])); ++i)
        sdlist_pushback(list, in[i]);

    sdlist_pop(list);

    SDNode *itr = sdlist_begin(list);
    for (int i = 0; itr != NULL; itr = sdlist_next(itr), ++i)
        out[i] = *sdlist_at(int, itr);

    TEST_ASSERT_EQUAL(1, out[0]);
    TEST_ASSERT_EQUAL(2, out[1]);
    TEST_ASSERT_EQUAL(0, out[2]);

    sdlist_destroy(&list);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_init);
    RUN_TEST(test_to_node);
    RUN_TEST(test_pushback);
    RUN_TEST(test_pushback_types);
    RUN_TEST(test_pushfront);
    RUN_TEST(test_pop);
}
