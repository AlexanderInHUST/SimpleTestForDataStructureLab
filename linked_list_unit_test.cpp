//
// Created by 唐艺峰 on 2017/11/13.
//

#include "linked_list_unit_test.h"

TEST(linked_list, initial_test) {
    auto * l = new LkList;
    EXPECT_EQ(SUCCESS, InitaList(l));
    EXPECT_EQ(SUCCESS, DestroyList(l));
    EXPECT_EQ(FAILURE, ClearList(l));
    delete l;
}

TEST(linked_list, insert_test) {
    auto * l = new LkList;
    int * e;
    EXPECT_EQ(SUCCESS, InitaList(l));
    EXPECT_EQ(SUCCESS, ListInsert(l, 1, 1));
    EXPECT_EQ(SUCCESS, ListInsert(l, 2, 2));
    EXPECT_EQ(SUCCESS, ListInsert(l, 1, 3));
    EXPECT_EQ(3, ListLength(l));
    EXPECT_EQ(FAILURE, GetElem(l, 20, e));
    EXPECT_EQ(SUCCESS, GetElem(l, 1, e));
    EXPECT_EQ(3, * e);
    EXPECT_EQ(SUCCESS, ListDelete(l, 2, e));
    EXPECT_EQ(1, * e);
    EXPECT_EQ(2, ListLength(l));
    EXPECT_EQ(SUCCESS, ClearList(l));
    EXPECT_EQ(0, ListLength(l));
    EXPECT_EQ(SUCCESS, DestroyList(l));
    delete l;
}

TEST(linked_list, next_test) {
    auto * l = new LkList;
    int * e;
    EXPECT_EQ(SUCCESS, InitaList(l));
    EXPECT_EQ(SUCCESS, ListInsert(l, 1, 1));
    EXPECT_EQ(SUCCESS, ListInsert(l, 2, 2));
    EXPECT_EQ(SUCCESS, ListInsert(l, 3, 3));
    EXPECT_EQ(SUCCESS, ListInsert(l, 4, 4));
    EXPECT_EQ(SUCCESS, NextElem(l, 2, e));
    EXPECT_EQ(3, * e);
    EXPECT_EQ(FAILURE, PriorElem(l, 1, e));
    EXPECT_EQ(0, LocateElem(l, 5, compare));
    EXPECT_EQ(4, LocateElem(l, 4, compare));
    EXPECT_EQ(SUCCESS, ListInsert(l, 0, 1));
    EXPECT_EQ(SUCCESS, PriorElem(l, 1, e));
    EXPECT_EQ(0, * e);
    EXPECT_EQ(SUCCESS, DestroyList(l));
    delete l;
}

TEST(linked_list, locate_test) {
    auto * l = new LkList;
    int * e;
    EXPECT_EQ(SUCCESS, InitaList(l));
    EXPECT_EQ(SUCCESS, ListInsert(l, 1, 1));
    EXPECT_EQ(SUCCESS, ListInsert(l, 2, 2));
    EXPECT_EQ(SUCCESS, ListInsert(l, 3, 3));
    EXPECT_EQ(SUCCESS, ListInsert(l, 4, 4));
    EXPECT_EQ(2, LocateElem(l, 2, compare));
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