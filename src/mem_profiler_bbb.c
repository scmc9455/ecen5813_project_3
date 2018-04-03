/*********************************************************************************************
@file - mem_profiler_bbb.c

@brief - mem_profiler_bbb.c file is the source file for memory profiler functions for BBB

This file will be used to profile the memory of the BBB.
The functions include the generation of a statics file and running of the profiler
The functions that are included are
1. profiler_my_memset_bbb
2. profiler_my_memmove_bbb
3. profiler_stdlib_memset_bbb
4. profiler_stdlib_memmove_bbb

@author - Scott McElroy

@date - April 1st, 2018

Created for ECEN5813
**********************************************************************************************/

#include "mem_profiler_bbb.h"

/*********************************************************************************************/
/****************************profiler_my_memset_bbb*******************************************/
/**********************************************************************************************
@brief - This function is the main code that will analyze the time it take to run my_mem functions

@param - memset_test_len: length of bytes of the test
@return - counter: returned value of the number of cycles
**********************************************************************************************/

void profiler_my_memset_bbb(uint32_t memset_test_len)
{
    printf("Test for BBB my_memset with a mem length of = %d \n", memset_test_len);
    /*necessary variables to run the profiler*/
    /*Variables need to get the clocking correctly*/
    clock_t start_t, end_t, cal_t, result_t;

    uint8_t *dst_memset_ptr = NULL;
    /*reverse block of memory to be set*/
    dst_memset_ptr = reserve_words(memset_test_len);
    /*Depending on the input type the pointers will have to be casted differently*/

    /*Calibrate the start and end for timer so it can be subtracted out*/
    start_t = clock(); /*grab clock timing*/
    end_t = clock();  /*stop timer*/
    /*Use the count value to calibrate the timing in and out of the functions*/
    cal_t = (end_t - start_t); /*Count value of systick timer*/
    printf("BBB Clock Cal Timing = %ld \n",cal_t); /*Print Cal Results*/

    /*Grab the clock time start*/
    start_t = clock();
    /*run the memset function to be tested*/
    my_memset(dst_memset_ptr, memset_test_len, MEMSET_VALUE);
    /*Grab the clock time start*/
    end_t = clock();
    /*Record the amount that it took to run the memset plus subtract out the cal value*/
    result_t = ((end_t - start_t) - cal_t);
    printf("BBB my_memset runs in = %ld\n\n\n",result_t); /*Print the results of the run out to the terminal*/

    /*Free allocated space from running code*/
    free_words(dst_memset_ptr);

    return;
}

/*********************************************************************************************/
/****************************profiler_my_memmove_bbb******************************************/
/**********************************************************************************************
@brief - This function is the main code that will analyze the time it take to run my_mem functions

@param - memset_test_len: length of bytes of the test
@return - counter: returned value of the number of cycles
**********************************************************************************************/

void profiler_my_memmove_bbb(uint32_t memmove_test_len)
{
    printf("Test for BBB my_memmove with a mem length of = %d \n", memmove_test_len);
    /*necessary variables to run the profiler*/
    /*Variables need to get the clocking correctly*/
    clock_t start_t, end_t, cal_t, result_t;

    uint8_t *src_memmove_ptr = NULL;
    uint8_t *dst_memmove_ptr = NULL;
    /*reverse block of memory to be moved*/
    src_memmove_ptr = reserve_words(memmove_test_len);
    dst_memmove_ptr = reserve_words(memmove_test_len);
    /*Fill the source address memory using for loop and dependent on the type*/
    for(uint32_t i=0; i<(memmove_test_len) ; i++)
    {
    	/*Load the allocated memory with an arbitrary value to move*/
        *(src_memmove_ptr + i) = 0xA5;
    }

    /*Calibrate the start and end for timer so it can be subtracted out*/
    start_t = clock(); /*grab clock timing*/
    end_t = clock();  /*stop timer*/
    /*Use the count value to calibrate the timing in and out of the functions*/
    cal_t = (end_t - start_t); /*Count value of systick timer*/
    printf("BBB Clock Cal Timing = %ld \n",cal_t); /*Print Cal Results*/

    /*Grab the clock time start*/
    start_t = clock();
    /*run the memset function to be tested*/
    my_memmove(src_memmove_ptr, dst_memmove_ptr, memmove_test_len);
   /*Grab the clock time start*/
    end_t = clock();
    /*Record the amount that it took to run the memset plus subtract out the cal value*/
    result_t = ((end_t - start_t) - cal_t);
    printf("BBB my_memmove runs in = %ld\n\n\n",result_t); /*Print the results of the run out to the terminal*/

    /*Free allocated space from running code*/
    free_words(dst_memmove_ptr);
    free_words(src_memmove_ptr);

    return;
}

