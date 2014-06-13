/*
** Copyright 2005-2013  Solarflare Communications Inc.
**                      7505 Irvine Center Drive, Irvine, CA 92618, USA
** Copyright 2002-2005  Level 5 Networks Inc.
**
** This program is free software; you can redistribute it and/or modify it
** under the terms of version 2 of the GNU General Public License as
** published by the Free Software Foundation.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
*/



/***********************************/
/* MC_CMD_FC
 * Perform an FC operation
 */
#define MC_CMD_FC 0x9

/* MC_CMD_FC_IN msgrequest */
#define    MC_CMD_FC_IN_LEN 4
#define       MC_CMD_FC_IN_OP_HDR_OFST 0
#define        MC_CMD_FC_IN_OP_LBN 0
#define        MC_CMD_FC_IN_OP_WIDTH 8
/* enum: NULL MCDI command to FC. */
#define          MC_CMD_FC_OP_NULL 0x1
/* enum: Unused opcode */
#define          MC_CMD_FC_OP_UNUSED 0x2
/* enum: MAC driver commands */
#define          MC_CMD_FC_OP_MAC 0x3
/* enum: Read FC memory */
#define          MC_CMD_FC_OP_READ32 0x4
/* enum: Write to FC memory */
#define          MC_CMD_FC_OP_WRITE32 0x5
/* enum: Read FC memory */
#define          MC_CMD_FC_OP_TRC_READ 0x6
/* enum: Write to FC memory */
#define          MC_CMD_FC_OP_TRC_WRITE 0x7
/* enum: FC firmware Version */
#define          MC_CMD_FC_OP_GET_VERSION 0x8
/* enum: Read FC memory */
#define          MC_CMD_FC_OP_TRC_RX_READ 0x9
/* enum: Write to FC memory */
#define          MC_CMD_FC_OP_TRC_RX_WRITE 0xa
/* enum: SFP parameters */
#define          MC_CMD_FC_OP_SFP 0xb
/* enum: DDR3 test */
#define          MC_CMD_FC_OP_DDR_TEST 0xc
/* enum: Get Crash context from FC */
#define          MC_CMD_FC_OP_GET_ASSERT 0xd
/* enum: Get FPGA Build registers */
#define          MC_CMD_FC_OP_FPGA_BUILD 0xe
/* enum: Read map support commands */
#define          MC_CMD_FC_OP_READ_MAP 0xf
/* enum: FC Capabilities */
#define          MC_CMD_FC_OP_CAPABILITIES 0x10
/* enum: FC Global flags */
#define          MC_CMD_FC_OP_GLOBAL_FLAGS 0x11
/* enum: FC IO using relative addressing modes */
#define          MC_CMD_FC_OP_IO_REL 0x12
/* enum: FPGA link information */
#define          MC_CMD_FC_OP_UHLINK 0x13
/* enum: Configure loopbacks and link on FPGA ports */
#define          MC_CMD_FC_OP_SET_LINK 0x14
/* enum: Licensing operations relating to AOE */
#define          MC_CMD_FC_OP_LICENSE 0x15
/* enum: Startup information to the FC */
#define          MC_CMD_FC_OP_STARTUP 0x16
/* enum: Configure a DMA read */
#define          MC_CMD_FC_OP_DMA 0x17
/* enum: Configure a timed read */
#define          MC_CMD_FC_OP_TIMED_READ 0x18
/* enum: Control UART logging */
#define          MC_CMD_FC_OP_LOG 0x19
/* enum: Get the value of a given clock_id */
#define          MC_CMD_FC_OP_CLOCK 0x1a
/* enum: DDR3/QDR3 parameters */
#define          MC_CMD_FC_OP_DDR 0x1b
/* enum: PTP and timestamp control */
#define          MC_CMD_FC_OP_TIMESTAMP 0x1c
/* enum: External AOE port. */
#define          MC_CMD_FC_IN_PORT_EXT_OFST 0x0
/* enum: Internal AOE port. */
#define          MC_CMD_FC_IN_PORT_INT_OFST 0x40

/* MC_CMD_FC_IN_NULL msgrequest */
#define    MC_CMD_FC_IN_NULL_LEN 4
#define       MC_CMD_FC_IN_CMD_OFST 0

/* MC_CMD_FC_IN_PHY msgrequest */
#define    MC_CMD_FC_IN_PHY_LEN 5
/*            MC_CMD_FC_IN_CMD_OFST 0 */
/* FC PHY driver operation code */
#define       MC_CMD_FC_IN_PHY_OP_OFST 4
#define       MC_CMD_FC_IN_PHY_OP_LEN 1
/* enum: PHY init handler */
#define          MC_CMD_FC_OP_PHY_OP_INIT 0x1
/* enum: PHY reconfigure handler */
#define          MC_CMD_FC_OP_PHY_OP_RECONFIGURE 0x2
/* enum: PHY reboot handler */
#define          MC_CMD_FC_OP_PHY_OP_REBOOT 0x3
/* enum: PHY get_supported_cap handler */
#define          MC_CMD_FC_OP_PHY_OP_GET_SUPPORTED_CAP 0x4
/* enum: PHY get_config handler */
#define          MC_CMD_FC_OP_PHY_OP_GET_CONFIG 0x5
/* enum: PHY get_media_info handler */
#define          MC_CMD_FC_OP_PHY_OP_GET_MEDIA_INFO 0x6
/* enum: PHY set_led handler */
#define          MC_CMD_FC_OP_PHY_OP_SET_LED 0x7
/* enum: PHY lasi_interrupt handler */
#define          MC_CMD_FC_OP_PHY_OP_LASI_INTERRUPT 0x8
/* enum: PHY check_link handler */
#define          MC_CMD_FC_OP_PHY_OP_CHECK_LINK 0x9
/* enum: PHY fill_stats handler */
#define          MC_CMD_FC_OP_PHY_OP_FILL_STATS 0xa
/* enum: PHY bpx_link_state_changed handler */
#define          MC_CMD_FC_OP_PHY_OP_BPX_LINK_STATE_CHANGED 0xb
/* enum: PHY get_state handler */
#define          MC_CMD_FC_OP_PHY_OP_GET_STATE 0xc
/* enum: PHY start_bist handler */
#define          MC_CMD_FC_OP_PHY_OP_START_BIST 0xd
/* enum: PHY poll_bist handler */
#define          MC_CMD_FC_OP_PHY_OP_POLL_BIST 0xe
/* enum: PHY nvram_test handler */
#define          MC_CMD_FC_OP_PHY_OP_NVRAM_TEST 0xf
/* enum: PHY relinquish handler */
#define          MC_CMD_FC_OP_PHY_OP_RELINQUISH_SPI 0x10
/* enum: PHY read connection from FC - may be not required */
#define          MC_CMD_FC_OP_PHY_OP_GET_CONNECTION 0x11
/* enum: PHY read flags from FC - may be not required */
#define          MC_CMD_FC_OP_PHY_OP_GET_FLAGS 0x12

/* MC_CMD_FC_IN_PHY_INIT msgrequest */
#define    MC_CMD_FC_IN_PHY_INIT_LEN 4
#define       MC_CMD_FC_IN_PHY_CMD_OFST 0

/* MC_CMD_FC_IN_MAC msgrequest */
#define    MC_CMD_FC_IN_MAC_LEN 8
/*            MC_CMD_FC_IN_CMD_OFST 0 */
#define       MC_CMD_FC_IN_MAC_HEADER_OFST 4
#define        MC_CMD_FC_IN_MAC_OP_LBN 0
#define        MC_CMD_FC_IN_MAC_OP_WIDTH 8
/* enum: MAC reconfigure handler */
#define          MC_CMD_FC_OP_MAC_OP_RECONFIGURE 0x1
/* enum: MAC Set command - same as MC_CMD_SET_MAC */
#define          MC_CMD_FC_OP_MAC_OP_SET_LINK 0x2
/* enum: MAC statistics */
#define          MC_CMD_FC_OP_MAC_OP_GET_STATS 0x3
/* enum: MAC RX statistics */
#define          MC_CMD_FC_OP_MAC_OP_GET_RX_STATS 0x6
/* enum: MAC TX statistics */
#define          MC_CMD_FC_OP_MAC_OP_GET_TX_STATS 0x7
/* enum: MAC Read status */
#define          MC_CMD_FC_OP_MAC_OP_READ_STATUS 0x8
#define        MC_CMD_FC_IN_MAC_PORT_TYPE_LBN 8
#define        MC_CMD_FC_IN_MAC_PORT_TYPE_WIDTH 8
/* enum: External FPGA port. */
#define          MC_CMD_FC_PORT_EXT 0x0
/* enum: Internal Siena-facing FPGA ports. */
#define          MC_CMD_FC_PORT_INT 0x1
#define        MC_CMD_FC_IN_MAC_PORT_IDX_LBN 16
#define        MC_CMD_FC_IN_MAC_PORT_IDX_WIDTH 8
#define        MC_CMD_FC_IN_MAC_CMD_FORMAT_LBN 24
#define        MC_CMD_FC_IN_MAC_CMD_FORMAT_WIDTH 8
/* enum: Default FC command format; the fields PORT_TYPE and PORT_IDX are
 * irrelevant. Port number is derived from pci_fn; passed in FC header.
 */
#define          MC_CMD_FC_OP_MAC_CMD_FORMAT_DEFAULT 0x0
/* enum: Override default port number. Port number determined by fields
 * PORT_TYPE and PORT_IDX.
 */
#define          MC_CMD_FC_OP_MAC_CMD_FORMAT_PORT_OVERRIDE 0x1

/* MC_CMD_FC_IN_MAC_RECONFIGURE msgrequest */
#define    MC_CMD_FC_IN_MAC_RECONFIGURE_LEN 8
/*            MC_CMD_FC_IN_CMD_OFST 0 */
/*            MC_CMD_FC_IN_MAC_HEADER_OFST 4 */

/* MC_CMD_FC_IN_MAC_SET_LINK msgrequest */
#define    MC_CMD_FC_IN_MAC_SET_LINK_LEN 32
/*            MC_CMD_FC_IN_CMD_OFST 0 */
/*            MC_CMD_FC_IN_MAC_HEADER_OFST 4 */
/* MTU size */
#define       MC_CMD_FC_IN_MAC_SET_LINK_MTU_OFST 8
/* Drain Tx FIFO */
#define       MC_CMD_FC_IN_MAC_SET_LINK_DRAIN_OFST 12
#define       MC_CMD_FC_IN_MAC_SET_LINK_ADDR_OFST 16
#define       MC_CMD_FC_IN_MAC_SET_LINK_ADDR_LEN 8
#define       MC_CMD_FC_IN_MAC_SET_LINK_ADDR_LO_OFST 16
#define       MC_CMD_FC_IN_MAC_SET_LINK_ADDR_HI_OFST 20
#define       MC_CMD_FC_IN_MAC_SET_LINK_REJECT_OFST 24
#define        MC_CMD_FC_IN_MAC_SET_LINK_REJECT_UNICAST_LBN 0
#define        MC_CMD_FC_IN_MAC_SET_LINK_REJECT_UNICAST_WIDTH 1
#define        MC_CMD_FC_IN_MAC_SET_LINK_REJECT_BRDCAST_LBN 1
#define        MC_CMD_FC_IN_MAC_SET_LINK_REJECT_BRDCAST_WIDTH 1
#define       MC_CMD_FC_IN_MAC_SET_LINK_FCNTL_OFST 28

/* MC_CMD_FC_IN_MAC_READ_STATUS msgrequest */
#define    MC_CMD_FC_IN_MAC_READ_STATUS_LEN 8
/*            MC_CMD_FC_IN_CMD_OFST 0 */
/*            MC_CMD_FC_IN_MAC_HEADER_OFST 4 */

/* MC_CMD_FC_IN_MAC_GET_RX_STATS msgrequest */
#define    MC_CMD_FC_IN_MAC_GET_RX_STATS_LEN 8
/*            MC_CMD_FC_IN_CMD_OFST 0 */
/*            MC_CMD_FC_IN_MAC_HEADER_OFST 4 */

/* MC_CMD_FC_IN_MAC_GET_TX_STATS msgrequest */
#define    MC_CMD_FC_IN_MAC_GET_TX_STATS_LEN 8
/*            MC_CMD_FC_IN_CMD_OFST 0 */
/*            MC_CMD_FC_IN_MAC_HEADER_OFST 4 */

/* MC_CMD_FC_IN_MAC_GET_STATS msgrequest */
#define    MC_CMD_FC_IN_MAC_GET_STATS_LEN 20
/*            MC_CMD_FC_IN_CMD_OFST 0 */
/*            MC_CMD_FC_IN_MAC_HEADER_OFST 4 */
/* MC Statistics index */
#define       MC_CMD_FC_IN_MAC_GET_STATS_STATS_INDEX_OFST 8
#define       MC_CMD_FC_IN_MAC_GET_STATS_FLAGS_OFST 12
#define        MC_CMD_FC_IN_MAC_GET_STATS_CLEAR_ALL_LBN 0
#define        MC_CMD_FC_IN_MAC_GET_STATS_CLEAR_ALL_WIDTH 1
#define        MC_CMD_FC_IN_MAC_GET_STATS_CLEAR_LBN 1
#define        MC_CMD_FC_IN_MAC_GET_STATS_CLEAR_WIDTH 1
#define        MC_CMD_FC_IN_MAC_GET_STATS_UPDATE_LBN 2
#define        MC_CMD_FC_IN_MAC_GET_STATS_UPDATE_WIDTH 1
/* Number of statistics to read */
#define       MC_CMD_FC_IN_MAC_GET_STATS_NUM_OFST 16
#define          MC_CMD_FC_MAC_NSTATS_PER_BLOCK 0x1e /* enum */
#define          MC_CMD_FC_MAC_NBYTES_PER_STAT 0x8 /* enum */

/* MC_CMD_FC_IN_READ32 msgrequest */
#define    MC_CMD_FC_IN_READ32_LEN 16
/*            MC_CMD_FC_IN_CMD_OFST 0 */
#define       MC_CMD_FC_IN_READ32_ADDR_HI_OFST 4
#define       MC_CMD_FC_IN_READ32_ADDR_LO_OFST 8
#define       MC_CMD_FC_IN_READ32_NUMWORDS_OFST 12

/* MC_CMD_FC_IN_WRITE32 msgrequest */
#define    MC_CMD_FC_IN_WRITE32_LENMIN 16
#define    MC_CMD_FC_IN_WRITE32_LENMAX 252
#define    MC_CMD_FC_IN_WRITE32_LEN(num) (12+4*(num))
/*            MC_CMD_FC_IN_CMD_OFST 0 */
#define       MC_CMD_FC_IN_WRITE32_ADDR_HI_OFST 4
#define       MC_CMD_FC_IN_WRITE32_ADDR_LO_OFST 8
#define       MC_CMD_FC_IN_WRITE32_BUFFER_OFST 12
#define       MC_CMD_FC_IN_WRITE32_BUFFER_LEN 4
#define       MC_CMD_FC_IN_WRITE32_BUFFER_MINNUM 1
#define       MC_CMD_FC_IN_WRITE32_BUFFER_MAXNUM 60

/* MC_CMD_FC_IN_TRC_READ msgrequest */
#define    MC_CMD_FC_IN_TRC_READ_LEN 12
/*            MC_CMD_FC_IN_CMD_OFST 0 */
#define       MC_CMD_FC_IN_TRC_READ_TRC_OFST 4
#define       MC_CMD_FC_IN_TRC_READ_CHANNEL_OFST 8

/* MC_CMD_FC_IN_TRC_WRITE msgrequest */
#define    MC_CMD_FC_IN_TRC_WRITE_LEN 28
/*            MC_CMD_FC_IN_CMD_OFST 0 */
#define       MC_CMD_FC_IN_TRC_WRITE_TRC_OFST 4
#define       MC_CMD_FC_IN_TRC_WRITE_CHANNEL_OFST 8
#define       MC_CMD_FC_IN_TRC_WRITE_DATA_OFST 12
#define       MC_CMD_FC_IN_TRC_WRITE_DATA_LEN 4
#define       MC_CMD_FC_IN_TRC_WRITE_DATA_NUM 4

/* MC_CMD_FC_IN_GET_VERSION msgrequest */
#define    MC_CMD_FC_IN_GET_VERSION_LEN 4
/*            MC_CMD_FC_IN_CMD_OFST 0 */

/* MC_CMD_FC_IN_TRC_RX_READ msgrequest */
#define    MC_CMD_FC_IN_TRC_RX_READ_LEN 12
/*            MC_CMD_FC_IN_CMD_OFST 0 */
#define       MC_CMD_FC_IN_TRC_RX_READ_TRC_OFST 4
#define       MC_CMD_FC_IN_TRC_RX_READ_CHANNEL_OFST 8

/* MC_CMD_FC_IN_TRC_RX_WRITE msgrequest */
#define    MC_CMD_FC_IN_TRC_RX_WRITE_LEN 20
/*            MC_CMD_FC_IN_CMD_OFST 0 */
#define       MC_CMD_FC_IN_TRC_RX_WRITE_TRC_OFST 4
#define       MC_CMD_FC_IN_TRC_RX_WRITE_CHANNEL_OFST 8
#define       MC_CMD_FC_IN_TRC_RX_WRITE_DATA_OFST 12
#define       MC_CMD_FC_IN_TRC_RX_WRITE_DATA_LEN 4
#define       MC_CMD_FC_IN_TRC_RX_WRITE_DATA_NUM 2

