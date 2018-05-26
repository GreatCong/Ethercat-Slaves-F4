#ifndef _EL9800APPL_H_
#define _EL9800APPL_H_

#include "ecatappl.h"

typedef struct OBJ_STRUCT_PACKED_START {
   UINT16   u16SubIndex0; /**< \brief SubIndex 0*/
   UINT32   aEntries[4]; /**< \brief Entry buffer*/
} OBJ_STRUCT_PACKED_END
TOBJ1600;

typedef struct OBJ_STRUCT_PACKED_START {
   UINT16   u16SubIndex0; /**< \brief SubIndex 0*/
   UINT32   aEntries[4]; /**< \brief Entry buffer*/
} OBJ_STRUCT_PACKED_END
TOBJ1A00;

typedef struct OBJ_STRUCT_PACKED_START {
   UINT16   u16SubIndex0; /**< \brief SubIndex 0*/
   UINT16   aEntries[1]; /**< \brief Entry buffer*/
} OBJ_STRUCT_PACKED_END
TOBJ1C12;

typedef struct OBJ_STRUCT_PACKED_START {
   UINT16   u16SubIndex0; /**< \brief SubIndex 0*/
   UINT16   aEntries[1]; /**< \brief Entry buffer*/
} OBJ_STRUCT_PACKED_END
TOBJ1C13;


#ifdef _EVALBOARD_
    #define PROTO
#else
    #define PROTO extern
#endif
		
PROTO INT16 AD_CH1_Obj6000
#ifdef _EVALBOARD_
 = 0
#endif
;
		
PROTO INT16 AD_CH2_Obj6010
#ifdef _EVALBOARD_
 = 0
#endif
;

PROTO INT16 AD_CH3_Obj6020
#ifdef _EVALBOARD_
 = 0
#endif
;
		
PROTO INT16 AD_CH4_Obj6030
#ifdef _EVALBOARD_
 = 0
#endif
;

PROTO INT16 CMD1_Obj7000
#ifdef _EVALBOARD_
 = 0
#endif
;
		
PROTO INT16 CMD2_Obj7010
#ifdef _EVALBOARD_
 = 0
#endif
;

PROTO INT16 CMD3_Obj7020
#ifdef _EVALBOARD_
 = 0
#endif
;
		
PROTO INT16 CMD4_Obj7030
#ifdef _EVALBOARD_
 = 0
#endif
;


/** \brief 0xF000 (Modular Device Profile) data structure*/
typedef struct OBJ_STRUCT_PACKED_START {
   UINT16   u16SubIndex0; /**< \brief SubIndex0*/
   UINT16   u16Moduleindexdistance; /**< \brief Module Index distance
                                     * 
                                     * Index distance between two modules (maximum number of objects per module and area)<br>
                                     * Default: 0x10*/
   UINT16   u16Maximumnumberofmodules; /**< \brief Maximum number of modules*/
} OBJ_STRUCT_PACKED_END
TOBJF000;


/** \brief 0xF010 (Module Profile List) data structure*/
typedef struct OBJ_STRUCT_PACKED_START {
   UINT16   u16SubIndex0; /**< \brief SubIndex0*/
   UINT32   aEntries[3]; /**< \brief Module profile information buffer
                          * 
                          * Bit 0..15: Profile number of the module on position 1<br>
                          * Bit 16..31: Profile specific*/
} OBJ_STRUCT_PACKED_END
TOBJF010;
/** @}*/

#endif //_EL9800APPL_H_




#ifdef _OBJD_
/**
 * \addtogroup SmAssignObjects SyncManager Assignment Objects
 * @{
 */
/**
 * \brief Entry descriptions of SyncManager assign objects
 *
 * SubIndex0<br>
 * SubIndex1 (for all other entries the same description will be used (because the object code is ARRAY))
 */
OBJCONST TSDOINFOENTRYDESC    OBJMEM asPDOAssignEntryDesc[] = {
   {DEFTYPE_UNSIGNED8, 0x08, ACCESS_READ},
   {DEFTYPE_UNSIGNED16, 0x10, ACCESS_READ}};
/** @}*/

   
/**
 * \addtogroup EnumObjects Enum Objects
 * @{
 * Presentation (Signed/Unsigned) : 0x800
 */