/*********************************************************************************************/
/****************************profiler_memmove_bbb_standard**********************************/
/**********************************************************************************************
@brief - This function is the main code that will analyze memmove standard lib functions

@param - memset_test_len: length of bytes of the test
@return - counter: returned value of the number of cycles
**********************************************************************************************/

void profiler_stdlib_memmove_bbb(uint32_t memmove_test_len)
{
    printf("Test for BBB stdlib_memmove with a mem length of = %d \n", memmove_test_len);
    /*necessary variables to run the profiler*/
    /*Variables need to get the clocking correctly*/
    clock_t start_t, end_t, cal_t, result_t;

    uint8_t *src_memmove_ptr = NULL;
    uint8_t *dst_memmove_ptr = NULL;
    /*reverse block of memory to be moved*/
    src_memmove_ptr = reserve_words(memmove_test_len);
    dst_memmove_ptr = reserve_words(memmove_test_len);
    /*Fill the source address memory using for loop and dependent on the type*/
    for(uint32_t i=0; i<(memmove_test_len) ; i++)
    {
    	/*Load the allocated memory with an arbitrary value to move*/
        *(src_memmove_ptr + i) = 0xA5;
    }

    /*Calibrate the start and end for timer so it can be subtracted out*/
    start_t = clock(); /*grab clock timing*/
    end_t = clock();  /*stop timer*/
    /*Use the count value to calibrate the timing in and out of the functions*/
    cal_t = (end_t - start_t); /*Count value of systick timer*/
    printf("BBB Clock Cal Timing = %ld \n",cal_t); /*Print Cal Results*/

    /*Grab the clock time start*/
    start_t = clock();
    /*run the memmove function to be tested*/
    memmove(dst_memmove_ptr, src_memmove_ptr, memmove_test_len);
   /*Grab the clock time start*/
    end_t = clock();
    /*Record the amount that it took to run the memset plus subtract out the cal value*/
    result_t = ((end_t - start_t) - cal_t);
    printf("BBB stdlib_memmove runs in = %ld\n\n\n",result_t); /*Print the results of the run out to the terminal*/

    /*Free allocated space from running code*/
    free_words(dst_memmove_ptr);
    free_words(src_memmove_ptr);

    return;
}


/*********************************************************************************************/
/*************************profiler_stdlib_memset_bbb****************************************/
/**********************************************************************************************
@brief - This function is the main code that will analyze the time it take to run mem functions

@param - memset_test_len: length of bytes of the test
@return - counter: returned value of the number of cycles
**********************************************************************************************/

void profiler_stdlib_memset_bbb(uint32_t memset_test_len)
{
   printf("Test for BBB stdlib_memmove with a mem length of = %d \n", memset_test_len);
    /*necessary variables to run the profiler*/
    /*Variables need to get the clocking correctly*/
    clock_t start_t, end_t, cal_t, result_t;

    uint8_t *dst_memset_ptr = NULL;
    /*reverse block of memory to be set*/
    dst_memset_ptr = reserve_words(memset_test_len);
    /*Depending on the input type the pointers will have to be casted differently*/

     /*Calibrate the start and end for timer so it can be subtracted out*/
    start_t = clock(); /*grab clock timing*/
    end_t = clock();  /*stop timer*/
    /*Use the count value to calibrate the timing in and out of the functions*/
    cal_t = (end_t - start_t); /*Count value of systick timer*/
    printf("BBB Clock Cal Timing = %ld \n",cal_t); /*Print Cal Results*/

    /*Grab the clock time start*/
    start_t = clock();
    /*run the memset function to be tested*/
    memset(dst_memset_ptr, MEMSET_VALUE, memset_test_len);
    /*Grab the clock time start*/
    end_t = clock();
    /*Record the amount that it took to run the memset plus subtract out the cal value*/
    result_t = ((end_t - start_t) - cal_t);
    printf("BBB stdlib_memmove runs in = %ld\n\n\n",result_t); /*Print the results of the run out to the terminal*/

    free_words(dst_memset_ptr);

    return;
}


/*********************************************************************************************/
/*****************************End of File*****************************************************/
/*********************************************************************************************/