/* MC_CMD_FC_IN_SFP msgrequest */
#define    MC_CMD_FC_IN_SFP_LEN 24
/*            MC_CMD_FC_IN_CMD_OFST 0 */
/* Link speed is 100, 1000, 10000 */
#define       MC_CMD_FC_IN_SFP_SPEED_OFST 4
/* Length of copper cable - zero when not relevant */
#define       MC_CMD_FC_IN_SFP_COPPER_LEN_OFST 8
/* True if a dual speed SFP+ module */
#define       MC_CMD_FC_IN_SFP_DUAL_SPEED_OFST 12
/* True if an SFP Module is present (other fields valid when true) */
#define       MC_CMD_FC_IN_SFP_PRESENT_OFST 16
/* The type of the SFP+ Module */
#define       MC_CMD_FC_IN_SFP_TYPE_OFST 20

/* MC_CMD_FC_IN_DDR_TEST msgrequest */
#define    MC_CMD_FC_IN_DDR_TEST_LEN 8
/*            MC_CMD_FC_IN_CMD_OFST 0 */
#define       MC_CMD_FC_IN_DDR_TEST_HEADER_OFST 4
#define        MC_CMD_FC_IN_DDR_TEST_OP_LBN 0
#define        MC_CMD_FC_IN_DDR_TEST_OP_WIDTH 8
/* enum: DRAM Test Start */
#define          MC_CMD_FC_OP_DDR_TEST_START 0x1
/* enum: DRAM Test Poll */
#define          MC_CMD_FC_OP_DDR_TEST_POLL 0x2

/* MC_CMD_FC_IN_DDR_TEST_START msgrequest */
#define    MC_CMD_FC_IN_DDR_TEST_START_LEN 12
/*            MC_CMD_FC_IN_CMD_OFST 0 */
/*            MC_CMD_FC_IN_DDR_TEST_HEADER_OFST 4 */
#define       MC_CMD_FC_IN_DDR_TEST_START_MASK_OFST 8
#define        MC_CMD_FC_IN_DDR_TEST_START_T0_LBN 0
#define        MC_CMD_FC_IN_DDR_TEST_START_T0_WIDTH 1
#define        MC_CMD_FC_IN_DDR_TEST_START_T1_LBN 1
#define        MC_CMD_FC_IN_DDR_TEST_START_T1_WIDTH 1
#define        MC_CMD_FC_IN_DDR_TEST_START_B0_LBN 2
#define        MC_CMD_FC_IN_DDR_TEST_START_B0_WIDTH 1
#define        MC_CMD_FC_IN_DDR_TEST_START_B1_LBN 3
#define        MC_CMD_FC_IN_DDR_TEST_START_B1_WIDTH 1

/* MC_CMD_FC_IN_DDR_TEST_POLL msgrequest */
#define    MC_CMD_FC_IN_DDR_TEST_POLL_LEN 8
#define       MC_CMD_FC_IN_DDR_TEST_CMD_OFST 0
/*            MC_CMD_FC_IN_DDR_TEST_HEADER_OFST 4 */

/* MC_CMD_FC_IN_GET_ASSERT msgrequest */
#define    MC_CMD_FC_IN_GET_ASSERT_LEN 4
/*            MC_CMD_FC_IN_CMD_OFST 0 */

/* MC_CMD_FC_IN_FPGA_BUILD msgrequest */
#define    MC_CMD_FC_IN_FPGA_BUILD_LEN 8
/*            MC_CMD_FC_IN_CMD_OFST 0 */
/* FPGA build info operation code */
#define       MC_CMD_FC_IN_FPGA_BUILD_OP_OFST 4
/* enum: Get the build registers */
#define          MC_CMD_FC_IN_FPGA_BUILD_BUILD 0x1
/* enum: Get the services registers */
#define          MC_CMD_FC_IN_FPGA_BUILD_SERVICES 0x2
/* enum: Get the BSP version */
#define          MC_CMD_FC_IN_FPGA_BUILD_BSP_VERSION 0x3

/* MC_CMD_FC_IN_READ_MAP msgrequest */
#define    MC_CMD_FC_IN_READ_MAP_LEN 8
/*            MC_CMD_FC_IN_CMD_OFST 0 */
#define       MC_CMD_FC_IN_READ_MAP_HEADER_OFST 4
#define        MC_CMD_FC_IN_READ_MAP_OP_LBN 0
#define        MC_CMD_FC_IN_READ_MAP_OP_WIDTH 8
/* enum: Get the number of map regions */
#define          MC_CMD_FC_OP_READ_MAP_COUNT 0x1
/* enum: Get the specified map */
#define          MC_CMD_FC_OP_READ_MAP_INDEX 0x2

/* MC_CMD_FC_IN_READ_MAP_COUNT msgrequest */
#define    MC_CMD_FC_IN_READ_MAP_COUNT_LEN 8
/*            MC_CMD_FC_IN_CMD_OFST 0 */
/*            MC_CMD_FC_IN_READ_MAP_HEADER_OFST 4 */

/* MC_CMD_FC_IN_READ_MAP_INDEX msgrequest */
#define    MC_CMD_FC_IN_READ_MAP_INDEX_LEN 12
/*            MC_CMD_FC_IN_CMD_OFST 0 */
/*            MC_CMD_FC_IN_READ_MAP_HEADER_OFST 4 */
#define       MC_CMD_FC_IN_MAP_INDEX_OFST 8

/* MC_CMD_FC_IN_CAPABILITIES msgrequest */
#define    MC_CMD_FC_IN_CAPABILITIES_LEN 4
/*            MC_CMD_FC_IN_CMD_OFST 0 */

/* MC_CMD_FC_IN_GLOBAL_FLAGS msgrequest */
#define    MC_CMD_FC_IN_GLOBAL_FLAGS_LEN 8
/*            MC_CMD_FC_IN_CMD_OFST 0 */
#define       MC_CMD_FC_IN_GLOBAL_FLAGS_FLAGS_OFST 4
#define        MC_CMD_FC_IN_GLOBAL_FLAGS_RX_TUNING_CABLE_PLUGGED_IN_LBN 0
#define        MC_CMD_FC_IN_GLOBAL_FLAGS_RX_TUNING_CABLE_PLUGGED_IN_WIDTH 1
#define        MC_CMD_FC_IN_GLOBAL_FLAGS_RX_TUNING_LINK_MONITORING_LBN 1
#define        MC_CMD_FC_IN_GLOBAL_FLAGS_RX_TUNING_LINK_MONITORING_WIDTH 1
#define        MC_CMD_FC_IN_GLOBAL_FLAGS_DFE_ENABLE_LBN 2
#define        MC_CMD_FC_IN_GLOBAL_FLAGS_DFE_ENABLE_WIDTH 1
#define        MC_CMD_FC_IN_GLOBAL_FLAGS_1D_EYE_ENABLE_LBN 3
#define        MC_CMD_FC_IN_GLOBAL_FLAGS_1D_EYE_ENABLE_WIDTH 1
#define        MC_CMD_FC_IN_GLOBAL_FLAGS_1D_TUNING_ENABLE_LBN 4
#define        MC_CMD_FC_IN_GLOBAL_FLAGS_1D_TUNING_ENABLE_WIDTH 1
#define        MC_CMD_FC_IN_GLOBAL_FLAGS_OFFCAL_ENABLE_LBN 5
#define        MC_CMD_FC_IN_GLOBAL_FLAGS_OFFCAL_ENABLE_WIDTH 1

/* MC_CMD_FC_IN_IO_REL msgrequest */
#define    MC_CMD_FC_IN_IO_REL_LEN 8
/*            MC_CMD_FC_IN_CMD_OFST 0 */
#define       MC_CMD_FC_IN_IO_REL_HEADER_OFST 4
#define        MC_CMD_FC_IN_IO_REL_OP_LBN 0
#define        MC_CMD_FC_IN_IO_REL_OP_WIDTH 8
/* enum: Get the base address that the FC applies to relative commands */
#define          MC_CMD_FC_IN_IO_REL_GET_ADDR 0x1
/* enum: Read data */
#define          MC_CMD_FC_IN_IO_REL_READ32 0x2
/* enum: Write data */
#define          MC_CMD_FC_IN_IO_REL_WRITE32 0x3
#define        MC_CMD_FC_IN_IO_REL_COMP_TYPE_LBN 8
#define        MC_CMD_FC_IN_IO_REL_COMP_TYPE_WIDTH 8
/* enum: Application address space */
#define          MC_CMD_FC_COMP_TYPE_APP_ADDR_SPACE 0x1
/* enum: Flash address space */
#define          MC_CMD_FC_COMP_TYPE_FLASH 0x2

/* MC_CMD_FC_IN_IO_REL_GET_ADDR msgrequest */
#define    MC_CMD_FC_IN_IO_REL_GET_ADDR_LEN 8
/*            MC_CMD_FC_IN_CMD_OFST 0 */
/*            MC_CMD_FC_IN_IO_REL_HEADER_OFST 4 */

/* MC_CMD_FC_IN_IO_REL_READ32 msgrequest */
#define    MC_CMD_FC_IN_IO_REL_READ32_LEN 20
/*            MC_CMD_FC_IN_CMD_OFST 0 */
/*            MC_CMD_FC_IN_IO_REL_HEADER_OFST 4 */
#define       MC_CMD_FC_IN_IO_REL_READ32_ADDR_HI_OFST 8
#define       MC_CMD_FC_IN_IO_REL_READ32_ADDR_LO_OFST 12
#define       MC_CMD_FC_IN_IO_REL_READ32_NUMWORDS_OFST 16

/* MC_CMD_FC_IN_IO_REL_WRITE32 msgrequest */
#define    MC_CMD_FC_IN_IO_REL_WRITE32_LENMIN 20
#define    MC_CMD_FC_IN_IO_REL_WRITE32_LENMAX 252
#define    MC_CMD_FC_IN_IO_REL_WRITE32_LEN(num) (16+4*(num))
/*            MC_CMD_FC_IN_CMD_OFST 0 */
/*            MC_CMD_FC_IN_IO_REL_HEADER_OFST 4 */
#define       MC_CMD_FC_IN_IO_REL_WRITE32_ADDR_HI_OFST 8
#define       MC_CMD_FC_IN_IO_REL_WRITE32_ADDR_LO_OFST 12
#define       MC_CMD_FC_IN_IO_REL_WRITE32_BUFFER_OFST 16
#define       MC_CMD_FC_IN_IO_REL_WRITE32_BUFFER_LEN 4
#define       MC_CMD_FC_IN_IO_REL_WRITE32_BUFFER_MINNUM 1
#define       MC_CMD_FC_IN_IO_REL_WRITE32_BUFFER_MAXNUM 59

/* MC_CMD_FC_IN_UHLINK msgrequest */
#define    MC_CMD_FC_IN_UHLINK_LEN 8
/*            MC_CMD_FC_IN_CMD_OFST 0 */
#define       MC_CMD_FC_IN_UHLINK_HEADER_OFST 4
#define        MC_CMD_FC_IN_UHLINK_OP_LBN 0
#define        MC_CMD_FC_IN_UHLINK_OP_WIDTH 8
/* enum: Get PHY configuration info */
#define          MC_CMD_FC_OP_UHLINK_PHY 0x1
/* enum: Get MAC configuration info */
#define          MC_CMD_FC_OP_UHLINK_MAC 0x2
/* enum: Get Rx eye table */
#define          MC_CMD_FC_OP_UHLINK_RX_EYE 0x3
/* enum: Get Rx eye plot */
#define          MC_CMD_FC_OP_UHLINK_DUMP_RX_EYE_PLOT 0x4
/* enum: Get Rx eye plot */
#define          MC_CMD_FC_OP_UHLINK_READ_RX_EYE_PLOT 0x5
/* enum: Retune Rx settings */
#define          MC_CMD_FC_OP_UHLINK_RX_TUNE 0x6
#define        MC_CMD_FC_IN_UHLINK_PORT_TYPE_LBN 8
#define        MC_CMD_FC_IN_UHLINK_PORT_TYPE_WIDTH 8
#define        MC_CMD_FC_IN_UHLINK_PORT_IDX_LBN 16
#define        MC_CMD_FC_IN_UHLINK_PORT_IDX_WIDTH 8
#define        MC_CMD_FC_IN_UHLINK_CMD_FORMAT_LBN 24
#define        MC_CMD_FC_IN_UHLINK_CMD_FORMAT_WIDTH 8
/* enum: Default FC command format; the fields PORT_TYPE and PORT_IDX are
 * irrelevant. Port number is derived from pci_fn; passed in FC header.
 */
#define          MC_CMD_FC_OP_UHLINK_CMD_FORMAT_DEFAULT 0x0
/* enum: Override default port number. Port number determined by fields
 * PORT_TYPE and PORT_IDX.
 */
#define          MC_CMD_FC_OP_UHLINK_CMD_FORMAT_PORT_OVERRIDE 0x1

/* MC_CMD_FC_OP_UHLINK_PHY msgrequest */
#define    MC_CMD_FC_OP_UHLINK_PHY_LEN 8
/*            MC_CMD_FC_IN_CMD_OFST 0 */
/*            MC_CMD_FC_IN_UHLINK_HEADER_OFST 4 */

/* MC_CMD_FC_OP_UHLINK_MAC msgrequest */
#define    MC_CMD_FC_OP_UHLINK_MAC_LEN 8
/*            MC_CMD_FC_IN_CMD_OFST 0 */
/*            MC_CMD_FC_IN_UHLINK_HEADER_OFST 4 */

/* MC_CMD_FC_OP_UHLINK_RX_EYE msgrequest */
#define    MC_CMD_FC_OP_UHLINK_RX_EYE_LEN 12
/*            MC_CMD_FC_IN_CMD_OFST 0 */
/*            MC_CMD_FC_IN_UHLINK_HEADER_OFST 4 */
#define       MC_CMD_FC_OP_UHLINK_RX_EYE_INDEX_OFST 8
#define          MC_CMD_FC_UHLINK_RX_EYE_PER_BLOCK 0x30 /* enum */

/* MC_CMD_FC_OP_UHLINK_DUMP_RX_EYE_PLOT msgrequest */
#define    MC_CMD_FC_OP_UHLINK_DUMP_RX_EYE_PLOT_LEN 8
/*            MC_CMD_FC_IN_CMD_OFST 0 */
/*            MC_CMD_FC_IN_UHLINK_HEADER_OFST 4 */

/* MC_CMD_FC_OP_UHLINK_READ_RX_EYE_PLOT msgrequest */
#define    MC_CMD_FC_OP_UHLINK_READ_RX_EYE_PLOT_LEN 20
/*            MC_CMD_FC_IN_CMD_OFST 0 */
/*            MC_CMD_FC_IN_UHLINK_HEADER_OFST 4 */
#define       MC_CMD_FC_OP_UHLINK_READ_RX_EYE_PLOT_DC_GAIN_OFST 8
#define       MC_CMD_FC_OP_UHLINK_READ_RX_EYE_PLOT_EQ_CONTROL_OFST 12
#define       MC_CMD_FC_OP_UHLINK_READ_RX_EYE_PLOT_INDEX_OFST 16
#define          MC_CMD_FC_UHLINK_RX_EYE_PLOT_ROWS_PER_BLOCK 0x1e /* enum */

/* MC_CMD_FC_OP_UHLINK_RX_TUNE msgrequest */
#define    MC_CMD_FC_OP_UHLINK_RX_TUNE_LEN 8
/*            MC_CMD_FC_IN_CMD_OFST 0 */
/*            MC_CMD_FC_IN_UHLINK_HEADER_OFST 4 */

/* MC_CMD_FC_IN_SET_LINK msgrequest */
#define    MC_CMD_FC_IN_SET_LINK_LEN 16
/*            MC_CMD_FC_IN_CMD_OFST 0 */
/* See MC_CMD_GET_LOOPBACK_MODES/MC_CMD_GET_LOOPBACK_MODES_OUT/100M */
#define       MC_CMD_FC_IN_SET_LINK_MODE_OFST 4
#define       MC_CMD_FC_IN_SET_LINK_SPEED_OFST 8
#define       MC_CMD_FC_IN_SET_LINK_FLAGS_OFST 12
#define        MC_CMD_FC_IN_SET_LINK_LOWPOWER_LBN 0
#define        MC_CMD_FC_IN_SET_LINK_LOWPOWER_WIDTH 1
#define        MC_CMD_FC_IN_SET_LINK_POWEROFF_LBN 1
#define        MC_CMD_FC_IN_SET_LINK_POWEROFF_WIDTH 1
#define        MC_CMD_FC_IN_SET_LINK_TXDIS_LBN 2
#define        MC_CMD_FC_IN_SET_LINK_TXDIS_WIDTH 1

/* MC_CMD_FC_IN_LICENSE msgrequest */
#define    MC_CMD_FC_IN_LICENSE_LEN 8
/*            MC_CMD_FC_IN_CMD_OFST 0 */
#define       MC_CMD_FC_IN_LICENSE_OP_OFST 4
#define          MC_CMD_FC_IN_LICENSE_UPDATE_LICENSE 0x0 /* enum */
#define          MC_CMD_FC_IN_LICENSE_GET_KEY_STATS 0x1 /* enum */

/* MC_CMD_FC_IN_STARTUP msgrequest */
#define    MC_CMD_FC_IN_STARTUP_LEN 40
/*            MC_CMD_FC_IN_CMD_OFST 0 */
#define       MC_CMD_FC_IN_STARTUP_BASE_OFST 4
#define       MC_CMD_FC_IN_STARTUP_LENGTH_OFST 8
/* Length of identifier */
#define       MC_CMD_FC_IN_STARTUP_IDLENGTH_OFST 12
/* Identifier for AOE FPGA */
#define       MC_CMD_FC_IN_STARTUP_ID_OFST 16
#define       MC_CMD_FC_IN_STARTUP_ID_LEN 1
#define       MC_CMD_FC_IN_STARTUP_ID_NUM 24

/* MC_CMD_FC_IN_DMA msgrequest */
#define    MC_CMD_FC_IN_DMA_LEN 8
/*            MC_CMD_FC_IN_CMD_OFST 0 */
#define       MC_CMD_FC_IN_DMA_OP_OFST 4
#define          MC_CMD_FC_IN_DMA_STOP  0x0 /* enum */
#define          MC_CMD_FC_IN_DMA_READ  0x1 /* enum */

