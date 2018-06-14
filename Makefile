################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS :=  \
../Include/ \
../Include/akilcd/ \
../Include/akilcd/akilcd_define/ \
../Include/akilcd/akilcd_name/ \
../Include/AVR/ \
../Include/AVR/ADChange/ \
../Include/AVR/IO/ \
../Include/AVR/IO/IoBase/ \
../Include/AVR/Timer/ \
../Include/AVR/Uart/ \
../Include/AVR/Uart/UartBase/ \
../Include/AVR/Uart/Uart/ \
../Include/MainCircit/ \
../Include/MainCircit/AirCylinder/ \
../Include/MainCircit/Controller/ \
../Include/MainCircit/Controller/ControllerBase/ \
../Include/MainCircit/Controller/ControllerBase/ControllerBase_inline/ \
../Include/MainCircit/Lolita/ \
../Include/MainCircit/MDC/ \
../Include/MainCircit/Motor/ \
../Include/MainCircit/Motor/MotorBase/ \
../Include/MainCircit/Servo/ \
../Include/MainCircit/Valve/ \
../Include/MainCircit/Valve/ValveBase/ \
../Include/MainCircit/Valve/ValveBase/ValveBase_inline/ \
../Include/Others/ \
../OffSeason_Project_class/ \
../OffSeason_Project_class/01_Akiduki/ \
../OffSeason_Project_class/02_Teruduki/ \
../Source/ \
../Source/akilcd/ \
../Source/AVR/ \
../Source/AVR/ADChange/ \
../Source/AVR/IO/ \
../Source/AVR/Timer/ \
../Source/AVR/Uart/ \
../Source/MainCircit/ \
../Source/MainCircit/AirCylinder/ \
../Source/MainCircit/Controller/ \
../Source/MainCircit/Lolita/ \
../Source/MainCircit/MDC/ \
../Source/MainCircit/Motor/ \
../Source/MainCircit/Servo/ \
../Source/MainCircit/Valve/ \
../Source/Others/


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../main.cpp \
../OffSeason_Project_class/01_Akiduki/TecnicSteer.cpp \
../OffSeason_Project_class/02_Teruduki/AIG_No_0.cpp \
../OffSeason_Project_class/02_Teruduki/Gourobo_Cteam.cpp \
../Source/akilcd/akilcd.c \
../Source/AVR/ADChange/ADChange.cpp \
../Source/AVR/IO/IO.cpp \
../Source/AVR/IO/IoBase.cpp \
../Source/AVR/Timer/GeneralTimer.cpp \
../Source/AVR/Uart/Uart.cpp \
../Source/AVR/Uart/UartBase.cpp \
../Source/AVR/Uart/Uart_func.cpp \
../Source/MainCircit/AirCylinder/AirCylinder.cpp \
../Source/MainCircit/Controller/Bit24Controller.cpp \
../Source/MainCircit/Controller/ContollerDoubleLine.cpp \
../Source/MainCircit/Controller/Bit28Controller.cpp \
../Source/MainCircit/Controller/ControllerBase.cpp \
../Source/MainCircit/Controller/Dualshock2.cpp \
../Source/MainCircit/Controller/WiiClassic.cpp \
../Source/MainCircit/Lolita/Lolita.cpp \
../Source/MainCircit/MainCircit.cpp \
../Source/MainCircit/MDC/FourOmuni.cpp \
../Source/MainCircit/MDC/FourSteer.cpp \
../Source/MainCircit/MDC/FourWheel.cpp \
../Source/MainCircit/MDC/MDC.cpp \
../Source/MainCircit/MDC/ThreeOmuni.cpp \
../Source/MainCircit/MDC/Wheel.cpp \
../Source/MainCircit/Motor/Motor.cpp \
../Source/MainCircit/Motor/MotorBase.cpp \
../Source/MainCircit/Motor/MotorRotationOnly.cpp \
../Source/MainCircit/Servo/Servo.cpp \
../Source/MainCircit/Valve/Valve.cpp \
../Source/MainCircit/Valve/ValveBase.cpp \
../Source/MainCircit/Valve/ValveBit.cpp \
../Source/MainCircit/Valve/ValveDouble.cpp \
../Source/MainCircit/Valve/ValveSingle.cpp


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
main.o \
OffSeason_Project_class/01_Akiduki/TecnicSteer.o \
OffSeason_Project_class/02_Teruduki/AIG_No_0.o \
OffSeason_Project_class/02_Teruduki/Gourobo_Cteam.o \
Source/akilcd/akilcd.o \
Source/AVR/ADChange/ADChange.o \
Source/AVR/IO/IO.o \
Source/AVR/IO/IoBase.o \
Source/AVR/Timer/GeneralTimer.o \
Source/AVR/Uart/Uart.o \
Source/AVR/Uart/UartBase.o \
Source/AVR/Uart/Uart_func.o \
Source/MainCircit/AirCylinder/AirCylinder.o \
Source/MainCircit/Controller/Bit24Controller.o \
Source/MainCircit/Controller/ContollerDoubleLine.o \
Source/MainCircit/Controller/Bit28Controller.o \
Source/MainCircit/Controller/ControllerBase.o \
Source/MainCircit/Controller/Dualshock2.o \
Source/MainCircit/Controller/WiiClassic.o \
Source/MainCircit/Lolita/Lolita.o \
Source/MainCircit/MainCircit.o \
Source/MainCircit/MDC/FourOmuni.o \
Source/MainCircit/MDC/FourSteer.o \
Source/MainCircit/MDC/FourWheel.o \
Source/MainCircit/MDC/MDC.o \
Source/MainCircit/MDC/ThreeOmuni.o \
Source/MainCircit/MDC/Wheel.o \
Source/MainCircit/Motor/Motor.o \
Source/MainCircit/Motor/MotorBase.o \
Source/MainCircit/Motor/MotorRotationOnly.o \
Source/MainCircit/Servo/Servo.o \
Source/MainCircit/Valve/Valve.o \
Source/MainCircit/Valve/ValveBase.o \
Source/MainCircit/Valve/ValveBit.o \
Source/MainCircit/Valve/ValveDouble.o \
Source/MainCircit/Valve/ValveSingle.o

