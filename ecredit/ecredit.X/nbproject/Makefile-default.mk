#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/ecredit.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/ecredit.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../../lib/src/pic24_clockfreq.c ../../lib/src/pic24_configbits.c ../../lib/src/pic24_serial.c ../../lib/src/pic24_uart.c ../../lib/src/pic24_util.c ../../lib/src/pic24_timer.c ../../lib/src/pic24_adc.c ../../lib/src/pic24_spi.c ../../lib/src/pic24_i2c.c ../nokia_5110.c ../pDot.c ../entity_gap.c ../ecredit.c ../eeprom.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/957557178/pic24_clockfreq.o ${OBJECTDIR}/_ext/957557178/pic24_configbits.o ${OBJECTDIR}/_ext/957557178/pic24_serial.o ${OBJECTDIR}/_ext/957557178/pic24_uart.o ${OBJECTDIR}/_ext/957557178/pic24_util.o ${OBJECTDIR}/_ext/957557178/pic24_timer.o ${OBJECTDIR}/_ext/957557178/pic24_adc.o ${OBJECTDIR}/_ext/957557178/pic24_spi.o ${OBJECTDIR}/_ext/957557178/pic24_i2c.o ${OBJECTDIR}/_ext/1472/nokia_5110.o ${OBJECTDIR}/_ext/1472/pDot.o ${OBJECTDIR}/_ext/1472/entity_gap.o ${OBJECTDIR}/_ext/1472/ecredit.o ${OBJECTDIR}/_ext/1472/eeprom.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/957557178/pic24_clockfreq.o.d ${OBJECTDIR}/_ext/957557178/pic24_configbits.o.d ${OBJECTDIR}/_ext/957557178/pic24_serial.o.d ${OBJECTDIR}/_ext/957557178/pic24_uart.o.d ${OBJECTDIR}/_ext/957557178/pic24_util.o.d ${OBJECTDIR}/_ext/957557178/pic24_timer.o.d ${OBJECTDIR}/_ext/957557178/pic24_adc.o.d ${OBJECTDIR}/_ext/957557178/pic24_spi.o.d ${OBJECTDIR}/_ext/957557178/pic24_i2c.o.d ${OBJECTDIR}/_ext/1472/nokia_5110.o.d ${OBJECTDIR}/_ext/1472/pDot.o.d ${OBJECTDIR}/_ext/1472/entity_gap.o.d ${OBJECTDIR}/_ext/1472/ecredit.o.d ${OBJECTDIR}/_ext/1472/eeprom.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/957557178/pic24_clockfreq.o ${OBJECTDIR}/_ext/957557178/pic24_configbits.o ${OBJECTDIR}/_ext/957557178/pic24_serial.o ${OBJECTDIR}/_ext/957557178/pic24_uart.o ${OBJECTDIR}/_ext/957557178/pic24_util.o ${OBJECTDIR}/_ext/957557178/pic24_timer.o ${OBJECTDIR}/_ext/957557178/pic24_adc.o ${OBJECTDIR}/_ext/957557178/pic24_spi.o ${OBJECTDIR}/_ext/957557178/pic24_i2c.o ${OBJECTDIR}/_ext/1472/nokia_5110.o ${OBJECTDIR}/_ext/1472/pDot.o ${OBJECTDIR}/_ext/1472/entity_gap.o ${OBJECTDIR}/_ext/1472/ecredit.o ${OBJECTDIR}/_ext/1472/eeprom.o