/* MC_CMD_FC_IN_DMA_STOP msgrequest */
#define    MC_CMD_FC_IN_DMA_STOP_LEN 12
/*            MC_CMD_FC_IN_CMD_OFST 0 */
/*            MC_CMD_FC_IN_DMA_OP_OFST 4 */
/* FC supplied handle */
#define       MC_CMD_FC_IN_DMA_STOP_FC_HANDLE_OFST 8

/* MC_CMD_FC_IN_DMA_READ msgrequest */
#define    MC_CMD_FC_IN_DMA_READ_LEN 16
/*            MC_CMD_FC_IN_CMD_OFST 0 */
/*            MC_CMD_FC_IN_DMA_OP_OFST 4 */
#define       MC_CMD_FC_IN_DMA_READ_OFFSET_OFST 8
#define       MC_CMD_FC_IN_DMA_READ_LENGTH_OFST 12

/* MC_CMD_FC_IN_TIMED_READ msgrequest */
#define    MC_CMD_FC_IN_TIMED_READ_LEN 8
/*            MC_CMD_FC_IN_CMD_OFST 0 */
#define       MC_CMD_FC_IN_TIMED_READ_OP_OFST 4
#define          MC_CMD_FC_IN_TIMED_READ_SET  0x0 /* enum */
#define          MC_CMD_FC_IN_TIMED_READ_GET  0x1 /* enum */
#define          MC_CMD_FC_IN_TIMED_READ_CLEAR  0x2 /* enum */

/* MC_CMD_FC_IN_TIMED_READ_SET msgrequest */
#define    MC_CMD_FC_IN_TIMED_READ_SET_LEN 52
/*            MC_CMD_FC_IN_CMD_OFST 0 */
/*            MC_CMD_FC_IN_TIMED_READ_OP_OFST 4 */
/* Host supplied handle (unique) */
#define       MC_CMD_FC_IN_TIMED_READ_SET_HOST_HANDLE_OFST 8
/* Address into which to transfer data in host */
#define       MC_CMD_FC_IN_TIMED_READ_SET_HOST_DMA_ADDRESS_OFST 12
#define       MC_CMD_FC_IN_TIMED_READ_SET_HOST_DMA_ADDRESS_LEN 8
#define       MC_CMD_FC_IN_TIMED_READ_SET_HOST_DMA_ADDRESS_LO_OFST 12
#define       MC_CMD_FC_IN_TIMED_READ_SET_HOST_DMA_ADDRESS_HI_OFST 16
/* AOE address from which to transfer data */
#define       MC_CMD_FC_IN_TIMED_READ_SET_AOE_ADDRESS_OFST 20
#define       MC_CMD_FC_IN_TIMED_READ_SET_AOE_ADDRESS_LEN 8
#define       MC_CMD_FC_IN_TIMED_READ_SET_AOE_ADDRESS_LO_OFST 20
#define       MC_CMD_FC_IN_TIMED_READ_SET_AOE_ADDRESS_HI_OFST 24
/* Length of AOE transfer (total) */
#define       MC_CMD_FC_IN_TIMED_READ_SET_AOE_LENGTH_OFST 28
/* Length of host transfer (total) */
#define       MC_CMD_FC_IN_TIMED_READ_SET_HOST_LENGTH_OFST 32
/* Offset back from aoe_address to apply operation to */
#define       MC_CMD_FC_IN_TIMED_READ_SET_OFFSET_OFST 36
/* Data to apply at offset */
#define       MC_CMD_FC_IN_TIMED_READ_SET_DATA_OFST 40
#define       MC_CMD_FC_IN_TIMED_READ_SET_FLAGS_OFST 44
#define        MC_CMD_FC_IN_TIMED_READ_SET_INDIRECT_LBN 0
#define        MC_CMD_FC_IN_TIMED_READ_SET_INDIRECT_WIDTH 1
#define        MC_CMD_FC_IN_TIMED_READ_SET_DOUBLE_LBN 1
#define        MC_CMD_FC_IN_TIMED_READ_SET_DOUBLE_WIDTH 1
#define        MC_CMD_FC_IN_TIMED_READ_SET_EVENT_LBN 2
#define        MC_CMD_FC_IN_TIMED_READ_SET_EVENT_WIDTH 1
#define        MC_CMD_FC_IN_TIMED_READ_SET_PREREAD_LBN 3
#define        MC_CMD_FC_IN_TIMED_READ_SET_PREREAD_WIDTH 2
#define          MC_CMD_FC_IN_TIMED_READ_SET_NONE  0x0 /* enum */
#define          MC_CMD_FC_IN_TIMED_READ_SET_READ  0x1 /* enum */
#define          MC_CMD_FC_IN_TIMED_READ_SET_WRITE  0x2 /* enum */
#define          MC_CMD_FC_IN_TIMED_READ_SET_READWRITE  0x3 /* enum */
/* Period at which reads are performed (100ms units) */
#define       MC_CMD_FC_IN_TIMED_READ_SET_PERIOD_OFST 48

/* MC_CMD_FC_IN_TIMED_READ_GET msgrequest */
#define    MC_CMD_FC_IN_TIMED_READ_GET_LEN 12
/*            MC_CMD_FC_IN_CMD_OFST 0 */
/*            MC_CMD_FC_IN_TIMED_READ_OP_OFST 4 */
/* FC supplied handle */
#define       MC_CMD_FC_IN_TIMED_READ_GET_FC_HANDLE_OFST 8

/* MC_CMD_FC_IN_TIMED_READ_CLEAR msgrequest */
#define    MC_CMD_FC_IN_TIMED_READ_CLEAR_LEN 12
/*            MC_CMD_FC_IN_CMD_OFST 0 */
/*            MC_CMD_FC_IN_TIMED_READ_OP_OFST 4 */
/* FC supplied handle */
#define       MC_CMD_FC_IN_TIMED_READ_CLEAR_FC_HANDLE_OFST 8

/* MC_CMD_FC_IN_LOG msgrequest */
#define    MC_CMD_FC_IN_LOG_LEN 8
/*            MC_CMD_FC_IN_CMD_OFST 0 */
#define       MC_CMD_FC_IN_LOG_OP_OFST 4
#define          MC_CMD_FC_IN_LOG_ADDR_RANGE  0x0 /* enum */
#define          MC_CMD_FC_IN_LOG_JTAG_UART  0x1 /* enum */

/* MC_CMD_FC_IN_LOG_ADDR_RANGE msgrequest */
#define    MC_CMD_FC_IN_LOG_ADDR_RANGE_LEN 20
/*            MC_CMD_FC_IN_CMD_OFST 0 */
/*            MC_CMD_FC_IN_LOG_OP_OFST 4 */
/* Partition offset into flash */
#define       MC_CMD_FC_IN_LOG_ADDR_RANGE_OFFSET_OFST 8
/* Partition length */
#define       MC_CMD_FC_IN_LOG_ADDR_RANGE_LENGTH_OFST 12
/* Partition erase size */
#define       MC_CMD_FC_IN_LOG_ADDR_RANGE_ERASE_SIZE_OFST 16

/* MC_CMD_FC_IN_LOG_JTAG_UART msgrequest */
#define    MC_CMD_FC_IN_LOG_JTAG_UART_LEN 12
/*            MC_CMD_FC_IN_CMD_OFST 0 */
/*            MC_CMD_FC_IN_LOG_OP_OFST 4 */
/* Enable/disable printing to JTAG UART */
#define       MC_CMD_FC_IN_LOG_JTAG_UART_ENABLE_OFST 8

/* MC_CMD_FC_IN_CLOCK msgrequest */
#define    MC_CMD_FC_IN_CLOCK_LEN 12
/*            MC_CMD_FC_IN_CMD_OFST 0 */
#define       MC_CMD_FC_IN_CLOCK_OP_OFST 4
#define          MC_CMD_FC_IN_CLOCK_GET_TIME  0x0 /* enum */
#define          MC_CMD_FC_IN_CLOCK_SET_TIME  0x1 /* enum */
/* Perform a clock operation */
#define       MC_CMD_FC_IN_CLOCK_ID_OFST 8
#define          MC_CMD_FC_IN_CLOCK_STATS  0x0 /* enum */
#define          MC_CMD_FC_IN_CLOCK_MAC  0x1 /* enum */

/* MC_CMD_FC_IN_CLOCK_GET_TIME msgrequest */
#define    MC_CMD_FC_IN_CLOCK_GET_TIME_LEN 12
/*            MC_CMD_FC_IN_CMD_OFST 0 */
/*            MC_CMD_FC_IN_CLOCK_OP_OFST 4 */
/* Retrieve the clock value of the specified clock */
/*            MC_CMD_FC_IN_CLOCK_ID_OFST 8 */

/* MC_CMD_FC_IN_CLOCK_SET_TIME msgrequest */
#define    MC_CMD_FC_IN_CLOCK_SET_TIME_LEN 24
/*            MC_CMD_FC_IN_CMD_OFST 0 */
/*            MC_CMD_FC_IN_CLOCK_OP_OFST 4 */
/*            MC_CMD_FC_IN_CLOCK_ID_OFST 8 */
#define       MC_CMD_FC_IN_CLOCK_SET_TIME_SECONDS_OFST 12
#define       MC_CMD_FC_IN_CLOCK_SET_TIME_SECONDS_LEN 8
#define       MC_CMD_FC_IN_CLOCK_SET_TIME_SECONDS_LO_OFST 12
#define       MC_CMD_FC_IN_CLOCK_SET_TIME_SECONDS_HI_OFST 16
/* Set the clock value of the specified clock */
#define       MC_CMD_FC_IN_CLOCK_SET_TIME_NANOSECONDS_OFST 20

/* MC_CMD_FC_IN_DDR msgrequest */
#define    MC_CMD_FC_IN_DDR_LEN 12
/*            MC_CMD_FC_IN_CMD_OFST 0 */
#define       MC_CMD_FC_IN_DDR_OP_OFST 4
#define          MC_CMD_FC_IN_DDR_SET_SPD  0x0 /* enum */
#define          MC_CMD_FC_IN_DDR_GET_STATUS  0x1 /* enum */
#define       MC_CMD_FC_IN_DDR_BANK_OFST 8
#define          MC_CMD_FC_IN_DDR_BANK_B0  0x0 /* enum */
#define          MC_CMD_FC_IN_DDR_BANK_B1  0x1 /* enum */
#define          MC_CMD_FC_IN_DDR_BANK_T0  0x2 /* enum */
#define          MC_CMD_FC_IN_DDR_BANK_T1  0x3 /* enum */
#define          MC_CMD_FC_IN_DDR_NUM_BANKS  0x4 /* enum */

/* MC_CMD_FC_IN_DDR_SET_SPD msgrequest */
#define    MC_CMD_FC_IN_DDR_SET_SPD_LEN 148
/*            MC_CMD_FC_IN_CMD_OFST 0 */
/*            MC_CMD_FC_IN_DDR_OP_OFST 4 */
/* Affected bank */
/*            MC_CMD_FC_IN_DDR_BANK_OFST 8 */
/* Flags */
#define       MC_CMD_FC_IN_DDR_FLAGS_OFST 12
#define          MC_CMD_FC_IN_DDR_SET_SPD_ACTIVE  0x1 /* enum */
/* 128-byte page of serial presence detect data read from module's EEPROM */
#define       MC_CMD_FC_IN_DDR_SPD_OFST 16
#define       MC_CMD_FC_IN_DDR_SPD_LEN 1
#define       MC_CMD_FC_IN_DDR_SPD_NUM 128
/* Page index of the spd data copied into MC_CMD_FC_IN_DDR_SPD */
#define       MC_CMD_FC_IN_DDR_SPD_PAGE_ID_OFST 144

/* MC_CMD_FC_IN_DDR_GET_STATUS msgrequest */
#define    MC_CMD_FC_IN_DDR_GET_STATUS_LEN 12
/*            MC_CMD_FC_IN_CMD_OFST 0 */
/*            MC_CMD_FC_IN_DDR_OP_OFST 4 */
/* Affected bank */
/*            MC_CMD_FC_IN_DDR_BANK_OFST 8 */

/* MC_CMD_FC_IN_TIMESTAMP msgrequest */
#define    MC_CMD_FC_IN_TIMESTAMP_LEN 8
/*            MC_CMD_FC_IN_CMD_OFST 0 */
/* FC timestamp operation code */
#define       MC_CMD_FC_IN_TIMESTAMP_OP_OFST 4
/* enum: Read transmit timestamp(s) */
#define          MC_CMD_FC_IN_TIMESTAMP_READ_TRANSMIT 0x0
/* enum: Read snapshot timestamps */
#define          MC_CMD_FC_IN_TIMESTAMP_READ_SNAPSHOT 0x1
/* enum: Clear all transmit timestamps */
#define          MC_CMD_FC_IN_TIMESTAMP_CLEAR_TRANSMIT 0x2

/* MC_CMD_FC_IN_TIMESTAMP_READ_TRANSMIT msgrequest */
#define    MC_CMD_FC_IN_TIMESTAMP_READ_TRANSMIT_LEN 28
/*            MC_CMD_FC_IN_CMD_OFST 0 */
#define       MC_CMD_FC_IN_TIMESTAMP_READ_TRANSMIT_OP_OFST 4
/* Control filtering of the returned timestamp and sequence number specified
 * here
 */
#define       MC_CMD_FC_IN_TIMESTAMP_READ_TRANSMIT_FILTER_OFST 8
/* enum: Return most recent timestamp. No filtering */
#define          MC_CMD_FC_IN_TIMESTAMP_READ_TRANSMIT_LATEST 0x0
/* enum: Match timestamp against the PTP clock ID, port number and sequence
 * number specified
 */
#define          MC_CMD_FC_IN_TIMESTAMP_READ_TRANSMIT_MATCH 0x1
/* Clock identity of PTP packet for which timestamp required */
#define       MC_CMD_FC_IN_TIMESTAMP_READ_TRANSMIT_CLOCK_ID_OFST 12
#define       MC_CMD_FC_IN_TIMESTAMP_READ_TRANSMIT_CLOCK_ID_LEN 8
#define       MC_CMD_FC_IN_TIMESTAMP_READ_TRANSMIT_CLOCK_ID_LO_OFST 12
#define       MC_CMD_FC_IN_TIMESTAMP_READ_TRANSMIT_CLOCK_ID_HI_OFST 16
/* Port number of PTP packet for which timestamp required */
#define       MC_CMD_FC_IN_TIMESTAMP_READ_TRANSMIT_PORT_NUM_OFST 20
/* Sequence number of PTP packet for which timestamp required */
#define       MC_CMD_FC_IN_TIMESTAMP_READ_TRANSMIT_SEQ_NUM_OFST 24

/* MC_CMD_FC_IN_TIMESTAMP_READ_SNAPSHOT msgrequest */
#define    MC_CMD_FC_IN_TIMESTAMP_READ_SNAPSHOT_LEN 8
/*            MC_CMD_FC_IN_CMD_OFST 0 */
#define       MC_CMD_FC_IN_TIMESTAMP_READ_SNAPSHOT_OP_OFST 4

/* MC_CMD_FC_IN_TIMESTAMP_CLEAR_TRANSMIT msgrequest */
#define    MC_CMD_FC_IN_TIMESTAMP_CLEAR_TRANSMIT_LEN 8
/*            MC_CMD_FC_IN_CMD_OFST 0 */
#define       MC_CMD_FC_IN_TIMESTAMP_CLEAR_TRANSMIT_OP_OFST 4

/* MC_CMD_FC_OUT msgresponse */
#define    MC_CMD_FC_OUT_LEN 0

/* MC_CMD_FC_OUT_NULL msgresponse */
#define    MC_CMD_FC_OUT_NULL_LEN 0

/* MC_CMD_FC_OUT_READ32 msgresponse */
#define    MC_CMD_FC_OUT_READ32_LENMIN 4
#define    MC_CMD_FC_OUT_READ32_LENMAX 252
#define    MC_CMD_FC_OUT_READ32_LEN(num) (0+4*(num))
#define       MC_CMD_FC_OUT_READ32_BUFFER_OFST 0
#define       MC_CMD_FC_OUT_READ32_BUFFER_LEN 4
#define       MC_CMD_FC_OUT_READ32_BUFFER_MINNUM 1
#define       MC_CMD_FC_OUT_READ32_BUFFER_MAXNUM 63

/* MC_CMD_FC_OUT_WRITE32 msgresponse */
#define    MC_CMD_FC_OUT_WRITE32_LEN 0

/* MC_CMD_FC_OUT_TRC_READ msgresponse */
#define    MC_CMD_FC_OUT_TRC_READ_LEN 16
#define       MC_CMD_FC_OUT_TRC_READ_DATA_OFST 0
#define       MC_CMD_FC_OUT_TRC_READ_DATA_LEN 4
#define       MC_CMD_FC_OUT_TRC_READ_DATA_NUM 4

/* MC_CMD_FC_OUT_TRC_WRITE msgresponse */
#define    MC_CMD_FC_OUT_TRC_WRITE_LEN 0

/* MC_CMD_FC_OUT_GET_VERSION msgresponse */
#define    MC_CMD_FC_OUT_GET_VERSION_LEN 12
#define       MC_CMD_FC_OUT_GET_VERSION_FIRMWARE_OFST 0
#define       MC_CMD_FC_OUT_GET_VERSION_VERSION_OFST 4
#define       MC_CMD_FC_OUT_GET_VERSION_VERSION_LEN 8
#define       MC_CMD_FC_OUT_GET_VERSION_VERSION_LO_OFST 4
#define       MC_CMD_FC_OUT_GET_VERSION_VERSION_HI_OFST 8