OBJS_AS_ARGS +=  \
main.o \
OffSeason_Project_class/01_Akiduki/TecnicSteer.o \
OffSeason_Project_class/02_Teruduki/AIG_No_0.o \
OffSeason_Project_class/02_Teruduki/Gourobo_Cteam.o \
Source/akilcd/akilcd.o \
Source/AVR/ADChange/ADChange.o \
Source/AVR/IO/IO.o \
Source/AVR/IO/IoBase.o \
Source/AVR/Timer/GeneralTimer.o \
Source/AVR/Uart/Uart.o \
Source/AVR/Uart/UartBase.o \
Source/AVR/Uart/Uart_func.o \
Source/MainCircit/AirCylinder/AirCylinder.o \
Source/MainCircit/Controller/Bit24Controller.o \
Source/MainCircit/Controller/ContollerDoubleLine.o \
Source/MainCircit/Controller/Bit28Controller.o \
Source/MainCircit/Controller/ControllerBase.o \
Source/MainCircit/Controller/Dualshock2.o \
Source/MainCircit/Controller/WiiClassic.o \
Source/MainCircit/Lolita/Lolita.o \
Source/MainCircit/MainCircit.o \
Source/MainCircit/MDC/FourOmuni.o \
Source/MainCircit/MDC/FourSteer.o \
Source/MainCircit/MDC/FourWheel.o \
Source/MainCircit/MDC/MDC.o \
Source/MainCircit/MDC/ThreeOmuni.o \
Source/MainCircit/MDC/Wheel.o \
Source/MainCircit/Motor/Motor.o \
Source/MainCircit/Motor/MotorBase.o \
Source/MainCircit/Motor/MotorRotationOnly.o \
Source/MainCircit/Servo/Servo.o \
Source/MainCircit/Valve/Valve.o \
Source/MainCircit/Valve/ValveBase.o \
Source/MainCircit/Valve/ValveBit.o \
Source/MainCircit/Valve/ValveDouble.o \
Source/MainCircit/Valve/ValveSingle.o

C_DEPS +=  \
main.d \
OffSeason_Project_class/01_Akiduki/TecnicSteer.d \
OffSeason_Project_class/02_Teruduki/AIG_No_0.d \
OffSeason_Project_class/02_Teruduki/Gourobo_Cteam.d \
Source/akilcd/akilcd.d \
Source/AVR/ADChange/ADChange.d \
Source/AVR/IO/IO.d \
Source/AVR/IO/IoBase.d \
Source/AVR/Timer/GeneralTimer.d \
Source/AVR/Uart/Uart.d \
Source/AVR/Uart/UartBase.d \
Source/AVR/Uart/Uart_func.d \
Source/MainCircit/AirCylinder/AirCylinder.d \
Source/MainCircit/Controller/Bit24Controller.d \
Source/MainCircit/Controller/ContollerDoubleLine.d \
Source/MainCircit/Controller/Bit28Controller.d \
Source/MainCircit/Controller/ControllerBase.d \
Source/MainCircit/Controller/Dualshock2.d \
Source/MainCircit/Controller/WiiClassic.d \
Source/MainCircit/Lolita/Lolita.d \
Source/MainCircit/MainCircit.d \
Source/MainCircit/MDC/FourOmuni.d \
Source/MainCircit/MDC/FourSteer.d \
Source/MainCircit/MDC/FourWheel.d \
Source/MainCircit/MDC/MDC.d \
Source/MainCircit/MDC/ThreeOmuni.d \
Source/MainCircit/MDC/Wheel.d \
Source/MainCircit/Motor/Motor.d \
Source/MainCircit/Motor/MotorBase.d \
Source/MainCircit/Motor/MotorRotationOnly.d \
Source/MainCircit/Servo/Servo.d \
Source/MainCircit/Valve/Valve.d \
Source/MainCircit/Valve/ValveBase.d \
Source/MainCircit/Valve/ValveBit.d \
Source/MainCircit/Valve/ValveDouble.d \
Source/MainCircit/Valve/ValveSingle.d

