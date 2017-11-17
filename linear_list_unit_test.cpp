//
// Created by 唐艺峰 on 2017/11/13.
//

#include "linear_list_unit_test.h"

TEST(linear_list, initial_test) {
    auto * l = new SqList;
    l->listsize = 0;
    int e;
    EXPECT_EQ(FAILURE, ClearList(l));
    EXPECT_EQ(FAILURE, PriorElem(l, 1, &e));
    EXPECT_EQ(FAILURE, ListInsert(l, 0 + SP, 1));
    EXPECT_EQ(SUCCESS, InitaList(l));
    EXPECT_EQ(SUCCESS, DestroyList(l));
    EXPECT_EQ(FAILURE, ClearList(l));
    EXPECT_EQ(FAILURE, ListInsert(l, 0 + SP, 1));
    delete l;
}

TEST(linear_list, insert_test) {
    auto * l = new SqList;
    l->listsize = 0;
    int e;
    EXPECT_EQ(SUCCESS, InitaList(l));
    EXPECT_EQ(SUCCESS, ListInsert(l, 0 + SP, 1));
    EXPECT_EQ(SUCCESS, ListInsert(l, 1 + SP, 2));
    EXPECT_EQ(SUCCESS, ListInsert(l, 0 + SP, 3));
    EXPECT_EQ(3, ListLength(l));
    EXPECT_EQ(FAILURE, GetElem(l, 19 + SP, &e));
    EXPECT_EQ(SUCCESS, GetElem(l, 0 + SP, &e));
    EXPECT_EQ(3, e);
    EXPECT_EQ(SUCCESS, ListDelete(l, 1 + SP, &e));
    EXPECT_EQ(1, e);
    EXPECT_EQ(2, ListLength(l));
    EXPECT_EQ(SUCCESS, ClearList(l));
    EXPECT_EQ(0, ListLength(l));
    EXPECT_EQ(SUCCESS, DestroyList(l));
    delete l;
}

TEST(linear_list, next_test) {
    auto * l = new SqList;
    l->listsize = 0;
    int e;
    EXPECT_EQ(SUCCESS, InitaList(l));
    EXPECT_EQ(SUCCESS, ListInsert(l, 0 + SP, 1));
    EXPECT_EQ(SUCCESS, ListInsert(l, 1 + SP, 2));
    EXPECT_EQ(SUCCESS, ListInsert(l, 2 + SP, 3));
    EXPECT_EQ(SUCCESS, ListInsert(l, 3 + SP, 4));
    EXPECT_EQ(SUCCESS, NextElem(l, 2, &e));
    EXPECT_EQ(3, e);
    EXPECT_EQ(FAILURE, PriorElem(l, 1, &e));
    EXPECT_EQ(0, LocateElem(l, 5, compare));
    EXPECT_EQ(3 + SP, LocateElem(l, 4, compare));
    EXPECT_EQ(SUCCESS, ListInsert(l, 0 + SP, 5));
    EXPECT_EQ(SUCCESS, PriorElem(l, 1, &e));
    EXPECT_EQ(5, e);
    EXPECT_EQ(SUCCESS, DestroyList(l));
    delete l;
}

TEST(linear_list, locate_test) {
    auto * l = new SqList;
    l->listsize = 0;
    int e;
    EXPECT_EQ(SUCCESS, InitaList(l));
    EXPECT_EQ(SUCCESS, ListInsert(l, 0 + SP, 1));
    EXPECT_EQ(SUCCESS, ListInsert(l, 1 + SP, 2));
    EXPECT_EQ(SUCCESS, ListInsert(l, 2 + SP, 3));
    EXPECT_EQ(SUCCESS, ListInsert(l, 3 + SP, 4));
    EXPECT_EQ(1 + SP, LocateElem(l, 2, compare));
    EXPECT_EQ(SUCCESS, ClearList(l));
    EXPECT_EQ(0, ListLength(l));
    EXPECT_EQ(TRUE, ListEmpty(l));
    EXPECT_EQ(SUCCESS, DestroyList(l));
    delete l;
}

int main(int argc, char * args[]) {
    ::testing::InitGoogleTest(&argc, args);
    RUN_ALL_TESTS();
}
