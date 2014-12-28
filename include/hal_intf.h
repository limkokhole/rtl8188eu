/******************************************************************************
 *
 * Copyright(c) 2007 - 2012 Realtek Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
 *
 *
 ******************************************************************************/
#ifndef __HAL_INTF_H__
#define __HAL_INTF_H__

#include <drv_conf.h>
#include <osdep_service.h>
#include <drv_types.h>

enum RTL871X_HCI_TYPE {
	RTW_PCIE	= BIT0,
	RTW_USB		= BIT1,
	RTW_SDIO	= BIT2,
	RTW_GSPI	= BIT3,
};

enum _CHIP_TYPE {
	NULL_CHIP_TYPE,
	RTL8712_8188S_8191S_8192S,
	RTL8188C_8192C,
	RTL8192D,
	RTL8723A,
	RTL8188E,
	MAX_CHIP_TYPE
};


typedef enum _HW_VARIABLES{
	HW_VAR_MEDIA_STATUS,
	HW_VAR_MEDIA_STATUS1,
	HW_VAR_SET_OPMODE,
	HW_VAR_MAC_ADDR,
	HW_VAR_BSSID,
	HW_VAR_INIT_RTS_RATE,
	HW_VAR_BASIC_RATE,
	HW_VAR_TXPAUSE,
	HW_VAR_BCN_FUNC,
	HW_VAR_CORRECT_TSF,
	HW_VAR_CHECK_BSSID,
	HW_VAR_MLME_DISCONNECT,
	HW_VAR_MLME_SITESURVEY,
	HW_VAR_MLME_JOIN,
	HW_VAR_ON_RCR_AM,
       HW_VAR_OFF_RCR_AM,
	HW_VAR_BEACON_INTERVAL,
	HW_VAR_SLOT_TIME,
	HW_VAR_RESP_SIFS,
	HW_VAR_ACK_PREAMBLE,
	HW_VAR_SEC_CFG,
	HW_VAR_BCN_VALID,
	HW_VAR_RF_TYPE,
	HW_VAR_DM_FLAG,
	HW_VAR_DM_FUNC_OP,
	HW_VAR_DM_FUNC_SET,
	HW_VAR_DM_FUNC_CLR,
	HW_VAR_CAM_EMPTY_ENTRY,
	HW_VAR_CAM_INVALID_ALL,
	HW_VAR_CAM_WRITE,
	HW_VAR_CAM_READ,
	HW_VAR_AC_PARAM_VO,
	HW_VAR_AC_PARAM_VI,
	HW_VAR_AC_PARAM_BE,
	HW_VAR_AC_PARAM_BK,
	HW_VAR_ACM_CTRL,
	HW_VAR_AMPDU_MIN_SPACE,
	HW_VAR_AMPDU_FACTOR,
	HW_VAR_RXDMA_AGG_PG_TH,
	HW_VAR_SET_RPWM,
	HW_VAR_GET_CPWM,
	HW_VAR_H2C_FW_PWRMODE,
	HW_VAR_H2C_FW_JOINBSSRPT,
	HW_VAR_FWLPS_RF_ON,
	HW_VAR_H2C_FW_P2P_PS_OFFLOAD,
	HW_VAR_TDLS_WRCR,
	HW_VAR_TDLS_INIT_CH_SEN,
	HW_VAR_TDLS_RS_RCR,
	HW_VAR_TDLS_DONE_CH_SEN,
	HW_VAR_INITIAL_GAIN,
	HW_VAR_TRIGGER_GPIO_0,
	HW_VAR_BT_SET_COEXIST,
	HW_VAR_BT_ISSUE_DELBA,
	HW_VAR_CURRENT_ANTENNA,
	HW_VAR_ANTENNA_DIVERSITY_LINK,
	HW_VAR_ANTENNA_DIVERSITY_SELECT,
	HW_VAR_SWITCH_EPHY_WoWLAN,
	HW_VAR_EFUSE_USAGE,
	HW_VAR_EFUSE_BYTES,
	HW_VAR_EFUSE_BT_USAGE,
	HW_VAR_EFUSE_BT_BYTES,
	HW_VAR_FIFO_CLEARN_UP,
	HW_VAR_CHECK_TXBUF,
	HW_VAR_APFM_ON_MAC, //Auto FSM to Turn On, include clock, isolation, power control for MAC only
	// The valid upper nav range for the HW updating, if the true value is larger than the upper range, the HW won't update it.
	// Unit in microsecond. 0 means disable this function.
#ifdef CONFIG_WOWLAN
	HW_VAR_WOWLAN,
#endif
	HW_VAR_SYS_CLKR,
	HW_VAR_NAV_UPPER,
	HW_VAR_RPT_TIMER_SETTING,
	HW_VAR_TX_RPT_MAX_MACID,
	HW_VAR_H2C_MEDIA_STATUS_RPT,
	HW_VAR_CHK_HI_QUEUE_EMPTY,
	HW_VAR_READ_LLT_TAB,
	HW_VAR_C2HEVT_CLEAR,
	HW_VAR_C2HEVT_MSG_NORMAL,
}HW_VARIABLES;