# Source Files
SOURCEFILES=../../lib/src/pic24_clockfreq.c ../../lib/src/pic24_configbits.c ../../lib/src/pic24_serial.c ../../lib/src/pic24_uart.c ../../lib/src/pic24_util.c ../../lib/src/pic24_timer.c ../../lib/src/pic24_adc.c ../../lib/src/pic24_spi.c ../../lib/src/pic24_i2c.c ../nokia_5110.c ../pDot.c ../entity_gap.c ../ecredit.c ../eeprom.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/ecredit.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33EP128GP502
MP_LINKER_FILE_OPTION=,--script="..\..\lib\lkr\p33EP128GP502_bootldr.gld"
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/957557178/pic24_clockfreq.o: ../../lib/src/pic24_clockfreq.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/957557178" 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_clockfreq.o.d 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_clockfreq.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../lib/src/pic24_clockfreq.c  -o ${OBJECTDIR}/_ext/957557178/pic24_clockfreq.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/957557178/pic24_clockfreq.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/957557178/pic24_clockfreq.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/957557178/pic24_configbits.o: ../../lib/src/pic24_configbits.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/957557178" 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_configbits.o.d 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_configbits.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../lib/src/pic24_configbits.c  -o ${OBJECTDIR}/_ext/957557178/pic24_configbits.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/957557178/pic24_configbits.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/957557178/pic24_configbits.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/957557178/pic24_serial.o: ../../lib/src/pic24_serial.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/957557178" 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_serial.o.d 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_serial.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../lib/src/pic24_serial.c  -o ${OBJECTDIR}/_ext/957557178/pic24_serial.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/957557178/pic24_serial.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/957557178/pic24_serial.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/957557178/pic24_uart.o: ../../lib/src/pic24_uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/957557178" 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../lib/src/pic24_uart.c  -o ${OBJECTDIR}/_ext/957557178/pic24_uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/957557178/pic24_uart.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/957557178/pic24_uart.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/957557178/pic24_util.o: ../../lib/src/pic24_util.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/957557178" 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_util.o.d 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_util.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../lib/src/pic24_util.c  -o ${OBJECTDIR}/_ext/957557178/pic24_util.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/957557178/pic24_util.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/957557178/pic24_util.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/957557178/pic24_timer.o: ../../lib/src/pic24_timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/957557178" 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../lib/src/pic24_timer.c  -o ${OBJECTDIR}/_ext/957557178/pic24_timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/957557178/pic24_timer.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/957557178/pic24_timer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/957557178/pic24_adc.o: ../../lib/src/pic24_adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/957557178" 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../lib/src/pic24_adc.c  -o ${OBJECTDIR}/_ext/957557178/pic24_adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/957557178/pic24_adc.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/957557178/pic24_adc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/957557178/pic24_spi.o: ../../lib/src/pic24_spi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/957557178" 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_spi.o.d 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_spi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../lib/src/pic24_spi.c  -o ${OBJECTDIR}/_ext/957557178/pic24_spi.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/957557178/pic24_spi.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/957557178/pic24_spi.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/957557178/pic24_i2c.o: ../../lib/src/pic24_i2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/957557178" 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_i2c.o.d 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_i2c.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../lib/src/pic24_i2c.c  -o ${OBJECTDIR}/_ext/957557178/pic24_i2c.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/957557178/pic24_i2c.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/957557178/pic24_i2c.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/nokia_5110.o: ../nokia_5110.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/nokia_5110.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/nokia_5110.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../nokia_5110.c  -o ${OBJECTDIR}/_ext/1472/nokia_5110.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/nokia_5110.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/nokia_5110.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/pDot.o: ../pDot.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/pDot.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/pDot.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../pDot.c  -o ${OBJECTDIR}/_ext/1472/pDot.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/pDot.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/pDot.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/entity_gap.o: ../entity_gap.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/entity_gap.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/entity_gap.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../entity_gap.c  -o ${OBJECTDIR}/_ext/1472/entity_gap.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/entity_gap.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/entity_gap.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ecredit.o: ../ecredit.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ecredit.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ecredit.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ecredit.c  -o ${OBJECTDIR}/_ext/1472/ecredit.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ecredit.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ecredit.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/eeprom.o: ../eeprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/eeprom.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/eeprom.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../eeprom.c  -o ${OBJECTDIR}/_ext/1472/eeprom.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/eeprom.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/eeprom.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/_ext/957557178/pic24_clockfreq.o: ../../lib/src/pic24_clockfreq.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/957557178" 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_clockfreq.o.d 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_clockfreq.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../lib/src/pic24_clockfreq.c  -o ${OBJECTDIR}/_ext/957557178/pic24_clockfreq.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/957557178/pic24_clockfreq.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/957557178/pic24_clockfreq.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/957557178/pic24_configbits.o: ../../lib/src/pic24_configbits.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/957557178" 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_configbits.o.d 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_configbits.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../lib/src/pic24_configbits.c  -o ${OBJECTDIR}/_ext/957557178/pic24_configbits.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/957557178/pic24_configbits.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/957557178/pic24_configbits.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/957557178/pic24_serial.o: ../../lib/src/pic24_serial.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/957557178" 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_serial.o.d 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_serial.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../lib/src/pic24_serial.c  -o ${OBJECTDIR}/_ext/957557178/pic24_serial.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/957557178/pic24_serial.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/957557178/pic24_serial.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/957557178/pic24_uart.o: ../../lib/src/pic24_uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/957557178" 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../lib/src/pic24_uart.c  -o ${OBJECTDIR}/_ext/957557178/pic24_uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/957557178/pic24_uart.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/957557178/pic24_uart.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/957557178/pic24_util.o: ../../lib/src/pic24_util.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/957557178" 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_util.o.d 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_util.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../lib/src/pic24_util.c  -o ${OBJECTDIR}/_ext/957557178/pic24_util.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/957557178/pic24_util.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/957557178/pic24_util.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/957557178/pic24_timer.o: ../../lib/src/pic24_timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/957557178" 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../lib/src/pic24_timer.c  -o ${OBJECTDIR}/_ext/957557178/pic24_timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/957557178/pic24_timer.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/957557178/pic24_timer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/957557178/pic24_adc.o: ../../lib/src/pic24_adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/957557178" 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../lib/src/pic24_adc.c  -o ${OBJECTDIR}/_ext/957557178/pic24_adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/957557178/pic24_adc.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/957557178/pic24_adc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/957557178/pic24_spi.o: ../../lib/src/pic24_spi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/957557178" 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_spi.o.d 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_spi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../lib/src/pic24_spi.c  -o ${OBJECTDIR}/_ext/957557178/pic24_spi.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/957557178/pic24_spi.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/957557178/pic24_spi.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/957557178/pic24_i2c.o: ../../lib/src/pic24_i2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/957557178" 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_i2c.o.d 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_i2c.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../lib/src/pic24_i2c.c  -o ${OBJECTDIR}/_ext/957557178/pic24_i2c.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/957557178/pic24_i2c.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/957557178/pic24_i2c.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/nokia_5110.o: ../nokia_5110.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/nokia_5110.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/nokia_5110.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../nokia_5110.c  -o ${OBJECTDIR}/_ext/1472/nokia_5110.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/nokia_5110.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/nokia_5110.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/pDot.o: ../pDot.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/pDot.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/pDot.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../pDot.c  -o ${OBJECTDIR}/_ext/1472/pDot.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/pDot.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/pDot.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/entity_gap.o: ../entity_gap.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/entity_gap.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/entity_gap.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../entity_gap.c  -o ${OBJECTDIR}/_ext/1472/entity_gap.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/entity_gap.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/entity_gap.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ecredit.o: ../ecredit.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ecredit.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ecredit.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ecredit.c  -o ${OBJECTDIR}/_ext/1472/ecredit.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ecredit.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ecredit.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/eeprom.o: ../eeprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/eeprom.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/eeprom.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../eeprom.c  -o ${OBJECTDIR}/_ext/1472/eeprom.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/eeprom.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/eeprom.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/ecredit.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    ../../lib/lkr/p33EP128GP502_bootldr.gld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/ecredit.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)      -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/ecredit.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   ../../lib/lkr/p33EP128GP502_bootldr.gld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/ecredit.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/ecredit.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf  
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