C_DEPS_AS_ARGS +=  \
main.d \
OffSeason_Project_class/01_Akiduki/TecnicSteer.d \
OffSeason_Project_class/02_Teruduki/AIG_No_0.d \
OffSeason_Project_class/02_Teruduki/Gourobo_Cteam.d \
Source/akilcd/akilcd.d \
Source/AVR/ADChange/ADChange.d \
Source/AVR/IO/IO.d \
Source/AVR/IO/IoBase.d \
Source/AVR/Timer/GeneralTimer.d \
Source/AVR/Uart/Uart.d \
Source/AVR/Uart/UartBase.d \
Source/AVR/Uart/Uart_func.d \
Source/MainCircit/AirCylinder/AirCylinder.d \
Source/MainCircit/Controller/Bit24Controller.d \
Source/MainCircit/Controller/ContollerDoubleLine.d \
Source/MainCircit/Controller/Bit28Controller.d \
Source/MainCircit/Controller/ControllerBase.d \
Source/MainCircit/Controller/Dualshock2.d \
Source/MainCircit/Controller/WiiClassic.d \
Source/MainCircit/Lolita/Lolita.d \
Source/MainCircit/MainCircit.d \
Source/MainCircit/MDC/FourOmuni.d \
Source/MainCircit/MDC/FourSteer.d \
Source/MainCircit/MDC/FourWheel.d \
Source/MainCircit/MDC/MDC.d \
Source/MainCircit/MDC/ThreeOmuni.d \
Source/MainCircit/MDC/Wheel.d \
Source/MainCircit/Motor/Motor.d \
Source/MainCircit/Motor/MotorBase.d \
Source/MainCircit/Motor/MotorRotationOnly.d \
Source/MainCircit/Servo/Servo.d \
Source/MainCircit/Valve/Valve.d \
Source/MainCircit/Valve/ValveBase.d \
Source/MainCircit/Valve/ValveBit.d \
Source/MainCircit/Valve/ValveDouble.d \
Source/MainCircit/Valve/ValveSingle.d

OUTPUT_FILE_PATH +=SuzuProject.elf

OUTPUT_FILE_PATH_AS_ARGS +=SuzuProject.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler









































































./%.o: .././%.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 5.4.0
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DDEBUG -DF_CPU=10000000UL  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\include" -I"C:\Users\FUJITSU\Documents\Atmel Studio\7.0\SuzuProject\SuzuProject\Include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega640 -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\gcc\dev\atmega640" -c -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

OffSeason_Project_class/01_Akiduki/%.o: ../OffSeason_Project_class/01_Akiduki/%.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 5.4.0
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DDEBUG -DF_CPU=10000000UL  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\include" -I"C:\Users\FUJITSU\Documents\Atmel Studio\7.0\SuzuProject\SuzuProject\Include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega640 -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\gcc\dev\atmega640" -c -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

OffSeason_Project_class/02_Teruduki/%.o: ../OffSeason_Project_class/02_Teruduki/%.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 5.4.0
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DDEBUG -DF_CPU=10000000UL  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\include" -I"C:\Users\FUJITSU\Documents\Atmel Studio\7.0\SuzuProject\SuzuProject\Include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega640 -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\gcc\dev\atmega640" -c -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

Source/akilcd/%.o: ../Source/akilcd/%.c
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 5.4.0
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG -DF_CPU=10000000UL  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\include" -I"C:\Users\FUJITSU\Documents\Atmel Studio\7.0\SuzuProject\SuzuProject\Include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega640 -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\gcc\dev\atmega640" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

Source/AVR/ADChange/%.o: ../Source/AVR/ADChange/%.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 5.4.0
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DDEBUG -DF_CPU=10000000UL  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\include" -I"C:\Users\FUJITSU\Documents\Atmel Studio\7.0\SuzuProject\SuzuProject\Include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega640 -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\gcc\dev\atmega640" -c -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