/* MC_CMD_FC_OUT_TRC_RX_READ msgresponse */
#define    MC_CMD_FC_OUT_TRC_RX_READ_LEN 8
#define       MC_CMD_FC_OUT_TRC_RX_READ_DATA_OFST 0
#define       MC_CMD_FC_OUT_TRC_RX_READ_DATA_LEN 4
#define       MC_CMD_FC_OUT_TRC_RX_READ_DATA_NUM 2

/* MC_CMD_FC_OUT_TRC_RX_WRITE msgresponse */
#define    MC_CMD_FC_OUT_TRC_RX_WRITE_LEN 0

/* MC_CMD_FC_OUT_MAC_RECONFIGURE msgresponse */
#define    MC_CMD_FC_OUT_MAC_RECONFIGURE_LEN 0

/* MC_CMD_FC_OUT_MAC_SET_LINK msgresponse */
#define    MC_CMD_FC_OUT_MAC_SET_LINK_LEN 0

/* MC_CMD_FC_OUT_MAC_READ_STATUS msgresponse */
#define    MC_CMD_FC_OUT_MAC_READ_STATUS_LEN 4
#define       MC_CMD_FC_OUT_MAC_READ_STATUS_STATUS_OFST 0

/* MC_CMD_FC_OUT_MAC_GET_RX_STATS msgresponse */
#define    MC_CMD_FC_OUT_MAC_GET_RX_STATS_LEN ((((0-1+(64*MC_CMD_FC_MAC_RX_NSTATS))+1))>>3)
#define       MC_CMD_FC_OUT_MAC_GET_RX_STATS_STATISTICS_OFST 0
#define       MC_CMD_FC_OUT_MAC_GET_RX_STATS_STATISTICS_LEN 8
#define       MC_CMD_FC_OUT_MAC_GET_RX_STATS_STATISTICS_LO_OFST 0
#define       MC_CMD_FC_OUT_MAC_GET_RX_STATS_STATISTICS_HI_OFST 4
#define       MC_CMD_FC_OUT_MAC_GET_RX_STATS_STATISTICS_NUM MC_CMD_FC_MAC_RX_NSTATS
#define          MC_CMD_FC_MAC_RX_STATS_OCTETS  0x0 /* enum */
#define          MC_CMD_FC_MAC_RX_OCTETS_OK  0x1 /* enum */
#define          MC_CMD_FC_MAC_RX_ALIGNMENT_ERRORS  0x2 /* enum */
#define          MC_CMD_FC_MAC_RX_PAUSE_MAC_CTRL_FRAMES  0x3 /* enum */
#define          MC_CMD_FC_MAC_RX_FRAMES_OK  0x4 /* enum */
#define          MC_CMD_FC_MAC_RX_CRC_ERRORS  0x5 /* enum */
#define          MC_CMD_FC_MAC_RX_VLAN_OK  0x6 /* enum */
#define          MC_CMD_FC_MAC_RX_ERRORS  0x7 /* enum */
#define          MC_CMD_FC_MAC_RX_UCAST_PKTS  0x8 /* enum */
#define          MC_CMD_FC_MAC_RX_MULTICAST_PKTS  0x9 /* enum */
#define          MC_CMD_FC_MAC_RX_BROADCAST_PKTS  0xa /* enum */
#define          MC_CMD_FC_MAC_RX_STATS_DROP_EVENTS  0xb /* enum */
#define          MC_CMD_FC_MAC_RX_STATS_PKTS  0xc /* enum */
#define          MC_CMD_FC_MAC_RX_STATS_UNDERSIZE_PKTS  0xd /* enum */
#define          MC_CMD_FC_MAC_RX_STATS_PKTS_64  0xe /* enum */
#define          MC_CMD_FC_MAC_RX_STATS_PKTS_65_127  0xf /* enum */
#define          MC_CMD_FC_MAC_RX_STATS_PKTS_128_255  0x10 /* enum */
#define          MC_CMD_FC_MAC_RX_STATS_PKTS_256_511  0x11 /* enum */
#define          MC_CMD_FC_MAC_RX_STATS_PKTS_512_1023  0x12 /* enum */
#define          MC_CMD_FC_MAC_RX_STATS_PKTS_1024_1518  0x13 /* enum */
#define          MC_CMD_FC_MAC_RX_STATS_PKTS_1519_MAX  0x14 /* enum */
#define          MC_CMD_FC_MAC_RX_STATS_OVERSIZE_PKTS  0x15 /* enum */
#define          MC_CMD_FC_MAC_RX_STATS_JABBERS  0x16 /* enum */
#define          MC_CMD_FC_MAC_RX_STATS_FRAGMENTS  0x17 /* enum */
#define          MC_CMD_FC_MAC_RX_MAC_CONTROL_FRAMES  0x18 /* enum */
/* enum: (Last entry) */
#define          MC_CMD_FC_MAC_RX_NSTATS  0x19

/* MC_CMD_FC_OUT_MAC_GET_TX_STATS msgresponse */
#define    MC_CMD_FC_OUT_MAC_GET_TX_STATS_LEN ((((0-1+(64*MC_CMD_FC_MAC_TX_NSTATS))+1))>>3)
#define       MC_CMD_FC_OUT_MAC_GET_TX_STATS_STATISTICS_OFST 0
#define       MC_CMD_FC_OUT_MAC_GET_TX_STATS_STATISTICS_LEN 8
#define       MC_CMD_FC_OUT_MAC_GET_TX_STATS_STATISTICS_LO_OFST 0
#define       MC_CMD_FC_OUT_MAC_GET_TX_STATS_STATISTICS_HI_OFST 4
#define       MC_CMD_FC_OUT_MAC_GET_TX_STATS_STATISTICS_NUM MC_CMD_FC_MAC_TX_NSTATS
#define          MC_CMD_FC_MAC_TX_STATS_OCTETS  0x0 /* enum */
#define          MC_CMD_FC_MAC_TX_OCTETS_OK  0x1 /* enum */
#define          MC_CMD_FC_MAC_TX_ALIGNMENT_ERRORS  0x2 /* enum */
#define          MC_CMD_FC_MAC_TX_PAUSE_MAC_CTRL_FRAMES  0x3 /* enum */
#define          MC_CMD_FC_MAC_TX_FRAMES_OK  0x4 /* enum */
#define          MC_CMD_FC_MAC_TX_CRC_ERRORS  0x5 /* enum */
#define          MC_CMD_FC_MAC_TX_VLAN_OK  0x6 /* enum */
#define          MC_CMD_FC_MAC_TX_ERRORS  0x7 /* enum */
#define          MC_CMD_FC_MAC_TX_UCAST_PKTS  0x8 /* enum */
#define          MC_CMD_FC_MAC_TX_MULTICAST_PKTS  0x9 /* enum */
#define          MC_CMD_FC_MAC_TX_BROADCAST_PKTS  0xa /* enum */
#define          MC_CMD_FC_MAC_TX_STATS_DROP_EVENTS  0xb /* enum */
#define          MC_CMD_FC_MAC_TX_STATS_PKTS  0xc /* enum */
#define          MC_CMD_FC_MAC_TX_STATS_UNDERSIZE_PKTS  0xd /* enum */
#define          MC_CMD_FC_MAC_TX_STATS_PKTS_64  0xe /* enum */
#define          MC_CMD_FC_MAC_TX_STATS_PKTS_65_127  0xf /* enum */
#define          MC_CMD_FC_MAC_TX_STATS_PKTS_128_255  0x10 /* enum */
#define          MC_CMD_FC_MAC_TX_STATS_PKTS_256_511  0x11 /* enum */
#define          MC_CMD_FC_MAC_TX_STATS_PKTS_512_1023  0x12 /* enum */
#define          MC_CMD_FC_MAC_TX_STATS_PKTS_1024_1518  0x13 /* enum */
#define          MC_CMD_FC_MAC_TX_STATS_PKTS_1519_TX_MTU  0x14 /* enum */
#define          MC_CMD_FC_MAC_TX_MAC_CONTROL_FRAMES  0x15 /* enum */
/* enum: (Last entry) */
#define          MC_CMD_FC_MAC_TX_NSTATS  0x16

/* MC_CMD_FC_OUT_MAC_GET_STATS msgresponse */
#define    MC_CMD_FC_OUT_MAC_GET_STATS_LEN ((((0-1+(64*MC_CMD_FC_MAC_NSTATS_PER_BLOCK))+1))>>3)
/* MAC Statistics */
#define       MC_CMD_FC_OUT_MAC_GET_STATS_STATISTICS_OFST 0
#define       MC_CMD_FC_OUT_MAC_GET_STATS_STATISTICS_LEN 8
#define       MC_CMD_FC_OUT_MAC_GET_STATS_STATISTICS_LO_OFST 0
#define       MC_CMD_FC_OUT_MAC_GET_STATS_STATISTICS_HI_OFST 4
#define       MC_CMD_FC_OUT_MAC_GET_STATS_STATISTICS_NUM MC_CMD_FC_MAC_NSTATS_PER_BLOCK

/* MC_CMD_FC_OUT_MAC msgresponse */
#define    MC_CMD_FC_OUT_MAC_LEN 0

/* MC_CMD_FC_OUT_SFP msgresponse */
#define    MC_CMD_FC_OUT_SFP_LEN 0

/* MC_CMD_FC_OUT_DDR_TEST_START msgresponse */
#define    MC_CMD_FC_OUT_DDR_TEST_START_LEN 0

/* MC_CMD_FC_OUT_DDR_TEST_POLL msgresponse */
#define    MC_CMD_FC_OUT_DDR_TEST_POLL_LEN 8
#define       MC_CMD_FC_OUT_DDR_TEST_POLL_STATUS_OFST 0
#define        MC_CMD_FC_OUT_DDR_TEST_POLL_CODE_LBN 0
#define        MC_CMD_FC_OUT_DDR_TEST_POLL_CODE_WIDTH 8
/* enum: Test not yet initiated */
#define          MC_CMD_FC_OP_DDR_TEST_NONE 0x0
/* enum: Test is in progress */
#define          MC_CMD_FC_OP_DDR_TEST_INPROGRESS 0x1
/* enum: Timed completed */
#define          MC_CMD_FC_OP_DDR_TEST_SUCCESS 0x2
/* enum: Test did not complete in specified time */
#define          MC_CMD_FC_OP_DDR_TEST_TIMER_EXPIRED 0x3
#define        MC_CMD_FC_OUT_DDR_TEST_POLL_PRESENT_T0_LBN 11
#define        MC_CMD_FC_OUT_DDR_TEST_POLL_PRESENT_T0_WIDTH 1
#define        MC_CMD_FC_OUT_DDR_TEST_POLL_PRESENT_T1_LBN 10
#define        MC_CMD_FC_OUT_DDR_TEST_POLL_PRESENT_T1_WIDTH 1
#define        MC_CMD_FC_OUT_DDR_TEST_POLL_PRESENT_B0_LBN 9
#define        MC_CMD_FC_OUT_DDR_TEST_POLL_PRESENT_B0_WIDTH 1
#define        MC_CMD_FC_OUT_DDR_TEST_POLL_PRESENT_B1_LBN 8
#define        MC_CMD_FC_OUT_DDR_TEST_POLL_PRESENT_B1_WIDTH 1
/* Test result from FPGA */
#define       MC_CMD_FC_OUT_DDR_TEST_POLL_RESULT_OFST 4
#define        MC_CMD_FC_OUT_DDR_TEST_POLL_FPGA_SUPPORTS_T0_LBN 31
#define        MC_CMD_FC_OUT_DDR_TEST_POLL_FPGA_SUPPORTS_T0_WIDTH 1
#define        MC_CMD_FC_OUT_DDR_TEST_POLL_FPGA_SUPPORTS_T1_LBN 30
#define        MC_CMD_FC_OUT_DDR_TEST_POLL_FPGA_SUPPORTS_T1_WIDTH 1
#define        MC_CMD_FC_OUT_DDR_TEST_POLL_FPGA_SUPPORTS_B0_LBN 29
#define        MC_CMD_FC_OUT_DDR_TEST_POLL_FPGA_SUPPORTS_B0_WIDTH 1
#define        MC_CMD_FC_OUT_DDR_TEST_POLL_FPGA_SUPPORTS_B1_LBN 28
#define        MC_CMD_FC_OUT_DDR_TEST_POLL_FPGA_SUPPORTS_B1_WIDTH 1
#define        MC_CMD_FC_OUT_DDR_TEST_POLL_T0_LBN 15
#define        MC_CMD_FC_OUT_DDR_TEST_POLL_T0_WIDTH 5
#define        MC_CMD_FC_OUT_DDR_TEST_POLL_T1_LBN 10
#define        MC_CMD_FC_OUT_DDR_TEST_POLL_T1_WIDTH 5
#define        MC_CMD_FC_OUT_DDR_TEST_POLL_B0_LBN 5
#define        MC_CMD_FC_OUT_DDR_TEST_POLL_B0_WIDTH 5
#define        MC_CMD_FC_OUT_DDR_TEST_POLL_B1_LBN 0
#define        MC_CMD_FC_OUT_DDR_TEST_POLL_B1_WIDTH 5
#define          MC_CMD_FC_OUT_DDR_TEST_POLL_TEST_COMPLETE 0x0 /* enum */
#define          MC_CMD_FC_OUT_DDR_TEST_POLL_TEST_FAIL 0x1 /* enum */
#define          MC_CMD_FC_OUT_DDR_TEST_POLL_TEST_PASS 0x2 /* enum */
#define          MC_CMD_FC_OUT_DDR_TEST_POLL_CAL_FAIL 0x3 /* enum */
#define          MC_CMD_FC_OUT_DDR_TEST_POLL_CAL_SUCCESS 0x4 /* enum */

/* MC_CMD_FC_OUT_DDR_TEST msgresponse */
#define    MC_CMD_FC_OUT_DDR_TEST_LEN 0

/* MC_CMD_FC_OUT_GET_ASSERT msgresponse */
#define    MC_CMD_FC_OUT_GET_ASSERT_LEN 144
/* Assertion status flag. */
#define       MC_CMD_FC_OUT_GET_ASSERT_GLOBAL_FLAGS_OFST 0
#define        MC_CMD_FC_OUT_GET_ASSERT_STATE_LBN 8
#define        MC_CMD_FC_OUT_GET_ASSERT_STATE_WIDTH 8
/* enum: No crash data available */
#define          MC_CMD_FC_GET_ASSERT_FLAGS_STATE_CLEAR 0x0
/* enum: New crash data available */
#define          MC_CMD_FC_GET_ASSERT_FLAGS_STATE_NEW 0x1
/* enum: Crash data has been sent */
#define          MC_CMD_FC_GET_ASSERT_FLAGS_STATE_NOTIFIED 0x2
#define        MC_CMD_FC_OUT_GET_ASSERT_TYPE_LBN 0
#define        MC_CMD_FC_OUT_GET_ASSERT_TYPE_WIDTH 8
/* enum: No crash has been recorded. */
#define          MC_CMD_FC_GET_ASSERT_FLAGS_TYPE_NONE 0x0
/* enum: Crash due to exception. */
#define          MC_CMD_FC_GET_ASSERT_FLAGS_TYPE_EXCEPTION 0x1
/* enum: Crash due to assertion. */
#define          MC_CMD_FC_GET_ASSERT_FLAGS_TYPE_ASSERTION 0x2
/* Failing PC value */
#define       MC_CMD_FC_OUT_GET_ASSERT_SAVED_PC_OFFS_OFST 4
/* Saved GP regs */
#define       MC_CMD_FC_OUT_GET_ASSERT_GP_REGS_OFFS_OFST 8
#define       MC_CMD_FC_OUT_GET_ASSERT_GP_REGS_OFFS_LEN 4
#define       MC_CMD_FC_OUT_GET_ASSERT_GP_REGS_OFFS_NUM 31
/* Exception Type */
#define       MC_CMD_FC_OUT_GET_ASSERT_EXCEPTION_TYPE_OFFS_OFST 132
/* Instruction at which exception occurred */
#define       MC_CMD_FC_OUT_GET_ASSERT_EXCEPTION_PC_ADDR_OFFS_OFST 136
/* BAD Address that triggered address-based exception */
#define       MC_CMD_FC_OUT_GET_ASSERT_EXCEPTION_BAD_ADDR_OFFS_OFST 140