typedef enum _HAL_DEF_VARIABLE{
	HAL_DEF_UNDERCORATEDSMOOTHEDPWDB,
	HAL_DEF_IS_SUPPORT_ANT_DIV,
	HAL_DEF_CURRENT_ANTENNA,
	HAL_DEF_DRVINFO_SZ,
	HAL_DEF_MAX_RECVBUF_SZ,
	HAL_DEF_RX_PACKET_OFFSET,
	HAL_DEF_DBG_DUMP_RXPKT,//for dbg
	HAL_DEF_DBG_DM_FUNC,//for dbg
	HAL_DEF_RA_DECISION_RATE,
	HAL_DEF_RA_SGI,
	HAL_DEF_PT_PWR_STATUS,
	HW_VAR_MAX_RX_AMPDU_FACTOR,
	HW_DEF_RA_INFO_DUMP,
	HAL_DEF_DBG_DUMP_TXPKT,
	HW_DEF_FA_CNT_DUMP,
	HW_DEF_ODM_DBG_FLAG,
	HW_DEF_ODM_DBG_LEVEL,
}HAL_DEF_VARIABLE;

typedef enum _HAL_ODM_VARIABLE{
	HAL_ODM_STA_INFO,
	HAL_ODM_P2P_STATE,
	HAL_ODM_WIFI_DISPLAY_STATE,
}HAL_ODM_VARIABLE;

typedef enum _HAL_INTF_PS_FUNC{
	HAL_USB_SELECT_SUSPEND,
	HAL_MAX_ID,
}HAL_INTF_PS_FUNC;

typedef s32 (*c2h_id_filter)(u8 id);

struct hal_ops {
	u32	(*hal_power_on)(struct adapter *padapter);
	void	(*hal_power_off)(struct adapter *padapter);
	u32	(*hal_init)(struct adapter *padapter);
	u32	(*hal_deinit)(struct adapter *padapter);

	void	(*free_hal_data)(struct adapter *padapter);

	u32	(*inirp_init)(struct adapter *padapter);
	u32	(*inirp_deinit)(struct adapter *padapter);

	s32	(*init_xmit_priv)(struct adapter *padapter);
	void	(*free_xmit_priv)(struct adapter *padapter);

	s32	(*init_recv_priv)(struct adapter *padapter);
	void	(*free_recv_priv)(struct adapter *padapter);

	void	(*InitSwLeds)(struct adapter *padapter);
	void	(*DeInitSwLeds)(struct adapter *padapter);

	void	(*dm_init)(struct adapter *padapter);
	void	(*dm_deinit)(struct adapter *padapter);
	void	(*read_chip_version)(struct adapter *padapter);

	void	(*init_default_value)(struct adapter *padapter);

	void	(*intf_chip_configure)(struct adapter *padapter);

	void	(*read_adapter_info)(struct adapter *padapter);

	void	(*enable_interrupt)(struct adapter *padapter);
	void	(*disable_interrupt)(struct adapter *padapter);
	s32	(*interrupt_handler)(struct adapter *padapter);
#ifdef CONFIG_WOWLAN
    void    (*clear_interrupt)(struct adapter *padapter);
#endif
	void	(*set_bwmode_handler)(struct adapter *padapter, HT_CHANNEL_WIDTH Bandwidth, u8 Offset);
	void	(*set_channel_handler)(struct adapter *padapter, u8 channel);

	void	(*hal_dm_watchdog)(struct adapter *padapter);

	void	(*SetHwRegHandler)(struct adapter *padapter, u8	variable,u8* val);
	void	(*GetHwRegHandler)(struct adapter *padapter, u8	variable,u8* val);

