/*
 * Stubs for the two optional sde-drm subsystems this port does not build.
 *
 * drm_dpps_mgr_imp.cpp and drm_panel_feature_mgr.cpp were dropped because both
 * depend on struct layouts that only exist in later trees:
 *
 *   - DPPS passes DRMDppsFeatureInfo, which gained obj_id/payload/payload_size.
 *   - Panel features (RC, SPR, demura) are a later addition; sm8150's SDM does
 *     not use them, and DisplayBuiltIn::CreatePanelfeatures() already treats a
 *     missing implementation as non-fatal.
 *
 * Both structs cross the SDM boundary, so extending them would change their
 * layout and break the very ABI this port exists to match. Returning nullptr
 * lets DRMManager::Init() proceed without either subsystem.
 */

#include <cstdint>
#include <cstdarg>
#include <cstring>
#include <string>
#include <vector>
#include <xf86drm.h>
#include <xf86drmMode.h>
#include <display/drm/sde_drm.h>
#include <drm_interface.h>
#include "drm_dpps_mgr_intf.h"
#include "drm_panel_feature_mgr_intf.h"

namespace sde_drm {

extern "C" DRMDppsManagerIntf *GetDppsManagerIntf() {
  return nullptr;
}

extern "C" DRMPanelFeatureMgrIntf *GetPanelFeatureManagerIntf() {
  return nullptr;
}

}  // namespace sde_drm
