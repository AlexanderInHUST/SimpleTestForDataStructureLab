//
// Created by 唐艺峰 on 2017/11/13.
//

#ifndef STRUCTUREEXPRUNITTEST_LINEAR_LIST_UNIT_TEST_H
#define STRUCTUREEXPRUNITTEST_LINEAR_LIST_UNIT_TEST_H

#include "gtest/gtest.h"

#define TRUE 1
#define FALSE 0

#define SUCCESS 1
#define FAILURE 0

typedef struct{
    int * elem;    // pointer of the elems
    int length;    // current length of list
    int listsize;  // size of memory which has been malloc
}SqList;

/*
 * @Name InitaList
 * @Args *l is the linear list being operated
 * @Return Success or Failure
 */
extern int InitaList(SqList * l);

/*
 * @Name DestroyList
 * @Args *l is the linear list being operated
 * @Return Success or Failure
 */
extern int DestroyList(SqList * l);

/*
 * @Name ClearList
 * @Args *l is the linear list being operated
 * @Return Success or Failure
 */
extern int ClearList(SqList * l);

/*
 * @Name ListEmpty
 * @Args *l is the linear list being operated
 * @Return True or False
 */
extern int ListEmpty(SqList * l);

/*
 * @Name ListLength
 * @Args *l is the linear list being operated
 * @Return an integer which is the length of List
 */
extern int ListLength(SqList * l);

/*
 * @Name GetElem
 * @Args *l is the linear list being operated
 *        i is the position of Elem
 *       *e is the Elem
 * @Return Success or Failure
 */
extern int GetElem(SqList * l, int i, int * e);

/*
 * @Name LocateElem
 * @Args *l is the linear list being operated
 *        e is the value provided
 *       compare(a, b) is the function which is provided below
 * @Return an integer which is the position of Elem who is able to pass the compare function
 *      and 0 is expected when no one can pass
 */
extern int LocateElem(SqList * l, int e, int (* compare) (int a, int b));

/*
 * @Name PriorElem
 * @Args *l is the linear list being operated
 *        cur_e is the possible Elem
 *       *pre_e is the pre-Elem
 * @Return Success or Failure
 */
extern int PriorElem(SqList * l, int cur_e, int * pre_e);

/*
 * @Name NextElem
 * @Args *l is the linear list being operated
 *        cur_e is the possible Elem
 *       *next_e is the next-Elem
 * @Return Success or Failure
 */
extern int NextElem(SqList * l, int cur_e, int * next_e);

/*
 * @Name ListInsert
 * @Args *l is the linear list being operated
 *        i is the aim position
 *        e is the Elem
 * @Return Success or Failure
 */
extern int ListInsert(SqList * l, int i, int e);

/*
 * @Name ListDelete
 * @Args *l is the linear list being operated
 *        i is the aim position
 *       *e is the Elem
 * @Return Success or Failure
 */
extern int ListDelete(SqList * l, int i, int * e);

/*
 * @Name ListTraverse
 * @Args *l is the linear list being operated
 *       visit(e) is the function which is provided below
 * @Return Success or Failure
 */
extern int ListTraverse(SqList * l, int (* visit) (int e));

extern int compare(int a, int b);

extern void visit(int e);

/*
//  * @Name compare
//  * @Args a is the first var
//  *       b is the second var
//  * @Return True or False
//  * @Usage this function is expected to be called in LocateElem
//  */
// int compare(int a, int b) {
//     return a == b ? TRUE : FALSE;
// }

// /*
//  * @Name visit
//  * @Args e
//  * @Return void
//  * @Usage this function is expected to be called in ListTraverse
//  */
// void visit(int e) {
//     printf("%d", e);
// }

#endif //STRUCTUREEXPRUNITTEST_LINEAR_LIST_UNIT_TEST_H