/*---------------------------------------------
-    0x0800: ENUM (Signed/Unsigned Presentation)
-----------------------------------------------*/
CHAR sEnum0800_Value00[] = "\000\000\000\000Signed presentation"; /**< \brief Value = 0x00, Text = Signed presentation */
CHAR sEnum0800_Value01[] = "\001\000\000\000Unsigned presentation"; /**< \brief Value = 0x01, Text = Unsigned presentation */
CHAR *apEnum0800[2] = { sEnum0800_Value00, sEnum0800_Value01};/**< \brief List of Enum (0x800) values*/

/**
 * \brief Enum entry description
 *
 * SubIndex0<br>
 * Enum (Signed Presentation)
 * enum (Unsigned Presentation)
 */
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x0800[] =
   {{DEFTYPE_UNSIGNED8, 8, ACCESS_READ | OBJACCESS_NOPDOMAPPING},
    {DEFTYPE_OCTETSTRING, 8*SIZEOF(sEnum0800_Value00), ACCESS_READ | OBJACCESS_NOPDOMAPPING},
   {DEFTYPE_OCTETSTRING, 8*SIZEOF(sEnum0800_Value01), ACCESS_READ | OBJACCESS_NOPDOMAPPING}};
/** @}*/


/**
* \addtogroup PdoMappingObjects PDO Mapping Objects
* @{
*/
/**
 * \brief Object 0x1601 (Digital output RxPDO) entry descriptions
 * 
 * SubIndex 0 : read only<br>
 * SubIndex x : read only<br>
 *  (x > 0)
 */
OBJCONST TSDOINFOENTRYDESC	OBJMEM asEntryDesc0x1600[] = {
   {DEFTYPE_UNSIGNED8, 0x8, ACCESS_READ },
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ}};


	 
OBJCONST UCHAR OBJMEM aName0x1600[] = "CMD_OUT RxPDO-Map\000\377";
	 
#endif //#ifdef _OBJD_

PROTO TOBJ1600 sDORxPDOMap
#ifdef _EVALBOARD_
 = {4, {0x70000010, 0x70100010, 0x70200010, 0x70300010}}
#endif
 ;


#ifdef _OBJD_
OBJCONST TSDOINFOENTRYDESC	OBJMEM asEntryDesc0x1A00[] = {
   {DEFTYPE_UNSIGNED8, 0x8, ACCESS_READ },
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ}};


OBJCONST UCHAR OBJMEM aName0x1A00[] = "AI TxPDO-Map\000\377";
#endif //#ifdef _OBJD_


PROTO TOBJ1A00 sDITxPDOMap
#ifdef _EVALBOARD_
 = {4, {0x60000010, 0x60100010, 0x60200010, 0x60300010}}
#endif
;

#ifdef _OBJD_
/**
 * \brief 0x1C12 (SyncManager 2 assignment) object name 
 * 
 * No entry names defined because the object code is ARRAY and all entry names are "SubIndex 000"
 */
OBJCONST UCHAR OBJMEM aName0x1C12[] = "RxPDO assign";
#endif //#ifdef _OBJD_

/**
 * \brief 0x1C12 (SyncManager 2 assignment) variable to handle object data
 * 
 * SubIndex 0 : 1<br>
 * SubIndex 1 : 0x1601
 */
PROTO TOBJ1C12 sRxPDOassign
#ifdef _EVALBOARD_
= {0x01, {0x1600}}
#endif
;


#ifdef _OBJD_
/**
 * \brief 0x1C13 (SyncManager 3 assignment) object name 
 * 
 * No entry names defined because the object code is ARRAY and all entry names are "SubIndex 000"
 */
OBJCONST UCHAR OBJMEM aName0x1C13[] = "TxPDO assign";
#endif //#ifdef _OBJD_


/**
 * \brief 0x1C13 (SyncManager 3 assignment) variable to handle object data
 * 
 * SubIndex 0 : 1<br>
 * SubIndex 1 : 0x1A00<br>
 * SubIndex 2 : 0x1A02
 */
PROTO TOBJ1C13 sTxPDOassign
#ifdef _EVALBOARD_
= {0x01, {0x1A00}}
#endif
;
/** @}*/


#ifdef _OBJD_

OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x6000 = {DEFTYPE_UNSIGNED16, 0x10, ACCESS_READ | OBJACCESS_TXPDOMAPPING }; 
OBJCONST UCHAR OBJMEM aName0x6000[] = "AI_CH1";


OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x6010 = {DEFTYPE_UNSIGNED16, 0x10, ACCESS_READ | OBJACCESS_TXPDOMAPPING }; 
OBJCONST UCHAR OBJMEM aName0x6010[] = "AI_CH2";


OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x6020 = {DEFTYPE_UNSIGNED16, 0x10, ACCESS_READ | OBJACCESS_TXPDOMAPPING }; 
OBJCONST UCHAR OBJMEM aName0x6020[] = "AI_CH3";


OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x6030 = {DEFTYPE_UNSIGNED16, 0x10, ACCESS_READ | OBJACCESS_TXPDOMAPPING }; 
OBJCONST UCHAR OBJMEM aName0x6030[] = "AI_CH4";

OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x7000 = {DEFTYPE_UNSIGNED16, 0x10, ACCESS_READ | OBJACCESS_RXPDOMAPPING }; 
OBJCONST UCHAR OBJMEM aName0x7000[] = "CMD1";


OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x7010 = {DEFTYPE_UNSIGNED16, 0x10, ACCESS_READ | OBJACCESS_RXPDOMAPPING }; 
OBJCONST UCHAR OBJMEM aName0x7010[] = "CMD2";


OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x7020 = {DEFTYPE_UNSIGNED16, 0x10, ACCESS_READ | OBJACCESS_RXPDOMAPPING }; 
OBJCONST UCHAR OBJMEM aName0x7020[] = "CMD3";


OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x7030 = {DEFTYPE_UNSIGNED16, 0x10, ACCESS_READ | OBJACCESS_RXPDOMAPPING }; 
OBJCONST UCHAR OBJMEM aName0x7030[] = "CMD4";
#endif //#ifdef _OBJD_


#ifdef _OBJD_
/** 
 * \brief 0xF000 (Modular Device Profile) entry descriptions
 *
 * Subindex 000<br>
 * SubIndex 001: Module index distance<br>
 * SubIndex 002: Maximum number of modules<br>
 */
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0xF000[] = {
   {DEFTYPE_UNSIGNED8, 0x8, ACCESS_READ },
   {DEFTYPE_UNSIGNED16, 0x10, ACCESS_READ},
   {DEFTYPE_UNSIGNED16, 0x10, ACCESS_READ}};


/** \brief 0xF000 (Modular Device Profile) object and entry names*/
OBJCONST UCHAR OBJMEM aName0xF000[] = "Modular device profile\000Module index distance\000Maximum number of modules\000\377";
#endif


/**
 * \brief 0xF000 (Modular Device Profile) variable to handle the object data
 *
 * SubIndex 0
 * SubIndex 1 (Module Index distance) : 0x10
 * SubIndex 2 (Maximum number of Modules) : 3
 */
/******************************************************************************
*                    Object 0xF000
******************************************************************************/
PROTO TOBJF000 sModulardeviceprofile
#ifdef _EVALBOARD_
= {2, 0x10, 0x03}
#endif
;


#ifdef _OBJD_
/** 
 * \brief 0xF010 (Module profile list) entry descriptions
 *
 * Subindex 0<br>
 * SubIndex x
 * (x > 0)
 */
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0xF010[] = {
   {DEFTYPE_UNSIGNED8, 0x08, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ}};

/**
 * \brief 0xF010 (Module profile list) object name
 *
 * no entry names defined because the object is an array (for every entry > 0 "SubIndex xxx" is returned)
 */
OBJCONST UCHAR OBJMEM aName0xF010[] = "Module profile list";
#endif


/**
 *\brief 0xF010 (Module profile list) variable to handle object data
 * 
 * SubIndex 0 : 3
 * SubIndex 1 : 100 (Digital Input SubProfile)
 * SubIndex 2 : 200 (Digital Output SubProfile)
 * SubIndex 3 : 300 (Analog Input SubProfile)
 */
PROTO TOBJF010 sModulelist
#ifdef _EVALBOARD_
= {0x03,{0x64, 0xC8, 0x12C}}
#endif
;
/** @}*/


#ifdef _OBJD_

