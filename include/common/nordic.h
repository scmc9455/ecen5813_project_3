/*********************************************************************************************
@file - nordic.h
@brief - nordic.h file is the header file for the nordic functionality

This file contains the functions for the nordic communciations.
This file contains functions definitions for the following
**Nordic Functions****
1. nrf_read_register
2. nrf_write_register
3. nrf_read_status
4. nrf_write_config
5. nrf_read_config
6. nrf_read_rf_setup
7. nrf_write_rf_setup
8. nrf_read_rf_ch
9. nrf_write_rf_ch
10. nrf_read_TX_ADDR
11. nrf_write_TX_ADDR
12. nrf_read_fifo_status
13. nrf_flush_tx_fifo
14. nrf_flush_rx_fifo

@author - Scott McElroy

@date - April 6, 2018

Created for ECEN5813
**********************************************************************************************/

#ifndef __NORDIC_H__
#define __NORDIC_H__

#include <stdint.h>
#include <stdlib.h>

/*********************************************************************************************/
/***********************************nrf_read_register*****************************************/
/**********************************************************************************************
@brief- This function reads the contents of the nordic IC register that is passed to it

@param - nordic_reg: register inside the nordic device that 
@return - value: contents of register
**********************************************************************************************/

uint8_t nrf_read_register(uint8_t nordic_reg);

/*********************************************************************************************/
/***********************************nrf_write_register*****************************************/
/**********************************************************************************************
@brief- This function writes to the nordic IC register that is passed to it

@param - nordic_reg: register inside the nordic device that
@param - value: value to pass to the nordic device register
@return - return: contents of register
**********************************************************************************************/

uint8_t nrf_write_register(uint8_t nordic_reg, uint8_t value);

/*********************************************************************************************/
/***********************************nrf_read_status*******************************************/
/**********************************************************************************************
@brief- This function reads that status register inside the nordic IC

@param - void
@return - return: contents of the status register
**********************************************************************************************/

uint8_t nrf_read_status(void);

/*********************************************************************************************/
/***********************************nrf_read_config*******************************************/
/**********************************************************************************************
@brief- This function reads that configuration register inside the nordic IC

@param - void
@return - return: contents of the config register
**********************************************************************************************/

uint8_t nrf_read_config(void);

/*********************************************************************************************/
/***********************************nrf_read_rf_setup*****************************************/
/**********************************************************************************************
@brief- This function reads the rf setup register inside the nordic IC

@param - void
@return - return: contents of the rf setup register
**********************************************************************************************/

uint8_t nrf_read_rf_setup(void);

/*********************************************************************************************/
/**********************************nrf_write_rf_setup*****************************************/
/**********************************************************************************************
@brief- This function configures the rf setup registers inside the nordic IC

@param - rf_config: configuration value for the RF setup register
@return - void
**********************************************************************************************/

void nrf_write_rf_setup(uint8_t rf_config);

/*********************************************************************************************/
/***********************************nrf_read_rf_ch********************************************/
/**********************************************************************************************
@brief- This function reads the rf channel register inside the nordic IC

@param - void
@return - return: contents of the rf_ch register
**********************************************************************************************/

uint8_t nrf_read_rf_ch(void);

/*********************************************************************************************/
/**********************************nrf_write_rf_ch********************************************/
/**********************************************************************************************
@brief- This function write to the rf channel register inside the nordic IC

@param - rf_channel: value to be written to the channel register
@return - void
**********************************************************************************************/

void nrf_write_rf_ch(uint8_t rf_channel);

/*********************************************************************************************/
/***********************************nrf_read_TX_ADDR******************************************/
/**********************************************************************************************
@brief- This function reads the 5 bytes of the TX_ADDR register 

@param - *tx_address: location where the byte reads will store the read contents
@return - void
**********************************************************************************************/

void nrf_read_TX_ADDR(uint8_t *tx_address);

/*********************************************************************************************/
/***********************************nrf_write_TX_ADDR******************************************/
/**********************************************************************************************
@brief- This function writes 5 bytes of data to the TX_ADDR register 

@param - *tx_address: location of the 5 byte values that will be written to the Nordic
@return - void
**********************************************************************************************/

void nrf_write_TX_ADDR(uint8_t *tx_address);

/*********************************************************************************************/
/******************************nrf_read_fifo_status*******************************************/
/**********************************************************************************************
@brief- This function reads the status register associated with the fifo inside the nordic IC

@param - void
@return - return: contents of the fifo status register
**********************************************************************************************/

uint8_t nrf_read_fifo_status(void);

/*********************************************************************************************/
/******************************nrf_flush_tx_fifo**********************************************/
/**********************************************************************************************
@brief- This function empties the tx fifo inside the nordic IC

@param - void
@return - void
**********************************************************************************************/

void nrf_flush_tx_fifo(void);

/*********************************************************************************************/
/******************************nrf_flush_rx_fifo**********************************************/
/**********************************************************************************************
@brief- This function empties the rx fifo inside the nordic IC

@param - void
@return - void
**********************************************************************************************/

void nrf_flush_rx_fifo(void);

#endif /*__NORDIC_H__*/

/*********************************************************************************************/
/***********************************End of File***********************************************/
/*********************************************************************************************/