/* MC_CMD_FC_OUT_FPGA_BUILD msgresponse */
#define    MC_CMD_FC_OUT_FPGA_BUILD_LEN 32
#define       MC_CMD_FC_OUT_FPGA_BUILD_COMPONENT_INFO_OFST 0
#define        MC_CMD_FC_OUT_FPGA_BUILD_IS_APPLICATION_LBN 31
#define        MC_CMD_FC_OUT_FPGA_BUILD_IS_APPLICATION_WIDTH 1
#define        MC_CMD_FC_OUT_FPGA_BUILD_IS_LICENSED_LBN 30
#define        MC_CMD_FC_OUT_FPGA_BUILD_IS_LICENSED_WIDTH 1
#define        MC_CMD_FC_OUT_FPGA_BUILD_COMPONENT_ID_LBN 16
#define        MC_CMD_FC_OUT_FPGA_BUILD_COMPONENT_ID_WIDTH 14
#define        MC_CMD_FC_OUT_FPGA_BUILD_VERSION_MAJOR_LBN 12
#define        MC_CMD_FC_OUT_FPGA_BUILD_VERSION_MAJOR_WIDTH 4
#define        MC_CMD_FC_OUT_FPGA_BUILD_VERSION_MINOR_LBN 4
#define        MC_CMD_FC_OUT_FPGA_BUILD_VERSION_MINOR_WIDTH 8
#define        MC_CMD_FC_OUT_FPGA_BUILD_BUILD_NUM_LBN 0
#define        MC_CMD_FC_OUT_FPGA_BUILD_BUILD_NUM_WIDTH 4
/* Build timestamp (seconds since epoch) */
#define       MC_CMD_FC_OUT_FPGA_BUILD_TIMESTAMP_OFST 4
#define       MC_CMD_FC_OUT_FPGA_BUILD_PARAMETERS_OFST 8
#define        MC_CMD_FC_OUT_FPGA_BUILD_FPGA_TYPE_LBN 0
#define        MC_CMD_FC_OUT_FPGA_BUILD_FPGA_TYPE_WIDTH 8
#define          MC_CMD_FC_FPGA_TYPE_A7 0xa7 /* enum */
#define          MC_CMD_FC_FPGA_TYPE_A5 0xa5 /* enum */
#define        MC_CMD_FC_OUT_FPGA_BUILD_RESERVED1_LBN 8
#define        MC_CMD_FC_OUT_FPGA_BUILD_RESERVED1_WIDTH 10
#define        MC_CMD_FC_OUT_FPGA_BUILD_PTP_ENABLED_LBN 18
#define        MC_CMD_FC_OUT_FPGA_BUILD_PTP_ENABLED_WIDTH 1
#define        MC_CMD_FC_OUT_FPGA_BUILD_SODIMM1_RLDRAM_DEF_LBN 19
#define        MC_CMD_FC_OUT_FPGA_BUILD_SODIMM1_RLDRAM_DEF_WIDTH 1
#define        MC_CMD_FC_OUT_FPGA_BUILD_SODIMM2_RLDRAM_DEF_LBN 20
#define        MC_CMD_FC_OUT_FPGA_BUILD_SODIMM2_RLDRAM_DEF_WIDTH 1
#define        MC_CMD_FC_OUT_FPGA_BUILD_SODIMM3_RLDRAM_DEF_LBN 21
#define        MC_CMD_FC_OUT_FPGA_BUILD_SODIMM3_RLDRAM_DEF_WIDTH 1
#define        MC_CMD_FC_OUT_FPGA_BUILD_SODIMM4_RLDRAM_DEF_LBN 22
#define        MC_CMD_FC_OUT_FPGA_BUILD_SODIMM4_RLDRAM_DEF_WIDTH 1
#define        MC_CMD_FC_OUT_FPGA_BUILD_SODIMM_T0_DDR3_DEF_LBN 23
#define        MC_CMD_FC_OUT_FPGA_BUILD_SODIMM_T0_DDR3_DEF_WIDTH 1
#define        MC_CMD_FC_OUT_FPGA_BUILD_SODIMM_T1_DDR3_DEF_LBN 24
#define        MC_CMD_FC_OUT_FPGA_BUILD_SODIMM_T1_DDR3_DEF_WIDTH 1
#define        MC_CMD_FC_OUT_FPGA_BUILD_SODIMM_B0_DDR3_DEF_LBN 25
#define        MC_CMD_FC_OUT_FPGA_BUILD_SODIMM_B0_DDR3_DEF_WIDTH 1
#define        MC_CMD_FC_OUT_FPGA_BUILD_SODIMM_B1_DDR3_DEF_LBN 26
#define        MC_CMD_FC_OUT_FPGA_BUILD_SODIMM_B1_DDR3_DEF_WIDTH 1
#define        MC_CMD_FC_OUT_FPGA_BUILD_DDR3_ECC_ENABLED_LBN 27
#define        MC_CMD_FC_OUT_FPGA_BUILD_DDR3_ECC_ENABLED_WIDTH 1
#define        MC_CMD_FC_OUT_FPGA_BUILD_SODIMM_T1_QDR_DEF_LBN 28
#define        MC_CMD_FC_OUT_FPGA_BUILD_SODIMM_T1_QDR_DEF_WIDTH 1
#define        MC_CMD_FC_OUT_FPGA_BUILD_RESERVED2_LBN 29
#define        MC_CMD_FC_OUT_FPGA_BUILD_RESERVED2_WIDTH 2
#define        MC_CMD_FC_OUT_FPGA_BUILD_CRC_APPEND_LBN 31
#define        MC_CMD_FC_OUT_FPGA_BUILD_CRC_APPEND_WIDTH 1
#define       MC_CMD_FC_OUT_FPGA_BUILD_IDENTIFIER_OFST 12
#define        MC_CMD_FC_OUT_FPGA_BUILD_CHANGESET_LBN 0
#define        MC_CMD_FC_OUT_FPGA_BUILD_CHANGESET_WIDTH 16
#define        MC_CMD_FC_OUT_FPGA_BUILD_BUILD_FLAG_LBN 16
#define        MC_CMD_FC_OUT_FPGA_BUILD_BUILD_FLAG_WIDTH 1
#define          MC_CMD_FC_FPGA_BUILD_FLAG_INTERNAL 0x0 /* enum */
#define          MC_CMD_FC_FPGA_BUILD_FLAG_RELEASE 0x1 /* enum */
#define        MC_CMD_FC_OUT_FPGA_BUILD_RESERVED3_LBN 17
#define        MC_CMD_FC_OUT_FPGA_BUILD_RESERVED3_WIDTH 15
#define       MC_CMD_FC_OUT_FPGA_BUILD_VERSION_HI_OFST 16
#define        MC_CMD_FC_OUT_FPGA_BUILD_DEPLOYMENT_VERSION_MINOR_LBN 0
#define        MC_CMD_FC_OUT_FPGA_BUILD_DEPLOYMENT_VERSION_MINOR_WIDTH 16
#define        MC_CMD_FC_OUT_FPGA_BUILD_DEPLOYMENT_VERSION_MAJOR_LBN 16
#define        MC_CMD_FC_OUT_FPGA_BUILD_DEPLOYMENT_VERSION_MAJOR_WIDTH 16
#define       MC_CMD_FC_OUT_FPGA_BUILD_VERSION_LO_OFST 20
#define        MC_CMD_FC_OUT_FPGA_BUILD_DEPLOYMENT_VERSION_BUILD_LBN 0
#define        MC_CMD_FC_OUT_FPGA_BUILD_DEPLOYMENT_VERSION_BUILD_WIDTH 16
#define        MC_CMD_FC_OUT_FPGA_BUILD_DEPLOYMENT_VERSION_MICRO_LBN 16
#define        MC_CMD_FC_OUT_FPGA_BUILD_DEPLOYMENT_VERSION_MICRO_WIDTH 16
#define       MC_CMD_FC_OUT_FPGA_BUILD_RESERVED4_OFST 16
#define       MC_CMD_FC_OUT_FPGA_BUILD_RESERVED4_LEN 8
#define       MC_CMD_FC_OUT_FPGA_BUILD_RESERVED4_LO_OFST 16
#define       MC_CMD_FC_OUT_FPGA_BUILD_RESERVED4_HI_OFST 20
#define       MC_CMD_FC_OUT_FPGA_BUILD_REVISION_LO_OFST 24
#define       MC_CMD_FC_OUT_FPGA_BUILD_REVISION_HI_OFST 28
#define        MC_CMD_FC_OUT_FPGA_BUILD_REVISION_HIGH_LBN 0
#define        MC_CMD_FC_OUT_FPGA_BUILD_REVISION_HIGH_WIDTH 16

/* MC_CMD_FC_OUT_FPGA_SERVICES msgresponse */
#define    MC_CMD_FC_OUT_FPGA_SERVICES_LEN 32
#define       MC_CMD_FC_OUT_FPGA_SERVICES_COMPONENT_INFO_OFST 0
#define        MC_CMD_FC_OUT_FPGA_SERVICES_IS_APPLICATION_LBN 31
#define        MC_CMD_FC_OUT_FPGA_SERVICES_IS_APPLICATION_WIDTH 1
#define        MC_CMD_FC_OUT_FPGA_SERVICES_IS_LICENSED_LBN 30
#define        MC_CMD_FC_OUT_FPGA_SERVICES_IS_LICENSED_WIDTH 1
#define        MC_CMD_FC_OUT_FPGA_SERVICES_COMPONENT_ID_LBN 16
#define        MC_CMD_FC_OUT_FPGA_SERVICES_COMPONENT_ID_WIDTH 14
#define        MC_CMD_FC_OUT_FPGA_SERVICES_VERSION_MAJOR_LBN 12
#define        MC_CMD_FC_OUT_FPGA_SERVICES_VERSION_MAJOR_WIDTH 4
#define        MC_CMD_FC_OUT_FPGA_SERVICES_VERSION_MINOR_LBN 4
#define        MC_CMD_FC_OUT_FPGA_SERVICES_VERSION_MINOR_WIDTH 8
#define        MC_CMD_FC_OUT_FPGA_SERVICES_BUILD_NUM_LBN 0
#define        MC_CMD_FC_OUT_FPGA_SERVICES_BUILD_NUM_WIDTH 4
/* Build timestamp (seconds since epoch) */
#define       MC_CMD_FC_OUT_FPGA_SERVICES_TIMESTAMP_OFST 4
#define       MC_CMD_FC_OUT_FPGA_SERVICES_PARAMETERS_OFST 8
#define        MC_CMD_FC_OUT_FPGA_SERVICES_FC_FLASH_BOOTED_LBN 8
#define        MC_CMD_FC_OUT_FPGA_SERVICES_FC_FLASH_BOOTED_WIDTH 1
#define        MC_CMD_FC_OUT_FPGA_SERVICES_NIC0_DEF_LBN 27
#define        MC_CMD_FC_OUT_FPGA_SERVICES_NIC0_DEF_WIDTH 1
#define        MC_CMD_FC_OUT_FPGA_SERVICES_NIC1_DEF_LBN 28
#define        MC_CMD_FC_OUT_FPGA_SERVICES_NIC1_DEF_WIDTH 1
#define        MC_CMD_FC_OUT_FPGA_SERVICES_SFP0_DEF_LBN 29
#define        MC_CMD_FC_OUT_FPGA_SERVICES_SFP0_DEF_WIDTH 1
#define        MC_CMD_FC_OUT_FPGA_SERVICES_SFP1_DEF_LBN 30
#define        MC_CMD_FC_OUT_FPGA_SERVICES_SFP1_DEF_WIDTH 1
#define        MC_CMD_FC_OUT_FPGA_SERVICES_RESERVED_LBN 31
#define        MC_CMD_FC_OUT_FPGA_SERVICES_RESERVED_WIDTH 1
#define       MC_CMD_FC_OUT_FPGA_SERVICES_IDENTIFIER_OFST 12
#define        MC_CMD_FC_OUT_FPGA_SERVICES_CHANGESET_LBN 0
#define        MC_CMD_FC_OUT_FPGA_SERVICES_CHANGESET_WIDTH 16
#define        MC_CMD_FC_OUT_FPGA_SERVICES_BUILD_FLAG_LBN 16
#define        MC_CMD_FC_OUT_FPGA_SERVICES_BUILD_FLAG_WIDTH 1
#define       MC_CMD_FC_OUT_FPGA_SERVICES_MEMORY_SIZE_OFST 16
#define        MC_CMD_FC_OUT_FPGA_SERVICES_MEMORY_SIZE_WIDTH_LBN 0
#define        MC_CMD_FC_OUT_FPGA_SERVICES_MEMORY_SIZE_WIDTH_WIDTH 16
#define        MC_CMD_FC_OUT_FPGA_SERVICES_MEMORY_SIZE_COUNT_LBN 16
#define        MC_CMD_FC_OUT_FPGA_SERVICES_MEMORY_SIZE_COUNT_WIDTH 16
#define       MC_CMD_FC_OUT_FPGA_SERVICES_INSTANCE_SIZE_OFST 20
#define        MC_CMD_FC_OUT_FPGA_SERVICES_INSTANCE_SIZE_WIDTH_LBN 0
#define        MC_CMD_FC_OUT_FPGA_SERVICES_INSTANCE_SIZE_WIDTH_WIDTH 16
#define        MC_CMD_FC_OUT_FPGA_SERVICES_INSTANCE_SIZE_COUNT_LBN 16
#define        MC_CMD_FC_OUT_FPGA_SERVICES_INSTANCE_SIZE_COUNT_WIDTH 16
#define       MC_CMD_FC_OUT_FPGA_SERVICES_REVISION_LO_OFST 24
#define       MC_CMD_FC_OUT_FPGA_SERVICES_REVISION_HI_OFST 28
#define        MC_CMD_FC_OUT_FPGA_SERVICES_REVISION_HIGH_LBN 0
#define        MC_CMD_FC_OUT_FPGA_SERVICES_REVISION_HIGH_WIDTH 16

/* MC_CMD_FC_OUT_BSP_VERSION msgresponse */
#define    MC_CMD_FC_OUT_BSP_VERSION_LEN 4
/* Qsys system ID */
#define       MC_CMD_FC_OUT_BSP_VERSION_SYSID_OFST 0
#define        MC_CMD_FC_OUT_BSP_VERSION_VERSION_MAJOR_LBN 12
#define        MC_CMD_FC_OUT_BSP_VERSION_VERSION_MAJOR_WIDTH 4
#define        MC_CMD_FC_OUT_BSP_VERSION_VERSION_MINOR_LBN 4
#define        MC_CMD_FC_OUT_BSP_VERSION_VERSION_MINOR_WIDTH 8
#define        MC_CMD_FC_OUT_BSP_VERSION_BUILD_NUM_LBN 0
#define        MC_CMD_FC_OUT_BSP_VERSION_BUILD_NUM_WIDTH 4

/* MC_CMD_FC_OUT_READ_MAP_COUNT msgresponse */
#define    MC_CMD_FC_OUT_READ_MAP_COUNT_LEN 4
/* Number of maps */
#define       MC_CMD_FC_OUT_READ_MAP_COUNT_NUM_MAPS_OFST 0

/* MC_CMD_FC_OUT_READ_MAP_INDEX msgresponse */
#define    MC_CMD_FC_OUT_READ_MAP_INDEX_LEN 164
/* Index of the map */
#define       MC_CMD_FC_OUT_READ_MAP_INDEX_INDEX_OFST 0
/* Options for the map */
#define       MC_CMD_FC_OUT_READ_MAP_INDEX_OPTIONS_OFST 4
#define          MC_CMD_FC_OUT_READ_MAP_INDEX_ALIGN_8  0x0 /* enum */
#define          MC_CMD_FC_OUT_READ_MAP_INDEX_ALIGN_16  0x1 /* enum */
#define          MC_CMD_FC_OUT_READ_MAP_INDEX_ALIGN_32  0x2 /* enum */
#define          MC_CMD_FC_OUT_READ_MAP_INDEX_ALIGN_64  0x3 /* enum */
#define          MC_CMD_FC_OUT_READ_MAP_INDEX_ALIGN_MASK  0x3 /* enum */
#define          MC_CMD_FC_OUT_READ_MAP_INDEX_PATH_FC  0x4 /* enum */
#define          MC_CMD_FC_OUT_READ_MAP_INDEX_PATH_MEM  0x8 /* enum */
#define          MC_CMD_FC_OUT_READ_MAP_INDEX_PERM_READ  0x10 /* enum */
#define          MC_CMD_FC_OUT_READ_MAP_INDEX_PERM_WRITE  0x20 /* enum */
#define          MC_CMD_FC_OUT_READ_MAP_INDEX_LICENSE_FREE  0x0 /* enum */
#define          MC_CMD_FC_OUT_READ_MAP_INDEX_LICENSE_LICENSED  0x40 /* enum */
/* Address of start of map */
#define       MC_CMD_FC_OUT_READ_MAP_INDEX_ADDRESS_OFST 8
#define       MC_CMD_FC_OUT_READ_MAP_INDEX_ADDRESS_LEN 8
#define       MC_CMD_FC_OUT_READ_MAP_INDEX_ADDRESS_LO_OFST 8
#define       MC_CMD_FC_OUT_READ_MAP_INDEX_ADDRESS_HI_OFST 12
/* Length of address map */
#define       MC_CMD_FC_OUT_READ_MAP_INDEX_LEN_OFST 16
#define       MC_CMD_FC_OUT_READ_MAP_INDEX_LEN_LEN 8
#define       MC_CMD_FC_OUT_READ_MAP_INDEX_LEN_LO_OFST 16
#define       MC_CMD_FC_OUT_READ_MAP_INDEX_LEN_HI_OFST 20
/* Component information field */
#define       MC_CMD_FC_OUT_READ_MAP_INDEX_COMP_INFO_OFST 24
/* License expiry data for map */
#define       MC_CMD_FC_OUT_READ_MAP_INDEX_LICENSE_DATE_OFST 28
#define       MC_CMD_FC_OUT_READ_MAP_INDEX_LICENSE_DATE_LEN 8
#define       MC_CMD_FC_OUT_READ_MAP_INDEX_LICENSE_DATE_LO_OFST 28
#define       MC_CMD_FC_OUT_READ_MAP_INDEX_LICENSE_DATE_HI_OFST 32
/* Name of the component */
#define       MC_CMD_FC_OUT_READ_MAP_INDEX_NAME_OFST 36
#define       MC_CMD_FC_OUT_READ_MAP_INDEX_NAME_LEN 1
#define       MC_CMD_FC_OUT_READ_MAP_INDEX_NAME_NUM 128

/* MC_CMD_FC_OUT_READ_MAP msgresponse */
#define    MC_CMD_FC_OUT_READ_MAP_LEN 0

/* MC_CMD_FC_OUT_CAPABILITIES msgresponse */
#define    MC_CMD_FC_OUT_CAPABILITIES_LEN 8
/* Number of internal ports */
#define       MC_CMD_FC_OUT_CAPABILITIES_INTERNAL_OFST 0
/* Number of external ports */
#define       MC_CMD_FC_OUT_CAPABILITIES_EXTERNAL_OFST 4

/* MC_CMD_FC_OUT_GLOBAL_FLAGS msgresponse */
#define    MC_CMD_FC_OUT_GLOBAL_FLAGS_LEN 4
#define       MC_CMD_FC_OUT_GLOBAL_FLAGS_FLAGS_OFST 0

