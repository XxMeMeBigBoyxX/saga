#include "game/gizmos/portal.h"

#include "decomp.h"

int portal_gizmotype_id = -1;

static int Portal_GetMaxGizmos(void *portal) {
    UNIMPLEMENTED();
}

static void Portal_AddGizmos(GIZMOSYS *gizmo_sys, int, void *, void *) {
    UNIMPLEMENTED();
}

static char *Portal_GetGizmoName(GIZMO *gizmo) {
    static char name[16];

    if (gizmo == NULL || gizmo->object.portal == NULL) {
        return NULL;
    }

    sprintf(name, "%s%d", "portal_", gizmo->object.portal->id);

    return name;
}

static int Portal_GetOutput(GIZMO *gizmo, int, int) {
    if (gizmo == NULL || gizmo->object.portal == NULL) {
        return 0;
    }

    return gizmo->object.portal->active & 1;
}

char *Portal_GetOutputName(GIZMO *gizmo, int output_index) {
    static char name[] = "Active";

    return name;
}

static int Portal_GetNumOutputs(GIZMO *gizmo) {
    return 1;
}

void Portal_Activate(GIZMO *gizmo, int) {
    UNIMPLEMENTED();
}

static int Portal_ActivateRev(GIZMO *gizmo, int, int) {
    UNIMPLEMENTED();
}

static void *Portals_AllocateProgressData(VARIPTR * buffer, VARIPTR * buffer_end) {
    return GizmoBufferAlloc(buffer, buffer_end, 4);
}

static void Portals_ClearProgress(void *, void *) {
    UNIMPLEMENTED();
}

static void Portals_StoreProgress(void *, void *, void *) {
    UNIMPLEMENTED();
}

static void Portals_Reset(void *, void *, void *) {
    UNIMPLEMENTED();
}

ADDGIZMOTYPE* Portal_RegisterGizmo(int type_id) {
    static ADDGIZMOTYPE addtype;

    addtype = Default_ADDGIZMOTYPE;
    addtype.name = "Portal";
    addtype.prefix = "portal_";
    addtype.fns.unknown1 = 0;
    addtype.fns.early_update_fn = NULL;
    addtype.fns.panel_draw_fn = NULL;
    addtype.fns.get_visibility_fn = NULL;
    addtype.fns.get_max_gizmos_fn = Portal_GetMaxGizmos;
    addtype.fns.get_pos_fn = NULL;
    addtype.fns.using_special_fn = NULL;
    addtype.fns.add_gizmos_fn = Portal_AddGizmos;
    addtype.fns.bolt_hit_plat_fn = NULL;
    addtype.fns.get_best_bolt_target_fn = NULL;
    addtype.fns.late_update_fn = NULL;
    addtype.fns.bolt_hit_fn = NULL;
    addtype.fns.draw_fn = NULL;
    addtype.fns.get_gizmo_name_fn = Portal_GetGizmoName;
    addtype.fns.get_output_fn = Portal_GetOutput;
    addtype.fns.get_output_name_fn = Portal_GetOutputName;
    addtype.fns.get_num_outputs_fn = Portal_GetNumOutputs;
    addtype.fns.activate_fn = Portal_Activate;
    addtype.fns.activate_rev_fn = Portal_ActivateRev;
    addtype.fns.set_visibility_fn = NULL;
    addtype.fns.allocate_progress_data_fn = Portals_AllocateProgressData;
    addtype.fns.clear_progress_fn = Portals_ClearProgress;
    addtype.fns.store_progress_fn = Portals_StoreProgress;
    addtype.fns.reset_fn = Portals_Reset;
    addtype.fns.reserve_buffer_space_fn = NULL;
    addtype.fns.load_fn = NULL;
    addtype.fns.post_load_fn = NULL;
    addtype.fns.add_level_sfx_fn = NULL;
    portal_gizmotype_id = type_id;

    return &addtype;
}
