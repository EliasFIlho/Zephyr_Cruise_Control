#define CONFIG_UART_INTERRUPT_DRIVEN 1
#define CONFIG_SYS_CLOCK_HW_CYCLES_PER_SEC 240000000
#define CONFIG_FLASH_SIZE 4194304
#define CONFIG_FLASH_BASE_ADDRESS 0x0
#define CONFIG_MP_MAX_NUM_CPUS 1
#define CONFIG_MAIN_STACK_SIZE 2048
#define CONFIG_IDLE_STACK_SIZE 1024
#define CONFIG_ISR_STACK_SIZE 2048
#define CONFIG_CLOCK_CONTROL 1
#define CONFIG_SYS_CLOCK_TICKS_PER_SEC 10000
#define CONFIG_ROM_START_OFFSET 0x0
#define CONFIG_KERNEL_ENTRY "__start"
#define CONFIG_BUILD_OUTPUT_BIN 1
#define CONFIG_TICKLESS_KERNEL 1
#define CONFIG_SYSTEM_WORKQUEUE_STACK_SIZE 1024
#define CONFIG_CLOCK_CONTROL_INIT_PRIORITY 30
#define CONFIG_DYNAMIC_INTERRUPTS 1
#define CONFIG_GEN_ISR_TABLES 1
#define CONFIG_TIMESLICE_SIZE 0
#define CONFIG_SYS_CLOCK_EXISTS 1
#define CONFIG_GPIO 1
#define CONFIG_SERIAL 1
#define CONFIG_XTENSA_TIMER 1
#define CONFIG_XTENSA_CCOUNT_HZ 240000000
#define CONFIG_ARCH_SW_ISR_TABLE_ALIGN 4
#define CONFIG_UART_USE_RUNTIME_CONFIGURE 1
#define CONFIG_SERIAL_INIT_PRIORITY 50
#define CONFIG_COMMON_LIBC_MALLOC_ARENA_SIZE -1
#define CONFIG_SOC_TOOLCHAIN_NAME "espressif_esp32"
#define CONFIG_GEN_SW_ISR_TABLE 1
#define CONFIG_GEN_IRQ_START_VECTOR 0
#define CONFIG_SRAM_OFFSET 0x0
#define CONFIG_XTENSA_TIMER_ID 0
#define CONFIG_CONSOLE 1
#define CONFIG_SOC_FLASH_ESP32 1
#define CONFIG_DT_HAS_ESPRESSIF_ESP32_BT_HCI_ENABLED 1
#define CONFIG_DT_HAS_ESPRESSIF_ESP32_FLASH_CONTROLLER_ENABLED 1
#define CONFIG_DT_HAS_ESPRESSIF_ESP32_GPIO_ENABLED 1
#define CONFIG_DT_HAS_ESPRESSIF_ESP32_I2C_ENABLED 1
#define CONFIG_DT_HAS_ESPRESSIF_ESP32_INTC_ENABLED 1
#define CONFIG_DT_HAS_ESPRESSIF_ESP32_PINCTRL_ENABLED 1
#define CONFIG_DT_HAS_ESPRESSIF_ESP32_RTC_ENABLED 1
#define CONFIG_DT_HAS_ESPRESSIF_ESP32_RTC_TIMER_ENABLED 1
#define CONFIG_DT_HAS_ESPRESSIF_ESP32_SDHC_ENABLED 1
#define CONFIG_DT_HAS_ESPRESSIF_ESP32_SPI_ENABLED 1
#define CONFIG_DT_HAS_ESPRESSIF_ESP32_TRNG_ENABLED 1
#define CONFIG_DT_HAS_ESPRESSIF_ESP32_UART_ENABLED 1
#define CONFIG_DT_HAS_ESPRESSIF_ESP32_WATCHDOG_ENABLED 1
#define CONFIG_DT_HAS_ESPRESSIF_XTENSA_LX6_ENABLED 1
#define CONFIG_DT_HAS_FIXED_PARTITIONS_ENABLED 1
#define CONFIG_DT_HAS_GPIO_KEYS_ENABLED 1
#define CONFIG_DT_HAS_GPIO_LEDS_ENABLED 1
#define CONFIG_DT_HAS_MMIO_SRAM_ENABLED 1
#define CONFIG_DT_HAS_SOC_NV_FLASH_ENABLED 1
#define CONFIG_DT_HAS_ZEPHYR_MEMORY_REGION_ENABLED 1
#define CONFIG_DT_HAS_ZEPHYR_POWER_STATE_ENABLED 1
#define CONFIG_TAINT_BLOBS 1
#define CONFIG_ZEPHYR_ACPICA_MODULE 1
#define CONFIG_ZEPHYR_CMSIS_MODULE 1
#define CONFIG_ZEPHYR_CMSIS_DSP_MODULE 1
#define CONFIG_ZEPHYR_CMSIS_NN_MODULE 1
#define CONFIG_ZEPHYR_FATFS_MODULE 1
#define CONFIG_ZEPHYR_ADI_MODULE 1
#define CONFIG_ZEPHYR_ALTERA_MODULE 1
#define CONFIG_ZEPHYR_HAL_AMBIQ_MODULE 1
#define CONFIG_ZEPHYR_ATMEL_MODULE 1
#define CONFIG_BOOTLOADER_LOG_LEVEL 3
#define CONFIG_LOG_TIMESTAMP_SOURCE_RTOS 1
#define CONFIG_ESP32_DPORT_DIS_INTERRUPT_LVL 5
#define CONFIG_FREERTOS_UNICORE 1
#define CONFIG_ESP_SYSTEM_SINGLE_CORE_MODE 1
#define CONFIG_IDF_FIRMWARE_CHIP_ID 0x0000
#define CONFIG_SPIRAM_ALLOW_BSS_SEG_EXTERNAL_MEMORY 1
#define CONFIG_IDF_TARGET_ESP32 1
#define CONFIG_ESP_SLEEP_WAIT_FLASH_READY_EXTRA_DELAY 2000
#define CONFIG_ZEPHYR_HAL_ESPRESSIF_MODULE 1
#define CONFIG_ZEPHYR_HAL_ESPRESSIF_MODULE_BLOBS 1
#define CONFIG_ZEPHYR_HAL_ETHOS_U_MODULE 1
#define CONFIG_ZEPHYR_HAL_GIGADEVICE_MODULE 1
#define CONFIG_ZEPHYR_HAL_INFINEON_MODULE 1
#define CONFIG_ZEPHYR_HAL_INTEL_MODULE 1
#define CONFIG_ZEPHYR_MICROCHIP_MODULE 1
#define CONFIG_ZEPHYR_HAL_NORDIC_MODULE 1
#define CONFIG_ZEPHYR_NUVOTON_MODULE 1
#define CONFIG_ZEPHYR_HAL_NXP_MODULE 1
#define CONFIG_ZEPHYR_OPENISA_MODULE 1
#define CONFIG_ZEPHYR_QUICKLOGIC_MODULE 1
#define CONFIG_ZEPHYR_HAL_RENESAS_MODULE 1
#define CONFIG_ZEPHYR_HAL_RPI_PICO_MODULE 1
#define CONFIG_ZEPHYR_HAL_SILABS_MODULE 1
#define CONFIG_ZEPHYR_HAL_ST_MODULE 1
#define CONFIG_ZEPHYR_HAL_STM32_MODULE 1
#define CONFIG_ZEPHYR_HAL_TDK_MODULE 1
#define CONFIG_ZEPHYR_HAL_TELINK_MODULE 1
#define CONFIG_ZEPHYR_TI_MODULE 1
#define CONFIG_ZEPHYR_HAL_WCH_MODULE 1
#define CONFIG_ZEPHYR_HAL_WURTHELEKTRONIK_MODULE 1
#define CONFIG_ZEPHYR_XTENSA_MODULE 1
#define CONFIG_ZEPHYR_HOSTAP_MODULE 1
#define CONFIG_ZEPHYR_LIBLC3_MODULE 1
#define CONFIG_ZEPHYR_LIBMETAL_MODULE 1
#define CONFIG_ZEPHYR_LITTLEFS_MODULE 1
#define CONFIG_ZEPHYR_LORAMAC_NODE_MODULE 1
#define CONFIG_ZEPHYR_LVGL_MODULE 1
#define CONFIG_ZEPHYR_MBEDTLS_MODULE 1
#define CONFIG_ZEPHYR_MCUBOOT_MODULE 1
#define CONFIG_ZEPHYR_MIPI_SYS_T_MODULE 1
#define CONFIG_ZEPHYR_NRF_WIFI_MODULE 1
#define CONFIG_ZEPHYR_OPEN_AMP_MODULE 1
#define CONFIG_ZEPHYR_OPENTHREAD_MODULE 1
#define CONFIG_ZEPHYR_PERCEPIO_MODULE 1
#define CONFIG_ZEPHYR_PICOLIBC_MODULE 1
#define CONFIG_ZEPHYR_SEGGER_MODULE 1
#define CONFIG_ZEPHYR_TINYCRYPT_MODULE 1
#define CONFIG_ZEPHYR_TRUSTED_FIRMWARE_A_MODULE 1
#define CONFIG_ZEPHYR_TRUSTED_FIRMWARE_M_MODULE 1
#define CONFIG_ZEPHYR_UOSCORE_UEDHOC_MODULE 1
#define CONFIG_ZEPHYR_ZCBOR_MODULE 1
#define CONFIG_ZEPHYR_NRF_HW_MODELS_MODULE 1
#define CONFIG_HAS_ESPRESSIF_HAL 1
#define CONFIG_BOARD "esp32_devkitc_wroom"
#define CONFIG_BOARD_REVISION ""
#define CONFIG_BOARD_TARGET "esp32_devkitc_wroom/esp32/procpu"
#define CONFIG_BOARD_ESP32_DEVKITC_WROOM 1
#define CONFIG_BOARD_ESP32_DEVKITC_WROOM_ESP32_PROCPU 1
#define CONFIG_BOARD_QUALIFIERS "esp32/procpu"
#define CONFIG_HEAP_MEM_POOL_ADD_SIZE_BOARD 4096
#define CONFIG_SOC "esp32"
#define CONFIG_SOC_SERIES "esp32"
#define CONFIG_SOC_FAMILY "espressif_esp32"
#define CONFIG_SOC_PART_NUMBER "ESP32_WROOM_32UE_N4"
#define CONFIG_SOC_FAMILY_ESPRESSIF_ESP32 1
#define CONFIG_SOC_SERIES_ESP32 1
#define CONFIG_SOC_ESP32_WROOM_32UE_N4 1
#define CONFIG_SOC_ESP32 1
#define CONFIG_SOC_ESP32_PROCPU 1
#define CONFIG_GPIO_INIT_PRIORITY 40
#define CONFIG_ESP32_USE_UNSUPPORTED_REVISION 1
#define CONFIG_ESP_SIMPLE_BOOT 1
#define CONFIG_ESP_HEAP_RUNTIME 1
#define CONFIG_ESP32_TIMER_TASK_STACK_SIZE 4096
#define CONFIG_ESP32_TIMER_TASK_PRIO 3
#define CONFIG_ESP_APPCPU_IRAM_SIZE 0x10000
#define CONFIG_ESP_APPCPU_DRAM_SIZE 0x10000
#define CONFIG_ESPTOOLPY_FLASHMODE_DIO 1
#define CONFIG_ESPTOOLPY_FLASH_SAMPLE_MODE_STR 1
#define CONFIG_ESPTOOLPY_FLASHMODE "dio"
#define CONFIG_ESPTOOLPY_FLASHFREQ_40M 1
#define CONFIG_ESPTOOLPY_FLASHFREQ "40m"
#define CONFIG_ESPTOOLPY_FLASHSIZE_2MB 1
#define CONFIG_ESPTOOLPY_FLASHSIZE "2MB"
#define CONFIG_ESPTOOLPY_BEFORE_RESET 1
#define CONFIG_ESPTOOLPY_BEFORE "default_reset"
#define CONFIG_ESPTOOLPY_AFTER_RESET 1
#define CONFIG_ESPTOOLPY_AFTER "hard_reset"
#define CONFIG_MMU_PAGE_SIZE 0x10000
#define CONFIG_SPI_FLASH_VENDOR_MXIC_SUPPORTED 1
#define CONFIG_SPI_FLASH_SUPPORT_ISSI_CHIP 1
#define CONFIG_SPI_FLASH_SUPPORT_MXIC_CHIP 1
#define CONFIG_SPI_FLASH_SUPPORT_GD_CHIP 1
#define CONFIG_SPI_FLASH_SUPPORT_WINBOND_CHIP 1
#define CONFIG_SPI_FLASH_ROM_DRIVER_PATCH 1
#define CONFIG_BOOTLOADER_FLASH_XMC_SUPPORT 1
#define CONFIG_BOOTLOADER_VDDSDIO_BOOST_1_9V 1
#define CONFIG_BOOTLOADER_REGION_PROTECTION_ENABLE 1
#define CONFIG_ESP32_BT_RESERVE_DRAM 0x0
#define CONFIG_ESP_HEAP_MEM_POOL_REGION_1_SIZE 1024
#define CONFIG_ESP32_DEEP_SLEEP_WAKEUP_DELAY 2000
#define CONFIG_ESP_MAC_ADDR_UNIVERSE_WIFI_STA 1
#define CONFIG_ESP_MAC_ADDR_UNIVERSE_WIFI_AP 1
#define CONFIG_ESP_MAC_ADDR_UNIVERSE_ETH 1
#define CONFIG_ESP_MAC_ADDR_UNIVERSE_BT 1
#define CONFIG_ESP_MAC_UNIVERSAL_MAC_ADDRESSES_FOUR 1
#define CONFIG_ESP32_UNIVERSAL_MAC_ADDRESSES_FOUR 1
#define CONFIG_ESP32_UNIVERSAL_MAC_ADDRESSES 4
#define CONFIG_RTC_CLK_CAL_CYCLES 3000
#define CONFIG_ARCH "xtensa"
#define CONFIG_XTENSA_ENABLE_BACKTRACE 1
#define CONFIG_XTENSA 1
#define CONFIG_ARCH_IS_SET 1
#define CONFIG_LITTLE_ENDIAN 1
#define CONFIG_SRAM_SIZE 128
#define CONFIG_SRAM_BASE_ADDRESS 0x3ffe0000
#define CONFIG_EXCEPTION_DEBUG 1
#define CONFIG_ARCH_HAS_TIMING_FUNCTIONS 1
#define CONFIG_ARCH_SUPPORTS_COREDUMP 1
#define CONFIG_ARCH_HAS_GDBSTUB 1
#define CONFIG_ARCH_HAS_CODE_DATA_RELOCATION 1
#define CONFIG_CPU_HAS_FPU 1
#define CONFIG_ARCH_HAS_DIRECTED_IPIS 1
#define CONFIG_TOOLCHAIN_HAS_BUILTIN_FFS 1
#define CONFIG_MULTITHREADING 1
#define CONFIG_NUM_COOP_PRIORITIES 16
#define CONFIG_NUM_PREEMPT_PRIORITIES 15
#define CONFIG_MAIN_THREAD_PRIORITY 0
#define CONFIG_COOP_ENABLED 1
#define CONFIG_PREEMPT_ENABLED 1
#define CONFIG_PRIORITY_CEILING -127
#define CONFIG_NUM_METAIRQ_PRIORITIES 0
#define CONFIG_THREAD_STACK_INFO 1
#define CONFIG_SCHED_DUMB 1
#define CONFIG_WAITQ_DUMB 1
#define CONFIG_ERRNO 1
#define CONFIG_BOOT_BANNER 1
#define CONFIG_BOOT_BANNER_STRING "Booting Zephyr OS build"
#define CONFIG_BOOT_DELAY 0
#define CONFIG_SYSTEM_WORKQUEUE_PRIORITY -1
#define CONFIG_TIMESLICING 1
#define CONFIG_TIMESLICE_PRIORITY 0
#define CONFIG_NUM_MBOX_ASYNC_MSGS 10
#define CONFIG_KERNEL_MEM_POOL 1
#define CONFIG_HEAP_MEM_POOL_SIZE 0
#define CONFIG_TIMEOUT_64BIT 1
#define CONFIG_SYS_CLOCK_MAX_TIMEOUT_DAYS 365
#define CONFIG_USE_SWITCH 1
#define CONFIG_USE_SWITCH_SUPPORTED 1
#define CONFIG_TOOLCHAIN_SUPPORTS_THREAD_LOCAL_STORAGE 1
#define CONFIG_TOOLCHAIN_SUPPORTS_STATIC_INIT_GNU 1
#define CONFIG_KERNEL_INIT_PRIORITY_OBJECTS 30
#define CONFIG_KERNEL_INIT_PRIORITY_LIBC 35
#define CONFIG_KERNEL_INIT_PRIORITY_DEFAULT 40
#define CONFIG_KERNEL_INIT_PRIORITY_DEVICE 50
#define CONFIG_APPLICATION_INIT_PRIORITY 90
#define CONFIG_CLOCK_CONTROL_ESP32 1
#define CONFIG_CONSOLE_INPUT_MAX_LINE_LEN 128
#define CONFIG_CONSOLE_HAS_DRIVER 1
#define CONFIG_CONSOLE_INIT_PRIORITY 60
#define CONFIG_UART_CONSOLE 1
#define CONFIG_GPIO_ESP32 1
#define CONFIG_INTC_INIT_PRIORITY 40
#define CONFIG_INTC_ESP32 1
#define CONFIG_PINCTRL 1
#define CONFIG_PINCTRL_ESP32 1
#define CONFIG_SERIAL_HAS_DRIVER 1
#define CONFIG_SERIAL_SUPPORT_INTERRUPT 1
#define CONFIG_UART_ESP32 1
#define CONFIG_UART_ESP32_TX_FIFO_THRESH 0x1
#define CONFIG_UART_ESP32_RX_FIFO_THRESH 0x16
#define CONFIG_SYSTEM_CLOCK_INIT_PRIORITY 0
#define CONFIG_TICKLESS_CAPABLE 1
#define CONFIG_FULL_LIBC_SUPPORTED 1
#define CONFIG_MINIMAL_LIBC_SUPPORTED 1
#define CONFIG_NEWLIB_LIBC_SUPPORTED 1
#define CONFIG_PICOLIBC_SUPPORTED 1
#define CONFIG_PICOLIBC 1
#define CONFIG_COMMON_LIBC_ABORT 1
#define CONFIG_COMMON_LIBC_MALLOC 1
#define CONFIG_COMMON_LIBC_CALLOC 1
#define CONFIG_COMMON_LIBC_REALLOCARRAY 1
#define CONFIG_PICOLIBC_USE_TOOLCHAIN 1
#define CONFIG_PICOLIBC_IO_LONG_LONG 1
#define CONFIG_STDOUT_CONSOLE 1
#define CONFIG_NEED_LIBC_MEM_PARTITION 1
#define CONFIG_SYS_HEAP_ALLOC_LOOPS 3
#define CONFIG_SYS_HEAP_SMALL_ONLY 1
#define CONFIG_ZVFS_OPEN_MAX 4
#define CONFIG_HAS_POWEROFF 1
#define CONFIG_CBPRINTF_COMPLETE 1
#define CONFIG_CBPRINTF_FULL_INTEGRAL 1
#define CONFIG_CBPRINTF_CONVERT_CHECK_PTR 1
#define CONFIG_POSIX_AEP_CHOICE_NONE 1
#define CONFIG_POSIX_C_LANG_SUPPORT_R 1
#define CONFIG_POSIX_OPEN_MAX 4
#define CONFIG_POSIX_PAGE_SIZE 0x40
#define CONFIG_EVENTFD_MAX 0
#define CONFIG_MAX_PTHREAD_COUNT 0
#define CONFIG_MAX_PTHREAD_KEY_COUNT 0
#define CONFIG_MAX_TIMER_COUNT 0
#define CONFIG_MSG_COUNT_MAX 0
#define CONFIG_POSIX_LIMITS_RTSIG_MAX 0
#define CONFIG_POSIX_MAX_FDS 4
#define CONFIG_POSIX_MAX_OPEN_FILES 4
#define CONFIG_TIMER_DELAYTIMER_MAX 0
#define CONFIG_SEM_NAMELEN_MAX 0
#define CONFIG_SEM_VALUE_MAX 0
#define CONFIG_TC_PROVIDES_POSIX_C_LANG_SUPPORT_R 1
#define CONFIG_LIBGCC_RTLIB 1
#define CONFIG_PRINTK 1
#define CONFIG_EARLY_CONSOLE 1
#define CONFIG_ASSERT_VERBOSE 1
#define CONFIG_LLEXT_EDK_NAME "llext-edk"
#define CONFIG_HAS_PM 1
#define CONFIG_TIMER_RANDOM_INITIAL_STATE 123456789
#define CONFIG_CSPRNG_AVAILABLE 1
#define CONFIG_TOOLCHAIN_ZEPHYR_0_17 1
#define CONFIG_TOOLCHAIN_ZEPHYR_SUPPORTS_THREAD_LOCAL_STORAGE 1
#define CONFIG_TOOLCHAIN_ZEPHYR_SUPPORTS_GNU_EXTENSIONS 1
#define CONFIG_LINKER_ORPHAN_SECTION_WARN 1
#define CONFIG_ROM_END_OFFSET 0x0
#define CONFIG_LD_LINKER_SCRIPT_SUPPORTED 1
#define CONFIG_LD_LINKER_TEMPLATE 1
#define CONFIG_LINKER_SORT_BY_ALIGNMENT 1
#define CONFIG_LINKER_GENERIC_SECTIONS_PRESENT_AT_BOOT 1
#define CONFIG_LINKER_USE_RELAX 1
#define CONFIG_LINKER_ITERABLE_SUBALIGN 4
#define CONFIG_STD_C99 1
#define CONFIG_TOOLCHAIN_SUPPORTS_GNU_EXTENSIONS 1
#define CONFIG_SIZE_OPTIMIZATIONS 1
#define CONFIG_COMPILER_TRACK_MACRO_EXPANSION 1
#define CONFIG_COMPILER_COLOR_DIAGNOSTICS 1
#define CONFIG_FORTIFY_SOURCE_COMPILE_TIME 1
#define CONFIG_COMPILER_OPT ""
#define CONFIG_RUNTIME_ERROR_CHECKS 1
#define CONFIG_KERNEL_BIN_NAME "zephyr"
#define CONFIG_OUTPUT_STAT 1
#define CONFIG_OUTPUT_PRINT_MEMORY_USAGE 1
#define CONFIG_BUILD_GAP_FILL_PATTERN 0xFF
#define CONFIG_BUILD_OUTPUT_STRIP_PATHS 1
#define CONFIG_CHECK_INIT_PRIORITIES 1
#define CONFIG_WARN_DEPRECATED 1
#define CONFIG_TAINT 1
#define CONFIG_ENFORCE_ZEPHYR_STDINT 1
#define CONFIG_LEGACY_GENERATED_INCLUDE_PATH 1