/* MC_CMD_FC_OUT_IO_REL msgresponse */
#define    MC_CMD_FC_OUT_IO_REL_LEN 0

/* MC_CMD_FC_OUT_IO_REL_GET_ADDR msgresponse */
#define    MC_CMD_FC_OUT_IO_REL_GET_ADDR_LEN 8
#define       MC_CMD_FC_OUT_IO_REL_GET_ADDR_ADDR_HI_OFST 0
#define       MC_CMD_FC_OUT_IO_REL_GET_ADDR_ADDR_LO_OFST 4

/* MC_CMD_FC_OUT_IO_REL_READ32 msgresponse */
#define    MC_CMD_FC_OUT_IO_REL_READ32_LENMIN 4
#define    MC_CMD_FC_OUT_IO_REL_READ32_LENMAX 252
#define    MC_CMD_FC_OUT_IO_REL_READ32_LEN(num) (0+4*(num))
#define       MC_CMD_FC_OUT_IO_REL_READ32_BUFFER_OFST 0
#define       MC_CMD_FC_OUT_IO_REL_READ32_BUFFER_LEN 4
#define       MC_CMD_FC_OUT_IO_REL_READ32_BUFFER_MINNUM 1
#define       MC_CMD_FC_OUT_IO_REL_READ32_BUFFER_MAXNUM 63

/* MC_CMD_FC_OUT_IO_REL_WRITE32 msgresponse */
#define    MC_CMD_FC_OUT_IO_REL_WRITE32_LEN 0

/* MC_CMD_FC_OUT_UHLINK_PHY msgresponse */
#define    MC_CMD_FC_OUT_UHLINK_PHY_LEN 48
#define       MC_CMD_FC_OUT_UHLINK_PHY_TRC_TX_SETTINGS_0_OFST 0
#define        MC_CMD_FC_OUT_UHLINK_PHY_TRC_TX_VOD_LBN 0
#define        MC_CMD_FC_OUT_UHLINK_PHY_TRC_TX_VOD_WIDTH 16
#define        MC_CMD_FC_OUT_UHLINK_PHY_TRC_TX_PREEMP_1STPOSTTAP_LBN 16
#define        MC_CMD_FC_OUT_UHLINK_PHY_TRC_TX_PREEMP_1STPOSTTAP_WIDTH 16
/* Transceiver Transmit settings */
#define       MC_CMD_FC_OUT_UHLINK_PHY_TRC_TX_SETTINGS_1_OFST 4
#define        MC_CMD_FC_OUT_UHLINK_PHY_TRC_TX_PREEMP_PRETAP_LBN 0
#define        MC_CMD_FC_OUT_UHLINK_PHY_TRC_TX_PREEMP_PRETAP_WIDTH 16
#define        MC_CMD_FC_OUT_UHLINK_PHY_TRC_TX_PREEMP_2NDPOSTTAP_LBN 16
#define        MC_CMD_FC_OUT_UHLINK_PHY_TRC_TX_PREEMP_2NDPOSTTAP_WIDTH 16
/* Transceiver Receive settings */
#define       MC_CMD_FC_OUT_UHLINK_PHY_TRC_RX_SETTINGS_OFST 8
#define        MC_CMD_FC_OUT_UHLINK_PHY_TRC_RX_DC_GAIN_LBN 0
#define        MC_CMD_FC_OUT_UHLINK_PHY_TRC_RX_DC_GAIN_WIDTH 16
#define        MC_CMD_FC_OUT_UHLINK_PHY_TRC_RX_EQ_CONTROL_LBN 16
#define        MC_CMD_FC_OUT_UHLINK_PHY_TRC_RX_EQ_CONTROL_WIDTH 16
/* Rx eye opening */
#define       MC_CMD_FC_OUT_UHLINK_PHY_RX_EYE_OFST 12
#define        MC_CMD_FC_OUT_UHLINK_PHY_RX_EYE_WIDTH_LBN 0
#define        MC_CMD_FC_OUT_UHLINK_PHY_RX_EYE_WIDTH_WIDTH 16
#define        MC_CMD_FC_OUT_UHLINK_PHY_RX_EYE_HEIGHT_LBN 16
#define        MC_CMD_FC_OUT_UHLINK_PHY_RX_EYE_HEIGHT_WIDTH 16
/* PCS status word */
#define       MC_CMD_FC_OUT_UHLINK_PHY_PCS_STATUS_OFST 16
/* Link status word */
#define       MC_CMD_FC_OUT_UHLINK_PHY_LINK_STATE_WORD_OFST 20
#define        MC_CMD_FC_OUT_UHLINK_PHY_LINK_STATE_LBN 0
#define        MC_CMD_FC_OUT_UHLINK_PHY_LINK_STATE_WIDTH 1
#define        MC_CMD_FC_OUT_UHLINK_PHY_LINK_CONFIGURED_LBN 1
#define        MC_CMD_FC_OUT_UHLINK_PHY_LINK_CONFIGURED_WIDTH 1
/* Current SFp parameters applied */
#define       MC_CMD_FC_OUT_UHLINK_PHY_SFP_PARAMS_OFST 24
#define       MC_CMD_FC_OUT_UHLINK_PHY_SFP_PARAMS_LEN 20
/* Link speed is 100, 1000, 10000 */
#define       MC_CMD_FC_OUT_UHLINK_PHY_SFP_SPEED_OFST 24
/* Length of copper cable - zero when not relevant */
#define       MC_CMD_FC_OUT_UHLINK_PHY_SFP_COPPER_LEN_OFST 28
/* True if a dual speed SFP+ module */
#define       MC_CMD_FC_OUT_UHLINK_PHY_SFP_DUAL_SPEED_OFST 32
/* True if an SFP Module is present (other fields valid when true) */
#define       MC_CMD_FC_OUT_UHLINK_PHY_SFP_PRESENT_OFST 36
/* The type of the SFP+ Module */
#define       MC_CMD_FC_OUT_UHLINK_PHY_SFP_TYPE_OFST 40
/* PHY config flags */
#define       MC_CMD_FC_OUT_UHLINK_PHY_PHY_CFG_OFST 44
#define        MC_CMD_FC_OUT_UHLINK_PHY_PHY_CFG_DFE_LBN 0
#define        MC_CMD_FC_OUT_UHLINK_PHY_PHY_CFG_DFE_WIDTH 1
#define        MC_CMD_FC_OUT_UHLINK_PHY_PHY_CFG_AEQ_LBN 1
#define        MC_CMD_FC_OUT_UHLINK_PHY_PHY_CFG_AEQ_WIDTH 1
#define        MC_CMD_FC_OUT_UHLINK_PHY_PHY_CFG_RX_TUNING_LBN 2
#define        MC_CMD_FC_OUT_UHLINK_PHY_PHY_CFG_RX_TUNING_WIDTH 1

/* MC_CMD_FC_OUT_UHLINK_MAC msgresponse */
#define    MC_CMD_FC_OUT_UHLINK_MAC_LEN 20
/* MAC configuration applied */
#define       MC_CMD_FC_OUT_UHLINK_MAC_CONFIG_OFST 0
/* MTU size */
#define       MC_CMD_FC_OUT_UHLINK_MAC_MTU_OFST 4
/* IF Mode status */
#define       MC_CMD_FC_OUT_UHLINK_MAC_IF_STATUS_OFST 8
/* MAC address configured */
#define       MC_CMD_FC_OUT_UHLINK_MAC_ADDR_OFST 12
#define       MC_CMD_FC_OUT_UHLINK_MAC_ADDR_LEN 8
#define       MC_CMD_FC_OUT_UHLINK_MAC_ADDR_LO_OFST 12
#define       MC_CMD_FC_OUT_UHLINK_MAC_ADDR_HI_OFST 16

/* MC_CMD_FC_OUT_UHLINK_RX_EYE msgresponse */
#define    MC_CMD_FC_OUT_UHLINK_RX_EYE_LEN ((((0-1+(32*MC_CMD_FC_UHLINK_RX_EYE_PER_BLOCK))+1))>>3)
/* Rx Eye measurements */
#define       MC_CMD_FC_OUT_UHLINK_RX_EYE_RX_EYE_OFST 0
#define       MC_CMD_FC_OUT_UHLINK_RX_EYE_RX_EYE_LEN 4
#define       MC_CMD_FC_OUT_UHLINK_RX_EYE_RX_EYE_NUM MC_CMD_FC_UHLINK_RX_EYE_PER_BLOCK

/* MC_CMD_FC_OUT_UHLINK_DUMP_RX_EYE_PLOT msgresponse */
#define    MC_CMD_FC_OUT_UHLINK_DUMP_RX_EYE_PLOT_LEN 0

/* MC_CMD_FC_OUT_UHLINK_READ_RX_EYE_PLOT msgresponse */
#define    MC_CMD_FC_OUT_UHLINK_READ_RX_EYE_PLOT_LEN ((((32-1+(64*MC_CMD_FC_UHLINK_RX_EYE_PLOT_ROWS_PER_BLOCK))+1))>>3)
/* Has the eye plot dump completed and data returned is valid? */
#define       MC_CMD_FC_OUT_UHLINK_READ_RX_EYE_PLOT_VALID_OFST 0
/* Rx Eye binary plot */
#define       MC_CMD_FC_OUT_UHLINK_READ_RX_EYE_PLOT_ROWS_OFST 4
#define       MC_CMD_FC_OUT_UHLINK_READ_RX_EYE_PLOT_ROWS_LEN 8
#define       MC_CMD_FC_OUT_UHLINK_READ_RX_EYE_PLOT_ROWS_LO_OFST 4
#define       MC_CMD_FC_OUT_UHLINK_READ_RX_EYE_PLOT_ROWS_HI_OFST 8
#define       MC_CMD_FC_OUT_UHLINK_READ_RX_EYE_PLOT_ROWS_NUM MC_CMD_FC_UHLINK_RX_EYE_PLOT_ROWS_PER_BLOCK

/* MC_CMD_FC_OUT_UHLINK_RX_TUNE msgresponse */
#define    MC_CMD_FC_OUT_UHLINK_RX_TUNE_LEN 0

/* MC_CMD_FC_OUT_UHLINK msgresponse */
#define    MC_CMD_FC_OUT_UHLINK_LEN 0

/* MC_CMD_FC_OUT_SET_LINK msgresponse */
#define    MC_CMD_FC_OUT_SET_LINK_LEN 0

/* MC_CMD_FC_OUT_LICENSE msgresponse */
#define    MC_CMD_FC_OUT_LICENSE_LEN 12
/* Count of valid keys */
#define       MC_CMD_FC_OUT_LICENSE_VALID_KEYS_OFST 0
/* Count of invalid keys */
#define       MC_CMD_FC_OUT_LICENSE_INVALID_KEYS_OFST 4
/* Count of blacklisted keys */
#define       MC_CMD_FC_OUT_LICENSE_BLACKLISTED_KEYS_OFST 8

/* MC_CMD_FC_OUT_STARTUP msgresponse */
#define    MC_CMD_FC_OUT_STARTUP_LEN 4
/* Capabilities of the FPGA/FC */
#define       MC_CMD_FC_OUT_STARTUP_CAPABILITIES_OFST 0
#define        MC_CMD_FC_OUT_STARTUP_CAN_ACCESS_FLASH_LBN 0
#define        MC_CMD_FC_OUT_STARTUP_CAN_ACCESS_FLASH_WIDTH 1

/* MC_CMD_FC_OUT_DMA_READ msgresponse */
#define    MC_CMD_FC_OUT_DMA_READ_LENMIN 1
#define    MC_CMD_FC_OUT_DMA_READ_LENMAX 252
#define    MC_CMD_FC_OUT_DMA_READ_LEN(num) (0+1*(num))
/* The data read */
#define       MC_CMD_FC_OUT_DMA_READ_DATA_OFST 0
#define       MC_CMD_FC_OUT_DMA_READ_DATA_LEN 1
#define       MC_CMD_FC_OUT_DMA_READ_DATA_MINNUM 1
#define       MC_CMD_FC_OUT_DMA_READ_DATA_MAXNUM 252

/* MC_CMD_FC_OUT_TIMED_READ_SET msgresponse */
#define    MC_CMD_FC_OUT_TIMED_READ_SET_LEN 4
/* Timer handle */
#define       MC_CMD_FC_OUT_TIMED_READ_SET_FC_HANDLE_OFST 0

/* MC_CMD_FC_OUT_TIMED_READ_GET msgresponse */
#define    MC_CMD_FC_OUT_TIMED_READ_GET_LEN 52
/* Host supplied handle (unique) */
#define       MC_CMD_FC_OUT_TIMED_READ_GET_HOST_HANDLE_OFST 0
/* Address into which to transfer data in host */
#define       MC_CMD_FC_OUT_TIMED_READ_GET_HOST_DMA_ADDRESS_OFST 4
#define       MC_CMD_FC_OUT_TIMED_READ_GET_HOST_DMA_ADDRESS_LEN 8
#define       MC_CMD_FC_OUT_TIMED_READ_GET_HOST_DMA_ADDRESS_LO_OFST 4
#define       MC_CMD_FC_OUT_TIMED_READ_GET_HOST_DMA_ADDRESS_HI_OFST 8
/* AOE address from which to transfer data */
#define       MC_CMD_FC_OUT_TIMED_READ_GET_AOE_ADDRESS_OFST 12
#define       MC_CMD_FC_OUT_TIMED_READ_GET_AOE_ADDRESS_LEN 8
#define       MC_CMD_FC_OUT_TIMED_READ_GET_AOE_ADDRESS_LO_OFST 12
#define       MC_CMD_FC_OUT_TIMED_READ_GET_AOE_ADDRESS_HI_OFST 16
/* Length of AOE transfer (total) */
#define       MC_CMD_FC_OUT_TIMED_READ_GET_AOE_LENGTH_OFST 20
/* Length of host transfer (total) */
#define       MC_CMD_FC_OUT_TIMED_READ_GET_HOST_LENGTH_OFST 24
/* See FLAGS entry for MC_CMD_FC_IN_TIMED_READ_SET */
#define       MC_CMD_FC_OUT_TIMED_READ_GET_FLAGS_OFST 28
#define       MC_CMD_FC_OUT_TIMED_READ_GET_PERIOD_OFST 32
/* When active, start read time */
#define       MC_CMD_FC_OUT_TIMED_READ_GET_CLOCK_START_OFST 36
#define       MC_CMD_FC_OUT_TIMED_READ_GET_CLOCK_START_LEN 8
#define       MC_CMD_FC_OUT_TIMED_READ_GET_CLOCK_START_LO_OFST 36
#define       MC_CMD_FC_OUT_TIMED_READ_GET_CLOCK_START_HI_OFST 40
/* When active, end read time */
#define       MC_CMD_FC_OUT_TIMED_READ_GET_CLOCK_END_OFST 44
#define       MC_CMD_FC_OUT_TIMED_READ_GET_CLOCK_END_LEN 8
#define       MC_CMD_FC_OUT_TIMED_READ_GET_CLOCK_END_LO_OFST 44
#define       MC_CMD_FC_OUT_TIMED_READ_GET_CLOCK_END_HI_OFST 48

/* MC_CMD_FC_OUT_LOG_ADDR_RANGE msgresponse */
#define    MC_CMD_FC_OUT_LOG_ADDR_RANGE_LEN 0

/* MC_CMD_FC_OUT_LOG msgresponse */
#define    MC_CMD_FC_OUT_LOG_LEN 0

/* MC_CMD_FC_OUT_CLOCK_GET_TIME msgresponse */
#define    MC_CMD_FC_OUT_CLOCK_GET_TIME_LEN 24
#define       MC_CMD_FC_OUT_CLOCK_GET_TIME_CLOCK_ID_OFST 0
#define       MC_CMD_FC_OUT_CLOCK_GET_TIME_SECONDS_OFST 4
#define       MC_CMD_FC_OUT_CLOCK_GET_TIME_SECONDS_LEN 8
#define       MC_CMD_FC_OUT_CLOCK_GET_TIME_SECONDS_LO_OFST 4
#define       MC_CMD_FC_OUT_CLOCK_GET_TIME_SECONDS_HI_OFST 8
#define       MC_CMD_FC_OUT_CLOCK_GET_TIME_NANOSECONDS_OFST 12
#define       MC_CMD_FC_OUT_CLOCK_GET_TIME_RANGE_OFST 16
#define       MC_CMD_FC_OUT_CLOCK_GET_TIME_PRECISION_OFST 20

/* MC_CMD_FC_OUT_CLOCK_SET_TIME msgresponse */
#define    MC_CMD_FC_OUT_CLOCK_SET_TIME_LEN 0

/* MC_CMD_FC_OUT_DDR_SET_SPD msgresponse */
#define    MC_CMD_FC_OUT_DDR_SET_SPD_LEN 0

/* MC_CMD_FC_OUT_DDR_GET_STATUS msgresponse */
#define    MC_CMD_FC_OUT_DDR_GET_STATUS_LEN 4
#define       MC_CMD_FC_OUT_DDR_GET_STATUS_FLAGS_OFST 0
#define        MC_CMD_FC_OUT_DDR_GET_STATUS_READY_LBN 0
#define        MC_CMD_FC_OUT_DDR_GET_STATUS_READY_WIDTH 1
#define        MC_CMD_FC_OUT_DDR_GET_STATUS_CALIBRATED_LBN 1
#define        MC_CMD_FC_OUT_DDR_GET_STATUS_CALIBRATED_WIDTH 1

/* MC_CMD_FC_OUT_TIMESTAMP_READ_TRANSMIT msgresponse */
#define    MC_CMD_FC_OUT_TIMESTAMP_READ_TRANSMIT_LEN 8
#define       MC_CMD_FC_OUT_TIMESTAMP_READ_TRANSMIT_SECONDS_OFST 0
#define       MC_CMD_FC_OUT_TIMESTAMP_READ_TRANSMIT_NANOSECONDS_OFST 4

