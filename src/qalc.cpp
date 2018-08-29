// rofi-qalc: A qalculator plugin for rofi
// Copyright (C) 2018 <tomKPZ@gmail.com>
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA

#include <rofi/helper.h>
#include <rofi/mode-private.h>
#include <rofi/mode.h>

typedef struct {
} CALCModePrivateData;

static int qalc_mode_init(Mode* sw) {
  if (mode_get_private_data(sw) == NULL) {
    CALCModePrivateData* pd = new CALCModePrivateData();
    mode_set_private_data(sw, (void*)pd);
  }
  return TRUE;
}

static unsigned int qalc_mode_get_num_entries(const Mode* sw) {
  return 0;
}

static ModeMode qalc_mode_result(Mode* sw,
                                 int menu_entry,
                                 G_GNUC_UNUSED char** input,
                                 unsigned int selected_line) {
  return MODE_EXIT;
}

static void qalc_mode_destroy(Mode* sw) {
  CALCModePrivateData* pd = (CALCModePrivateData*)mode_get_private_data(sw);
  if (pd != NULL) {
    g_free(pd);
    mode_set_private_data(sw, NULL);
  }
}

static int qalc_token_match(G_GNUC_UNUSED const Mode* sw,
                            G_GNUC_UNUSED rofi_int_matcher** tokens,
                            G_GNUC_UNUSED unsigned int index) {
  return TRUE;
}

static char* qalc_get_display_value(const Mode* sw,
                                    unsigned int selected_line,
                                    G_GNUC_UNUSED int* state,
                                    G_GNUC_UNUSED GList** attr_list,
                                    int get_entry) {
  return nullptr;
}

static char* qalc_get_message(const Mode* sw) {
  return nullptr;
}

static char* qalc_preprocess_input(Mode* sw, const char* input) {
  return nullptr;
}

Mode mode = {
    .abi_version = ABI_VERSION,
    .name = "qalc",
    .cfg_name_key = "display-qalc",
    ._init = qalc_mode_init,
    ._get_num_entries = qalc_mode_get_num_entries,
    ._result = qalc_mode_result,
    ._destroy = qalc_mode_destroy,
    ._token_match = qalc_token_match,
    ._get_display_value = qalc_get_display_value,
    ._get_message = qalc_get_message,
    ._preprocess_input = qalc_preprocess_input,
    .private_data = NULL,
    .free = NULL,
};
