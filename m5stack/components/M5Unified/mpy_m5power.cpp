#include <utility/Power_Class.hpp>

extern "C"
{
#include "mpy_m5power.h"

namespace m5
{
    static inline Power_Class *getPower(const mp_obj_t& self) {
        return (Power_Class *)(((pwr_obj_t *)MP_OBJ_TO_PTR(self))->btn);
    }

    mp_obj_t power_setExtPower(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args) {
        enum {ARG_en, ARG_mask};
        /* *FORMAT-OFF* */
        const mp_arg_t allowed_args[] = {
            { MP_QSTR_en,   MP_ARG_BOOL | MP_ARG_REQUIRED, {.u_bool = true } },
            { MP_QSTR_mask, MP_ARG_INT                   , {.u_int  = 0xFF } },
        };
        /* *FORMAT-ON* */
        mp_arg_val_t args[MP_ARRAY_SIZE(allowed_args)];
        // The first parameter is the Power object, parse from second parameter.
        mp_arg_parse_all(n_args - 1, pos_args + 1, kw_args, MP_ARRAY_SIZE(allowed_args), allowed_args, args);

        getPower(pos_args[0])->setExtPower(args[ARG_en].u_bool, (ext_port_mask_t)args[ARG_en].u_int);
        return mp_const_none;
    }

    mp_obj_t power_setLed(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args) {
        enum {ARG_br};
        /* *FORMAT-OFF* */
        const mp_arg_t allowed_args[] = {
            { MP_QSTR_br, MP_ARG_INT | MP_ARG_REQUIRED, {.u_int = 0 } }
        };
        /* *FORMAT-ON* */
        mp_arg_val_t args[MP_ARRAY_SIZE(allowed_args)];
        // The first parameter is the Power object, parse from second parameter.
        mp_arg_parse_all(n_args - 1, pos_args + 1, kw_args, MP_ARRAY_SIZE(allowed_args), allowed_args, args);

        getPower(pos_args[0])->setLed(args[ARG_br].u_int);
        return mp_const_none;
    }

    mp_obj_t power_powerOff(mp_obj_t self) {
        getPower(self)->powerOff();
        return mp_const_none;
    }
}
}