	u8	(*GetHalDefVarHandler)(struct adapter *padapter, HAL_DEF_VARIABLE eVariable, PVOID pValue);
	u8	(*SetHalDefVarHandler)(struct adapter *padapter, HAL_DEF_VARIABLE eVariable, PVOID pValue);

	void	(*GetHalODMVarHandler)(struct adapter *padapter, HAL_ODM_VARIABLE eVariable, PVOID pValue1,BOOLEAN bSet);
	void	(*SetHalODMVarHandler)(struct adapter *padapter, HAL_ODM_VARIABLE eVariable, PVOID pValue1,BOOLEAN bSet);

	void	(*UpdateRAMaskHandler)(struct adapter *padapter, u32 mac_id, u8 rssi_level);
	void	(*SetBeaconRelatedRegistersHandler)(struct adapter *padapter);

	void	(*Add_RateATid)(struct adapter *padapter, u32 bitmap, u8 arg, u8 rssi_level);

	void	(*run_thread)(struct adapter *padapter);
	void	(*cancel_thread)(struct adapter *padapter);

#ifdef CONFIG_ANTENNA_DIVERSITY
	u8	(*AntDivBeforeLinkHandler)(struct adapter *padapter);
	void	(*AntDivCompareHandler)(struct adapter *padapter, WLAN_BSSID_EX *dst, WLAN_BSSID_EX *src);
#endif
	u8	(*interface_ps_func)(struct adapter *padapter,HAL_INTF_PS_FUNC efunc_id, u8* val);

	s32	(*hal_xmit)(struct adapter *padapter, struct xmit_frame *pxmitframe);
	s32 (*mgnt_xmit)(struct adapter *padapter, struct xmit_frame *pmgntframe);
	s32	(*hal_xmitframe_enqueue)(struct adapter *padapter, struct xmit_frame *pxmitframe);

	u32	(*read_bbreg)(struct adapter *padapter, u32 RegAddr, u32 BitMask);
	void	(*write_bbreg)(struct adapter *padapter, u32 RegAddr, u32 BitMask, u32 Data);
	u32	(*read_rfreg)(struct adapter *padapter, u32 eRFPath, u32 RegAddr, u32 BitMask);
	void	(*write_rfreg)(struct adapter *padapter, u32 eRFPath, u32 RegAddr, u32 BitMask, u32 Data);

#ifdef CONFIG_HOSTAPD_MLME
	s32	(*hostap_mgnt_xmit_entry)(struct adapter *padapter, _pkt *pkt);
#endif

	void (*EfusePowerSwitch)(struct adapter *padapter, u8 bWrite, u8 PwrState);
	void (*ReadEFuse)(struct adapter *padapter, u8 efuseType, u16 _offset, u16 _size_byte, u8 *pbuf, BOOLEAN bPseudoTest);
	void (*EFUSEGetEfuseDefinition)(struct adapter *padapter, u8 efuseType, u8 type, void *pOut, BOOLEAN bPseudoTest);
	u16	(*EfuseGetCurrentSize)(struct adapter *padapter, u8 efuseType, BOOLEAN bPseudoTest);
	int	(*Efuse_PgPacketRead)(struct adapter *padapter, u8 offset, u8 *data, BOOLEAN bPseudoTest);
	int	(*Efuse_PgPacketWrite)(struct adapter *padapter, u8 offset, u8 word_en, u8 *data, BOOLEAN bPseudoTest);
	u8	(*Efuse_WordEnableDataWrite)(struct adapter *padapter, u16 efuse_addr, u8 word_en, u8 *data, BOOLEAN bPseudoTest);
	BOOLEAN	(*Efuse_PgPacketWrite_BT)(struct adapter *padapter, u8 offset, u8 word_en, u8 *data, BOOLEAN bPseudoTest);

#ifdef DBG_CONFIG_ERROR_DETECT
	void (*sreset_init_value)(struct adapter *padapter);
	void (*sreset_reset_value)(struct adapter *padapter);
	void (*silentreset)(struct adapter *padapter);
	void (*sreset_xmit_status_check)(struct adapter *padapter);
	void (*sreset_linked_status_check) (struct adapter *padapter);
	u8 (*sreset_get_wifi_status)(struct adapter *padapter);
	bool (*sreset_inprogress)(struct adapter *padapter);
#endif

#ifdef CONFIG_IOL
	int (*IOL_exec_cmds_sync)(struct adapter *padapter, struct xmit_frame *xmit_frame, u32 max_wating_ms, u32 bndy_cnt);
#endif

#ifdef CONFIG_XMIT_THREAD_MODE
	s32 (*xmit_thread_handler)(struct adapter *padapter);
#endif
	void (*hal_notch_filter)(struct adapter * adapter, bool enable);
	void (*hal_reset_security_engine)(struct adapter * adapter);
	s32 (*c2h_handler)(struct adapter *padapter, struct c2h_evt_hdr *c2h_evt);
	c2h_id_filter c2h_id_filter_ccx;
#if defined(CONFIG_CHECK_BT_HANG) && defined(CONFIG_BT_COEXIST)
	void (*hal_init_checkbthang_workqueue)(struct adapter * padapter);
	void (*hal_free_checkbthang_workqueue)(struct adapter * padapter);
	void (*hal_cancel_checkbthang_workqueue)(struct adapter * padapter);
	void (*hal_checke_bt_hang)(struct adapter * padapter);
#endif
};