TOBJECT    OBJMEM ApplicationObjDic[] = {
   /* Enum 0x0800 */
   {NULL,NULL, 0x0800, {DEFTYPE_ENUM, 0x02 | (OBJCODE_REC << 8)}, asEntryDesc0x0800, 0, apEnum0800 },
   /* Object 0x1601 */
   {NULL,NULL,  0x1600, {DEFTYPE_PDOMAPPING, 9 | (OBJCODE_REC << 8)}, asEntryDesc0x1600, aName0x1600, &sDORxPDOMap, NULL, NULL, 0x0000 },
   /* Object 0x1A00 */
   {NULL,NULL,   0x1A00, {DEFTYPE_PDOMAPPING, 9 | (OBJCODE_REC << 8)}, asEntryDesc0x1A00, aName0x1A00, &sDITxPDOMap, NULL, NULL, 0x0000 },
   /* Object 0x1A02 */
    /* Object 0x1C12 */
   {NULL,NULL,   0x1C12, {DEFTYPE_UNSIGNED16, 1 | (OBJCODE_ARR << 8)}, asPDOAssignEntryDesc, aName0x1C12, &sRxPDOassign, NULL, NULL, 0x0000 },
   /* Object 0x1C13 */
   {NULL,NULL,   0x1C13, {DEFTYPE_UNSIGNED16, 1 | (OBJCODE_ARR << 8)}, asPDOAssignEntryDesc, aName0x1C13, &sTxPDOassign, NULL, NULL, 0x0000 },
   
	 /* Object 0x60X0 */
   {NULL,NULL,   0x6000, {DEFTYPE_INTEGER16, 0 | (OBJCODE_VAR << 8)}, &asEntryDesc0x6000, aName0x6000, &AD_CH1_Obj6000, NULL, NULL, 0x0000 },
	 {NULL,NULL,   0x6010, {DEFTYPE_INTEGER16, 0 | (OBJCODE_VAR << 8)}, &asEntryDesc0x6010, aName0x6010, &AD_CH2_Obj6010, NULL, NULL, 0x0000 },
	 {NULL,NULL,   0x6020, {DEFTYPE_INTEGER16, 0 | (OBJCODE_VAR << 8)}, &asEntryDesc0x6020, aName0x6020, &AD_CH3_Obj6020, NULL, NULL, 0x0000 },
	 {NULL,NULL,   0x6030, {DEFTYPE_INTEGER16, 0 | (OBJCODE_VAR << 8)}, &asEntryDesc0x6030, aName0x6030, &AD_CH4_Obj6030, NULL, NULL, 0x0000 },
	 
    /* Object 0x70X0 */
   {NULL,NULL,   0x7000, {DEFTYPE_UNSIGNED16, 0 | (OBJCODE_VAR << 8)}, &asEntryDesc0x7000, aName0x7000, &CMD1_Obj7000, NULL, NULL, 0x0000 },
	 {NULL,NULL,   0x7010, {DEFTYPE_UNSIGNED16, 0 | (OBJCODE_VAR << 8)}, &asEntryDesc0x7010, aName0x7010, &CMD2_Obj7010, NULL, NULL, 0x0000 },
	 {NULL,NULL,   0x7020, {DEFTYPE_UNSIGNED16, 0 | (OBJCODE_VAR << 8)}, &asEntryDesc0x7020, aName0x7020, &CMD3_Obj7020, NULL, NULL, 0x0000 },
	 {NULL,NULL,   0x7030, {DEFTYPE_UNSIGNED16, 0 | (OBJCODE_VAR << 8)}, &asEntryDesc0x7030, aName0x7030, &CMD4_Obj7030, NULL, NULL, 0x0000 },  
    /* Object 0xF000 */
   {NULL,NULL,   0xF000, {DEFTYPE_RECORD, 2 | (OBJCODE_REC << 8)}, asEntryDesc0xF000, aName0xF000, &sModulardeviceprofile, NULL, NULL, 0x0000 },
   /* Object 0xF010 */
   {NULL,NULL,   0xF010, {DEFTYPE_UNSIGNED32, 3 | (OBJCODE_ARR << 8)}, asEntryDesc0xF010, aName0xF010, &sModulelist, NULL, NULL, 0x0000 },
   {NULL,NULL, 0xFFFF, {0, 0}, NULL, NULL, NULL, NULL}};
#endif    //#ifdef _OBJD_

PROTO void APPL_Application(void);

PROTO void   APPL_AckErrorInd(UINT16 stateTrans);
PROTO UINT16 APPL_StartMailboxHandler(void);
PROTO UINT16 APPL_StopMailboxHandler(void);
PROTO UINT16 APPL_StartInputHandler(UINT16 *pIntMask);
PROTO UINT16 APPL_StopInputHandler(void);
PROTO UINT16 APPL_StartOutputHandler(void);
PROTO UINT16 APPL_StopOutputHandler(void);

PROTO UINT16 APPL_GenerateMapping(UINT16 *pInputSize,UINT16 *pOutputSize);
PROTO void APPL_InputMapping(UINT16* pData);
PROTO void APPL_OutputMapping(UINT16* pData);


#undef PROTO
