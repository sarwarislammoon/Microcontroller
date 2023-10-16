################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1250/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/sislam/WORK/Microcontroller/TI_TM4C123G/Code/UART" --include_path="C:/Users/sislam/WORK/Microcontroller/TI_TM4C123G/Code/Q_driver" --include_path="C:/CMSIS.5.9.0" --include_path="C:/CMSIS.5.9.0/CMSIS/Core/Include" --include_path="C:/CMSIS.5.9.0/Device/TI/TM4C/Include" --include_path="C:/ti/ccs1250/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" --define=ccs="ccs" --define=__FPU_PRESENT --define=PART_TM4C123GE6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

tm4c123ge6pm_startup_ccs_SI_V1.0.obj: ../tm4c123ge6pm_startup_ccs_SI_V1.0.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1250/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/sislam/WORK/Microcontroller/TI_TM4C123G/Code/UART" --include_path="C:/Users/sislam/WORK/Microcontroller/TI_TM4C123G/Code/Q_driver" --include_path="C:/CMSIS.5.9.0" --include_path="C:/CMSIS.5.9.0/CMSIS/Core/Include" --include_path="C:/CMSIS.5.9.0/Device/TI/TM4C/Include" --include_path="C:/ti/ccs1250/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" --define=ccs="ccs" --define=__FPU_PRESENT --define=PART_TM4C123GE6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