typedef	enum _RT_EEPROM_TYPE{
	EEPROM_93C46,
	EEPROM_93C56,
	EEPROM_BOOT_EFUSE,
}RT_EEPROM_TYPE,*PRT_EEPROM_TYPE;



#define RF_CHANGE_BY_INIT	0
#define RF_CHANGE_BY_IPS	BIT28
#define RF_CHANGE_BY_PS		BIT29
#define RF_CHANGE_BY_HW		BIT30
#define RF_CHANGE_BY_SW		BIT31

typedef enum _HARDWARE_TYPE{
	HARDWARE_TYPE_RTL8180,
	HARDWARE_TYPE_RTL8185,
	HARDWARE_TYPE_RTL8187,
	HARDWARE_TYPE_RTL8188,
	HARDWARE_TYPE_RTL8190P,
	HARDWARE_TYPE_RTL8192E,
	HARDWARE_TYPE_RTL819xU,
	HARDWARE_TYPE_RTL8192SE,
	HARDWARE_TYPE_RTL8192SU,
	HARDWARE_TYPE_RTL8192CE,
	HARDWARE_TYPE_RTL8192CU,
	HARDWARE_TYPE_RTL8192DE,
	HARDWARE_TYPE_RTL8192DU,
	HARDWARE_TYPE_RTL8723AE,
	HARDWARE_TYPE_RTL8723AU,
	HARDWARE_TYPE_RTL8723AS,
	HARDWARE_TYPE_RTL8188EE,
	HARDWARE_TYPE_RTL8188EU,
	HARDWARE_TYPE_RTL8188ES,
	HARDWARE_TYPE_MAX,
}HARDWARE_TYPE;

//
// RTL8192C Series
//
#define IS_HARDWARE_TYPE_8192CE(_Adapter)	(((struct adapter *)_Adapter)->HardwareType==HARDWARE_TYPE_RTL8192CE)
#define IS_HARDWARE_TYPE_8192CU(_Adapter)	(((struct adapter *)_Adapter)->HardwareType==HARDWARE_TYPE_RTL8192CU)
#define	IS_HARDWARE_TYPE_8192C(_Adapter)			\
(IS_HARDWARE_TYPE_8192CE(_Adapter) || IS_HARDWARE_TYPE_8192CU(_Adapter))

//
// RTL8192D Series
//
#define IS_HARDWARE_TYPE_8192DE(_Adapter)	(((struct adapter *)_Adapter)->HardwareType==HARDWARE_TYPE_RTL8192DE)
#define IS_HARDWARE_TYPE_8192DU(_Adapter)	(((struct adapter *)_Adapter)->HardwareType==HARDWARE_TYPE_RTL8192DU)
#define	IS_HARDWARE_TYPE_8192D(_Adapter)			\
(IS_HARDWARE_TYPE_8192DE(_Adapter) || IS_HARDWARE_TYPE_8192DU(_Adapter))

//
// RTL8723A Series
//
#define IS_HARDWARE_TYPE_8723AE(_Adapter)	(((struct adapter *)_Adapter)->HardwareType==HARDWARE_TYPE_RTL8723AE)
#define IS_HARDWARE_TYPE_8723AU(_Adapter)	(((struct adapter *)_Adapter)->HardwareType==HARDWARE_TYPE_RTL8723AU)
#define IS_HARDWARE_TYPE_8723AS(_Adapter)	(((struct adapter *)_Adapter)->HardwareType==HARDWARE_TYPE_RTL8723AS)
#define	IS_HARDWARE_TYPE_8723A(_Adapter)	\
(IS_HARDWARE_TYPE_8723AE(_Adapter) || IS_HARDWARE_TYPE_8723AU(_Adapter) || IS_HARDWARE_TYPE_8723AS(_Adapter))

