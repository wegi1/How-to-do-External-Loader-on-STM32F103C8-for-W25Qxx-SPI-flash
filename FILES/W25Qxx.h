/*
 * W25Qxx.h
 *
 *  Created on: Jul 15, 2023
 *      Author: controllerstech
 */

#ifndef INC_W25QXX_H_
#define INC_W25QXX_H_

#include "main.h"
#define W25Q32
#ifdef W25Q32
#define MEMORY_FLASH_SIZE				0x1000000 /* 32Mbit =>4Mbyte */
#else
#define MEMORY_FLASH_SIZE				0x200000 /* 16Mbit =>2Mbyte */
#endif

#define MEMORY_BLOCK_SIZE				0x10000   /*  blocks of 64KBytes */
#define MEMORY_SECTOR_SIZE				0x1000    /* 4kBytes */
#define MEMORY_PAGE_SIZE				0x100     /* 256 bytes */

#define W25Q_WRITE_ENABLE 0x06
#define W25Q_WRITE_DISABLE 0x04

#define W25Q_READ_SR1 0x05
#define W25Q_READ_SR2 0x35
#define W25Q_READ_SR3 0x15
#define W25Q_WRITE_SR1 0x01
#define W25Q_WRITE_SR2 0x31
#define W25Q_WRITE_SR3 0x11

#define W25Q_READ_DATA 0x03
#define W25Q_READ_DATA_4B 0x13
#define W25Q_FAST_READ 0x0B
#define W25Q_FAST_READ_4B 0x0C

#define W25Q_PAGE_PROGRAM 0x02
#define W25Q_PAGE_PROGRAM_4B 0x12

#define W25Q_SECTOR_ERASE 0x20
#define W25Q_SECTOR_ERASE_4B 0x21
#define W25Q_32KB_BLOCK_ERASE 0x52
#define W25Q_64KB_BLOCK_ERASE 0xD8
#define W25Q_64KB_BLOCK_ERASE_4B 0xDC
#define W25Q_CHIP_ERASE 0xC7

#define W25Q_ENABLE_RST 0x66
#define W25Q_RESET 0x99

void W25Q_Reset (void);
void W25Q_Chip_Erase (void);
uint32_t W25Q_ReadID (void);

void W25Q_Read (uint32_t startPage, uint8_t offset, uint32_t size, uint8_t *rData);
void W25Q_FastRead (uint32_t startPage, uint8_t offset, uint32_t size, uint8_t *rData);

void W25Q_Erase_Sector (uint16_t numsector);

void W25Q_Write_Clean(uint32_t page, uint16_t offset, uint32_t size, uint8_t *data);
void W25Q_Write (uint32_t page, uint16_t offset, uint32_t size, uint8_t *data);

void W25Q_Write_Byte (uint32_t Addr, uint8_t data);
uint8_t W25Q_Read_Byte (uint32_t Addr);

float W25Q_Read_NUM (uint32_t page, uint16_t offset);
void W25Q_Write_NUM (uint32_t page, uint16_t offset, float data);

void W25Q_Read_32B (uint32_t page, uint16_t offset, uint32_t size, uint32_t *data);
void W25Q_Write_32B (uint32_t page, uint16_t offset, uint32_t size, uint32_t *data);


void flash_WriteMemory(uint8_t* buffer, uint32_t address, uint32_t buffer_size);
void flash_ReadMemory (uint32_t Addr, uint32_t Size, uint8_t* buffer);
void flash_SectorErase(uint32_t EraseStartAddress, uint32_t EraseEndAddress);
void flash_ChipErase (void);
void flash_Reset (void);

#endif /* INC_W25QXX_H_ */