/* MC_CMD_FC_OUT_TIMESTAMP_READ_SNAPSHOT msgresponse */
#define    MC_CMD_FC_OUT_TIMESTAMP_READ_SNAPSHOT_LENMIN 8
#define    MC_CMD_FC_OUT_TIMESTAMP_READ_SNAPSHOT_LENMAX 248
#define    MC_CMD_FC_OUT_TIMESTAMP_READ_SNAPSHOT_LEN(num) (0+8*(num))
#define       MC_CMD_FC_OUT_TIMESTAMP_READ_SNAPSHOT_SECONDS_OFST 0
#define       MC_CMD_FC_OUT_TIMESTAMP_READ_SNAPSHOT_NANOSECONDS_OFST 4
#define       MC_CMD_FC_OUT_TIMESTAMP_READ_SNAPSHOT_TIMESTAMP_OFST 0
#define       MC_CMD_FC_OUT_TIMESTAMP_READ_SNAPSHOT_TIMESTAMP_LEN 8
#define       MC_CMD_FC_OUT_TIMESTAMP_READ_SNAPSHOT_TIMESTAMP_LO_OFST 0
#define       MC_CMD_FC_OUT_TIMESTAMP_READ_SNAPSHOT_TIMESTAMP_HI_OFST 4
#define       MC_CMD_FC_OUT_TIMESTAMP_READ_SNAPSHOT_TIMESTAMP_MINNUM 0
#define       MC_CMD_FC_OUT_TIMESTAMP_READ_SNAPSHOT_TIMESTAMP_MAXNUM 31


/***********************************/
/* MC_CMD_AOE
 * AOE operations on MC
 */
#define MC_CMD_AOE 0xa

/* MC_CMD_AOE_IN msgrequest */
#define    MC_CMD_AOE_IN_LEN 4
#define       MC_CMD_AOE_IN_OP_HDR_OFST 0
#define        MC_CMD_AOE_IN_OP_LBN 0
#define        MC_CMD_AOE_IN_OP_WIDTH 8
/* enum: FPGA and CPLD information */
#define          MC_CMD_AOE_OP_INFO 0x1
/* enum: Currents and voltages read from MCP3424s; DEBUG */
#define          MC_CMD_AOE_OP_CURRENTS 0x2
/* enum: Temperatures at locations around the PCB; DEBUG */
#define          MC_CMD_AOE_OP_TEMPERATURES 0x3
/* enum: Set CPLD to idle */
#define          MC_CMD_AOE_OP_CPLD_IDLE 0x4
/* enum: Read from CPLD register */
#define          MC_CMD_AOE_OP_CPLD_READ 0x5
/* enum: Write to CPLD register */
#define          MC_CMD_AOE_OP_CPLD_WRITE 0x6
/* enum: Execute CPLD instruction */
#define          MC_CMD_AOE_OP_CPLD_INSTRUCTION 0x7
/* enum: Reprogram the CPLD on the AOE device */
#define          MC_CMD_AOE_OP_CPLD_REPROGRAM 0x8
/* enum: AOE power control */
#define          MC_CMD_AOE_OP_POWER 0x9
/* enum: AOE image loading */
#define          MC_CMD_AOE_OP_LOAD 0xa
/* enum: Fan monitoring */
#define          MC_CMD_AOE_OP_FAN_CONTROL 0xb
/* enum: Fan failures since last reset */
#define          MC_CMD_AOE_OP_FAN_FAILURES 0xc
/* enum: Get generic AOE MAC statistics */
#define          MC_CMD_AOE_OP_MAC_STATS 0xd
/* enum: Retrieve PHY specific information */
#define          MC_CMD_AOE_OP_GET_PHY_MEDIA_INFO 0xe
/* enum: Write a number of JTAG primitive commands, return will give data */
#define          MC_CMD_AOE_OP_JTAG_WRITE 0xf
/* enum: Control access to the FPGA via the Siena JTAG Chain */
#define          MC_CMD_AOE_OP_FPGA_ACCESS 0x10
/* enum: Set the MTU offset between Siena and AOE MACs */
#define          MC_CMD_AOE_OP_SET_MTU_OFFSET 0x11
/* enum: How link state is handled */
#define          MC_CMD_AOE_OP_LINK_STATE 0x12
/* enum: How Siena MAC statistics are reported */
#define          MC_CMD_AOE_OP_SIENA_STATS 0x13
/* enum: DDR memory information */
#define          MC_CMD_AOE_OP_DDR 0x14
/* enum: FC control */
#define          MC_CMD_AOE_OP_FC 0x15
/* enum: DDR ECC status reads */
#define          MC_CMD_AOE_OP_DDR_ECC_STATUS 0x16

/* MC_CMD_AOE_OUT msgresponse */
#define    MC_CMD_AOE_OUT_LEN 0

/* MC_CMD_AOE_IN_INFO msgrequest */
#define    MC_CMD_AOE_IN_INFO_LEN 4
#define       MC_CMD_AOE_IN_CMD_OFST 0

/* MC_CMD_AOE_IN_CURRENTS msgrequest */
#define    MC_CMD_AOE_IN_CURRENTS_LEN 4
/*            MC_CMD_AOE_IN_CMD_OFST 0 */

/* MC_CMD_AOE_IN_TEMPERATURES msgrequest */
#define    MC_CMD_AOE_IN_TEMPERATURES_LEN 4
/*            MC_CMD_AOE_IN_CMD_OFST 0 */

/* MC_CMD_AOE_IN_CPLD_IDLE msgrequest */
#define    MC_CMD_AOE_IN_CPLD_IDLE_LEN 4
/*            MC_CMD_AOE_IN_CMD_OFST 0 */

/* MC_CMD_AOE_IN_CPLD_READ msgrequest */
#define    MC_CMD_AOE_IN_CPLD_READ_LEN 12
/*            MC_CMD_AOE_IN_CMD_OFST 0 */
#define       MC_CMD_AOE_IN_CPLD_READ_REGISTER_OFST 4
#define       MC_CMD_AOE_IN_CPLD_READ_WIDTH_OFST 8

/* MC_CMD_AOE_IN_CPLD_WRITE msgrequest */
#define    MC_CMD_AOE_IN_CPLD_WRITE_LEN 16
/*            MC_CMD_AOE_IN_CMD_OFST 0 */
#define       MC_CMD_AOE_IN_CPLD_WRITE_REGISTER_OFST 4
#define       MC_CMD_AOE_IN_CPLD_WRITE_WIDTH_OFST 8
#define       MC_CMD_AOE_IN_CPLD_WRITE_VALUE_OFST 12

/* MC_CMD_AOE_IN_CPLD_INSTRUCTION msgrequest */
#define    MC_CMD_AOE_IN_CPLD_INSTRUCTION_LEN 8
/*            MC_CMD_AOE_IN_CMD_OFST 0 */
#define       MC_CMD_AOE_IN_CPLD_INSTRUCTION_INSTRUCTION_OFST 4

/* MC_CMD_AOE_IN_CPLD_REPROGRAM msgrequest */
#define    MC_CMD_AOE_IN_CPLD_REPROGRAM_LEN 8
/*            MC_CMD_AOE_IN_CMD_OFST 0 */
#define       MC_CMD_AOE_IN_CPLD_REPROGRAM_OP_OFST 4
/* enum: Reprogram CPLD, poll for completion */
#define          MC_CMD_AOE_IN_CPLD_REPROGRAM_REPROGRAM 0x1
/* enum: Reprogram CPLD, send event on completion */
#define          MC_CMD_AOE_IN_CPLD_REPROGRAM_REPROGRAM_EVENT 0x3
/* enum: Get status of reprogramming operation */
#define          MC_CMD_AOE_IN_CPLD_REPROGRAM_STATUS 0x4

/* MC_CMD_AOE_IN_POWER msgrequest */
#define    MC_CMD_AOE_IN_POWER_LEN 8
/*            MC_CMD_AOE_IN_CMD_OFST 0 */
/* Turn on or off AOE power */
#define       MC_CMD_AOE_IN_POWER_OP_OFST 4
/* enum: Turn off FPGA power */
#define          MC_CMD_AOE_IN_POWER_OFF  0x0
/* enum: Turn on FPGA power */
#define          MC_CMD_AOE_IN_POWER_ON  0x1
/* enum: Clear peak power measurement */
#define          MC_CMD_AOE_IN_POWER_CLEAR  0x2
/* enum: Show current power in sensors output */
#define          MC_CMD_AOE_IN_POWER_SHOW_CURRENT  0x3
/* enum: Show peak power in sensors output */
#define          MC_CMD_AOE_IN_POWER_SHOW_PEAK  0x4
/* enum: Show current DDR current */
#define          MC_CMD_AOE_IN_POWER_DDR_LAST  0x5
/* enum: Show peak DDR current */
#define          MC_CMD_AOE_IN_POWER_DDR_PEAK  0x6
/* enum: Clear peak DDR current */
#define          MC_CMD_AOE_IN_POWER_DDR_CLEAR  0x7

/* MC_CMD_AOE_IN_LOAD msgrequest */
#define    MC_CMD_AOE_IN_LOAD_LEN 8
/*            MC_CMD_AOE_IN_CMD_OFST 0 */
/* Image to be loaded (0 - main or 1 - diagnostic) to load in normal sequence
 */
#define       MC_CMD_AOE_IN_LOAD_IMAGE_OFST 4

/* MC_CMD_AOE_IN_FAN_CONTROL msgrequest */
#define    MC_CMD_AOE_IN_FAN_CONTROL_LEN 8
/*            MC_CMD_AOE_IN_CMD_OFST 0 */
/* If non zero report measured fan RPM rather than nominal */
#define       MC_CMD_AOE_IN_FAN_CONTROL_REAL_RPM_OFST 4

/* MC_CMD_AOE_IN_FAN_FAILURES msgrequest */
#define    MC_CMD_AOE_IN_FAN_FAILURES_LEN 4
/*            MC_CMD_AOE_IN_CMD_OFST 0 */

/* MC_CMD_AOE_IN_MAC_STATS msgrequest */
#define    MC_CMD_AOE_IN_MAC_STATS_LEN 24
/*            MC_CMD_AOE_IN_CMD_OFST 0 */
/* AOE port */
#define       MC_CMD_AOE_IN_MAC_STATS_PORT_OFST 4
/* Host memory address for statistics */
#define       MC_CMD_AOE_IN_MAC_STATS_DMA_ADDR_OFST 8
#define       MC_CMD_AOE_IN_MAC_STATS_DMA_ADDR_LEN 8
#define       MC_CMD_AOE_IN_MAC_STATS_DMA_ADDR_LO_OFST 8
#define       MC_CMD_AOE_IN_MAC_STATS_DMA_ADDR_HI_OFST 12
#define       MC_CMD_AOE_IN_MAC_STATS_CMD_OFST 16
#define        MC_CMD_AOE_IN_MAC_STATS_DMA_LBN 0
#define        MC_CMD_AOE_IN_MAC_STATS_DMA_WIDTH 1
#define        MC_CMD_AOE_IN_MAC_STATS_CLEAR_LBN 1
#define        MC_CMD_AOE_IN_MAC_STATS_CLEAR_WIDTH 1
#define        MC_CMD_AOE_IN_MAC_STATS_PERIODIC_CHANGE_LBN 2
#define        MC_CMD_AOE_IN_MAC_STATS_PERIODIC_CHANGE_WIDTH 1
#define        MC_CMD_AOE_IN_MAC_STATS_PERIODIC_ENABLE_LBN 3
#define        MC_CMD_AOE_IN_MAC_STATS_PERIODIC_ENABLE_WIDTH 1
#define        MC_CMD_AOE_IN_MAC_STATS_PERIODIC_CLEAR_LBN 4
#define        MC_CMD_AOE_IN_MAC_STATS_PERIODIC_CLEAR_WIDTH 1
#define        MC_CMD_AOE_IN_MAC_STATS_PERIODIC_NOEVENT_LBN 5
#define        MC_CMD_AOE_IN_MAC_STATS_PERIODIC_NOEVENT_WIDTH 1
#define        MC_CMD_AOE_IN_MAC_STATS_PERIOD_MS_LBN 16
#define        MC_CMD_AOE_IN_MAC_STATS_PERIOD_MS_WIDTH 16
/* Length of DMA data (optional) */
#define       MC_CMD_AOE_IN_MAC_STATS_DMA_LEN_OFST 20

/* MC_CMD_AOE_IN_GET_PHY_MEDIA_INFO msgrequest */
#define    MC_CMD_AOE_IN_GET_PHY_MEDIA_INFO_LEN 12
/*            MC_CMD_AOE_IN_CMD_OFST 0 */
/* AOE port */
#define       MC_CMD_AOE_IN_GET_PHY_MEDIA_INFO_PORT_OFST 4
#define       MC_CMD_AOE_IN_GET_PHY_MEDIA_INFO_PAGE_OFST 8

/* MC_CMD_AOE_IN_JTAG_WRITE msgrequest */
#define    MC_CMD_AOE_IN_JTAG_WRITE_LENMIN 12
#define    MC_CMD_AOE_IN_JTAG_WRITE_LENMAX 252
#define    MC_CMD_AOE_IN_JTAG_WRITE_LEN(num) (8+4*(num))
/*            MC_CMD_AOE_IN_CMD_OFST 0 */
#define       MC_CMD_AOE_IN_JTAG_WRITE_DATALEN_OFST 4
#define       MC_CMD_AOE_IN_JTAG_WRITE_DATA_OFST 8
#define       MC_CMD_AOE_IN_JTAG_WRITE_DATA_LEN 4
#define       MC_CMD_AOE_IN_JTAG_WRITE_DATA_MINNUM 1
#define       MC_CMD_AOE_IN_JTAG_WRITE_DATA_MAXNUM 61

/* MC_CMD_AOE_IN_FPGA_ACCESS msgrequest */
#define    MC_CMD_AOE_IN_FPGA_ACCESS_LEN 8
/*            MC_CMD_AOE_IN_CMD_OFST 0 */
/* Enable or disable access */
#define       MC_CMD_AOE_IN_FPGA_ACCESS_OP_OFST 4
/* enum: Enable access */
#define          MC_CMD_AOE_IN_FPGA_ACCESS_ENABLE 0x1
/* enum: Disable access */
#define          MC_CMD_AOE_IN_FPGA_ACCESS_DISABLE 0x2

/* MC_CMD_AOE_IN_SET_MTU_OFFSET msgrequest */
#define    MC_CMD_AOE_IN_SET_MTU_OFFSET_LEN 12
/*            MC_CMD_AOE_IN_CMD_OFST 0 */
/* AOE port - when not ALL_EXTERNAL or ALL_INTERNAL specifies port number */
#define       MC_CMD_AOE_IN_SET_MTU_OFFSET_PORT_OFST 4
/* enum: Apply to all external ports */
#define          MC_CMD_AOE_IN_SET_MTU_OFFSET_ALL_EXTERNAL 0x8000
/* enum: Apply to all internal ports */
#define          MC_CMD_AOE_IN_SET_MTU_OFFSET_ALL_INTERNAL 0x4000
/* The MTU offset to be applied to the external ports */
#define       MC_CMD_AOE_IN_SET_MTU_OFFSET_OFFSET_OFST 8

/* MC_CMD_AOE_IN_LINK_STATE msgrequest */
#define    MC_CMD_AOE_IN_LINK_STATE_LEN 8
/*            MC_CMD_AOE_IN_CMD_OFST 0 */
#define       MC_CMD_AOE_IN_LINK_STATE_MODE_OFST 4
#define        MC_CMD_AOE_IN_LINK_STATE_CONFIG_MODE_LBN 0
#define        MC_CMD_AOE_IN_LINK_STATE_CONFIG_MODE_WIDTH 8
/* enum: AOE and associated external port */
#define          MC_CMD_AOE_IN_LINK_STATE_SIMPLE_SEPARATE  0x0
/* enum: AOE and OR of all external ports */
#define          MC_CMD_AOE_IN_LINK_STATE_SIMPLE_COMBINED  0x1
/* enum: Individual ports */
#define          MC_CMD_AOE_IN_LINK_STATE_DIAGNOSTIC  0x2
/* enum: Configure link state mode on given AOE port */
#define          MC_CMD_AOE_IN_LINK_STATE_CUSTOM  0x3
#define        MC_CMD_AOE_IN_LINK_STATE_OPERATION_LBN 8
#define        MC_CMD_AOE_IN_LINK_STATE_OPERATION_WIDTH 8
/* enum: No-op */
#define          MC_CMD_AOE_IN_LINK_STATE_OP_NONE  0x0
/* enum: logical OR of all SFP ports link status */
#define          MC_CMD_AOE_IN_LINK_STATE_OP_OR  0x1
/* enum: logical AND of all SFP ports link status */
#define          MC_CMD_AOE_IN_LINK_STATE_OP_AND  0x2
#define        MC_CMD_AOE_IN_LINK_STATE_SFP_MASK_LBN 16
#define        MC_CMD_AOE_IN_LINK_STATE_SFP_MASK_WIDTH 16

/* MC_CMD_AOE_IN_SIENA_STATS msgrequest */
#define    MC_CMD_AOE_IN_SIENA_STATS_LEN 8
/*            MC_CMD_AOE_IN_CMD_OFST 0 */
/* How MAC statistics are reported */
#define       MC_CMD_AOE_IN_SIENA_STATS_MODE_OFST 4
/* enum: Statistics from Siena (default) */
#define          MC_CMD_AOE_IN_SIENA_STATS_STATS_SIENA  0x0
/* enum: Statistics from AOE external ports */
#define          MC_CMD_AOE_IN_SIENA_STATS_STATS_AOE  0x1