//
// RTL8188E Series
//
#define IS_HARDWARE_TYPE_8188EE(_Adapter)	(((struct adapter *)_Adapter)->HardwareType==HARDWARE_TYPE_RTL8188EE)
#define IS_HARDWARE_TYPE_8188EU(_Adapter)	(((struct adapter *)_Adapter)->HardwareType==HARDWARE_TYPE_RTL8188EU)
#define IS_HARDWARE_TYPE_8188ES(_Adapter)	(((struct adapter *)_Adapter)->HardwareType==HARDWARE_TYPE_RTL8188ES)
#define	IS_HARDWARE_TYPE_8188E(_Adapter)	\
(IS_HARDWARE_TYPE_8188EE(_Adapter) || IS_HARDWARE_TYPE_8188EU(_Adapter) || IS_HARDWARE_TYPE_8188ES(_Adapter))


typedef struct eeprom_priv EEPROM_EFUSE_PRIV, *PEEPROM_EFUSE_PRIV;
#define GET_EEPROM_EFUSE_PRIV(adapter) (&adapter->eeprompriv)
#define is_boot_from_eeprom(adapter) (adapter->eeprompriv.EepromOrEfuse)

#ifdef CONFIG_WOWLAN
typedef enum _wowlan_subcode{
	WOWLAN_PATTERN_MATCH	= 1,
	WOWLAN_MAGIC_PACKET		= 2,
	WOWLAN_UNICAST			= 3,
	WOWLAN_SET_PATTERN		= 4,
	WOWLAN_DUMP_REG			= 5,
	WOWLAN_ENABLE			= 6,
	WOWLAN_DISABLE			= 7,
	WOWLAN_STATUS			= 8,
	WOWLAN_DEBUG_RELOAD_FW	= 9,
	WOWLAN_DEBUG_1			=10,
	WOWLAN_DEBUG_2			=11
}wowlan_subcode;

struct wowlan_ioctl_param{
	unsigned int subcode;
	unsigned int subcode_value;
	unsigned int wakeup_reason;
	unsigned int len;
	unsigned char pattern[0];
};

#define Rx_Pairwisekey			0x01
#define Rx_GTK					0x02
#define Rx_DisAssoc				0x04
#define Rx_DeAuth				0x08
#define FWDecisionDisconnect	0x10
#define Rx_MagicPkt				0x21
#define Rx_UnicastPkt			0x22
#define Rx_PatternPkt			0x23
#endif // CONFIG_WOWLAN

void rtw_hal_def_value_init(struct adapter *padapter);

void	rtw_hal_free_data(struct adapter *padapter);

void rtw_hal_dm_init(struct adapter *padapter);
void rtw_hal_dm_deinit(struct adapter *padapter);
void rtw_hal_sw_led_init(struct adapter *padapter);
void rtw_hal_sw_led_deinit(struct adapter *padapter);

u32 rtw_hal_power_on(struct adapter *padapter);
void rtw_hal_power_off(struct adapter *padapter);
uint rtw_hal_init(struct adapter *padapter);
uint rtw_hal_deinit(struct adapter *padapter);
void rtw_hal_stop(struct adapter *padapter);
void rtw_hal_set_hwreg(struct adapter *padapter, u8 variable, u8 *val);
void rtw_hal_get_hwreg(struct adapter *padapter, u8 variable, u8 *val);

void rtw_hal_chip_configure(struct adapter *padapter);
void rtw_hal_read_chip_info(struct adapter *padapter);
void rtw_hal_read_chip_version(struct adapter *padapter);

u8 rtw_hal_set_def_var(struct adapter *padapter, HAL_DEF_VARIABLE eVariable, PVOID pValue);
u8 rtw_hal_get_def_var(struct adapter *padapter, HAL_DEF_VARIABLE eVariable, PVOID pValue);

