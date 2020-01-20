#ifndef HW_RISCV_MULTICO_H
#define HW_RISCV_MULTICO_H

#include "hw/riscv/riscv_hart.h"
#include "hw/sysbus.h"

typedef struct {
    /*< private >*/
    SysBusDevice parent_obj;

    /*< public >*/
    RISCVHartArrayState soc;
    void *fdt;
    int fdt_size;
} MulticoState;

enum {
    MULTICO_MROM,
    MULTICO_CLINT,
    MULTICO_DRAM
};

#define MULTICO_START 0x80000000

#if defined(TARGET_RISCV32)
#define MULTICO_CPU TYPE_RISCV_CPU_RV32GCSU_V1_10_0
#elif defined(TARGET_RISCV64)
#define MULTICO_CPU TYPE_RISCV_CPU_MULTICO_RV64
#endif

#endif
