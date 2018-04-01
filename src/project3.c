/*********************************************************************************************
@file - project3.c
@brief - project3.c file is the header file for the project3 testing functionality

This file runs that required programs for project 3 including the memory profiler
and the SPI communication commands

@author - Scott McElroy

@date - March 31, 2018

Created for ECEN5813
**********************************************************************************************/

#include "project3.h"

/*********************************************************************************************/
/*****************************Project3********************************************************/
/**********************************************************************************************
@brief - This function is the main code that runs the program for project3

@param - void
@return -  void
**********************************************************************************************/

void project3(void)
{
    #ifdef KL25Z_PRO
	/*********************************************************************/
    /******************Profiler run for memset using DMA on KL25Z*********/
	/*********************************************************************/
	/*needed variables for the program*/
	uint32_t memset_dma_kl25z_count_10 = 0;
    uint32_t memset_dma_kl25z_count_10_32bit = 0;
    uint32_t memset_dma_kl25z_count_100 = 0;
    uint32_t memset_dma_kl25z_count_1000 = 0;
    //uint32_t memset_dma_kl25z_count_5000 = 0;

    /*profiler code to run the analysis on the memset_dma using systick timer*/
    /*using 8-bit conversion (the number of conversions are listed as variables)*/
    memset_dma_kl25z_count_10 = profiler_memset_dma_kl25z(MEM_LEN_10, MEM_TYPE8);
    memset_dma_kl25z_count_10_32bit = profiler_memset_dma_kl25z(MEM_LEN_10, MEM_TYPE32);
    memset_dma_kl25z_count_100 = profiler_memset_dma_kl25z(MEM_LEN_100, MEM_TYPE8);
    memset_dma_kl25z_count_1000 = profiler_memset_dma_kl25z(MEM_LEN_1000, MEM_TYPE8);
    /*5000 will not run because linker is not allowing changes*/
    //memset_dma_kl25z_count_5000 = profiler_memset_dma_kl25z(MEM_LEN_5000, MEM_TYPE8);
    /******************************************************************************/
    /*****************End of KL25Z memset_dma test*********************************/
    /******************************************************************************/

    /**********************************************************************/
    /******************Profiler run for memmove using DMA on KL25Z*********/
    /*********************************************************************/
	/*needed variables for the program*/
	uint32_t memmove_dma_kl25z_count_10 = 0;
    uint32_t memmove_dma_kl25z_count_10_32bit = 0;
    uint32_t memmove_dma_kl25z_count_100 = 0;
    uint32_t memmove_dma_kl25z_count_1000 = 0;
    //uint32_t memmove_dma_kl25z_count_5000 = 0;

    /*profiler code to run the analysis on the memmove_dma using systick timer*/
    /*using 8-bit conversion (the number of conversions are listed as variables)*/
    memmove_dma_kl25z_count_10 = profiler_memmove_dma_kl25z(MEM_LEN_10, MEM_TYPE8);
    memmove_dma_kl25z_count_10_32bit = profiler_memmove_dma_kl25z(MEM_LEN_10, MEM_TYPE32);
    memmove_dma_kl25z_count_100 = profiler_memmove_dma_kl25z(MEM_LEN_100, MEM_TYPE8);
    memmove_dma_kl25z_count_1000 = profiler_memmove_dma_kl25z(MEM_LEN_1000, MEM_TYPE8);
    /*5000 will not run because linker is not allowing changes*/
    //memmove_dma_kl25z_count_5000 = profiler_memmove_dma_kl25z(MEM_LEN_5000);

    /******************************************************************************/
    /*****************End of KL25Z memmove_dma test*********************************/
    /******************************************************************************/


    while(memset_dma_kl25z_count_10 || memset_dma_kl25z_count_100 || memset_dma_kl25z_count_1000 ){};
    while(memset_dma_kl25z_count_10_32bit){};
    while(memmove_dma_kl25z_count_10 || memmove_dma_kl25z_count_100 || memmove_dma_kl25z_count_1000 ){};
    while(memmove_dma_kl25z_count_10_32bit){};

    #endif /*KL25Z_PRO*/

    return;
}

/*********************************************************************************************/
/***********************************END OF FILE***********************************************/
/*********************************************************************************************/