void rtw_hal_set_odm_var(struct adapter *padapter, HAL_ODM_VARIABLE eVariable, PVOID pValue1,BOOLEAN bSet);
void	rtw_hal_get_odm_var(struct adapter *padapter, HAL_ODM_VARIABLE eVariable, PVOID pValue1,BOOLEAN bSet);

void rtw_hal_enable_interrupt(struct adapter *padapter);
void rtw_hal_disable_interrupt(struct adapter *padapter);

u32	rtw_hal_inirp_init(struct adapter *padapter);
u32	rtw_hal_inirp_deinit(struct adapter *padapter);

u8	rtw_hal_intf_ps_func(struct adapter *padapter,HAL_INTF_PS_FUNC efunc_id, u8* val);

s32	rtw_hal_xmitframe_enqueue(struct adapter *padapter, struct xmit_frame *pxmitframe);
s32	rtw_hal_xmit(struct adapter *padapter, struct xmit_frame *pxmitframe);
s32	rtw_hal_mgnt_xmit(struct adapter *padapter, struct xmit_frame *pmgntframe);

s32	rtw_hal_init_xmit_priv(struct adapter *padapter);
void	rtw_hal_free_xmit_priv(struct adapter *padapter);

s32	rtw_hal_init_recv_priv(struct adapter *padapter);
void	rtw_hal_free_recv_priv(struct adapter *padapter);

void rtw_hal_update_ra_mask(struct sta_info *psta, u8 rssi_level);
void	rtw_hal_add_ra_tid(struct adapter *padapter, u32 bitmap, u8 arg, u8 rssi_level);

void	rtw_hal_start_thread(struct adapter *padapter);
void	rtw_hal_stop_thread(struct adapter *padapter);

void rtw_hal_bcn_related_reg_setting(struct adapter *padapter);

u32	rtw_hal_read_bbreg(struct adapter *padapter, u32 RegAddr, u32 BitMask);
void	rtw_hal_write_bbreg(struct adapter *padapter, u32 RegAddr, u32 BitMask, u32 Data);
u32	rtw_hal_read_rfreg(struct adapter *padapter, u32 eRFPath, u32 RegAddr, u32 BitMask);
void	rtw_hal_write_rfreg(struct adapter *padapter, u32 eRFPath, u32 RegAddr, u32 BitMask, u32 Data);

s32	rtw_hal_interrupt_handler(struct adapter *padapter);

void	rtw_hal_set_bwmode(struct adapter *padapter, HT_CHANNEL_WIDTH Bandwidth, u8 Offset);
void	rtw_hal_set_chan(struct adapter *padapter, u8 channel);
void	rtw_hal_dm_watchdog(struct adapter *padapter);

#ifdef CONFIG_ANTENNA_DIVERSITY
u8	rtw_hal_antdiv_before_linked(struct adapter *padapter);
void	rtw_hal_antdiv_rssi_compared(struct adapter *padapter, WLAN_BSSID_EX *dst, WLAN_BSSID_EX *src);
#endif

#ifdef CONFIG_HOSTAPD_MLME
s32	rtw_hal_hostap_mgnt_xmit_entry(struct adapter *padapter, _pkt *pkt);
#endif

#ifdef DBG_CONFIG_ERROR_DETECT
void rtw_hal_sreset_init(struct adapter *padapter);
void rtw_hal_sreset_reset(struct adapter *padapter);
void rtw_hal_sreset_reset_value(struct adapter *padapter);
void rtw_hal_sreset_xmit_status_check(struct adapter *padapter);
void rtw_hal_sreset_linked_status_check (struct adapter *padapter);
u8   rtw_hal_sreset_get_wifi_status(struct adapter *padapter);
bool rtw_hal_sreset_inprogress(struct adapter *padapter);
#endif

#ifdef CONFIG_IOL
int rtw_hal_iol_cmd(struct adapter *adapter, struct xmit_frame *xmit_frame, u32 max_wating_ms, u32 bndy_cnt);
#endif

#ifdef CONFIG_XMIT_THREAD_MODE
s32 rtw_hal_xmit_thread_handler(struct adapter *padapter);
#endif

void rtw_hal_notch_filter(struct adapter * adapter, bool enable);
void rtw_hal_reset_security_engine(struct adapter * adapter);

s32 rtw_hal_c2h_handler(struct adapter *adapter, struct c2h_evt_hdr *c2h_evt);
c2h_id_filter rtw_hal_c2h_id_filter_ccx(struct adapter *adapter);

#endif //__HAL_INTF_H__
