#ifndef _TINY6410_H_
#define _TINY6410_H_

#define CONFIG_ENV_SIZE	0x1000
#define CONFIG_SYS_SDRAM_BASE 0x50000000
#define CONFIG_SYS_MAPPED_RAM_BASE	CONFIG_SYS_SDRAM_BASE
#define CONFIG_SYS_UBOOT_BASE	(CONFIG_SYS_MAPPED_RAM_BASE + 0x0fe00000)
#define CONFIG_SYS_TEXT_BASE	0x5fe00000

/* SMDK6400 has 2 banks of DRAM, but we use only one in U-Boot */
#define CONFIG_NR_DRAM_BANKS    1
#define PHYS_SDRAM_1            CONFIG_SYS_SDRAM_BASE   /* SDRAM Bank #1  board/samsung/tiny6410/smdk6400.c:89      */
#define PHYS_SDRAM_1_SIZE       0x10000000      /* 256 MB in Bank #1    */

#define CONFIG_SYS_MAXARGS              16              /* max number of command args */

#define CONFIG_SYS_MAX_FLASH_BANKS      1       /* max number of memory banks   */

#define CONFIG_SYS_LOAD_ADDR            CONFIG_SYS_SDRAM_BASE   /* default load address cmd/source.c 154*/

#define CONFIG_SYS_CBSIZE               256             /* Console I/O Buffer Size    cmd/nvedit.c:587 */

/* Settings as above boot configuration  cmd/nvedit.c:57*/
#define CONFIG_ENV_IS_IN_NAND

/*include/environment.h:77*/
#define CONFIG_ENV_OFFSET               0x0100000

/* allow to overwrite serial and ethaddr */
#define CONFIG_ENV_OVERWRITE
/*common/board_f.c:147*/
#define CONFIG_BAUDRATE         115200

/*
 *  * Size of malloc() pool
 *  include/common.h:199 */
#define CONFIG_SYS_MALLOC_LEN           (CONFIG_ENV_SIZE + 1024 * 1024)

/*arch/arm/lib/crt0.S:76*/
#define CONFIG_SYS_IRAM_BASE    0x0c000000  /* Internal SRAM base address */
#define CONFIG_SYS_IRAM_SIZE    0x2000      /* 8 KB of internal SRAM memory */
#define CONFIG_SYS_IRAM_END     (CONFIG_SYS_IRAM_BASE + CONFIG_SYS_IRAM_SIZE)
#define CONFIG_SYS_INIT_SP_ADDR (CONFIG_SYS_IRAM_END - GENERATED_GBL_DATA_SIZE)

/*cmd/nvedit.c:712*/
/*   #define CONFIG_ENV_IS_IN_FLASH   */

/*#define CONFIG_CLK_667_133_66*/
/*board/samsung/tiny6410/lowlevel_init.S:220*/
#define CONFIG_CLK_533_133_66
/*
 * #define CONFIG_CLK_400_100_50
 * #define CONFIG_CLK_400_133_66
 * #define CONFIG_SYNC_MODE
 * */

/* NAND configuration cmd/nand.c:118*/
#define CONFIG_SYS_MAX_NAND_DEVICE      1
#define CONFIG_SYS_NAND_BASE            0x70200010
#define CONFIG_SYS_S3C_NAND_HWECC

/*include/environment.h:25*/
#define CONFIG_SYS_FLASH_BASE           0x10000000

/* input clock of PLL: SMDK6400 has 12MHz input clock arch/arm/cpu/arm1176/s3c6410/cpu_init.S:37*/
#define CONFIG_SYS_CLK_FREQ     12000000

/*
 *  * Architecture magic and machine type
 *  board/samsung/tiny6410/smdk6400.c:88 */
#define MACH_TYPE               1270

/*drivers/mtd/nand/nand.c:86*/
#define CONFIG_NAND_S3C6410

/* Size of the block protected by one OOB (Spare Area in Samsung terminology) drivers/mtd/nand/s3c64xx.c:360*/
#define CONFIG_SYS_NAND_ECCSIZE (512)
/* Number of ECC bytes per OOB - S3C6400 calculates 13 bytes ECC in 8-bit mode */
#define CONFIG_SYS_NAND_ECCBYTES        13
/* Number of ECC-blocks per NAND page */
#define CONFIG_SYS_NAND_ECCSTEPS        (CONFIG_SYS_NAND_PAGE_SIZE / CONFIG_SYS_NAND_ECCSIZE)
/* Size of a single OOB region */
#define CONFIG_SYS_NAND_OOBSIZE 436
/* Number of ECC bytes per page */
#define CONFIG_SYS_NAND_ECCTOTAL        (CONFIG_SYS_NAND_ECCBYTES * CONFIG_SYS_NAND_ECCSTEPS)
/* ECC byte positions */
#define CONFIG_SYS_NAND_ECCPOS          {40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52,\
                                 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68,\
                                 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84,\
                                 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99,100,\
                                 104,105,106,107,108,109,110,111,112,113,114,115,116,\
                                 120,121,122,123,124,125,126,127,128,129,130,131,132,\
                                 136,137,138,139,140,141,142,143,144,145,146,147,148,\
                                 152,153,154,155,156,157,158,159,160,161,162,163,164,\
                                 168,169,170,171,172,173,174,175,176,177,178,179,180,\
                                 184,185,186,187,188,189,190,191,192,193,194,195,196,\
                                 200,201,202,203,204,205,206,207,208,209,210,211,212,\
                                 216,217,218,219,220,221,222,223,224,225,226,227,228,\
                                 232,233,234,235,236,237,238,239,240,241,242,243,244,\
                                 248,249,250,251,252,253,254,255,256,257,258,259,260,\
                                 264,265,266,267,268,269,270,271,272,273,274,275,276,\
                                 280,281,282,283,284,285,286,287,288,289,290,291,292}

/*for serial*/
#define CONFIG_S3C6410
#define CONFIG_SERIAL1




#endif  /* _TINY6410_H_ */
