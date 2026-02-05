#include "game/gizmos/giztimer.h"

#include "decomp.h"

int giztimer_gizmotype_id = -1;

int GizTimer_GetMaxGizmos(void *timer) {
    UNIMPLEMENTED();
}

void GizTimer_AddGizmos(GIZMOSYS *gizmo_sys, int, void *, void *) {
    UNIMPLEMENTED();
}

void GizTimer_Update(void *, void *, float) {
    UNIMPLEMENTED();
}

char *GizTimer_GetGizmoName(GIZMO *gizmo) {
    UNIMPLEMENTED();
}

int GizTimer_GetOutput(GIZMO *gizmo, int, int) {
    UNIMPLEMENTED();
}

char *GizTimer_GetOutputName(GIZMO *gizmo, int output_index) {
    return "Ping";
}

int GizTimer_GetNumOutputs(GIZMO *gizmo) {
    return 1;
}

void GizTimer_Activate(GIZMO *gizmo, int) {
    UNIMPLEMENTED();
}

int GizTimer_ReserveBufferSpace(void *, int) {
    UNIMPLEMENTED();
}

int GizTimer_Load(void *, void *) {
    UNIMPLEMENTED();
}

ADDGIZMOTYPE* GizTimer_RegisterGizmo(int type_id) {
    static ADDGIZMOTYPE addtype;

    addtype = Default_ADDGIZMOTYPE;
    addtype.name = "GizTimer";
    addtype.prefix = "";
    addtype.fns.unknown1 = 0;
    addtype.fns.early_update_fn = GizTimer_Update;
    addtype.fns.panel_draw_fn = NULL;
    addtype.fns.get_visibility_fn = NULL;
    addtype.fns.get_max_gizmos_fn = GizTimer_GetMaxGizmos;
    addtype.fns.get_pos_fn = NULL;
    addtype.fns.using_special_fn = NULL;
    addtype.fns.add_gizmos_fn = GizTimer_AddGizmos;
    addtype.fns.bolt_hit_plat_fn = NULL;
    addtype.fns.get_best_bolt_target_fn = NULL;
    addtype.fns.late_update_fn = NULL;
    addtype.fns.bolt_hit_fn = NULL;
    addtype.fns.draw_fn = NULL;
    addtype.fns.get_gizmo_name_fn = GizTimer_GetGizmoName;
    addtype.fns.get_output_fn = GizTimer_GetOutput;
    addtype.fns.get_output_name_fn = GizTimer_GetOutputName;
    addtype.fns.get_num_outputs_fn = GizTimer_GetNumOutputs;
    addtype.fns.activate_fn = GizTimer_Activate;
    addtype.fns.activate_rev_fn = NULL;
    addtype.fns.set_visibility_fn = NULL;
    addtype.fns.allocate_progress_data_fn = NULL;
    addtype.fns.clear_progress_fn = NULL;
    addtype.fns.store_progress_fn = NULL;
    addtype.fns.reset_fn = NULL;
    addtype.fns.reserve_buffer_space_fn = GizTimer_ReserveBufferSpace;
    addtype.fns.load_fn = GizTimer_Load;
    addtype.fns.post_load_fn = NULL;
    addtype.fns.add_level_sfx_fn = NULL;
    giztimer_gizmotype_id = type_id;

    return &addtype;
}