/* MC_CMD_AOE_IN_DDR msgrequest */
#define    MC_CMD_AOE_IN_DDR_LEN 12
/*            MC_CMD_AOE_IN_CMD_OFST 0 */
#define       MC_CMD_AOE_IN_DDR_BANK_OFST 4
/*            Enum values, see field(s): */
/*               MC_CMD_FC/MC_CMD_FC_IN_DDR/MC_CMD_FC_IN_DDR_BANK */
/* Page index of SPD data */
#define       MC_CMD_AOE_IN_DDR_SPD_PAGE_ID_OFST 8

/* MC_CMD_AOE_IN_FC msgrequest */
#define    MC_CMD_AOE_IN_FC_LEN 4
/*            MC_CMD_AOE_IN_CMD_OFST 0 */

/* MC_CMD_AOE_IN_DDR_ECC_STATUS msgrequest */
#define    MC_CMD_AOE_IN_DDR_ECC_STATUS_LEN 8
/*            MC_CMD_AOE_IN_CMD_OFST 0 */
#define       MC_CMD_AOE_IN_DDR_ECC_STATUS_BANK_OFST 4
/*            Enum values, see field(s): */
/*               MC_CMD_FC/MC_CMD_FC_IN_DDR/MC_CMD_FC_IN_DDR_BANK */

/* MC_CMD_AOE_OUT_INFO msgresponse */
#define    MC_CMD_AOE_OUT_INFO_LEN 44
/* JTAG IDCODE of CPLD */
#define       MC_CMD_AOE_OUT_INFO_CPLD_IDCODE_OFST 0
/* Version of CPLD */
#define       MC_CMD_AOE_OUT_INFO_CPLD_VERSION_OFST 4
/* JTAG IDCODE of FPGA */
#define       MC_CMD_AOE_OUT_INFO_FPGA_IDCODE_OFST 8
/* JTAG USERCODE of FPGA */
#define       MC_CMD_AOE_OUT_INFO_FPGA_VERSION_OFST 12
/* FPGA type - read from CPLD straps */
#define       MC_CMD_AOE_OUT_INFO_FPGA_TYPE_OFST 16
/* FPGA state (debug) */
#define       MC_CMD_AOE_OUT_INFO_FPGA_STATE_OFST 20
/* FPGA image - partition from which loaded */
#define       MC_CMD_AOE_OUT_INFO_FPGA_IMAGE_OFST 24
/* FC state */
#define       MC_CMD_AOE_OUT_INFO_FC_STATE_OFST 28
/* enum: Set if watchdog working */
#define          MC_CMD_AOE_OUT_INFO_WATCHDOG 0x1
/* enum: Set if MC-FC communications working */
#define          MC_CMD_AOE_OUT_INFO_COMMS 0x2
/* Random pieces of information */
#define       MC_CMD_AOE_OUT_INFO_FLAGS_OFST 32
/* enum: Power to FPGA supplied by PEG connector, not PCIe bus */
#define          MC_CMD_AOE_OUT_INFO_PEG_POWER 0x1
/* enum: CPLD apparently good */
#define          MC_CMD_AOE_OUT_INFO_CPLD_GOOD 0x2
/* enum: FPGA working normally */
#define          MC_CMD_AOE_OUT_INFO_FPGA_GOOD 0x4
/* enum: FPGA is powered */
#define          MC_CMD_AOE_OUT_INFO_FPGA_POWER 0x8
/* enum: Board has incompatible SODIMMs fitted */
#define          MC_CMD_AOE_OUT_INFO_BAD_SODIMM 0x10
/* enum: Board has ByteBlaster connected */
#define          MC_CMD_AOE_OUT_INFO_HAS_BYTEBLASTER 0x20
/* Revision of Modena board */
#define       MC_CMD_AOE_OUT_INFO_BOARD_REVISION_OFST 36
#define          MC_CMD_AOE_OUT_INFO_UNKNOWN  0x0 /* enum */
#define          MC_CMD_AOE_OUT_INFO_R1_0  0x10 /* enum */
#define          MC_CMD_AOE_OUT_INFO_R1_1  0x11 /* enum */
#define          MC_CMD_AOE_OUT_INFO_R1_2  0x12 /* enum */
/* Result of FC booting - not valid while a ByteBlaster is connected. */
#define       MC_CMD_AOE_OUT_INFO_FC_BOOT_RESULT_OFST 40
/* enum: No error */
#define          MC_CMD_AOE_OUT_INFO_FC_BOOT_FAIL_NO_ERROR 0x0
/* enum: Bad address set in CPLD */
#define          MC_CMD_AOE_OUT_INFO_FC_BOOT_FAIL_BAD_ADDRESS 0x1
/* enum: Bad header */
#define          MC_CMD_AOE_OUT_INFO_FC_BOOT_FAIL_BAD_MAGIC 0x2
/* enum: Bad text section details */
#define          MC_CMD_AOE_OUT_INFO_FC_BOOT_FAIL_BAD_TEXT 0x3
/* enum: Bad checksum */
#define          MC_CMD_AOE_OUT_INFO_FC_BOOT_FAIL_BAD_CHECKSUM 0x4
/* enum: Bad BSP */
#define          MC_CMD_AOE_OUT_INFO_FC_BOOT_FAIL_BAD_BSP 0x5
/* enum: FC application loaded and execution attempted */
#define          MC_CMD_AOE_OUT_INFO_FC_BOOT_APP_EXECUTE 0x80
/* enum: No bootrom in FPGA */
#define          MC_CMD_AOE_OUT_INFO_FC_BOOT_NO_BOOTROM 0xff

/* MC_CMD_AOE_OUT_CURRENTS msgresponse */
#define    MC_CMD_AOE_OUT_CURRENTS_LEN 68
/* Set of currents and voltages (mA or mV as appropriate) */
#define       MC_CMD_AOE_OUT_CURRENTS_VALUES_OFST 0
#define       MC_CMD_AOE_OUT_CURRENTS_VALUES_LEN 4
#define       MC_CMD_AOE_OUT_CURRENTS_VALUES_NUM 17
#define          MC_CMD_AOE_OUT_CURRENTS_I_2V5 0x0 /* enum */
#define          MC_CMD_AOE_OUT_CURRENTS_I_1V8 0x1 /* enum */
#define          MC_CMD_AOE_OUT_CURRENTS_I_GXB 0x2 /* enum */
#define          MC_CMD_AOE_OUT_CURRENTS_I_PGM 0x3 /* enum */
#define          MC_CMD_AOE_OUT_CURRENTS_I_XCVR 0x4 /* enum */
#define          MC_CMD_AOE_OUT_CURRENTS_I_1V5 0x5 /* enum */
#define          MC_CMD_AOE_OUT_CURRENTS_V_3V3 0x6 /* enum */
#define          MC_CMD_AOE_OUT_CURRENTS_V_1V5 0x7 /* enum */
#define          MC_CMD_AOE_OUT_CURRENTS_I_IN 0x8 /* enum */
#define          MC_CMD_AOE_OUT_CURRENTS_I_OUT 0x9 /* enum */
#define          MC_CMD_AOE_OUT_CURRENTS_V_IN 0xa /* enum */
#define          MC_CMD_AOE_OUT_CURRENTS_I_OUT_DDR1 0xb /* enum */
#define          MC_CMD_AOE_OUT_CURRENTS_V_OUT_DDR1 0xc /* enum */
#define          MC_CMD_AOE_OUT_CURRENTS_I_OUT_DDR2 0xd /* enum */
#define          MC_CMD_AOE_OUT_CURRENTS_V_OUT_DDR2 0xe /* enum */
#define          MC_CMD_AOE_OUT_CURRENTS_I_OUT_DDR3 0xf /* enum */
#define          MC_CMD_AOE_OUT_CURRENTS_V_OUT_DDR3 0x10 /* enum */

/* MC_CMD_AOE_OUT_TEMPERATURES msgresponse */
#define    MC_CMD_AOE_OUT_TEMPERATURES_LEN 40
/* Set of temperatures */
#define       MC_CMD_AOE_OUT_TEMPERATURES_VALUES_OFST 0
#define       MC_CMD_AOE_OUT_TEMPERATURES_VALUES_LEN 4
#define       MC_CMD_AOE_OUT_TEMPERATURES_VALUES_NUM 10
#define          MC_CMD_AOE_OUT_TEMPERATURES_MAIN_0 0x0 /* enum */
#define          MC_CMD_AOE_OUT_TEMPERATURES_MAIN_1 0x1 /* enum */
#define          MC_CMD_AOE_OUT_TEMPERATURES_IND_0 0x2 /* enum */
#define          MC_CMD_AOE_OUT_TEMPERATURES_IND_1 0x3 /* enum */
#define          MC_CMD_AOE_OUT_TEMPERATURES_VCCIO1 0x4 /* enum */
#define          MC_CMD_AOE_OUT_TEMPERATURES_VCCIO2 0x5 /* enum */
#define          MC_CMD_AOE_OUT_TEMPERATURES_VCCIO3 0x6 /* enum */
#define          MC_CMD_AOE_OUT_TEMPERATURES_PSU 0x7 /* enum */
#define          MC_CMD_AOE_OUT_TEMPERATURES_FPGA 0x8 /* enum */
#define          MC_CMD_AOE_OUT_TEMPERATURES_SIENA 0x9 /* enum */

/* MC_CMD_AOE_OUT_CPLD_READ msgresponse */
#define    MC_CMD_AOE_OUT_CPLD_READ_LEN 4
/* The value read from the CPLD */
#define       MC_CMD_AOE_OUT_CPLD_READ_VALUE_OFST 0

/* MC_CMD_AOE_OUT_FAN_FAILURES msgresponse */
#define    MC_CMD_AOE_OUT_FAN_FAILURES_LENMIN 4
#define    MC_CMD_AOE_OUT_FAN_FAILURES_LENMAX 252
#define    MC_CMD_AOE_OUT_FAN_FAILURES_LEN(num) (0+4*(num))
/* Failure counts for each fan */
#define       MC_CMD_AOE_OUT_FAN_FAILURES_COUNT_OFST 0
#define       MC_CMD_AOE_OUT_FAN_FAILURES_COUNT_LEN 4
#define       MC_CMD_AOE_OUT_FAN_FAILURES_COUNT_MINNUM 1
#define       MC_CMD_AOE_OUT_FAN_FAILURES_COUNT_MAXNUM 63

/* MC_CMD_AOE_OUT_CPLD_REPROGRAM msgresponse */
#define    MC_CMD_AOE_OUT_CPLD_REPROGRAM_LEN 4
/* Results of status command (only) */
#define       MC_CMD_AOE_OUT_CPLD_REPROGRAM_STATUS_OFST 0

/* MC_CMD_AOE_OUT_MAC_STATS_DMA msgresponse */
#define    MC_CMD_AOE_OUT_MAC_STATS_DMA_LEN 0

/* MC_CMD_AOE_OUT_MAC_STATS_NO_DMA msgresponse: See MC_CMD_MAC_STATS_OUT_NO_DMA
 * for details
 */
#define    MC_CMD_AOE_OUT_MAC_STATS_NO_DMA_LEN (((MC_CMD_MAC_NSTATS*64))>>3)
#define       MC_CMD_AOE_OUT_MAC_STATS_NO_DMA_STATISTICS_OFST 0
#define       MC_CMD_AOE_OUT_MAC_STATS_NO_DMA_STATISTICS_LEN 8
#define       MC_CMD_AOE_OUT_MAC_STATS_NO_DMA_STATISTICS_LO_OFST 0
#define       MC_CMD_AOE_OUT_MAC_STATS_NO_DMA_STATISTICS_HI_OFST 4
#define       MC_CMD_AOE_OUT_MAC_STATS_NO_DMA_STATISTICS_NUM MC_CMD_MAC_NSTATS

/* MC_CMD_AOE_OUT_GET_PHY_MEDIA_INFO msgresponse */
#define    MC_CMD_AOE_OUT_GET_PHY_MEDIA_INFO_LENMIN 5
#define    MC_CMD_AOE_OUT_GET_PHY_MEDIA_INFO_LENMAX 252
#define    MC_CMD_AOE_OUT_GET_PHY_MEDIA_INFO_LEN(num) (4+1*(num))
/* in bytes */
#define       MC_CMD_AOE_OUT_GET_PHY_MEDIA_INFO_DATALEN_OFST 0
#define       MC_CMD_AOE_OUT_GET_PHY_MEDIA_INFO_DATA_OFST 4
#define       MC_CMD_AOE_OUT_GET_PHY_MEDIA_INFO_DATA_LEN 1
#define       MC_CMD_AOE_OUT_GET_PHY_MEDIA_INFO_DATA_MINNUM 1
#define       MC_CMD_AOE_OUT_GET_PHY_MEDIA_INFO_DATA_MAXNUM 248

/* MC_CMD_AOE_OUT_JTAG_WRITE msgresponse */
#define    MC_CMD_AOE_OUT_JTAG_WRITE_LENMIN 12
#define    MC_CMD_AOE_OUT_JTAG_WRITE_LENMAX 252
#define    MC_CMD_AOE_OUT_JTAG_WRITE_LEN(num) (8+4*(num))
/* Used to align the in and out data blocks so the MC can re-use the cmd */
#define       MC_CMD_AOE_OUT_JTAG_WRITE_DATALEN_OFST 0
/* out bytes */
#define       MC_CMD_AOE_OUT_JTAG_WRITE_PAD_OFST 4
#define       MC_CMD_AOE_OUT_JTAG_WRITE_DATA_OFST 8
#define       MC_CMD_AOE_OUT_JTAG_WRITE_DATA_LEN 4
#define       MC_CMD_AOE_OUT_JTAG_WRITE_DATA_MINNUM 1
#define       MC_CMD_AOE_OUT_JTAG_WRITE_DATA_MAXNUM 61

/* MC_CMD_AOE_OUT_FPGA_ACCESS msgresponse */
#define    MC_CMD_AOE_OUT_FPGA_ACCESS_LEN 0

/* MC_CMD_AOE_OUT_DDR msgresponse */
#define    MC_CMD_AOE_OUT_DDR_LENMIN 17
#define    MC_CMD_AOE_OUT_DDR_LENMAX 252
#define    MC_CMD_AOE_OUT_DDR_LEN(num) (16+1*(num))
/* Information on the module. */
#define       MC_CMD_AOE_OUT_DDR_FLAGS_OFST 0
#define        MC_CMD_AOE_OUT_DDR_PRESENT_LBN 0
#define        MC_CMD_AOE_OUT_DDR_PRESENT_WIDTH 1
#define        MC_CMD_AOE_OUT_DDR_POWERED_LBN 1
#define        MC_CMD_AOE_OUT_DDR_POWERED_WIDTH 1
#define        MC_CMD_AOE_OUT_DDR_OPERATIONAL_LBN 2
#define        MC_CMD_AOE_OUT_DDR_OPERATIONAL_WIDTH 1
/* Memory size, in MB. */
#define       MC_CMD_AOE_OUT_DDR_CAPACITY_OFST 4
/* The memory type, as reported from SPD information */
#define       MC_CMD_AOE_OUT_DDR_TYPE_OFST 8
/* Nominal voltage of the module (as applied) */
#define       MC_CMD_AOE_OUT_DDR_VOLTAGE_OFST 12
/* SPD data read from the module */
#define       MC_CMD_AOE_OUT_DDR_SPD_OFST 16
#define       MC_CMD_AOE_OUT_DDR_SPD_LEN 1
#define       MC_CMD_AOE_OUT_DDR_SPD_MINNUM 1
#define       MC_CMD_AOE_OUT_DDR_SPD_MAXNUM 236

/* MC_CMD_AOE_OUT_LINK_STATE msgresponse */
#define    MC_CMD_AOE_OUT_LINK_STATE_LEN 0

/* MC_CMD_AOE_OUT_FC msgresponse */
#define    MC_CMD_AOE_OUT_FC_LEN 0

/* MC_CMD_AOE_OUT_DDR_ECC_STATUS msgresponse */
#define    MC_CMD_AOE_OUT_DDR_ECC_STATUS_LEN 8
/* Flags describing status info on the module. */
#define       MC_CMD_AOE_OUT_DDR_ECC_STATUS_FLAGS_OFST 0
#define        MC_CMD_AOE_OUT_DDR_ECC_STATUS_VALID_LBN 0
#define        MC_CMD_AOE_OUT_DDR_ECC_STATUS_VALID_WIDTH 1
/* DDR ECC status on the module. */
#define       MC_CMD_AOE_OUT_DDR_ECC_STATUS_STATUS_OFST 4
#define        MC_CMD_AOE_OUT_DDR_ECC_STATUS_SBE_LBN 0
#define        MC_CMD_AOE_OUT_DDR_ECC_STATUS_SBE_WIDTH 1
#define        MC_CMD_AOE_OUT_DDR_ECC_STATUS_DBE_LBN 1
#define        MC_CMD_AOE_OUT_DDR_ECC_STATUS_DBE_WIDTH 1
#define        MC_CMD_AOE_OUT_DDR_ECC_STATUS_CORDROP_LBN 2
#define        MC_CMD_AOE_OUT_DDR_ECC_STATUS_CORDROP_WIDTH 1
#define        MC_CMD_AOE_OUT_DDR_ECC_STATUS_SBE_COUNT_LBN 8
#define        MC_CMD_AOE_OUT_DDR_ECC_STATUS_SBE_COUNT_WIDTH 8
#define        MC_CMD_AOE_OUT_DDR_ECC_STATUS_DBE_COUNT_LBN 16
#define        MC_CMD_AOE_OUT_DDR_ECC_STATUS_DBE_COUNT_WIDTH 8
#define        MC_CMD_AOE_OUT_DDR_ECC_STATUS_CORDROP_COUNT_LBN 24
#define        MC_CMD_AOE_OUT_DDR_ECC_STATUS_CORDROP_COUNT_WIDTH 8