Source/AVR/IO/%.o: ../Source/AVR/IO/%.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 5.4.0
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DDEBUG -DF_CPU=10000000UL  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\include" -I"C:\Users\FUJITSU\Documents\Atmel Studio\7.0\SuzuProject\SuzuProject\Include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega640 -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\gcc\dev\atmega640" -c -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

Source/AVR/Timer/%.o: ../Source/AVR/Timer/%.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 5.4.0
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DDEBUG -DF_CPU=10000000UL  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\include" -I"C:\Users\FUJITSU\Documents\Atmel Studio\7.0\SuzuProject\SuzuProject\Include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega640 -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\gcc\dev\atmega640" -c -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

Source/AVR/Uart/%.o: ../Source/AVR/Uart/%.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 5.4.0
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DDEBUG -DF_CPU=10000000UL  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\include" -I"C:\Users\FUJITSU\Documents\Atmel Studio\7.0\SuzuProject\SuzuProject\Include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega640 -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\gcc\dev\atmega640" -c -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

Source/MainCircit/AirCylinder/%.o: ../Source/MainCircit/AirCylinder/%.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 5.4.0
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DDEBUG -DF_CPU=10000000UL  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\include" -I"C:\Users\FUJITSU\Documents\Atmel Studio\7.0\SuzuProject\SuzuProject\Include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega640 -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\gcc\dev\atmega640" -c -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

Source/MainCircit/Controller/%.o: ../Source/MainCircit/Controller/%.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 5.4.0
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DDEBUG -DF_CPU=10000000UL  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\include" -I"C:\Users\FUJITSU\Documents\Atmel Studio\7.0\SuzuProject\SuzuProject\Include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega640 -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\gcc\dev\atmega640" -c -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

Source/MainCircit/Lolita/%.o: ../Source/MainCircit/Lolita/%.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 5.4.0
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DDEBUG -DF_CPU=10000000UL  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\include" -I"C:\Users\FUJITSU\Documents\Atmel Studio\7.0\SuzuProject\SuzuProject\Include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega640 -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\gcc\dev\atmega640" -c -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

Source/MainCircit/%.o: ../Source/MainCircit/%.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 5.4.0
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DDEBUG -DF_CPU=10000000UL  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\include" -I"C:\Users\FUJITSU\Documents\Atmel Studio\7.0\SuzuProject\SuzuProject\Include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega640 -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\gcc\dev\atmega640" -c -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

Source/MainCircit/MDC/%.o: ../Source/MainCircit/MDC/%.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 5.4.0
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DDEBUG -DF_CPU=10000000UL  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\include" -I"C:\Users\FUJITSU\Documents\Atmel Studio\7.0\SuzuProject\SuzuProject\Include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega640 -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\gcc\dev\atmega640" -c -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

Source/MainCircit/Motor/%.o: ../Source/MainCircit/Motor/%.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 5.4.0
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DDEBUG -DF_CPU=10000000UL  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\include" -I"C:\Users\FUJITSU\Documents\Atmel Studio\7.0\SuzuProject\SuzuProject\Include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega640 -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\gcc\dev\atmega640" -c -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

Source/MainCircit/Servo/%.o: ../Source/MainCircit/Servo/%.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 5.4.0
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DDEBUG -DF_CPU=10000000UL  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\include" -I"C:\Users\FUJITSU\Documents\Atmel Studio\7.0\SuzuProject\SuzuProject\Include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega640 -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\gcc\dev\atmega640" -c -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

Source/MainCircit/Valve/%.o: ../Source/MainCircit/Valve/%.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 5.4.0
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DDEBUG -DF_CPU=10000000UL  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\include" -I"C:\Users\FUJITSU\Documents\Atmel Studio\7.0\SuzuProject\SuzuProject\Include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega640 -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\gcc\dev\atmega640" -c -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR8/GNU Linker : 5.4.0
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="SuzuProject.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=atmega640 -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\gcc\dev\atmega640"  
	@echo Finished building target: $@
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "SuzuProject.elf" "SuzuProject.hex"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "SuzuProject.elf" "SuzuProject.eep" || exit 0
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "SuzuProject.elf" > "SuzuProject.lss"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "SuzuProject.elf" "SuzuProject.srec"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "SuzuProject.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "SuzuProject.elf" "SuzuProject.a" "SuzuProject.hex" "SuzuProject.lss" "SuzuProject.eep" "SuzuProject.map" "SuzuProject.srec" "SuzuProject.usersignatures"
	